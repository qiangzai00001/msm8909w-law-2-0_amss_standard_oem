#ifndef NVI_H
#define NVI_H
/*==========================================================================

         N V    T A S K    I N T E R N A L S    H E A D E R    F I L E

DESCRIPTION
  This header file contains all the internal definitions of NVM items.
  Items are passed to the NV task using an external interface definition
  provided in NV.H.  This file specifies how NVM items are stored internally
  within the NV EEPROM.  

Copyright (c) 1992-2013 by QUALCOMM Technologies, Incorporated.
All Rights Reserved.
Qualcomm Confidential and Proprietary
===========================================================================*/
/*===========================================================================

                        EDIT HISTORY FOR FILE

$PVCSPath:  L:/src/asw/MSM5200/drivers/vcs/nvi.h_v   1.2   15 May 2001 14:08:32   pingguan  $
$Header: //components/rel/core.mpss/3.5.c12.3/services/nv/src/nvi.h#1 $ $DateTime: 2016/12/13 07:59:23 $ $Author: mplcsds1 $
   
when       who     what, where, why
--------   ---     ----------------------------------------------------------
03/22/13   sri     Removed dog_report_timer migrated to dog HB
03/30/01   pg      Made changes to make use of the files generated by NVC.
12/18/00   pg      Ported to simba MSM5200.
11/15/00   pg      Recovered item NV_CDMA_TX_LIM_VS_VOLT_I as it is needed in
                   FFA5000 build.
11/01/00   pg      Reverted the previous change.
10/31/00   pg      Replaced NV_FEATURE_TRIMODE_ITEMS with FEATURE_TRIMODE_ITEMS.
                   And made it a feature to be turned on by customers.
10/19/00   pg      Added support for NV_GPS1_GPS_RF_LOSS_I associated with
                   FEATURE_GPSONE.
10/05/00   pg      Merged TigerII and PP/PPG archive.
                   Added support for NV_SUBPCG_PA_WARMUP_DELAY_I associated
                   with FEATURE_SUBPCG_PA_WARMUP_DELAY.
09/25/00   pg      Added NV_FEATURE_TRIMODE_ITEMS to associated with 
                   NV_PCS_ENC_BTF_I to make sure that it can only accessed
                   in Trimode builds.
09/20/00   pg      Added support for invariant item NV_BD_ADDR_I associated
                   with FEATURE_BT.
09/18/00   pg      Added support for NV_PCS_ENC_BTF_I and NV_CDMA_ENC_BTF_I 
                   associated with FEATURE_ENC_BTF_IN_NV.
09/07/00   pg      Added support for NV_GPS1_GPS_RF_DELAY_I and 
                   NV_GPS1_CDMA_RF_DELAY_I associated with FEATURE_GPSONE.
09/01/00   pg      Changed FEATURE_RUIM_SMS to FEATURE_RUIM_SMSS.
08/25/00   pg      Added support for 
                   NV_RUIM_SMS_STATUS_I 
                   NV_PCS_TX_LIN_MASTER0_I          
                   NV_PCS_TX_LIN_MASTER1_I          
                   NV_PCS_TX_LIN_MASTER2_I 
                   NV_PCS_TX_LIN_MASTER3_I   
                   NV_PCS_PA_RANGE_OFFSETS_I
                   NV_PCS_TX_COMP0_I
                   NV_PCS_TX_COMP1_I
                   NV_PCS_TX_COMP2_I
                   NV_PCS_TX_COMP3_I
                   NV_DIAG_RESTART_CONFIG_I
07/27/00   pg      Fixed error feature name for MM items in nvi_items_enum_type.
07/25/00   rp      Changed FS_FILENAME_MAX_LENGTH to NV_FS_FILENAME_MAX_LENGTH
                   to remove dependency on FS_FILENAME_MAX_LENGTH.
07/06/00   pg      Added support for NV_MM_STORAGE_DEVICE_I, NV_UBROWSER_I.
07/05/00   pg      Added support for NV_MM_RINGER_FILE_I.
06/23/00   rp      Merged in support for all MSM3300 GPS One items under
                   FEATURE_GPSONE.
06/23/00   rp      Updated NV_FEATURE_CONFIG_LENGTH used in nvi_verno_ext_type
                   to track new features from 2 bytes to 4 bytes. 
05/30/00   pg      Added support for NV_PRIMARY_DNS_I, NV_SECONDARY_DNS_I.
                   Added support for NV_DIAG_PORT_SELECT_I associated with
                   FEATURE_DIAG_PORT_SELECT.
05/05/00   pg      Cleaned out obsolete items:
                   NV_PPCNCH_I
                   NV_SPCNCH_I
                   NV_CDMA_TX_LIM_VS_VOLT_I
                   NV_WILDCARD_SID_I
                   NV_ROAM_MSG_I
                   NV_FULL_PREF_MODE_I
                   NV_CDMA_TX_LIMIT_I
                   NV_CDMA_RIPPLE_I
                   NV_CDMA_RX_OFFSET_I
                   NV_CDMA_RX_POWER_I
                   NV_CDMA_RX_ERROR_I
                   NV_CDMA_TX_SLOPE_1_I
                   NV_CDMA_TX_SLOPE_2_I
                   NV_CDMA_TX_ERROR_I
                   NV_VOC_GAIN_I
                   NV_POWER_CYCLES_I
                   NV_MESSAGE_ALERT_I
                   NV_AUTO_REDIAL_SHADOW_I
                   NV_IMSI_I
                   NV_RESTRICT_GLOBAL_I
                   NV_CALL_TIMER_I
                   NV_LIFE_TIMER_I
                   NV_SONY_ATTEN_1_I
                   NV_SONY_ATTEN_2_I
                   NV_SIO_PWRDWN_I
05/02/00   pg      Changed NV_TX_COMP_I from indexed item to individual items:
                   NV_TX_COMP0_I, NV_TX_COMP1_I, NV_TX_COMP2_I, NV_TX_COMP3_I.
04/25/00   pg      Added support for NV_PA_RANGE_OFFSETS_I, NV_TX_COMP_I 
                   associated with FEATURE_PA_RANGE_TEMP_FREQ_COMP.
                   Added support for SDAC items associated with 
                   FEATURE_STEREO_DAC.
                   Added support for multimedia items associated with 
                   FEATURE_MULTIMEDIA.
04/09/00   pg      Added support for NV_PREF_FOR_RC_I, NV_DS_DEFAULT_BAUD_I,
                   NV_DIAG_DEFAULT_BAUD_I, NV_SIO_DEV_MAP_MENU_ITEM_I,
                   NV_TTY_I.
03/18/00   rp      Fixed typo in NV_RUIM_CHV_SIZE. 
03/16/00   rp      Added support for R-UIM items based on 
                   FEATURE_RUIM_CHV_FROM_NV.
03/13/00   rp      Added Broadcast SMS items support for EEPROM based on 
                   FEATURE_BROADCAST_SMS. 
03/09/00   rp      Changed #ifdef FEATURE_DS_PAP to 
                   #if (defined (FEATURE_DS_PAP) || defined (FEATURE_DS_CHAP) )
03/09/00   rp      Added support for RF calibration items associated with
                   FEATURE_PA_RANGE_DIG_COMP and FEATURE_4PAGE_TX_LINEARIZER.
03/09/00   rp      Updated type for NVI_IM_LEVEL1_I and NVI_IM_LEVEL2_I from
                   byte to int1.  
03/01/00   rp      Added limited support for nvi_verno_ext_type to track new 
                   feature definitions so that a rebuild will occur when
                   feature selection changes, this code will be obsolete
                   when the new NV meta compiler is available in the future.
02/22/00   rp      Added support for new RFR3100 items for Trimode.
02/22/00   rp      Changed type for NV_LNA_RANGE_12_OFFSET_I from word to 
                   int2.  
02/22/00   rp      Added support for new RFR3100 item NV_RX_AGC_MIN_11_I.
02/22/00   rp      Changed NAM_LOCK to be a per-NAM item.
                   Made NAM_LOCK and OTAPA_ENABLED support conditional
                   based on FEATURE_OTASP_OTAPA. 
02/16/00   rp      Added support for new RFR3100 items based on 
                   FEATURE_RFR3100.
01/31/00   rp      Added Broadcast SMS items support for NVIM based on 
                   FEATURE_BROADCAST_SMS. 
12/06/99   rp      Added Trimode items support based on
                   NV_FEATURE_TRIMODE_ITEMS.
10/08/99   pg      Added featurized support for nvi_rental_timer_type and 
                   nvi_rental_cnt_type.
10/04/99   rp      Added featurized support for NV_ROAM_MSG_I, NV_OTKSL_FLAG_I,
                   NV_SMS_REMINDER_TONE_I, NV_FULL_PREF_MODE_I,
                   NV_UP_BROWSER_WARN_I, NV_USER_ZONE_ENABLED_I, NV_USER_ZONE_I,
                   NV_AUTO_VOLUME_ENABLED_I, and NV_WILDCARD_SID_I for Digby.
08/16/99   rp      Removed support for NV_PAP_DATA_I. Added support for
                   NV_PAP_USER_ID_I and NV_PAP_PASSWORD_I.
08/13/99   rp      Added support for NV_PAP_DATA_I.
06/30/99   kmp     Changed FEATURE_NV_JSTD008 to FEATURE_NV_TMSI and removed
                   PACKED from the enums for the ARM 2.50 compiler.
03/31/99   snn     Deleted the references to Pragma Packs.
03/31/99   snn     ls made the following changes. I merged them here.  
                   Made NV_OTKSL_I universal.
                   Added NV_DATA_AUTO_PACKET_DETECTION_I item.
                   Made UP link access key a separate item.
03/11/99   snn     ck did the following changes in earlier version. I included
                   them here: 
                   Ifdefed PREF_VOICE_SO_I under FEATURE_EVRC_SO_MGMT
03/11/99   snn     ny did the following changes in earlier version. I included
                   them here:
                   Cleaned up the compilation to remove warnings/error messges.
                   Applied merge guidelines 3.0 to clean up the code
03/02/99   ls      Changed "int" to "word" in UP items.
02/26/99   ls      Added MDR items and IS-95B support.
02/11/99   ls      Merged OTASP 3.0.
02/05/99   ls      Changed featurization of NV_PREF_MODE_I.
02/03/99   ls      Introduced enums-as-words option.
02/02/99   ls      Added stack checker items.
01/14/99   ls      Added PDM tables support for ISS2 targets.
12/01/98   dlb     Added handover block support.        
11/29/98   ls      Removed obsolete page msg items and types.
11/21/98   ls      Added NV_OUTPUT_UI_KEYS_I.
10/28/98   dlb     Added support for ARM.
10/26/98   ls      Added NV_SRDA_ENABLED_I.
10/19/98   ls      Merged SSPR Enhancements.
10/01/98   ls      Changed EVRC item subtypes and added NV_SMS_AUTO_DELETE_I.
09/29/98   ls      Added EVRC, VRHFK, and new RF Cal items.
09/10/98   ls      Revived AUTO_ANSWER_SHADOW, added NV_SIO_PWRDWN_I.
08/27/98   ls      Added NV_AFAX_I, plus other configuration changes.
08/25/98   ls      Added CARRIER_INFO for module.
08/19/98   ls      Added BORSCHT items.
08/11/98   ls      Added NV_FULL_SYSTEM_PREF_I.
08/04/98   ls      Added rental timer enabled item support.
08/02/98   ls      Added rental counter item support.
07/27/98   ls      Added rental timer items.
07/14/98   ls      Merged remainder of SSPR-800  support under internal 
                   feature control.
07/06/98   ls      Partial merge of SSPR-800: added IS-683A PRL support.
06/22/98   ls      Added numAddr field to UP_LINK_INFO item.
06/12/98   ls      Added Unwired Planet alert items.
05/14/98   ls      Added NV_PDM1_VS_TEMP_I and NV_PDM2_VS_TEMP_I.
03/19/98   ls      Added PDM1, BELL_MODEM, and ALERTS_LVL_SHADOW.
01/20/98   ls      Added DTACO items, new RF Cal items, and version field in
                   roaming list.
12/16/97   ls      Added RF Cal pointer, elapsed_time item, and disconnect
                   timer.
11/26/97   ls      Removed several obsolete items.
11/05/97   ls      Added Unwired Planet support, version 2.
10/31/97   ls      Made OTKSL available to 2-NAM builds.
10/21/97   ls      Added data services items.
09/09/97   ls      Returned RSVD_MEM_SIZE to 0 after fixing nva_memavail().
08/29/97   ls      Removed extraneous nam field in dir_number_type.
08/03/97   ls      Made RSVD_MEM_SIZ one short block so nvdiv move works.
07/23/97   ls      Added initial support for Unwired Planet.
06/06/97   ls      Added voice_privacy_alert item for TGP.
06/03/97   ls      Implemented auto-detection of EEPROM configuration.
05/15/97   ls      Added support for OTASP-800.
04/30/97   ls      Added ISS2 dialing plan state table item.
04/22/97   ls      Featurized redial item.
04/02/97   ls      Added Clam-Shell Call Answer item, removed old MRU
                   table format.
02/13/97   ls      Added vibrator item, defined both MRU table formats.
01/17/97   ls      Changed MRU Table format.
01/03/97   ls      Featurized NV.
11/12/96   ls      Bumped all KLT_REVs due to addition of invariant area.
11/11/96   ls      Added valid flag to roaming_list_type.
10/11/96   ls      Remove unneeded nvi_sizeof_structure to save RAM.
10/08/96   ls      Shrunk NVI_RSVD_MEM_SIZ (no longer any double-buffered 
                   items in the dynamic pool).
10/03/96   ls      Added NV_TIMED_PREF_MODE_I.
09/17/96   ls      Change dial_type to contain all 32 digits.
09/11/96   ls      Remove unused items from TPS, save about 60 bytes.
08/29/96   ls      Mass migration of items to the fixed pool.
08/22/96   ls      Make FEATURE_JSTD008 available to ISS2 target.
08/06/96   ls      Added FEATURE_NV_ONE_NAM_RL_LARGE.
08/01/96   ls      Bumped all KLT_REVs due to CURR_NAM correction.
07/03/96   ls      Added NV_REDIAL_I item.
06/26/96   ls      Added Roaming List and MRU Table support.
06/17/96   ls      Added support for OTASP "commit" operation.
06/06/96   ls      Added target-specific KLT_REV.
05/30/96   ls      Added initial subset of J-STD-008 NAM parameters and 
                   extensions.
05/10/96   ls      Added PCS registration updates.
02/28/96   ls      Changed types of LNA_RANGE_RISE and LNA_RANGE_FALL to
                   nvi_int1_type.
02/27/96   ls      Added N1m nv item.
02/15/96   ls      Added RF Calibration items.
12/22/95   ras     pre-code review cleanup.
12/21/95   ras     split klt into klt as substructure in fixed pool
                   moved sec_code,lock_code,err_log to fixed pool. 
                   bumper KLT REV.
12/06/95   ras     moved fm_rssi and vbatt to the fixed pool, bumped klt rev.
11/30/95   ras     bumped KLT version for structure changes do to pack() fix.
11/22/95   ras     added NV_HW_CONFIG. Cleanup "pack()" usage
10/02/95   ras     added fm_agc,fsc2,fsc2_chksum,wdc, moved lcd to fixed item.
09/28/95   ras     bumped NV_VER_MAJ for err log fix
09/24/95   ras     changed nvi_err_log_type to match nv_err_log_type, bumped
                   dynamic pool rev.
09/11/95   ras     added fm_lna,life_timer_g,call_timer_g, pwr_up_tmr
                   made a_key a fixed item
09/08/95   ras     added support for ALARMS, STANDING_ALARMS, DIALING_PLAN,
                   ISD_STD_PASSWD, ISD_STD_RESTRICT
09/05/95   ras     NVI_SIZEOF, NVI_FSC_I, bumped klt rev. Tied klt and verno
                   together
08/29/95   ras     Bumped rev for sms bug fix
08/23/95   ras     added fixed items into enum, introduced klt version + bumped
08/08/95   ras     lint cleanup, IMSI, bad pwr down structures
07/20/95   ras     fixed iss2 build
07/17/95   ras     added sms support, Bumped rev. (0x0d)
06/26/95   ras     Bumped rev. for stack and dial. (0x0c)
06/15/95   ras     Bumped rev. for nva bug fix. (0x0b)
06/11/95   ras     added support for 20 new rf & ui items
06/06/95   ras     dynamic long stored  bug fix
05/29/95   ras     bumped rev to 0x09 since 0x08 revs are corrupted by ERR bug
05/22/95   ras     support for combined items and dynamic long stored #'s
                   went to rev 0x08
05/12/95   ras     rf item additions + NV_LCD_I - NV_BRIGHT_I
05/09/95   ras     Initial next generation nv checkin
01/18/94   jjw     Fixed error introduced earlier: corrupted fixed structure
                   Incremented Major version number
01/13/94   jjw     Fixed a buf where items added messed up the data in the
                   1st 18 or so bytes of actual NV data. Made the sizing of
                   the fixed structure compile-time configurable
01/06/94   jah     Changed watchdog iface to use dog_report().
12/17/93   jjw     Added DM address item
08/22/93   jjw     Added data services items
05/14/93   jjw     Added compile-time directive for Beta II target
05/10/93   jjw     Changed FM_RSSI to a min_max type
04/06/93   jjw     Major upgrade: Added numerous new items, changed numerous 
                   items, rolled version number to 2
02/05/93   jjw     Added new items for FM TX power levels & V battery min/max
10/29/92    ip     Modified items: err_log, sid_acq, auto_answer,
                   auto_redial, page_set, stack_idx.  Added items:
                   unit_id, name_nam, roam_timer, freq_adj (externally
                   visible); ESN_valid (externally invisible).
10/07/92    ip     Removed boot_err item.
08/06/92    ip     Fixed cast in NVI_SEG macro.
07/18/92    ip     Release after code review and initial unit test.
07/03/92    ip     Released for code review.
05/07/92    ip     Created file.

===========================================================================*/


