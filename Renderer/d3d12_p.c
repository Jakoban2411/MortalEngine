

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 08:44:07 2038
 */
/* Compiler settings for Helpers\D3D\d3d12.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#include "ndr64types.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "d3d12_h.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _d3d12_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } d3d12_MIDL_TYPE_FORMAT_STRING;

typedef struct _d3d12_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } d3d12_MIDL_PROC_FORMAT_STRING;

typedef struct _d3d12_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } d3d12_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

static const RPC_SYNTAX_IDENTIFIER  _NDR64_RpcTransferSyntax = 
{{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}};

#if defined(_CONTROL_FLOW_GUARD_XFG)
#define XFG_TRAMPOLINES(ObjectType)\
static unsigned long ObjectType ## _UserSize_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize(pFlags, Offset, pObject);\
}\
static unsigned char * ObjectType ## _UserMarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal(pFlags, pBuffer, pObject);\
}\
static unsigned char * ObjectType ## _UserUnmarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal(pFlags, pBuffer, pObject);\
}\
static void ObjectType ## _UserFree_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree(pFlags, pObject);\
}
#define XFG_TRAMPOLINES64(ObjectType)\
static unsigned long ObjectType ## _UserSize64_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize64(pFlags, Offset, pObject);\
}\
static unsigned char * ObjectType ## _UserMarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal64(pFlags, pBuffer, pObject);\
}\
static unsigned char * ObjectType ## _UserUnmarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal64(pFlags, pBuffer, pObject);\
}\
static void ObjectType ## _UserFree64_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree64(pFlags, pObject);\
}
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)\
static void* ObjectType ## _bind_XFG(HandleType pObject)\
{\
return ObjectType ## _bind((ObjectType) pObject);\
}\
static void ObjectType ## _unbind_XFG(HandleType pObject, handle_t ServerHandle)\
{\
ObjectType ## _unbind((ObjectType) pObject, ServerHandle);\
}
#define XFG_TRAMPOLINE_FPTR(Function) Function ## _XFG
#else
#define XFG_TRAMPOLINES(ObjectType)
#define XFG_TRAMPOLINES64(ObjectType)
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)
#define XFG_TRAMPOLINE_FPTR(Function) Function
#endif



extern const d3d12_MIDL_TYPE_FORMAT_STRING d3d12__MIDL_TypeFormatString;
extern const d3d12_MIDL_PROC_FORMAT_STRING d3d12__MIDL_ProcFormatString;
extern const d3d12_MIDL_EXPR_FORMAT_STRING d3d12__MIDL_ExprFormatString;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const d3d12_MIDL_PROC_FORMAT_STRING d3d12__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const d3d12_MIDL_TYPE_FORMAT_STRING d3d12__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_d3d12_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ID3D12Object, ver. 0.0,
   GUID={0xc4fec28f,0x7966,0x4e95,{0x9f,0x94,0xf4,0x31,0xcb,0x56,0xc3,0xb8}} */


/* Object interface: ID3D12DeviceChild, ver. 0.0,
   GUID={0x905db94b,0xa00c,0x4140,{0x9d,0xf5,0x2b,0x64,0xca,0x9e,0xa3,0x57}} */


/* Object interface: ID3D12RootSignature, ver. 0.0,
   GUID={0xc54a6b66,0x72df,0x4ee8,{0x8b,0xe5,0xa9,0x46,0xa1,0x42,0x92,0x14}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0001, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12RootSignatureDeserializer, ver. 0.0,
   GUID={0x34AB647B,0x3CC8,0x46AC,{0x84,0x1B,0xC0,0x96,0x56,0x45,0xC0,0x46}} */


/* Object interface: ID3D12VersionedRootSignatureDeserializer, ver. 0.0,
   GUID={0x7F91CE67,0x090C,0x4BB7,{0xB7,0x8E,0xED,0x8F,0xF2,0xE3,0x1D,0xA0}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0003, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Pageable, ver. 0.0,
   GUID={0x63ee58fb,0x1268,0x4835,{0x86,0xda,0xf0,0x08,0xce,0x62,0xf0,0xd6}} */


