#include <device/Devices.h>

#ifdef SPOOPY_VULKAN
#include <SpoopyHelpers.h>
#endif

namespace spoopy {
    #ifdef SPOOPY_VULKAN
    const std::vector<const char*> Devices::Extensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};

        #ifdef SPOOPY_DEBUG_MESSENGER
        const std::vector<const char*> Devices::ValidationLayers = {"VK_LAYER_KHRONOS_validation"};
        #else
        const std::vector<const char*> Devices::ValidationLayers = {"VK_LAYER_LUNARG_standard_validation"};
        #endif
    #else
    const std::vector<const char*> Devices::Extensions = {};
    const std::vector<const char*> Devices::ValidationLayers = {};
    #endif
}