/*===========================================================================
 
                           INCLUDE FILES

===========================================================================*/

#include "comdef.h"
#include "nv_v.h"
#ifdef FEATURE_TREX
#pragma pack(1)
#endif
#include "nvi_items.h"   // This file is generated by NVC 
#ifdef FEATURE_TREX
#pragma pack()
#endif



/*===========================================================================
 
                           DATA DECLARATIONS

===========================================================================*/

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/*                                                                         */
/*                              DATA                                       */
/*                                                                         */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

extern boolean        nvi_build_dynamic_pool_only; /* nvb flag for rebuild */


/*-------------------------------------------------------------------------*/
/*                                                                         */
/*                    NVM storage type notes.                              */
/*                                                                         */
/*-------------------------------------------------------------------------*/
/*
   Each variable in NVM is either fixed, active, or double buffered.

   A fixed variable is not relocated in NVM.  Fixed variables which are
   accessible from external tasks have a pointer, while fixed variables
   which are used internally do not have a pointer to them.

   An active variable is of the form:
   1 byte:  Active flag:
            0 if not active (no valid information stored in the variable),
            NOT 0 if active.
   n bytes: The variable
   An active variable is pointer based and can be relocated in NVM.

   A double buffered variable is of the form:
   1 byte:  Active flag:
            0 if not active (no valid information stored in the variable),
            NOT 0 if active.
   n bytes: The variable
   A double buffered item is pointer based and can be relocated in NVM.
*/