/* Object interface: ID3D12Heap, ver. 0.0,
   GUID={0x6b3b2502,0x6e51,0x45b3,{0x90,0xee,0x98,0x84,0x26,0x5e,0x8d,0xf3}} */


/* Object interface: ID3D12Resource, ver. 0.0,
   GUID={0x696442be,0xa72e,0x4059,{0xbc,0x79,0x5b,0x5c,0x98,0x04,0x0f,0xad}} */


/* Object interface: ID3D12CommandAllocator, ver. 0.0,
   GUID={0x6102dee4,0xaf59,0x4b09,{0xb9,0x99,0xb4,0x4d,0x73,0xf0,0x9b,0x24}} */


/* Object interface: ID3D12Fence, ver. 0.0,
   GUID={0x0a753dcf,0xc4d8,0x4b91,{0xad,0xf6,0xbe,0x5a,0x60,0xd9,0x5a,0x76}} */


/* Object interface: ID3D12Fence1, ver. 0.0,
   GUID={0x433685fe,0xe22b,0x4ca0,{0xa8,0xdb,0xb5,0xb4,0xf4,0xdd,0x0e,0x4a}} */


/* Object interface: ID3D12PipelineState, ver. 0.0,
   GUID={0x765a30f3,0xf624,0x4c6f,{0xa8,0x28,0xac,0xe9,0x48,0x62,0x24,0x45}} */


/* Object interface: ID3D12DescriptorHeap, ver. 0.0,
   GUID={0x8efb471d,0x616c,0x4f49,{0x90,0xf7,0x12,0x7b,0xb7,0x63,0xfa,0x51}} */


/* Object interface: ID3D12QueryHeap, ver. 0.0,
   GUID={0x0d9658ae,0xed45,0x469e,{0xa6,0x1d,0x97,0x0e,0xc5,0x83,0xca,0xb4}} */


/* Object interface: ID3D12CommandSignature, ver. 0.0,
   GUID={0xc36a797c,0xec80,0x4f0a,{0x89,0x85,0xa7,0xb2,0x47,0x50,0x82,0xd1}} */


/* Object interface: ID3D12CommandList, ver. 0.0,
   GUID={0x7116d91c,0xe7e4,0x47ce,{0xb8,0xc6,0xec,0x81,0x68,0xf4,0x37,0xe5}} */


/* Object interface: ID3D12GraphicsCommandList, ver. 0.0,
   GUID={0x5b160d0f,0xac1b,0x4185,{0x8b,0xa8,0xb3,0xae,0x42,0xa5,0xa4,0x55}} */


/* Object interface: ID3D12GraphicsCommandList1, ver. 0.0,
   GUID={0x553103fb,0x1fe7,0x4557,{0xbb,0x38,0x94,0x6d,0x7d,0x0e,0x7c,0xa7}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0018, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12GraphicsCommandList2, ver. 0.0,
   GUID={0x38C3E585,0xFF17,0x412C,{0x91,0x50,0x4F,0xC6,0xF9,0xD7,0x2A,0x28}} */


/* Object interface: ID3D12CommandQueue, ver. 0.0,
   GUID={0x0ec870a6,0x5d7e,0x4c22,{0x8c,0xfc,0x5b,0xaa,0xe0,0x76,0x16,0xed}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0020, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device, ver. 0.0,
   GUID={0x189819f1,0x1db6,0x4b57,{0xbe,0x54,0x18,0x21,0x33,0x9b,0x85,0xf7}} */


/* Object interface: ID3D12PipelineLibrary, ver. 0.0,
   GUID={0xc64226a8,0x9201,0x46af,{0xb4,0xcc,0x53,0xfb,0x9f,0xf7,0x41,0x4f}} */


