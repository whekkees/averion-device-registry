#pragma once

#include <stdint.h>


struct DeviceInfo {
    uint32_t id;
    uint32_t category;
    const char* name;
};

constexpr uint32_t DEVICE_BLOCK = 0;
constexpr uint32_t DEVICE_OTHER = 1;

extern "C" {
    bool device_register(uint32_t id, uint32_t category, const char* name);
    DeviceInfo* device_get_by_id(uint32_t id);
    uint32_t device_count_get();
    DeviceInfo* device_get_by_index(uint32_t index);
}