/*-------------------------------------------------------------------------*/
/*                                                                         */
/*                      Constants definitions.                             */
/*                                                                         */
/*-------------------------------------------------------------------------*/

/* The KLT Revision number (NVI_KLT_REV) is set in the "feature defines"   */
/* section of "nv.h," and uniquely identifies a specific configuration     */
/* of NV.  It MUST be changed every time there are additions, deletions,   */
/* or changes to the size or ordering of existing items.  Note that, when  */
/* incrementing KLT_REV, a never-previously-used value must be chosen (to  */
/* insure the uniqueness of that specific NV configuration).               */

#define NVI_VERNO_MAJ (0x14 + NVI_KLT_REV)  /* increment to rebuild NV */

/* Special value to indicate nvm has been built */
#define NVIKLTMAGIC       (((word)NVI_KLT_REV<<8)+0x55)

/* Number of bytes per NVM page.                                           */

#define NVI_BYTES_PER_PAGE 32

/* Number of bytes allowed per NVM write.  This number is best set to be   */
/* the same as page size above, since this yields the most efficient NVM   */
/* write.                                                                  */

#define NVI_BYTES_PER_WRITE 32

/* Number of attempts to make at writing to a location in NVM.             */
/* 1st generation targets                                                  */

#define NVI_WRITE_TRIES 2

