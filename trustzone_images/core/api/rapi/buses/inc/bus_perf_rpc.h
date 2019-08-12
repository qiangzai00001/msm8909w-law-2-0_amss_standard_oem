#ifndef BUS_PERF_RPC_H
#define BUS_PERF_RPC_H

/* BUS_PERF TOOL VERSION: 4.30 */
/*=============================================================================
                          B U S _ P E R F _ R P C . H

GENERAL DESCRIPTION
  This is an AUTO GENERATED file that provides declarations pertaining to the
  exporting of the bus_perf api using ONCRPC.

  ---------------------------------------------------------------------------
  Copyright (c) 2009 Qualcomm Technologies Incorporated.
  All Rights Reserved. QUALCOMM Proprietary and Confidential.
  ---------------------------------------------------------------------------
=============================================================================*/

/*=============================================================================

                              Edit History

                             AUTO GENERATED                                  */
/* Generated by following versions of Htorpc modules:
Id: //source/qcom/qct/core/mproc/tools/main/latest/htorpc/htorpc.pl#3 
$Id: //components/rel/tz.bf/2.5.c10/trustzone_images/core/api/rapi/buses/inc/bus_perf_rpc.h#1 $
Id: //source/qcom/qct/core/mproc/tools/main/latest/htorpc/lib/Htorpc/Htoxdr.pm#1 
Id: //source/qcom/qct/core/mproc/tools/main/latest/htorpc/lib/Htorpc/XDR.pm#5 
Id: //source/qcom/qct/core/mproc/tools/main/latest/htorpc/lib/Htorpc/Output.pm#17 
Id: //source/qcom/qct/core/mproc/tools/main/latest/htorpc/lib/Htorpc/Parser.pm#3 
Id: //source/qcom/qct/core/mproc/tools/main/latest/htorpc/lib/Htorpc/Metacomments.pm#2 
$Id: //components/rel/tz.bf/2.5.c10/trustzone_images/core/api/rapi/buses/inc/bus_perf_rpc.h#1 $ 
=============================================================================*/
/*=============================================================================
$Header: //components/rel/tz.bf/2.5.c10/trustzone_images/core/api/rapi/buses/inc/bus_perf_rpc.h#1 $ 
=============================================================================*/


/* Include ONCRPC headers */
#include "oncrpc.h"
#include "comdef.h"

#define BUS_PERFPROG					0x30000025
#define BUS_PERFVERS					0x00010001 /* 0x00010001 */
/*defines for feature and tool version*/
#define BUS_PERF_TOOLVERS					0x0004001e
#define BUS_PERF_FEATURES					0x00000001
 

#define BUS_ALLOC_VERS                                    	0x00010001
#define BUS_UNHALT_PORT_REQUESTS_VERS                     	0x00010001
#define BUS_SET_HW_UPDATES_VERS                           	0x00010001
#define BUS_GET_OVERSUBSCRIBE_INFO_VERS                   	0x00010001
#define BUS_FREE_VERS                                     	0x00010001
#define BUS_PERF_NULL_VERS                                	0x00010001
#define BUS_HALT_PORT_REQUESTS_VERS                       	0x00010001
#define BUS_PERF_API_VERSIONS_VERS                        	0x00010001
#define BUS_PERF_RPC_GLUE_CODE_INFO_REMOTE_VERS           	0x00010001
/* prototypes for the app_init routines for the api and the api's callback
 * services
 */
extern void bus_perf_app_init( void );
extern void bus_perfcb_app_init( void );

/* prototypes for the app_lock routines for the api and the api's callback
 * services
 */
#define bus_perf_app_enable()  bus_perf_app_lock( FALSE )
#define bus_perf_app_disable() bus_perf_app_lock( TRUE )
extern void bus_perf_app_lock( boolean lock );

#define bus_perfcb_app_enable()  bus_perfcb_app_lock( FALSE )
#define bus_perfcb_app_disable() bus_perfcb_app_lock( TRUE )
extern void bus_perfcb_app_lock( boolean lock );

/* prototypes for glue code info querty functions:
 *
 * toolvers   : Tool version
 * features   : Features turned on in the code.
 *              0x00000001    ONCRPC Server Cleanup Support
 * proghash   : Unique hash value that represents the API XDR definition
 * cbproghash : Unique hash value that represents the Callbacks' XDR definition
 */
extern boolean bus_perf_rpc_glue_code_info_remote    /* REMOTE INFO */
(
  uint32 *toolvers,
  uint32 *features,
  uint32 *proghash,
  uint32 *cbproghash
);
extern boolean bus_perf_rpc_glue_code_info_local     /* LOCAL INFO */
(
  uint32 *toolvers,
  uint32 *features,
  uint32 *proghash,
  uint32 *cbproghash
);

/* prototype for API null routine */
extern boolean bus_perf_null(void);

/* prototype for API version function */
extern uint32 *bus_perf_api_versions
(
   uint32 *len
);

#define ONCRPC_BUS_PERF_NULL_PROC 0
#define ONCRPC_BUS_PERF_RPC_GLUE_CODE_INFO_REMOTE_PROC 1

#define ONCRPC_BUS_ALLOC_PROC 2
#define ONCRPC_BUS_FREE_PROC 3
#define ONCRPC_BUS_GET_OVERSUBSCRIBE_INFO_PROC 4
#define ONCRPC_BUS_SET_HW_UPDATES_PROC 5
#define ONCRPC_BUS_HALT_PORT_REQUESTS_PROC 6
#define ONCRPC_BUS_UNHALT_PORT_REQUESTS_PROC 7
#define ONCRPC_BUS_PERF_API_VERSIONS_PROC 0xFFFFFFFF


/* XDR Routine Prototypes go here */

/*
 * bus_perf_request XDR_BUS_PERF_SEND
 */
boolean xdr_bus_perf_send_bus_perf_request (xdr_s_type *xdrs, bus_perf_request const *sptr);

/*
 * bus_perf_request XDR_BUS_PERF_RECV
 */
boolean xdr_bus_perf_recv_bus_perf_request (xdr_s_type *xdrs, bus_perf_request *sptr);

/*
 * bus_oversubscribe_port_info XDR_BUS_PERF_SEND
 */
boolean xdr_bus_perf_send_bus_oversubscribe_port_info (xdr_s_type *xdrs, bus_oversubscribe_port_info const *sptr);

/*
 * bus_oversubscribe_port_info XDR_BUS_PERF_RECV
 */
boolean xdr_bus_perf_recv_bus_oversubscribe_port_info (xdr_s_type *xdrs, bus_oversubscribe_port_info *sptr);

/*
 * bus_oversubscribe_info XDR_BUS_PERF_SEND
 */
boolean xdr_bus_perf_send_bus_oversubscribe_info (xdr_s_type *xdrs, bus_oversubscribe_info const *sptr);

/*
 * bus_oversubscribe_info XDR_BUS_PERF_RECV
 */
boolean xdr_bus_perf_recv_bus_oversubscribe_info (xdr_s_type *xdrs, bus_oversubscribe_info *sptr);

#endif /* ! BUS_PERF_RPC_H */