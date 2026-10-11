#include "device_registry.hpp"

constexpr uint32_t MAX_DEVICES = 32;

static DeviceInfo devices[MAX_DEVICES];
static uint32_t device_count = 0;

extern "C" bool device_register(uint32_t id, uint32_t category, const char* name) {
    if (name == nullptr || device_count >=  MAX_DEVICES) {
        return false;
    }

    for (uint32_t i = 0; i < device_count; ++i) {
        if (devices[i].id == id) {
            return false;
        }
    }

    devices[device_count] = {id, category, name};

    ++device_count;

    return true;

}

extern "C" DeviceInfo* device_get_by_id(uint32_t id) {
    for (uint32_t i = 0; i < device_count; ++i) {
        if (devices[i].id == id) {
            return &devices[i];
        }
    }

    return nullptr;
}

extern "C" uint32_t device_count_get() {
    return device_count;
}


extern "C" DeviceInfo* device_get_by_index(uint32_t index) {
    if (index < device_count) {
        return &devices[index];
    }

    return nullptr;
}
