/* HSU_MDM_APIS TOOL VERSION: 4.39 */
/* GENERATED: TUE JUN 22 2010 */
/*=============================================================================
                      H S U _ M D M _ A P I S _ S V C . C

GENERAL DESCRIPTION
  This is an AUTO GENERATED file that dispatches RPC requests targetting the
  hsu_mdm_apis api.

  ---------------------------------------------------------------------------
  Copyright (c) 2010 Qualcomm Technologies Incorporated.
  All Rights Reserved. QUALCOMM Proprietary and Confidential.
  ---------------------------------------------------------------------------
=============================================================================*/

/*=============================================================================

                              Edit History

                             AUTO GENERATED                                  */
/* Generated by following versions of Htorpc modules:
Id: //source/qcom/qct/core/mproc/tools/rel/05.01/htorpc/htorpc.pl#2 
Id: //source/qcom/qct/core/mproc/tools/rel/05.01/htorpc/lib/Htorpc/Start.pm#1 
Id: //source/qcom/qct/core/mproc/tools/rel/05.01/htorpc/lib/Htorpc/Htoxdr.pm#1 
Id: //source/qcom/qct/core/mproc/tools/rel/05.01/htorpc/lib/Htorpc/XDR.pm#1 
Id: //source/qcom/qct/core/mproc/tools/rel/05.01/htorpc/lib/Htorpc/Output.pm#2 
Id: //source/qcom/qct/core/mproc/tools/rel/05.01/htorpc/lib/Htorpc/Parser.pm#1 
Id: //source/qcom/qct/core/mproc/tools/rel/05.01/htorpc/lib/Htorpc/Metacomments.pm#1 
Id: //source/qcom/qct/core/mproc/tools/rel/05.01/htorpc/lib/Htorpc/SymbolTable.pm#1   

hsu_mdm_apis Definition File(s):

=============================================================================*/
/*=============================================================================
$Header: //components/rel/tz.bf/2.5.c10/trustzone_images/core/api/rapi/wiredconnectivity/src/hsu_mdm_apis_svc.c#1 $ 
=============================================================================*/


/* Include files */
#include "oncrpc.h"
#include "hsu_mdm_apis.h"
#include "hsu_mdm_apis_rpc.h"

/* Only one copy needed per API */
//static opaque_auth Hsu_mdm_apisCred = { ONCRPC_AUTH_NONE, 0, 0 };
static opaque_auth Hsu_mdm_apisVerf = { ONCRPC_AUTH_NONE, 0, 0 };

/*=======================================================================
             Prototypes for the API's RPC Server Functions
=======================================================================*/

static void hsu_mdm_apisprog_0x00010003 ( struct svc_req *rqstp, xdr_s_type *srv );
static void hsu_mdm_apis_null_0x00010003( xdr_s_type *svc );
static void hsu_mdm_apis_rpc_glue_code_info_remote_0x00010003( xdr_s_type *svc );
static void hsu_mdm_apis_api_versions_0x00010003( xdr_s_type *srv );

static void hsu_api_init_phy_0x00010003( xdr_s_type *srv );

static void hsu_api_init_uicc_0x00010003( xdr_s_type *srv );

static void hsu_api_start_uicc_0x00010003( xdr_s_type *srv );

static void hsu_api_polldown_uicc_0x00010003( xdr_s_type *srv );

static void hsu_api_vbus_powerup_0x00010003( xdr_s_type *srv );

static void hsu_api_vbus_shutdown_0x00010003( xdr_s_type *srv );

static void hsu_api_update_product_id_0x00010003( xdr_s_type *srv );

static void hsu_api_update_serial_number_0x00010003( xdr_s_type *srv );

static void hsu_api_update_is_serial_number_null_0x00010003( xdr_s_type *srv );

static void hsu_api_notif_charger_not_avail_0x00010003( xdr_s_type *srv );

static void hsu_api_notif_charger_is_avail_0x00010003( xdr_s_type *srv );

static void hsu_api_notif_charger_disconnected_0x00010003( xdr_s_type *srv );

static void hsu_api_notif_charger_connected_0x00010003( xdr_s_type *srv );

static void hsu_api_init_chg_0x00010003( xdr_s_type *srv );

static void hsu_api_chg_is_connected_0x00010003( xdr_s_type *srv );