/* Object interface: ID3D12PipelineLibrary1, ver. 0.0,
   GUID={0x80eabf42,0x2568,0x4e5e,{0xbd,0x82,0xc3,0x7f,0x86,0x96,0x1d,0xc3}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0023, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device1, ver. 0.0,
   GUID={0x77acce80,0x638e,0x4e65,{0x88,0x95,0xc1,0xf2,0x33,0x86,0x86,0x3e}} */


/* Object interface: ID3D12Device2, ver. 0.0,
   GUID={0x30baa41e,0xb15b,0x475c,{0xa0,0xbb,0x1a,0xf5,0xc5,0xb6,0x43,0x28}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0025, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device3, ver. 0.0,
   GUID={0x81dadc15,0x2bad,0x4392,{0x93,0xc5,0x10,0x13,0x45,0xc4,0xaa,0x98}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0026, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12ProtectedSession, ver. 0.0,
   GUID={0xA1533D18,0x0AC1,0x4084,{0x85,0xB9,0x89,0xA9,0x61,0x16,0x80,0x6B}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0027, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12ProtectedResourceSession, ver. 0.0,
   GUID={0x6CD696F4,0xF289,0x40CC,{0x80,0x91,0x5A,0x6C,0x0A,0x09,0x9C,0x3D}} */


/* Object interface: ID3D12Device4, ver. 0.0,
   GUID={0xe865df17,0xa9ee,0x46f9,{0xa4,0x63,0x30,0x98,0x31,0x5a,0xa2,0xe5}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0029, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12LifetimeOwner, ver. 0.0,
   GUID={0xe667af9f,0xcd56,0x4f46,{0x83,0xce,0x03,0x2e,0x59,0x5d,0x70,0xa8}} */


/* Object interface: ID3D12SwapChainAssistant, ver. 0.0,
   GUID={0xf1df64b6,0x57fd,0x49cd,{0x88,0x07,0xc0,0xeb,0x88,0xb4,0x5c,0x8f}} */


/* Object interface: ID3D12LifetimeTracker, ver. 0.0,
   GUID={0x3fd03d36,0x4eb1,0x424a,{0xa5,0x82,0x49,0x4e,0xcb,0x8b,0xa8,0x13}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0032, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12StateObject, ver. 0.0,
   GUID={0x47016943,0xfca8,0x4594,{0x93,0xea,0xaf,0x25,0x8b,0x55,0x34,0x6d}} */


/* Object interface: ID3D12StateObjectProperties, ver. 0.0,
   GUID={0xde5fa827,0x9bf9,0x4f26,{0x89,0xff,0xd7,0xf5,0x6f,0xde,0x38,0x60}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0034, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device5, ver. 0.0,
   GUID={0x8b4f173b,0x2fea,0x4b80,{0x8f,0x58,0x43,0x07,0x19,0x1a,0xb9,0x5d}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0035, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12DeviceRemovedExtendedDataSettings, ver. 0.0,
   GUID={0x82BC481C,0x6B9B,0x4030,{0xAE,0xDB,0x7E,0xE3,0xD1,0xDF,0x1E,0x63}} */


/* Object interface: ID3D12DeviceRemovedExtendedDataSettings1, ver. 0.0,
   GUID={0xDBD5AE51,0x3317,0x4F0A,{0xAD,0xF9,0x1D,0x7C,0xED,0xCA,0xAE,0x0B}} */


/* Object interface: ID3D12DeviceRemovedExtendedData, ver. 0.0,
   GUID={0x98931D33,0x5AE8,0x4791,{0xAA,0x3C,0x1A,0x73,0xA2,0x93,0x4E,0x71}} */


/* Object interface: ID3D12DeviceRemovedExtendedData1, ver. 0.0,
   GUID={0x9727A022,0xCF1D,0x4DDA,{0x9E,0xBA,0xEF,0xFA,0x65,0x3F,0xC5,0x06}} */