/* Number of milliseconds between testing to see if a write to NVM         */
/* is successful.                                                          */
/* 1st generation targets                                                  */

#define NVI_CHECK_TIME 6

/* Number of times to check for a successful NVM write.                    */
/* 1st generation targets                                                  */

#define NVI_TMO_CNT 3

/* Number of times to retry writing an item with an active flag.           */
/* 1st generation targets                                                  */

#define NVI_ACT_RETRY 3

/* Number of times to retry writing a item which is double buffered.       */
/* 1st generation targets                                                  */

#define NVI_DOUBLE_RETRY 3

/* Number of times to retry writing an item during initialization.         */
/* 1st generation targets                                                  */

#define NVI_INIT_RETRY 3

/* The NVM physical address translation factor.  As an example, if NVM is  */
/* addressed on every other byte then this value is two (2).               */
/* 1st generation targets, address every other byte                        */

#define NVI_ADDRESS_FACTOR 1

/* Maximum number of times to try to write to NVM in the fatal error       */
/* condition.                                                              */
/* 1st generation targets                                                  */

#define NVI_FATAL_RETRY 5

#define NVI_WRITE_RETRY 1

/* The following define the addresses and data which are used in order to  */
/* unlock the write protect of the NVM before it can be written to.  There */
/* are three logical addresses (which are NOT mapped to physical address)  */
/* and a unique data byte to be written to each.                           */
/* 1st generation targets                                                  */

