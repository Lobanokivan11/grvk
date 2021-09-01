#ifndef MANTLE_DBG_H_
#define MANTLE_DBG_H_

#include "mantle.h"

#ifdef __cplusplus
extern "C" {
#endif

// Enumerations

typedef enum _GR_DBG_DATA_TYPE
{
    GR_DBG_DATA_OBJECT_TYPE = 0x00020a00,
    GR_DBG_DATA_OBJECT_CREATE_INFO = 0x00020a01,
    GR_DBG_DATA_OBJECT_TAG = 0x00020a02,
    GR_DBG_DATA_CMD_BUFFER_API_TRACE = 0x00020b00,
    GR_DBG_DATA_MEMORY_OBJECT_LAYOUT = 0x00020c00,
    GR_DBG_DATA_MEMORY_OBJECT_STATE = 0x00020c01,
    GR_DBG_DATA_SEMAPHORE_IS_BLOCKED = 0x00020d00,
} GR_DBG_DATA_TYPE;

typedef enum _GR_DBG_DEVICE_OPTION
{
    GR_DBG_OPTION_DISABLE_PIPELINE_LOADS = 0x00020400,
    GR_DBG_OPTION_FORCE_OBJECT_MEMORY_REQS = 0x00020401,
    GR_DBG_OPTION_FORCE_LARGE_IMAGE_ALIGNMENT = 0x00020402,
    GR_DBG_OPTION_SKIP_EXECUTION_ON_ERROR = 0x00020403,
} GR_DBG_DEVICE_OPTION;

typedef enum _GR_DBG_GLOBAL_OPTION
{
    GR_DBG_OPTION_DEBUG_ECHO_ENABLE = 0x00020100,
    GR_DBG_OPTION_BREAK_ON_ERROR = 0x00020101,
    GR_DBG_OPTION_BREAK_ON_WARNING = 0x00020102,
} GR_DBG_GLOBAL_OPTION;

typedef enum _GR_DBG_MSG_FILTER
{
    GR_DBG_MSG_FILTER_NONE = 0x00020800,
    GR_DBG_MSG_FILTER_REPEATED = 0x00020801,
    GR_DBG_MSG_FILTER_ALL = 0x00020802,
} GR_DBG_MSG_FILTER;

typedef enum _GR_DBG_MSG_TYPE
{
    GR_DBG_MSG_UNKNOWN = 0x00020000,
    GR_DBG_MSG_ERROR = 0x00020001,
    GR_DBG_MSG_WARNING = 0x00020002,
    GR_DBG_MSG_PERF_WARNING = 0x00020003,
} GR_DBG_MSG_TYPE;

typedef enum _GR_DBG_OBJECT_TYPE
{
    GR_DBG_OBJECT_UNKNOWN = 0x00020900,
    GR_DBG_OBJECT_DEVICE = 0x00020901,
    GR_DBG_OBJECT_QUEUE = 0x00020902,
    GR_DBG_OBJECT_GPU_MEMORY = 0x00020903,
    GR_DBG_OBJECT_IMAGE = 0x00020904,
    GR_DBG_OBJECT_IMAGE_VIEW = 0x00020905,
    GR_DBG_OBJECT_COLOR_TARGET_VIEW = 0x00020906,
    GR_DBG_OBJECT_DEPTH_STENCIL_VIEW = 0x00020907,
    GR_DBG_OBJECT_SHADER = 0x00020908,
    GR_DBG_OBJECT_GRAPHICS_PIPELINE = 0x00020909,
    GR_DBG_OBJECT_COMPUTE_PIPELINE = 0x0002090a,
    GR_DBG_OBJECT_SAMPLER = 0x0002090b,
    GR_DBG_OBJECT_DESCRIPTOR_SET = 0x0002090c,
    GR_DBG_OBJECT_VIEWPORT_STATE = 0x0002090d,
    GR_DBG_OBJECT_RASTER_STATE = 0x0002090e,
    GR_DBG_OBJECT_MSAA_STATE = 0x0002090f,
    GR_DBG_OBJECT_COLOR_BLEND_STATE = 0x00020910,
    GR_DBG_OBJECT_DEPTH_STENCIL_STATE = 0x00020911,
    GR_DBG_OBJECT_CMD_BUFFER = 0x00020912,
    GR_DBG_OBJECT_FENCE = 0x00020913,
    GR_DBG_OBJECT_QUEUE_SEMAPHORE = 0x00020914,
    GR_DBG_OBJECT_EVENT = 0x00020915,
    GR_DBG_OBJECT_QUERY_POOL = 0x00020916,
    GR_DBG_OBJECT_SHARED_GPU_MEMORY = 0x00020917,
    GR_DBG_OBJECT_SHARED_QUEUE_SEMAPHORE = 0x00020918,
    GR_DBG_OBJECT_PEER_GPU_MEMORY = 0x00020919,
    GR_DBG_OBJECT_PEER_IMAGE = 0x0002091a,
    GR_DBG_OBJECT_PINNED_GPU_MEMORY = 0x0002091b,
    GR_DBG_OBJECT_INTERNAL_GPU_MEMORY = 0x0002091c,
} GR_DBG_OBJECT_TYPE;

// Callbacks

typedef GR_VOID (GR_STDCALL *GR_DBG_MSG_CALLBACK_FUNCTION)(
    GR_ENUM msgType,
    GR_ENUM validationLevel,
    GR_BASE_OBJECT srcObject,
    GR_SIZE location,
    GR_ENUM msgCode,
    const GR_CHAR* pMsg,
    GR_VOID* pUserData);

// Functions

GR_RESULT GR_STDCALL grDbgSetValidationLevel(
    GR_DEVICE device,
    GR_ENUM validationLevel);

GR_RESULT GR_STDCALL grDbgRegisterMsgCallback(
    GR_DBG_MSG_CALLBACK_FUNCTION pfnMsgCallback,
    GR_VOID* pUserData);

GR_RESULT GR_STDCALL grDbgUnregisterMsgCallback(
    GR_DBG_MSG_CALLBACK_FUNCTION pfnMsgCallback);

GR_RESULT GR_STDCALL grDbgSetMessageFilter(
    GR_DEVICE device,
    GR_ENUM msgCode,
    GR_ENUM filter);

GR_RESULT GR_STDCALL grDbgSetObjectTag(
    GR_BASE_OBJECT object,
    GR_SIZE tagSize,
    const GR_VOID* pTag);

GR_RESULT GR_STDCALL grDbgSetGlobalOption(
    GR_DBG_GLOBAL_OPTION dbgOption,
    GR_SIZE dataSize,
    const GR_VOID* pData);

GR_RESULT GR_STDCALL grDbgSetDeviceOption(
    GR_DEVICE device,
    GR_DBG_DEVICE_OPTION dbgOption,
    GR_SIZE dataSize,
    const GR_VOID* pData);

GR_VOID GR_STDCALL grCmdDbgMarkerBegin(
    GR_CMD_BUFFER cmdBuffer,
    const GR_CHAR* pMarker);

GR_VOID GR_STDCALL grCmdDbgMarkerEnd(
    GR_CMD_BUFFER cmdBuffer);

#ifdef __cplusplus
}
#endif

#endif // MANTLE_DBG_H_
