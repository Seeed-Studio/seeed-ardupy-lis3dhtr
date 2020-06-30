#ifndef ARDUPY_LIS3DHTR_H
#define ARDUPY_LIS3DHTR_H
/**************************************************************************
    I2C ADDRESS/BITS
**************************************************************************/
#define LIS3DHTR_DEFAULT_ADDRESS (0x18) // 3C >> 1 = 7-bit default
#define LIS3DHTR_ADDRESS_UPDATED (0x19) //

#ifdef __cplusplus
extern "C"
{
#endif
#include "py/objtype.h"
#include "shared-bindings/util.h"
    void common_hal_lis3dhtr_construct(abstract_module_t *self, size_t n_args, const mp_obj_t *args);
    void common_hal_lis3dhtr_deinit(abstract_module_t *self);
    bool common_hal_lis3dhtr_available(abstract_module_t *self);
    float common_hal_lis3dhtr_getAccelerationX(abstract_module_t *self);
    float common_hal_lis3dhtr_getAccelerationY(abstract_module_t *self);
    float common_hal_lis3dhtr_getAccelerationZ(abstract_module_t *self);
    void common_hal_lis3dhtr_setPowerMode(abstract_module_t *self, uint8_t mode);
    void common_hal_lis3dhtr_setFullScaleRange(abstract_module_t *self, uint8_t range);
    void common_hal_lis3dhtr_setOutputDataRate(abstract_module_t *self, uint8_t odr);
    void common_hal_lis3dhtr_setHighSolution(abstract_module_t *self, bool enable);
    void common_hal_lis3dhtr_openTemp(abstract_module_t *self);
    void common_hal_lis3dhtr_closeTemp(abstract_module_t *self);
    uint16_t common_hal_lis3dhtr_readbitADC1(abstract_module_t *self);
    uint16_t common_hal_lis3dhtr_readbitADC2(abstract_module_t *self);
    uint16_t common_hal_lis3dhtr_readbitADC3(abstract_module_t *self);
    int16_t common_hal_lis3dhtr_getTemperature(abstract_module_t *self);
#ifdef __cplusplus
}
#endif

#endif