/* Object interface: ID3D12DeviceRemovedExtendedData2, ver. 0.0,
   GUID={0x67FC5816,0xE4CA,0x4915,{0xBF,0x18,0x42,0x54,0x12,0x72,0xDA,0x54}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0040, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device6, ver. 0.0,
   GUID={0xc70b221b,0x40e4,0x4a17,{0x89,0xaf,0x02,0x5a,0x07,0x27,0xa6,0xdc}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0041, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12ProtectedResourceSession1, ver. 0.0,
   GUID={0xD6F12DD6,0x76FB,0x406E,{0x89,0x61,0x42,0x96,0xEE,0xFC,0x04,0x09}} */


/* Object interface: ID3D12Device7, ver. 0.0,
   GUID={0x5c014b53,0x68a1,0x4b9b,{0x8b,0xd1,0xdd,0x60,0x46,0xb9,0x35,0x8b}} */


/* Object interface: ID3D12Device8, ver. 0.0,
   GUID={0x9218E6BB,0xF944,0x4F7E,{0xA7,0x5C,0xB1,0xB2,0xC7,0xB7,0x01,0xF3}} */


/* Object interface: ID3D12Resource1, ver. 0.0,
   GUID={0x9D5E227A,0x4430,0x4161,{0x88,0xB3,0x3E,0xCA,0x6B,0xB1,0x6E,0x19}} */


/* Object interface: ID3D12Resource2, ver. 0.0,
   GUID={0xBE36EC3B,0xEA85,0x4AEB,{0xA4,0x5A,0xE9,0xD7,0x64,0x04,0xA4,0x95}} */


/* Object interface: ID3D12Heap1, ver. 0.0,
   GUID={0x572F7389,0x2168,0x49E3,{0x96,0x93,0xD6,0xDF,0x58,0x71,0xBF,0x6D}} */


/* Object interface: ID3D12GraphicsCommandList3, ver. 0.0,
   GUID={0x6FDA83A7,0xB84C,0x4E38,{0x9A,0xC8,0xC7,0xBD,0x22,0x01,0x6B,0x3D}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0048, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12MetaCommand, ver. 0.0,
   GUID={0xDBB84C27,0x36CE,0x4FC9,{0xB8,0x01,0xF0,0x48,0xC4,0x6A,0xC5,0x70}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0049, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12GraphicsCommandList4, ver. 0.0,
   GUID={0x8754318e,0xd3a9,0x4541,{0x98,0xcf,0x64,0x5b,0x50,0xdc,0x48,0x74}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0050, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12ShaderCacheSession, ver. 0.0,
   GUID={0x28e2495d,0x0f64,0x4ae4,{0xa6,0xec,0x12,0x92,0x55,0xdc,0x49,0xa8}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0051, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device9, ver. 0.0,
   GUID={0x4c80e962,0xf032,0x4f60,{0xbc,0x9e,0xeb,0xc2,0xcf,0xa1,0xd8,0x3c}} */


/* Object interface: ID3D12Device10, ver. 0.0,
   GUID={0x517f8718,0xaa66,0x49f9,{0xb0,0x2b,0xa7,0xab,0x89,0xc0,0x60,0x31}} */


/* Object interface: ID3D12VirtualizationGuestDevice, ver. 0.0,
   GUID={0xbc66d368,0x7373,0x4943,{0x87,0x57,0xfc,0x87,0xdc,0x79,0xe4,0x76}} */


/* Object interface: ID3D12Tools, ver. 0.0,
   GUID={0x7071e1f0,0xe84b,0x4b33,{0x97,0x4f,0x12,0xfa,0x49,0xde,0x65,0xc5}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0055, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12SDKConfiguration, ver. 0.0,
   GUID={0xe9eb5314,0x33aa,0x42b2,{0xa7,0x18,0xd7,0x7f,0x58,0xb1,0xf1,0xc7}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0056, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12GraphicsCommandList5, ver. 0.0,
   GUID={0x55050859,0x4024,0x474c,{0x87,0xf5,0x64,0x72,0xea,0xee,0x44,0xea}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0057, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12GraphicsCommandList6, ver. 0.0,
   GUID={0xc3827890,0xe548,0x4cfa,{0x96,0xcf,0x56,0x89,0xa9,0x37,0x0f,0x80}} */


