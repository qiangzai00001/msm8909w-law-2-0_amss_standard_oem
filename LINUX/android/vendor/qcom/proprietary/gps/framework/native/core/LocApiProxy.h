/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2013 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
=============================================================================*/
/*=============================================================================*/
/* DO NOT EDIT THIS FILE IF YOU DO NOT HAVE ACCESS TO SOURCE FOR IZAT BINARIES.
   THIS PROXY ACTS AS A LINK TO IZAT BINARIES.
   EDITING AND RECOMPILING THIS FILE WITHOUT RECOMPILING IZAT BINARIES
   CAN CAUSE UNKNOWN BEHAVIOR*/
/*=============================================================================*/

#ifndef LOC_API_PROXY_H
#define LOC_API_PROXY_H

#include <LBSProxyBase.h>
#include <log_util.h>

#ifdef _HAS_LOC_V02_
#include <LBSApiV02.h>
#endif

#ifdef _HAS_LOC_RPC_
#include <LBSApiRpc.h>
#endif

namespace lbs_core {
#ifdef _HAS_LOC_V02_
class LocApiProxyV02 : public LocApiProxyBase {
protected:
    LBSApiV02 *mLBSApi;
    IzatApiV02 *mIzatApi;
public:
    LocApiProxyV02(LBSApiV02* lbsApi);
    virtual ~LocApiProxyV02();
    virtual void *getSibling2() { return (void *)mIzatApi; }
    locClientHandleType getClientHandle() { return mLBSApi->clientHandle; }

    inline bool isMessageSupported(LocCheckingMessagesID msgID) {
        return mLBSApi->isMessageSupported(msgID);
    }

    int eventCb(locClientHandleType client_handle,
                uint32_t loc_event_id,
                locClientEventIndUnionType loc_event_payload);
};
#endif //_HAS_LOC_V02_

#ifdef _HAS_LOC_RPC_
class LocApiProxyRpc : public LocApiProxyBase {
protected:
    LBSApiRpc *mLBSApi;
    IzatApiRpc *mIzatApi;
public:
    LocApiProxyRpc(LBSApiRpc* lbsApi);
    virtual ~LocApiProxyRpc();
    virtual void *getSibling2() { return (void *)mIzatApi; }
    rpc_loc_client_handle_type getClientHandle() {
        return mLBSApi->client_handle;
    }
    virtual int locEventCB(rpc_loc_client_handle_type handle,
                   rpc_loc_event_mask_type event,
                   const rpc_loc_event_payload_u_type* payload);
}
#endif //_HAS_LOC_RPC_

}; //namespace lbs_core
#endif //LOC_API_PROXY_H