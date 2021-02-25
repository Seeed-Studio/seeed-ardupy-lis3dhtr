/**
 * The MIT License (MIT)
 *
 * Author: PowerfulCat (x4495@outlook.com) & Hongtai.liu (lht856@foxmail.com)
 *
 * Copyright (C) 2020  Seeed Technology Co.,Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <Arduino.h>
#include <Wire.h>
#include "Seeed_Arduino_LIS3DHTR/src/LIS3DHTR.h"
extern "C"
{
#include "py/objtype.h"
#include "py/obj.h"
#include "shared-bindings/util.h"
#include "shared-bindings/arduino_util.h"
}
#define lis (*(LIS3DHTR<TwoWire> *)self->module)
void *operator new(size_t, void *);

extern "C"
{
    void common_hal_lis3dhtr_construct(abstract_module_t *self, size_t n_args, const mp_obj_t *args)
    {
      
        self->module = new (m_new_obj(LIS3DHTR<TwoWire>)) LIS3DHTR<TwoWire>;
        TwoWire *_wire = &Wire;
        uint8_t addr = LIS3DHTR_DEFAULT_ADDRESS;
        #ifdef ARDUPY_GET_WIRE
        if(n_args >= 1)
        {
            int32_t wire_num = mp_obj_get_int(args[0]);
            _wire = ardupy_get_wire(wire_num); 
        }
        if(n_args == 2)
        {
            addr = mp_obj_get_int(args[1]);
        }
        #endif
        lis.begin(*_wire, addr);
        _wire->setClock(400000);
        lis.setOutputDataRate(LIS3DHTR_DATARATE_50HZ); //Data output rate
        lis.setFullScaleRange(LIS3DHTR_RANGE_2G);      //Scale range set to 2g
    }
    void common_hal_lis3dhtr_deinit(abstract_module_t *self)
    {
        lis.~LIS3DHTR();
    }
    bool common_hal_lis3dhtr_available(abstract_module_t *self)
    {
        return lis.available();
    }
    void common_hal_lis3dhtr_getAcceleration(abstract_module_t *self, float *x, float *y, float *z)
    {
        lis.getAcceleration(x,y,z);
    }
    float common_hal_lis3dhtr_getAccelerationX(abstract_module_t *self)
    {
        return lis.getAccelerationX();
    }
    float common_hal_lis3dhtr_getAccelerationY(abstract_module_t *self)
    {
        return lis.getAccelerationY();
    }
    float common_hal_lis3dhtr_getAccelerationZ(abstract_module_t *self)
    {
        return lis.getAccelerationZ();
    }
    void common_hal_lis3dhtr_setPowerMode(abstract_module_t *self, uint8_t mode)
    {
        mode=mode<<3;
        lis.setPowerMode((power_type_t)mode);
    }
    void common_hal_lis3dhtr_setFullScaleRange(abstract_module_t *self, uint8_t range)
    {
        range=range<<4;
        lis.setFullScaleRange((scale_type_t)range);
    }
    void common_hal_lis3dhtr_setOutputDataRate(abstract_module_t *self, uint8_t odr)
    {
        odr=odr<<4;
        lis.setOutputDataRate((odr_type_t)odr);
    }
    void common_hal_lis3dhtr_setHighSolution(abstract_module_t *self, bool enable)
    {
        lis.setHighSolution(enable);
    }
    void common_hal_lis3dhtr_openTemp(abstract_module_t *self)
    {
        lis.openTemp();
    }
    void common_hal_lis3dhtr_closeTemp(abstract_module_t *self)
    {
        lis.closeTemp();
    }
    uint16_t common_hal_lis3dhtr_readbitADC1(abstract_module_t *self)
    {
        return lis.readbitADC1();
    }
    uint16_t common_hal_lis3dhtr_readbitADC2(abstract_module_t *self)
    {
        return lis.readbitADC2();
    }
    uint16_t common_hal_lis3dhtr_readbitADC3(abstract_module_t *self)
    {
        return lis.readbitADC3();
    }
    int16_t common_hal_lis3dhtr_getTemperature(abstract_module_t *self)
    {
        return lis.getTemperature();
    }
}
