/****************************************************************************
 * flash_scrub_task.c
 *
 * Task to handle events for scrubbing.
 *
 * Copyright (C) 2013-2014 QUALCOMM Technologies, Inc.
 *
 * The Scrub task handles the events generated by the scrub master module.
 *
 ***************************************************************************/

/*===========================================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/rel/core.mpss/3.5.c12.3/storage/flash_scrub/src/flash_scrub_task.c#1 $ $DateTime: 2016/12/13 07:59:23 $ $Author: mplcsds1 $

when        who  what, where, why
----------  ---  ------------------------------------------------------------
2014-04-28   vm    Use correct MSG macros to save RAM.
2013-10-04   dks   Handle Fota update message from apps.
2013-09-05   dks   Fix accuracy of scrub timer when no system time available.
2013-08-26   rp    Clear the correct signal-bit when system-timer expires.
2013-08-15   rp    Prefix flash_scrub to all non-static functions.
2013-08-15   rp    Make all target file names to start with flash_scrub.
2013-08-14   rp    Include "scrub_config_i.h" before any other includes.
2013-08-14   rp    Add f3 messages for debug.
2013-08-12   rp    Do not compute MD5-hash at rcinit boot time.
2013-08-01   rp    Scrub-Master module cleanup.
2013-06-05   wek   Create.

===========================================================================*/

#include "flash_scrub_config_i.h"
#include "flash_scrub_priv_funcs.h"
#include "flash_scrub_global_lock.h"
#include "flash_scrub_err.h"

#include "rex.h"
#include "task.h"
#include "assert.h"


void
scrub_task (dword parm)
{
  rex_tcb_type *tcb;
  rex_sigs_type task_sigs;

  (void) parm;

  tcb = rex_self ();

  FLASH_SCRUB_GLOBAL_LOCK_INIT ();
  FLASH_SCRUB_GLOBAL_LOCK ();

  /* Wait for start signal */
  rcinit_handshake_startup ();

  FLASH_SCRUB_MSG_MED_0 ("Scrub task started");

  flash_scrub_init ();

  rcinit_register_termfn_group(RCINIT_GROUP_6,
                               flash_scrub_rcinit_shutdown_callback);

  FLASH_SCRUB_GLOBAL_UNLOCK ();

  FLASH_SCRUB_MSG_MED_0 ("Scrub task inited");
  /* Loop forever handling commands. */
  for (;;)
  {
    task_sigs = rex_wait (FLASH_SCRUB_SYSTEM_TIMER_EXPIRED_SIGNAL         |
                          FLASH_SCRUB_SCRUB_TIMER_EXPIRED_SIGNAL          |
                          FLASH_SCRUB_START_SCRUB_SIGNAL                  |
                          FLASH_SCRUB_SAVE_TIME_IN_EFS_SIGNAL             |
                          FLASH_SCRUB_FOTA_NOTIFICATION_SIGNAL);

    if ((task_sigs & FLASH_SCRUB_SYSTEM_TIMER_EXPIRED_SIGNAL) != 0)
    {
      FLASH_SCRUB_MSG_MED_0 ("system-timer expired signal recd.");
      (void) rex_clr_sigs (tcb, FLASH_SCRUB_SYSTEM_TIMER_EXPIRED_SIGNAL);
      flash_scrub_system_timer_signal_received ();
    }

    if ((task_sigs & FLASH_SCRUB_SCRUB_TIMER_EXPIRED_SIGNAL) != 0)
    {
      FLASH_SCRUB_MSG_MED_0 ("scrub-timer expired signal recd.");
      (void) rex_clr_sigs (tcb, FLASH_SCRUB_SCRUB_TIMER_EXPIRED_SIGNAL);
      flash_scrub_scrub_timer_signal_received ();
    }

    if ((task_sigs & FLASH_SCRUB_START_SCRUB_SIGNAL) != 0)
    {
      FLASH_SCRUB_MSG_MED_0 ("scrub start-signal recd.");
      (void) rex_clr_sigs (tcb, FLASH_SCRUB_START_SCRUB_SIGNAL);
      flash_scrub_start_scrub_signal_received ();
    }

    if ((task_sigs & FLASH_SCRUB_SAVE_TIME_IN_EFS_SIGNAL) != 0)
    {
      FLASH_SCRUB_MSG_MED_0 ("update time in efs signal recd.");
      (void)rex_clr_sigs (tcb, FLASH_SCRUB_SAVE_TIME_IN_EFS_SIGNAL);
      flash_scrub_save_time_in_efs_signal_received ();
    }

    if ((task_sigs & FLASH_SCRUB_FOTA_NOTIFICATION_SIGNAL) != 0)
    {
      FLASH_SCRUB_MSG_MED_0 ("FOTA notification signal recd.");
      (void)rex_clr_sigs (tcb, FLASH_SCRUB_FOTA_NOTIFICATION_SIGNAL);
      flash_scrub_fota_notification_signal_received ();
    }
  }
}