/* Object interface: ID3D12GraphicsCommandList7, ver. 0.0,
   GUID={0xdd171223,0x8b61,0x4769,{0x90,0xe3,0x16,0x0c,0xcd,0xe4,0xe2,0xc1}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0059, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


#endif /* defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 08:44:07 2038
 */
/* Compiler settings for Helpers\D3D\d3d12.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)




#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif


#include "ndr64types.h"
#include "pshpack8.h"


typedef 
NDR64_FORMAT_UINT32
__midl_frag1_t;
extern const __midl_frag1_t __midl_frag1;

static const __midl_frag1_t __midl_frag1 =
(NDR64_UINT32) 0 /* 0x0 */;


#include "poppack.h"



/* Standard interface: __MIDL_itf_d3d12_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ID3D12Object, ver. 0.0,
   GUID={0xc4fec28f,0x7966,0x4e95,{0x9f,0x94,0xf4,0x31,0xcb,0x56,0xc3,0xb8}} */


/* Object interface: ID3D12DeviceChild, ver. 0.0,
   GUID={0x905db94b,0xa00c,0x4140,{0x9d,0xf5,0x2b,0x64,0xca,0x9e,0xa3,0x57}} */


/* Object interface: ID3D12RootSignature, ver. 0.0,
   GUID={0xc54a6b66,0x72df,0x4ee8,{0x8b,0xe5,0xa9,0x46,0xa1,0x42,0x92,0x14}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0001, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12RootSignatureDeserializer, ver. 0.0,
   GUID={0x34AB647B,0x3CC8,0x46AC,{0x84,0x1B,0xC0,0x96,0x56,0x45,0xC0,0x46}} */


/* Object interface: ID3D12VersionedRootSignatureDeserializer, ver. 0.0,
   GUID={0x7F91CE67,0x090C,0x4BB7,{0xB7,0x8E,0xED,0x8F,0xF2,0xE3,0x1D,0xA0}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0003, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Pageable, ver. 0.0,
   GUID={0x63ee58fb,0x1268,0x4835,{0x86,0xda,0xf0,0x08,0xce,0x62,0xf0,0xd6}} */


/* Object interface: ID3D12Heap, ver. 0.0,
   GUID={0x6b3b2502,0x6e51,0x45b3,{0x90,0xee,0x98,0x84,0x26,0x5e,0x8d,0xf3}} */


/* Object interface: ID3D12Resource, ver. 0.0,
   GUID={0x696442be,0xa72e,0x4059,{0xbc,0x79,0x5b,0x5c,0x98,0x04,0x0f,0xad}} */


/* Object interface: ID3D12CommandAllocator, ver. 0.0,
   GUID={0x6102dee4,0xaf59,0x4b09,{0xb9,0x99,0xb4,0x4d,0x73,0xf0,0x9b,0x24}} */


/* Object interface: ID3D12Fence, ver. 0.0,
   GUID={0x0a753dcf,0xc4d8,0x4b91,{0xad,0xf6,0xbe,0x5a,0x60,0xd9,0x5a,0x76}} */


/* Object interface: ID3D12Fence1, ver. 0.0,
   GUID={0x433685fe,0xe22b,0x4ca0,{0xa8,0xdb,0xb5,0xb4,0xf4,0xdd,0x0e,0x4a}} */


/* Object interface: ID3D12PipelineState, ver. 0.0,
   GUID={0x765a30f3,0xf624,0x4c6f,{0xa8,0x28,0xac,0xe9,0x48,0x62,0x24,0x45}} */