#define NV_PROT_ADDR_1 0x1555
#define NV_PROT_ADDR_2 0x0AAA
#define NV_PROT_ADDR_3 0x1555

#define NV_PROT_DATA_1 0xAA
#define NV_PROT_DATA_2 0x55
#define NV_PROT_DATA_3 0xA0

/* Possible NVRAM capacities */
#define NV_8K_VALUE   0x2000
#define NV_16K_VALUE  0x4000

/* An always-invalid NV address */
#define NV_INVALID_ADDRESS  0x7FFF

/* Initial size of the short allocation pool within the dynamic pool */
/* (Note that this is only a starting point, it can move dynamically */
/* if needed)                                                        */
#define NVI_SHORT_POOL_INITIAL_SIZE  32

/* Bytes to reserve to insure that double buffered items can be allocated. */
/* This 'extra' space is required because the new item is allocated before */
/* the old item is free'd.  Currently, there are no double-buffered items  */
/* in the dynamic pool, so the value should be zero.                       */
#define NVI_RSVD_MEM_SIZ  0


/*-------------------------------------------------------------------------*/
/*                                                                         */
/*                              MACROS                                     */
/*                                                                         */
/*-------------------------------------------------------------------------*/

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/* Macro to calculate position of structure member within nvi_fixed_type   */
/* (which defines the layout of fixed items in the lower 8K address space) */
#define NV_FIXED_POS(field)  FPOS(nvi_fixed_type, field)

