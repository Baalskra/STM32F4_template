#pragma once

#include "pwr_field_values.hpp"
#include "Register.hpp"

template<typename MCU>
class PWRBase
{
private:
	static constexpr auto pwr_address 	= 0x40007000;
	static constexpr auto cr_address 	= pwr_address + 0x00;
	static constexpr auto csr_address 	= pwr_address + 0x04;
	
protected:
    struct CR: public Register<MCU, STM32F4xxxx, cr_address, 32, RW>
    {
        using LPDS = EmptyValues<MCU, STM32F4xxxx, PWRBase::CR, 0, 1, RW>;
        using PDDS = EmptyValues<MCU, STM32F4xxxx, PWRBase::CR, 1, 1, RW>;
        using CWUF = EmptyValues<MCU, STM32F4xxxx, PWRBase::CR, 2, 1, RC_W1>;
        using CSBF = EmptyValues<MCU, STM32F4xxxx, PWRBase::CR, 3, 1, RC_W1>;
        using PVDE = StateValues<MCU, STM32F4xxxx, PWRBase::CR, 4, 1, RW>;
        using PLS = EmptyValues<MCU, STM32F4xxxx, PWRBase::CR, 5, 3, RW>;
        using DBP = StateValues<MCU, STM32F4xxxx, PWRBase::CR, 8, 1, RW>;
        using FPDS = EmptyValues<MCU, STM32F4xxxx, PWRBase::CR, 9, 1, RW>;
        using LPUDS = EmptyValues<MCU, STM32F42_43xxx, PWRBase::CR, 10, 1, RW>;
        using MRUDS = EmptyValues<MCU, STM32F42_43xxx, PWRBase::CR, 11, 1, RW>;
        using ADCDC1 = EmptyValues<MCU, STM32F42_43xxx, PWRBase::CR, 13, 1, RW>;
        using VOS = EmptyValues<MCU, STM32F4xxxx, PWRBase::CR, 14, 2, RW>; // Тут не все значения
        using ODEN = StateValues<MCU, STM32F42_43xxx, PWRBase::CR, 16, 1, RW>;
        using ODSWEN = StateValues<MCU, STM32F42_43xxx, PWRBase::CR, 17, 1, RW>;
        using UNDEN = EmptyValues<MCU, STM32F42_43xxx, PWRBase::CR, 18, 2, RW>;
    };

     struct CSR: public Register<MCU, STM32F4xxxx, csr_address, 32, RW>
    {
        using WUF = EmptyValues<MCU, STM32F4xxxx, PWRBase::CSR, 0, 1, RO>;
        using SBF = EmptyValues<MCU, STM32F4xxxx, PWRBase::CSR, 1, 1, RO>;
        using PVDO = EmptyValues<MCU, STM32F4xxxx, PWRBase::CSR, 2, 1, RO>;
        using BRR = StatusValues<MCU, STM32F4xxxx, PWRBase::CSR, 3, 1, RO>;
        using EWUP = EmptyValues<MCU, STM32F4xxxx, PWRBase::CSR, 8, 1, RW>;
        using BRE = StateValues<MCU, STM32F4xxxx, PWRBase::CSR, 9, 1, RW>;
        using VOSRDY = StatusValues<MCU, STM32F4xxxx, PWRBase::CSR, 14, 1, RO>;
        using ODRDY = StatusValues<MCU, STM32F42_43xxx, PWRBase::CSR, 16, 1, RO>;
        using ODSWRDY = StatusValues<MCU, STM32F42_43xxx, PWRBase::CSR, 17, 1, RO>;
        using UDRDY = EmptyValues<MCU, STM32F42_43xxx, PWRBase::CSR, 18, 2, RC_W1>;
    };
};