/* Object interface: ID3D12DescriptorHeap, ver. 0.0,
   GUID={0x8efb471d,0x616c,0x4f49,{0x90,0xf7,0x12,0x7b,0xb7,0x63,0xfa,0x51}} */


/* Object interface: ID3D12QueryHeap, ver. 0.0,
   GUID={0x0d9658ae,0xed45,0x469e,{0xa6,0x1d,0x97,0x0e,0xc5,0x83,0xca,0xb4}} */


/* Object interface: ID3D12CommandSignature, ver. 0.0,
   GUID={0xc36a797c,0xec80,0x4f0a,{0x89,0x85,0xa7,0xb2,0x47,0x50,0x82,0xd1}} */


/* Object interface: ID3D12CommandList, ver. 0.0,
   GUID={0x7116d91c,0xe7e4,0x47ce,{0xb8,0xc6,0xec,0x81,0x68,0xf4,0x37,0xe5}} */


/* Object interface: ID3D12GraphicsCommandList, ver. 0.0,
   GUID={0x5b160d0f,0xac1b,0x4185,{0x8b,0xa8,0xb3,0xae,0x42,0xa5,0xa4,0x55}} */


/* Object interface: ID3D12GraphicsCommandList1, ver. 0.0,
   GUID={0x553103fb,0x1fe7,0x4557,{0xbb,0x38,0x94,0x6d,0x7d,0x0e,0x7c,0xa7}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0018, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12GraphicsCommandList2, ver. 0.0,
   GUID={0x38C3E585,0xFF17,0x412C,{0x91,0x50,0x4F,0xC6,0xF9,0xD7,0x2A,0x28}} */


/* Object interface: ID3D12CommandQueue, ver. 0.0,
   GUID={0x0ec870a6,0x5d7e,0x4c22,{0x8c,0xfc,0x5b,0xaa,0xe0,0x76,0x16,0xed}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0020, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device, ver. 0.0,
   GUID={0x189819f1,0x1db6,0x4b57,{0xbe,0x54,0x18,0x21,0x33,0x9b,0x85,0xf7}} */


/* Object interface: ID3D12PipelineLibrary, ver. 0.0,
   GUID={0xc64226a8,0x9201,0x46af,{0xb4,0xcc,0x53,0xfb,0x9f,0xf7,0x41,0x4f}} */


/* Object interface: ID3D12PipelineLibrary1, ver. 0.0,
   GUID={0x80eabf42,0x2568,0x4e5e,{0xbd,0x82,0xc3,0x7f,0x86,0x96,0x1d,0xc3}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0023, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device1, ver. 0.0,
   GUID={0x77acce80,0x638e,0x4e65,{0x88,0x95,0xc1,0xf2,0x33,0x86,0x86,0x3e}} */


/* Object interface: ID3D12Device2, ver. 0.0,
   GUID={0x30baa41e,0xb15b,0x475c,{0xa0,0xbb,0x1a,0xf5,0xc5,0xb6,0x43,0x28}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0025, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device3, ver. 0.0,
   GUID={0x81dadc15,0x2bad,0x4392,{0x93,0xc5,0x10,0x13,0x45,0xc4,0xaa,0x98}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0026, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12ProtectedSession, ver. 0.0,
   GUID={0xA1533D18,0x0AC1,0x4084,{0x85,0xB9,0x89,0xA9,0x61,0x16,0x80,0x6B}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0027, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12ProtectedResourceSession, ver. 0.0,
   GUID={0x6CD696F4,0xF289,0x40CC,{0x80,0x91,0x5A,0x6C,0x0A,0x09,0x9C,0x3D}} */


/* Object interface: ID3D12Device4, ver. 0.0,
   GUID={0xe865df17,0xa9ee,0x46f9,{0xa4,0x63,0x30,0x98,0x31,0x5a,0xa2,0xe5}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0029, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12LifetimeOwner, ver. 0.0,
   GUID={0xe667af9f,0xcd56,0x4f46,{0x83,0xce,0x03,0x2e,0x59,0x5d,0x70,0xa8}} */