static void hsu_api_usb_reset_rework_installed_0x00010003( xdr_s_type *srv );

static void hsu_api_enable_pmic_ulpidata0_irq_handler_0x00010003( xdr_s_type *srv );

static void hsu_api_disable_pmic_ulpidata0_irq_handler_0x00010003( xdr_s_type *srv );

static void hsu_dload_set_usb_imax_0x00010003( xdr_s_type *srv );

static void hsu_dload_enable_disable_core_0x00010003( xdr_s_type *srv );

static void hsu_dload_is_wall_charger_0x00010003( xdr_s_type *srv );

static void hsu_dload_sess_is_valid_0x00010003( xdr_s_type *srv );

static void hsu_api_enable_pmic_otg_comparators_0x00010003( xdr_s_type *srv );

static void hsu_api_disable_pmic_otg_comparators_0x00010003( xdr_s_type *srv );

static void hsu_api_disconnect_pulldowns_uicc_0x00010003( xdr_s_type *srv );

static void hsu_api_update_vendor_id_0x00010003( xdr_s_type *srv );

/******************************************************************************/
/*=======================================================================
             API RPC Server Implementation
=======================================================================*/
static uint32 hsu_mdm_apis_api_versions_table[] = {  0x00010001 , 0x00010002 , 0x00010003  };

uint32 * hsu_mdm_apis_api_versions(uint32 *size_entries)
{
  *size_entries = sizeof( hsu_mdm_apis_api_versions_table) / sizeof(uint32);
  return hsu_mdm_apis_api_versions_table;
}

void hsu_mdm_apis_app_init( void )
{
  (void) svc_register_auto_apiversions(HSU_MDM_APISPROG, HSU_MDM_APISVERS, hsu_mdm_apisprog_0x00010003, 
                                       hsu_mdm_apis_api_versions);
} /* hsu_mdm_apis_app_init */

void hsu_mdm_apis_app_lock( boolean lock )
{
  svc_lock( HSU_MDM_APISPROG, HSU_MDM_APISVERS, lock );
} /* hsu_mdm_apis_app_lock */

static void hsu_mdm_apisprog_0x00010003 ( struct svc_req *rqstp, xdr_s_type *srv )
{
  switch ( rqstp->rq_proc ) {
    case ONCRPC_HSU_MDM_APIS_NULL_PROC:
      hsu_mdm_apis_null_0x00010003( srv );
      break;
    case ONCRPC_HSU_MDM_APIS_RPC_GLUE_CODE_INFO_REMOTE_PROC:
      hsu_mdm_apis_rpc_glue_code_info_remote_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_INIT_PHY_PROC:
      hsu_api_init_phy_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_INIT_UICC_PROC:
      hsu_api_init_uicc_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_START_UICC_PROC:
      hsu_api_start_uicc_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_POLLDOWN_UICC_PROC:
      hsu_api_polldown_uicc_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_VBUS_POWERUP_PROC:
      hsu_api_vbus_powerup_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_VBUS_SHUTDOWN_PROC:
      hsu_api_vbus_shutdown_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_UPDATE_PRODUCT_ID_PROC:
      hsu_api_update_product_id_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_UPDATE_SERIAL_NUMBER_PROC:
      hsu_api_update_serial_number_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_UPDATE_IS_SERIAL_NUMBER_NULL_PROC:
      hsu_api_update_is_serial_number_null_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_NOTIF_CHARGER_NOT_AVAIL_PROC:
      hsu_api_notif_charger_not_avail_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_NOTIF_CHARGER_IS_AVAIL_PROC:
      hsu_api_notif_charger_is_avail_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_NOTIF_CHARGER_DISCONNECTED_PROC:
      hsu_api_notif_charger_disconnected_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_NOTIF_CHARGER_CONNECTED_PROC:
      hsu_api_notif_charger_connected_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_INIT_CHG_PROC:
      hsu_api_init_chg_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_CHG_IS_CONNECTED_PROC:
      hsu_api_chg_is_connected_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_USB_RESET_REWORK_INSTALLED_PROC:
      hsu_api_usb_reset_rework_installed_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_ENABLE_PMIC_ULPIDATA0_IRQ_HANDLER_PROC:
      hsu_api_enable_pmic_ulpidata0_irq_handler_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_DISABLE_PMIC_ULPIDATA0_IRQ_HANDLER_PROC:
      hsu_api_disable_pmic_ulpidata0_irq_handler_0x00010003( srv );
      break;
    case ONCRPC_HSU_DLOAD_SET_USB_IMAX_PROC:
      hsu_dload_set_usb_imax_0x00010003( srv );
      break;
    case ONCRPC_HSU_DLOAD_ENABLE_DISABLE_CORE_PROC:
      hsu_dload_enable_disable_core_0x00010003( srv );
      break;
    case ONCRPC_HSU_DLOAD_IS_WALL_CHARGER_PROC:
      hsu_dload_is_wall_charger_0x00010003( srv );
      break;
    case ONCRPC_HSU_DLOAD_SESS_IS_VALID_PROC:
      hsu_dload_sess_is_valid_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_ENABLE_PMIC_OTG_COMPARATORS_PROC:
      hsu_api_enable_pmic_otg_comparators_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_DISABLE_PMIC_OTG_COMPARATORS_PROC:
      hsu_api_disable_pmic_otg_comparators_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_DISCONNECT_PULLDOWNS_UICC_PROC:
      hsu_api_disconnect_pulldowns_uicc_0x00010003( srv );
      break;
    case ONCRPC_HSU_API_UPDATE_VENDOR_ID_PROC:
      hsu_api_update_vendor_id_0x00010003( srv );
      break;
    case ONCRPC_HSU_MDM_APIS_API_VERSIONS_PROC:
      hsu_mdm_apis_api_versions_0x00010003( srv );
      break;

    default:
      // invalid RPC procedure number
      (void) XDR_MSG_DONE( srv );
      svcerr_default_err( srv, rqstp, hsu_mdm_apis_api_versions  );
      break;
  }

  oncrpcxdr_mem_free( srv );
} /* hsu_mdm_apisprog_0x00010003 */

