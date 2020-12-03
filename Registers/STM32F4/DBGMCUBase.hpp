#pragma once

#include "dbgmcu_field_values.hpp"
#include "Register.hpp"

template<typename MCU = STM32F4xxxx>
class DBGMCUBase
{
private:
	static constexpr auto dbgmcu_address 	= 0xE0042000;
    static constexpr auto idcode_address    = dbgmcu_address + 0x00;
	static constexpr auto cr_address 	    = dbgmcu_address + 0x04;
	static constexpr auto apb1_fr_address 	= dbgmcu_address + 0x08;
    static constexpr auto apb2_fr_address 	= dbgmcu_address + 0x0C;

    static constexpr auto unique_id_address     = 0x1FFF7A10;
    static constexpr auto flash_size_address    = 0x1FFF7A22;
	
protected:  
    struct IDCODE: public Register<MCU, STM32F4xxxx, idcode_address, 32, RO>
    {
        using DEVID = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::IDCODE, 0, 12, RO>;
        using REVID = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::IDCODE, 16, 16, RO>;
    };

    struct CR: public Register<MCU, STM32F4xxxx, cr_address, 32, RW>
    {
        using DBGSLEEP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::CR, 0, 1, RW>;
        using DBGSTOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::CR, 1, 1, RW>;
        using DBGSTANDBY = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::CR, 2, 1, RW>;
        using TRACEIOEN = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::CR, 5, 1, RW>;
        using TRACEMODE = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::CR, 6, 2, RW>;
    };

    struct APB1_FZ: public Register<MCU, STM32F4xxxx, apb1_fr_address, 32, RW>
    {
        using TIM2STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 0, 1, RW>;
        using TIM3STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 1, 1, RW>;
        using TIM4STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 2, 1, RW>;
        using TIM5STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 3, 1, RW>;
        using TIM6STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 4, 1, RW>;
        using TIM7STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 5, 1, RW>;
        using TIM12STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 6, 1, RW>;
        using TIM13STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 7, 1, RW>;
        using TIM14STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 8, 1, RW>;
        using RTCSTOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 10, 1, RW>;
        using WWDGSTOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 11, 1, RW>;
        using IWDGSTOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 12, 1, RW>;
        using I2C1SMBUSTIMEOUT = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 21, 1, RW>;
        using I2C2SMBUSTIMEOUT = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 22, 1, RW>;
        using I2C3SMBUSTIMEOUT = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 23, 1, RW>;
        using CAN1STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 25, 1, RW>;
        using CAN2STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB1_FZ, 26, 1, RW>;
    };

    struct APB2_FZ: public Register<MCU, STM32F4xxxx, apb2_fr_address, 32, RW>
    {
        using TIM1STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB2_FZ, 0, 1, RW>;
        using TIM8STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB2_FZ, 1, 1, RW>;
        using TIM9STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB2_FZ, 16, 1, RW>;
        using TIM10STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB2_FZ, 17, 1, RW>;
        using TIM11STOP = EmptyValues<MCU, STM32F4xxxx, DBGMCUBase::APB2_FZ, 18, 1, RW>;
    };

    struct FLASH_SIZE: public Register<MCU, STM32F4xxxx, flash_size_address, 16, RO> {};

    inline static uint32_t* UID = (uint32_t *)(unique_id_address);
};