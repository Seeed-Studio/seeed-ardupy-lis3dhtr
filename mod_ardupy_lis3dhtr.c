/**
 * The MIT License (MIT)
 *
 * Author: Hongtai.liu (lht856@foxmail.com)
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

#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "shared-bindings/util.h"
#include "wrapper_ardupy_lis3dhtr.h"

extern const mp_obj_type_t grove_lis3dhtr_type;

m_generic_make(lis3dhtr)
{
    abstract_module_t *self = new_abstruct_module(type);
    mp_arg_check_num(n_args, n_kw, 0, 2, true);
    common_hal_lis3dhtr_construct(self, n_args, args);
    return self;
}

mp_obj_t lis3dhtr_available(mp_obj_t self_in)
{
    bool ret_val = common_hal_lis3dhtr_available((abstract_module_t *)self_in);
    return mp_obj_new_bool(ret_val);
}

MP_DEFINE_CONST_FUN_OBJ_1(lis3dhtr_available_obj, lis3dhtr_available);

mp_obj_t lis3dhtr_openTemp(mp_obj_t self_in)
{
    common_hal_lis3dhtr_openTemp((abstract_module_t *)self_in);
    return mp_const_none;
}

MP_DEFINE_CONST_FUN_OBJ_1(lis3dhtr_openTemp_obj, lis3dhtr_openTemp);

mp_obj_t lis3dhtr_closeTemp(mp_obj_t self_in)
{
    common_hal_lis3dhtr_closeTemp((abstract_module_t *)self_in);
    return mp_const_none;
}

MP_DEFINE_CONST_FUN_OBJ_1(lis3dhtr_closeTemp_obj, lis3dhtr_closeTemp);

mp_obj_t lis3dhtr_setPowerMode(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args)
{
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint8_t mode = mp_obj_get_int(pos_args[1]);
    common_hal_lis3dhtr_setPowerMode(self, mode);
    return mp_const_none;
}

MP_DEFINE_CONST_FUN_OBJ_KW(lis3dhtr_setPowerMode_obj, 1, lis3dhtr_setPowerMode);

mp_obj_t lis3dhtr_setFullScaleRange(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args)
{
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint8_t range = mp_obj_get_int(pos_args[1]);
    common_hal_lis3dhtr_setFullScaleRange(self, range);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(lis3dhtr_setFullScaleRange_obj, 1, lis3dhtr_setFullScaleRange);

mp_obj_t lis3dhtr_setOutputDataRate(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args)
{
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint8_t rate = mp_obj_get_int(pos_args[1]);
    common_hal_lis3dhtr_setOutputDataRate(self, rate);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(lis3dhtr_setOutputDataRate_obj, 1, lis3dhtr_setOutputDataRate);

mp_obj_t lis3dhtr_setHighSolution(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args)
{
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    bool enable = mp_obj_is_true(pos_args[1]);
    common_hal_lis3dhtr_setHighSolution(self, enable);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(lis3dhtr_setHighSolution_obj, 1, lis3dhtr_setHighSolution);

mp_obj_t lis3dhtr_getAcceleration(mp_obj_t self_in)
{
    float x,y,z;
    common_hal_lis3dhtr_getAcceleration((abstract_module_t *)self_in,&x,&y,&z);
    mp_obj_t list[3]={mp_obj_new_float(x),mp_obj_new_float(y),mp_obj_new_float(z)};
    return mp_obj_new_list(3,list);
}

MP_DEFINE_CONST_FUN_OBJ_1(lis3dhtr_getAcceleration_obj, lis3dhtr_getAcceleration);

void lis3dhtr_obj_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    abstract_module_t *self = (abstract_module_t *)self_in;
    float value;

    if (dest[0] == MP_OBJ_NULL)
    {
        if (attr == MP_QSTR_x)
        {
            float value = common_hal_lis3dhtr_getAccelerationX(self);
            dest[0] = mp_obj_new_float(value);
            return;
        }
        else if (attr == MP_QSTR_y)
        {
            float value = common_hal_lis3dhtr_getAccelerationY(self);
            dest[0] = mp_obj_new_float(value);
            return;
        }
        else if (attr == MP_QSTR_z)
        {
            float value = common_hal_lis3dhtr_getAccelerationZ(self);
            dest[0] = mp_obj_new_float(value);
            return;
        }
        else if (attr == MP_QSTR_adc1)
        {
            uint16_t value = common_hal_lis3dhtr_readbitADC1(self);
            dest[0] = mp_obj_new_int(value);
            return;
        }
        else if (attr == MP_QSTR_adc2)
        {
            uint16_t value = common_hal_lis3dhtr_readbitADC1(self);
            dest[0] = mp_obj_new_int(value);
            return;
        }
        else if (attr == MP_QSTR_adc3)
        {
            uint16_t value = common_hal_lis3dhtr_readbitADC1(self);
            dest[0] = mp_obj_new_int(value);
            return;
        }
        else if (attr == MP_QSTR_temperature)
        {
            uint16_t value = common_hal_lis3dhtr_getTemperature(self);
            dest[0] = mp_obj_new_int(value);
            return;
        }
    }

    generic_method_lookup(self_in, attr, dest);
}

const mp_rom_map_elem_t lis3dhtr_locals_dict_table[] = {
    // instance methods
    {MP_ROM_QSTR(MP_QSTR_deinit), MP_ROM_PTR(&lis3dhtr_deinit_obj)},
    {MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj)},
    {MP_ROM_QSTR(MP_QSTR___exit__), MP_ROM_PTR(&lis3dhtr_obj___exit___obj)},
    {MP_ROM_QSTR(MP_QSTR_available), MP_ROM_PTR(&lis3dhtr_available_obj)},
    {MP_ROM_QSTR(MP_QSTR_setPowerMode), MP_ROM_PTR(&lis3dhtr_setPowerMode_obj)},
    {MP_ROM_QSTR(MP_QSTR_setFullScaleRange), MP_ROM_PTR(&lis3dhtr_setFullScaleRange_obj)},
    {MP_ROM_QSTR(MP_QSTR_setOutputDataRate), MP_ROM_PTR(&lis3dhtr_setOutputDataRate_obj)},
    {MP_ROM_QSTR(MP_QSTR_setHighSolution), MP_ROM_PTR(&lis3dhtr_setHighSolution_obj)},
    {MP_ROM_QSTR(MP_QSTR_getAcceleration), MP_ROM_PTR(&lis3dhtr_getAcceleration_obj)},
    {MP_ROM_QSTR(MP_QSTR_openTemp), MP_ROM_PTR(&lis3dhtr_openTemp_obj)},
    {MP_ROM_QSTR(MP_QSTR_closeTemp), MP_ROM_PTR(&lis3dhtr_closeTemp_obj)},
};

MP_DEFINE_CONST_DICT(lis3dhtr_locals_dict, lis3dhtr_locals_dict_table);

const mp_obj_type_t grove_lis3dhtr_type = {
    {&mp_type_type},
    .name = MP_QSTR_grove_lis3dhtr,
    .make_new = lis3dhtr_make_new,
    .locals_dict = (mp_obj_t)&lis3dhtr_locals_dict,
    .attr = lis3dhtr_obj_attr};
