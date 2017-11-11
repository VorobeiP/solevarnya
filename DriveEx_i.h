

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Nov 07 23:11:57 2017
 */
/* Compiler settings for DriveEx.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __DriveEx_i_h__
#define __DriveEx_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDriveShlExt_FWD_DEFINED__
#define __IDriveShlExt_FWD_DEFINED__
typedef interface IDriveShlExt IDriveShlExt;

#endif 	/* __IDriveShlExt_FWD_DEFINED__ */


#ifndef __DriveShlExt_FWD_DEFINED__
#define __DriveShlExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class DriveShlExt DriveShlExt;
#else
typedef struct DriveShlExt DriveShlExt;
#endif /* __cplusplus */

#endif 	/* __DriveShlExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IDriveShlExt_INTERFACE_DEFINED__
#define __IDriveShlExt_INTERFACE_DEFINED__

/* interface IDriveShlExt */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDriveShlExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C765AD2-FC5F-4649-9912-300D42B3DC5C")
    IDriveShlExt : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IDriveShlExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDriveShlExt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDriveShlExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDriveShlExt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDriveShlExt * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDriveShlExt * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDriveShlExt * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDriveShlExt * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IDriveShlExtVtbl;

    interface IDriveShlExt
    {
        CONST_VTBL struct IDriveShlExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDriveShlExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDriveShlExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDriveShlExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDriveShlExt_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDriveShlExt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDriveShlExt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDriveShlExt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDriveShlExt_INTERFACE_DEFINED__ */



#ifndef __DriveExLib_LIBRARY_DEFINED__
#define __DriveExLib_LIBRARY_DEFINED__

/* library DriveExLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_DriveExLib;

EXTERN_C const CLSID CLSID_DriveShlExt;

#ifdef __cplusplus

class DECLSPEC_UUID("F4DD580A-D0DC-43C5-A9FE-A90EA9701FE2")
DriveShlExt;
#endif
#endif /* __DriveExLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