/******************************************************************************/

static void hsu_mdm_apis_null_0x00010003( xdr_s_type *srv )
{
  if ( ! XDR_MSG_DONE( srv ) ) {
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  if ( ! xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf ) ) {
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_mdm_apis_null_0x00010003 */

static void hsu_mdm_apis_rpc_glue_code_info_remote_0x00010003( xdr_s_type *srv )
{
  uint32 toolvers   = HSU_MDM_APIS_TOOLVERS; /* 4.39 */
  uint32 proghash   = 0x00010003; /* 0x00010003 */
  uint32 cbproghash = 0x00010003; /* 0x00010003 */
  uint32 features   = HSU_MDM_APIS_FEATURES; /* ONCRPC Server Cleanup Support */
                      

  if ( ! XDR_MSG_DONE( srv ) ) {
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  if ( ! xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf ) ||
       ! XDR_SEND_UINT32( srv, &toolvers ) ||
       ! XDR_SEND_UINT32( srv, &features ) ||
       ! XDR_SEND_UINT32( srv, &proghash ) ||
       ! XDR_SEND_UINT32( srv, &cbproghash ) )
  {
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_mdm_apis_rpc_glue_code_info_remote_0x00010003 */

static void hsu_api_init_phy_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_init_phy();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_init_phy_0x00010003 */

static void hsu_api_init_uicc_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_init_uicc();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_init_uicc_0x00010003 */

static void hsu_api_start_uicc_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_start_uicc();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_start_uicc_0x00010003 */

static void hsu_api_polldown_uicc_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_polldown_uicc();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_polldown_uicc_0x00010003 */

static void hsu_api_vbus_powerup_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_vbus_powerup();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_vbus_powerup_0x00010003 */

static void hsu_api_vbus_shutdown_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_vbus_shutdown();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_vbus_shutdown_0x00010003 */

static void hsu_api_update_product_id_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  unsigned short product_id = 0;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = XDR_RECV_UINT16( srv, &product_id );

  if ( xdr_status )
  {
    xdr_op_number++;
  }

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_update_product_id(product_id);

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_update_product_id_0x00010003 */

static void hsu_api_update_serial_number_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  void *memset_temp;
  uint32 length_uint32;
  char *serial_number = NULL;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = XDR_RECV_UINT32( srv, &length_uint32 );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status && length_uint32 > 0 )
  {
    xdr_op_number  = 2;
    if ( serial_number == NULL ) {
      memset_temp = oncrpcxdr_mem_alloc( srv, length_uint32);
      memset(memset_temp, 0, length_uint32);
      serial_number = memset_temp;
    }

      xdr_status = XDR_RECV_STRING(srv, serial_number, length_uint32);
  }

  if ( xdr_status )
  {
    xdr_op_number++;
  }

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_update_serial_number(serial_number);

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_update_serial_number_0x00010003 */

static void hsu_api_update_is_serial_number_null_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  boolean is_serial_number_null = FALSE;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = XDR_RECV_BOOLEAN( srv, &is_serial_number_null );

  if ( xdr_status )
  {
    xdr_op_number++;
  }

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_update_is_serial_number_null(is_serial_number_null);

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_update_is_serial_number_null_0x00010003 */

static void hsu_api_notif_charger_not_avail_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_notif_charger_not_avail();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_notif_charger_not_avail_0x00010003 */

static void hsu_api_notif_charger_is_avail_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  uint32 amount_current_to_draw = 0;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = XDR_RECV_UINT32( srv, &amount_current_to_draw );

  if ( xdr_status )
  {
    xdr_op_number++;
  }

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_notif_charger_is_avail(amount_current_to_draw);

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_notif_charger_is_avail_0x00010003 */

static void hsu_api_notif_charger_disconnected_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_notif_charger_disconnected();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_notif_charger_disconnected_0x00010003 */

static void hsu_api_notif_charger_connected_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  boolean is_wall_charger = FALSE;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = XDR_RECV_BOOLEAN( srv, &is_wall_charger );

  if ( xdr_status )
  {
    xdr_op_number++;
  }

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_notif_charger_connected(is_wall_charger);

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_notif_charger_connected_0x00010003 */

static void hsu_api_init_chg_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_init_chg();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_init_chg_0x00010003 */

static void hsu_api_chg_is_connected_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  boolean hsu_api_chg_is_connected_result;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_chg_is_connected_result = hsu_api_chg_is_connected();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status )
  {
    xdr_op_number = 2;
    xdr_status = XDR_SEND_BOOLEAN( srv, &hsu_api_chg_is_connected_result );
  }

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_chg_is_connected_0x00010003 */

static void hsu_api_usb_reset_rework_installed_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  boolean hsu_api_usb_reset_rework_installed_result;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_usb_reset_rework_installed_result = hsu_api_usb_reset_rework_installed();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status )
  {
    xdr_op_number = 2;
    xdr_status = XDR_SEND_BOOLEAN( srv, &hsu_api_usb_reset_rework_installed_result );
  }

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_usb_reset_rework_installed_0x00010003 */

static void hsu_api_enable_pmic_ulpidata0_irq_handler_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_enable_pmic_ulpidata0_irq_handler();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_enable_pmic_ulpidata0_irq_handler_0x00010003 */

static void hsu_api_disable_pmic_ulpidata0_irq_handler_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_disable_pmic_ulpidata0_irq_handler();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_disable_pmic_ulpidata0_irq_handler_0x00010003 */

static void hsu_dload_set_usb_imax_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_dload_set_usb_imax();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_dload_set_usb_imax_0x00010003 */

static void hsu_dload_enable_disable_core_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  boolean enable = FALSE;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = XDR_RECV_BOOLEAN( srv, &enable );

  if ( xdr_status )
  {
    xdr_op_number++;
  }

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_dload_enable_disable_core(enable);

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_dload_enable_disable_core_0x00010003 */

static void hsu_dload_is_wall_charger_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  boolean hsu_dload_is_wall_charger_result;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_dload_is_wall_charger_result = hsu_dload_is_wall_charger();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status )
  {
    xdr_op_number = 2;
    xdr_status = XDR_SEND_BOOLEAN( srv, &hsu_dload_is_wall_charger_result );
  }

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_dload_is_wall_charger_0x00010003 */