/* Macro to calculate position of structure member within nvi_fixed_upper8_*/
/* type (which defines the layout of fixed items in the upper 8K space)    */
#define NV_FIXED_UPPER8_POS(field)  FPOS(nvi_fixed_upper8_type, field)

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/* Macro to calculate position of structure member within nvi_tps_type.    */
#define NV_TPS_POS(field)    FPOS(nvi_tps_type, field)

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/* Macro to calculate position of structure member within nvi_msl_type.    */
#define NV_MSL_POS(field)    FPOS(nvi_msl_type, field)

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/* Macro to calculate size of double buffered item given the size of the   */
/* variable included in the item.                                          */

#define NV_DOUBLE_SIZE(size)  ((size * 2) + 1)

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/* Macro to word align location of variable.  All pointers of pointer      */
/* based NVM items are word aligned, which ensures that both pointer       */
/* bytes are contained on the same NVM page.                               */
/* This is only used for first generation targets.                         */

#define NV_WORD_ALIGN(loc) ((loc) + ((loc) % 2))

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/* Macro to page align location of variable.  This ensures that a given    */
/* item resides within one physical NVM page.  The macro checks that if    */
/* the value is 0 it is not changed (to avoid negative number arithmetic   */
/* on unsigned value).  The macro also ensures that a number which is      */
/* already on a page boundary is not changed.                              */
/* This is only used for first generation targets.                         */