/* Object interface: ID3D12SwapChainAssistant, ver. 0.0,
   GUID={0xf1df64b6,0x57fd,0x49cd,{0x88,0x07,0xc0,0xeb,0x88,0xb4,0x5c,0x8f}} */


/* Object interface: ID3D12LifetimeTracker, ver. 0.0,
   GUID={0x3fd03d36,0x4eb1,0x424a,{0xa5,0x82,0x49,0x4e,0xcb,0x8b,0xa8,0x13}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0032, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12StateObject, ver. 0.0,
   GUID={0x47016943,0xfca8,0x4594,{0x93,0xea,0xaf,0x25,0x8b,0x55,0x34,0x6d}} */


/* Object interface: ID3D12StateObjectProperties, ver. 0.0,
   GUID={0xde5fa827,0x9bf9,0x4f26,{0x89,0xff,0xd7,0xf5,0x6f,0xde,0x38,0x60}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0034, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device5, ver. 0.0,
   GUID={0x8b4f173b,0x2fea,0x4b80,{0x8f,0x58,0x43,0x07,0x19,0x1a,0xb9,0x5d}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0035, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12DeviceRemovedExtendedDataSettings, ver. 0.0,
   GUID={0x82BC481C,0x6B9B,0x4030,{0xAE,0xDB,0x7E,0xE3,0xD1,0xDF,0x1E,0x63}} */


/* Object interface: ID3D12DeviceRemovedExtendedDataSettings1, ver. 0.0,
   GUID={0xDBD5AE51,0x3317,0x4F0A,{0xAD,0xF9,0x1D,0x7C,0xED,0xCA,0xAE,0x0B}} */


/* Object interface: ID3D12DeviceRemovedExtendedData, ver. 0.0,
   GUID={0x98931D33,0x5AE8,0x4791,{0xAA,0x3C,0x1A,0x73,0xA2,0x93,0x4E,0x71}} */


/* Object interface: ID3D12DeviceRemovedExtendedData1, ver. 0.0,
   GUID={0x9727A022,0xCF1D,0x4DDA,{0x9E,0xBA,0xEF,0xFA,0x65,0x3F,0xC5,0x06}} */


/* Object interface: ID3D12DeviceRemovedExtendedData2, ver. 0.0,
   GUID={0x67FC5816,0xE4CA,0x4915,{0xBF,0x18,0x42,0x54,0x12,0x72,0xDA,0x54}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0040, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device6, ver. 0.0,
   GUID={0xc70b221b,0x40e4,0x4a17,{0x89,0xaf,0x02,0x5a,0x07,0x27,0xa6,0xdc}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0041, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12ProtectedResourceSession1, ver. 0.0,
   GUID={0xD6F12DD6,0x76FB,0x406E,{0x89,0x61,0x42,0x96,0xEE,0xFC,0x04,0x09}} */


/* Object interface: ID3D12Device7, ver. 0.0,
   GUID={0x5c014b53,0x68a1,0x4b9b,{0x8b,0xd1,0xdd,0x60,0x46,0xb9,0x35,0x8b}} */


/* Object interface: ID3D12Device8, ver. 0.0,
   GUID={0x9218E6BB,0xF944,0x4F7E,{0xA7,0x5C,0xB1,0xB2,0xC7,0xB7,0x01,0xF3}} */


/* Object interface: ID3D12Resource1, ver. 0.0,
   GUID={0x9D5E227A,0x4430,0x4161,{0x88,0xB3,0x3E,0xCA,0x6B,0xB1,0x6E,0x19}} */


/* Object interface: ID3D12Resource2, ver. 0.0,
   GUID={0xBE36EC3B,0xEA85,0x4AEB,{0xA4,0x5A,0xE9,0xD7,0x64,0x04,0xA4,0x95}} */