static void hsu_dload_sess_is_valid_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  boolean hsu_dload_sess_is_valid_result;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_dload_sess_is_valid_result = hsu_dload_sess_is_valid();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status )
  {
    xdr_op_number = 2;
    xdr_status = XDR_SEND_BOOLEAN( srv, &hsu_dload_sess_is_valid_result );
  }

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_dload_sess_is_valid_0x00010003 */

static void hsu_api_enable_pmic_otg_comparators_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  boolean hsu_api_enable_pmic_otg_comparators_result;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_enable_pmic_otg_comparators_result = hsu_api_enable_pmic_otg_comparators();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status )
  {
    xdr_op_number = 2;
    xdr_status = XDR_SEND_BOOLEAN( srv, &hsu_api_enable_pmic_otg_comparators_result );
  }

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_enable_pmic_otg_comparators_0x00010003 */

static void hsu_api_disable_pmic_otg_comparators_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  boolean hsu_api_disable_pmic_otg_comparators_result;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_disable_pmic_otg_comparators_result = hsu_api_disable_pmic_otg_comparators();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status )
  {
    xdr_op_number = 2;
    xdr_status = XDR_SEND_BOOLEAN( srv, &hsu_api_disable_pmic_otg_comparators_result );
  }

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_disable_pmic_otg_comparators_0x00010003 */

