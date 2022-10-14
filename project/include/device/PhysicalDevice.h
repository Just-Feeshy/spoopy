#ifndef SPOOPY_PHYSICAL_DEVICE_H
#define SPOOPY_PHYSICAL_DEVICE_H

#include <vector>
#include <map>

#include <SpoopyHelpers.h>
#include <core/Log.h>

namespace spoopy {
    class InstanceDevice;

    class PhysicalDevice {
        public:
            explicit PhysicalDevice(const InstanceDevice &instance);

            #ifdef SPOOPY_VULKAN
            virtual VkPhysicalDevice getSuitablePhysical(const std::vector<VkPhysicalDevice> &physicalDevices);
            virtual uint32_t scoreDeviceSuitability(VkPhysicalDevice device);

            virtual const VkPhysicalDevice &getPhysicalDevice() const;
            #endif
        private:
            #ifdef SPOOPY_VULKAN
            VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
            #endif
    };
}
#endif