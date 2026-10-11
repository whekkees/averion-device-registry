
#[repr(C)]
pub struct DeviceInfo {
    id : u32,
    category : u32,
    name : *const u8,
}

pub const DEVICE_BLOCK: u32 = 0;
pub const DEIVCE_OTHER: u32 = 1;

unsafe extern "C" {
    pub fn device_register(id: u32, category: u32, name: *const u8) -> bool;
    pub fn device_get_by_id(id: u32) -> *mut DeviceInfo;
    pub fn device_count_get() -> u32;
    pub unsafe fn device_get_by_index(index: u32) -> *mut DeviceInfo;
}