#define NV_PAGE_ALIGN(loc) \
        (((loc) == 0) ? \
         (loc) : \
         ((loc) - 1) + NVI_BYTES_PER_PAGE - (((loc) - 1) % NVI_BYTES_PER_PAGE))

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/* Macro to turn NVM address to physical address.   This macro multiplies  */
/* its argument by the logical-to-physical translation factor.  As an      */
/* example, if physical NVM is addressed on every other byte then the      */
/* logical address is always multiplied by the address factor.             */
/* This is only used for first generation targets.                         */

#define NV_PHYSICAL(addr) ((addr) * (NVI_ADDRESS_FACTOR))


/*-------------------------------------------------------------------------*/
/*                                                                         */
/* Following are all the internal NV storage types.  The definitions       */
/* start with the pack(1) pragma, to force byte packing, and end with      */
/* the pack() pragma to return to default packing.  Types are defined      */
/* in the order of the external item enum type (NV_..._I from NV.H).       */
/*                                                                         */
/*-------------------------------------------------------------------------*/

#ifdef FEATURE_TREX
#pragma pack(1)
#endif


/*-------------------------------------------------------------------------*/
/*                                                                         */
/* Item type definitions and constants.                                    */
/*                                                                         */
/*-------------------------------------------------------------------------*/

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/* This is the value of the "length" field above */
#define  NVI_VERNO_EXT_LENGTH   (sizeof(nvi_verno_ext_type) - sizeof(byte))


/*=========================================================================*/
/* Enumerators of items whose pointers are stored in the tps.              */

#ifdef FEATURE_NV_ENUMS_ARE_WORDS
#error code not present
#else
typedef enum {
  NVI_TPS_SMS_00_I = 0,
  NVI_TPS_SMS_01_I,
  NVI_TPS_SMS_02_I,
  NVI_TPS_SMS_03_I,
  NVI_TPS_SMS_04_I,
  NVI_TPS_SMS_05_I,
  NVI_TPS_SMS_06_I,
  NVI_TPS_SMS_07_I,
  NVI_TPS_SMS_08_I,
  NVI_TPS_SMS_09_I,
  NVI_TPS_SMS_10_I,
  NVI_TPS_SMS_11_I,
  NVI_TPS_SMS_12_I,
  NVI_TPS_SMS_13_I,
  NVI_TPS_SMS_14_I,
  NVI_TPS_SMS_15_I,
  NVI_TPS_SMS_16_I,
  NVI_TPS_SMS_17_I,
  NVI_TPS_SMS_18_I,
  NVI_TPS_SMS_19_I,
  NVI_TPS_SMS_20_I,
  NVI_TPS_SMS_21_I,
  NVI_TPS_SMS_22_I,
  NVI_TPS_SMS_23_I,
  NVI_TPS_MAX_I,       /* Size of this enum, MUST be the last item */
                       /* (except for padding)                     */
  NVI_TPS_ITEMS_PAD = 0x7FFF /* Pad to 16 bits on ARM */

} nvi_tps_items_type;
#endif

typedef enum {
  NVI_LONGPOOL_I,
  NVI_SHORTPOOL_I,
  NVI_POOL_ENUM_PAD = 0x7FFF /* Pad to 16 bits on ARM */
} nvi_pool_enum_type; 

/* Return to default packing of data structures.                        */
#ifdef FEATURE_TREX
#pragma pack()
#endif


/*===========================================================================

MACRO NVI_SIZEOF

DESCRIPTION
  Size an internal nv item of the union type "nvi_item_type."

PARAMETERS
  Member of the nvi_enum_type to be sized.

DEPENDENCIES
  None.

LIMITATIONS
  None.

RETURN VALUE
  sizeof the internal item.

SIDE EFFECTS
  None.

===========================================================================*/
#define NVI_SIZEOF(A) ((word) (sizeof(((nvi_item_type *) 0)-> ##A)))
#endif /*NVI_H*/