/* Object interface: ID3D12Heap1, ver. 0.0,
   GUID={0x572F7389,0x2168,0x49E3,{0x96,0x93,0xD6,0xDF,0x58,0x71,0xBF,0x6D}} */


/* Object interface: ID3D12GraphicsCommandList3, ver. 0.0,
   GUID={0x6FDA83A7,0xB84C,0x4E38,{0x9A,0xC8,0xC7,0xBD,0x22,0x01,0x6B,0x3D}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0048, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12MetaCommand, ver. 0.0,
   GUID={0xDBB84C27,0x36CE,0x4FC9,{0xB8,0x01,0xF0,0x48,0xC4,0x6A,0xC5,0x70}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0049, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12GraphicsCommandList4, ver. 0.0,
   GUID={0x8754318e,0xd3a9,0x4541,{0x98,0xcf,0x64,0x5b,0x50,0xdc,0x48,0x74}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0050, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12ShaderCacheSession, ver. 0.0,
   GUID={0x28e2495d,0x0f64,0x4ae4,{0xa6,0xec,0x12,0x92,0x55,0xdc,0x49,0xa8}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0051, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12Device9, ver. 0.0,
   GUID={0x4c80e962,0xf032,0x4f60,{0xbc,0x9e,0xeb,0xc2,0xcf,0xa1,0xd8,0x3c}} */


/* Object interface: ID3D12Device10, ver. 0.0,
   GUID={0x517f8718,0xaa66,0x49f9,{0xb0,0x2b,0xa7,0xab,0x89,0xc0,0x60,0x31}} */


/* Object interface: ID3D12VirtualizationGuestDevice, ver. 0.0,
   GUID={0xbc66d368,0x7373,0x4943,{0x87,0x57,0xfc,0x87,0xdc,0x79,0xe4,0x76}} */


/* Object interface: ID3D12Tools, ver. 0.0,
   GUID={0x7071e1f0,0xe84b,0x4b33,{0x97,0x4f,0x12,0xfa,0x49,0xde,0x65,0xc5}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0055, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12SDKConfiguration, ver. 0.0,
   GUID={0xe9eb5314,0x33aa,0x42b2,{0xa7,0x18,0xd7,0x7f,0x58,0xb1,0xf1,0xc7}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0056, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12GraphicsCommandList5, ver. 0.0,
   GUID={0x55050859,0x4024,0x474c,{0x87,0xf5,0x64,0x72,0xea,0xee,0x44,0xea}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0057, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ID3D12GraphicsCommandList6, ver. 0.0,
   GUID={0xc3827890,0xe548,0x4cfa,{0x96,0xcf,0x56,0x89,0xa9,0x37,0x0f,0x80}} */


/* Object interface: ID3D12GraphicsCommandList7, ver. 0.0,
   GUID={0xdd171223,0x8b61,0x4769,{0x90,0xe3,0x16,0x0c,0xcd,0xe4,0xe2,0xc1}} */


/* Standard interface: __MIDL_itf_d3d12_0000_0059, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    d3d12__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x8010272, /* MIDL Version 8.1.626 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x2000001, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _d3d12_ProxyVtblList[] = 
{
    0
};

const CInterfaceStubVtbl * const _d3d12_StubVtblList[] = 
{
    0
};

PCInterfaceName const _d3d12_InterfaceNamesList[] = 
{
    0
};


#define _d3d12_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _d3d12, pIID, n)

int __stdcall _d3d12_IID_Lookup( const IID * pIID, int * pIndex )
{
    UNREFERENCED_PARAMETER(pIID);
    UNREFERENCED_PARAMETER(pIndex);
    return 0;
}

const ExtendedProxyFileInfo d3d12_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _d3d12_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _d3d12_StubVtblList,
    (const PCInterfaceName * ) & _d3d12_InterfaceNamesList,
    0, /* no delegation */
    & _d3d12_IID_Lookup, 
    0,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