static void hsu_api_disconnect_pulldowns_uicc_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_disconnect_pulldowns_uicc();

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_disconnect_pulldowns_uicc_0x00010003 */

static void hsu_api_update_vendor_id_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  unsigned short vendor_id = 0;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = XDR_RECV_UINT16( srv, &vendor_id );

  if ( xdr_status )
  {
    xdr_op_number++;
  }

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_api_update_vendor_id(vendor_id);

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_api_update_vendor_id_0x00010003 */

/*=========================================================================== 
              API Standard function for api versioning
===========================================================================*/

static void hsu_mdm_apis_api_versions_0x00010003( xdr_s_type *srv )
{
  boolean xdr_status = TRUE;
  int xdr_op_number = 0;
  uint32 i;
  boolean output_pointer_not_null;
  uint32 length_uint32;
  uint32 *len = NULL;

  uint32 *hsu_mdm_apis_api_versions_result = NULL;

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  /* The server must know whether to allocate memory for the output parameter
   * len or not. A boolean is received to indicate that.
   */
  xdr_status = XDR_RECV_UINT8( srv, &output_pointer_not_null );

  if ( xdr_status && output_pointer_not_null ) {
    len = oncrpcxdr_mem_alloc( srv, sizeof(*len) );
  }

  if ( xdr_status )
  {
    xdr_op_number++;
  }

  if ( ! XDR_MSG_DONE( srv ) || ! xdr_status ) {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_decode reply
    svcerr_decode( srv );
    return;
  }

  hsu_mdm_apis_api_versions_result = hsu_mdm_apis_api_versions(len);

  /* XDR OP NUMBER = 1 */
  xdr_op_number = 1;
  xdr_status = xdr_reply_msg_start( srv, &Hsu_mdm_apisVerf );

  /* XDR OP NUMBER = 2 */
  if ( xdr_status )
  {
    xdr_op_number = 2;
    if ( hsu_mdm_apis_api_versions_result != NULL ) {
      length_uint32 = *len;

      xdr_status = XDR_SEND_UINT32( srv, &length_uint32 );

      /* XDR OP NUMBER = 3 */
      if ( xdr_status )
      {
        xdr_op_number  = 3;

        /* Calling array of XDR routines */
        for ( i = 0; xdr_status && i < (length_uint32); i++ ) {
          /*lint -save -e545*/
          xdr_status = XDR_SEND_UINT32( srv, &(hsu_mdm_apis_api_versions_result[i]) );
          /*lint -restore */
        }
      }
    } else {
      length_uint32 = 0;

      xdr_status = XDR_SEND_UINT32( srv, &length_uint32 );
    }
  }

  /* XDR OP NUMBER = 3 */
  if ( xdr_status )
  {
    xdr_op_number = 3;
    /*lint -save -e123*/
    XDR_SEND_POINTER( srv, &len, XDR_SEND_UINT32, xdr_status );
    /*lint -restore */
  }

  if ( ! xdr_status )
  {
    XDR_OP_ERR( srv, xdr_op_number );
    // send svcerr_systemerr reply
    svcerr_systemerr( srv );
    return;
  }

  if ( ! XDR_MSG_SEND( srv, NULL ) ) {
    XDR_MSG_SEND_ERR( srv, NULL );
  }
} /* hsu_mdm_apis_api_versions_0x00010003 */
