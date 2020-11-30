#pragma once

#include "common_field_values.hpp"
#include "Register.hpp"

template<typename MCU>
class EXTIBase
{
private:
	static constexpr auto exti_address 	= 0x40013C00;
	static constexpr auto imr_address 	= exti_address + 0x00;
	static constexpr auto emr_address 	= exti_address + 0x04;
	static constexpr auto rtsr_address 	= exti_address + 0x08;
	static constexpr auto ftsr_address 	= exti_address + 0x0C;
	static constexpr auto swier_address = exti_address + 0x10;
	static constexpr auto pr_address 	= exti_address + 0x14;
	
protected:
    struct IMR
    {
        using MR0 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 0, 1, RW>;
        using MR1 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 1, 1, RW>;
        using MR2 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 2, 1, RW>;
        using MR3 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 3, 1, RW>;
        using MR4 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 4, 1, RW>;
        using MR5 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 5, 1, RW>;
        using MR6 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 6, 1, RW>;
        using MR7 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 7, 1, RW>;
        using MR8 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 8, 1, RW>;
        using MR9 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 9, 1, RW>;
        using MR10 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 10, 1, RW>;
        using MR11 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 11, 1, RW>;
        using MR12 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 12, 1, RW>;
        using MR13 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 13, 1, RW>;
        using MR14 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 14, 1, RW>;
        using MR15 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 15, 1, RW>;
        using MR16 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 16, 1, RW>;
        using MR17 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 17, 1, RW>;
        using MR18 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 18, 1, RW>;
        using MR19 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 19, 1, RW>;
        using MR20 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 20, 1, RW>;
        using MR21 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 21, 1, RW>;
        using MR22 = StateValues<MCU, STM32F4xxxx, EXTIBase::IMR, 22, 1, RW>;
    };

    struct EMR
    {
        using MR0 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 0, 1, RW>;
        using MR1 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 1, 1, RW>;
        using MR2 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 2, 1, RW>;
        using MR3 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 3, 1, RW>;
        using MR4 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 4, 1, RW>;
        using MR5 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 5, 1, RW>;
        using MR6 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 6, 1, RW>;
        using MR7 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 7, 1, RW>;
        using MR8 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 8, 1, RW>;
        using MR9 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 9, 1, RW>;
        using MR10 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 10, 1, RW>;
        using MR11 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 11, 1, RW>;
        using MR12 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 12, 1, RW>;
        using MR13 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 13, 1, RW>;
        using MR14 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 14, 1, RW>;
        using MR15 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 15, 1, RW>;
        using MR16 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 16, 1, RW>;
        using MR17 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 17, 1, RW>;
        using MR18 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 18, 1, RW>;
        using MR19 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 19, 1, RW>;
        using MR20 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 20, 1, RW>;
        using MR21 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 21, 1, RW>;
        using MR22 = StateValues<MCU, STM32F4xxxx, EXTIBase::EMR, 22, 1, RW>;
    };

    struct RTSR
    {
        using TR0 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 0, 1, RW>;
        using TR1 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 1, 1, RW>;
        using TR2 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 2, 1, RW>;
        using TR3 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 3, 1, RW>;
        using TR4 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 4, 1, RW>;
        using TR5 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 5, 1, RW>;
        using TR6 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 6, 1, RW>;
        using TR7 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 7, 1, RW>;
        using TR8 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 8, 1, RW>;
        using TR9 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 9, 1, RW>;
        using TR10 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 10, 1, RW>;
        using TR11 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 11, 1, RW>;
        using TR12 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 12, 1, RW>;
        using TR13 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 13, 1, RW>;
        using TR14 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 14, 1, RW>;
        using TR15 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 15, 1, RW>;
        using TR16 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 16, 1, RW>;
        using TR17 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 17, 1, RW>;
        using TR18 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 18, 1, RW>;
        using TR19 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 19, 1, RW>;
        using TR20 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 20, 1, RW>;
        using TR21 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 21, 1, RW>;
        using TR22 = StateValues<MCU, STM32F4xxxx, EXTIBase::RTSR, 22, 1, RW>;
    };

    struct FTSR
    {
        using TR0 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 0, 1, RW>;
        using TR1 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 1, 1, RW>;
        using TR2 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 2, 1, RW>;
        using TR3 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 3, 1, RW>;
        using TR4 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 4, 1, RW>;
        using TR5 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 5, 1, RW>;
        using TR6 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 6, 1, RW>;
        using TR7 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 7, 1, RW>;
        using TR8 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 8, 1, RW>;
        using TR9 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 9, 1, RW>;
        using TR10 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 10, 1, RW>;
        using TR11 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 11, 1, RW>;
        using TR12 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 12, 1, RW>;
        using TR13 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 13, 1, RW>;
        using TR14 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 14, 1, RW>;
        using TR15 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 15, 1, RW>;
        using TR16 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 16, 1, RW>;
        using TR17 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 17, 1, RW>;
        using TR18 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 18, 1, RW>;
        using TR19 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 19, 1, RW>;
        using TR20 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 20, 1, RW>;
        using TR21 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 21, 1, RW>;
        using TR22 = StateValues<MCU, STM32F4xxxx, EXTIBase::FTSR, 22, 1, RW>;
    };

    struct SWIER
    {
        using SWIER0 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 0, 1, RW>;
        using SWIER1 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 1, 1, RW>;
        using SWIER2 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 2, 1, RW>;
        using SWIER3 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 3, 1, RW>;
        using SWIER4 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 4, 1, RW>;
        using SWIER5 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 5, 1, RW>;
        using SWIER6 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 6, 1, RW>;
        using SWIER7 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 7, 1, RW>;
        using SWIER8 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 8, 1, RW>;
        using SWIER9 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 9, 1, RW>;
        using SWIER10 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 10, 1, RW>;
        using SWIER11 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 11, 1, RW>;
        using SWIER12 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 12, 1, RW>;
        using SWIER13 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 13, 1, RW>;
        using SWIER14 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 14, 1, RW>;
        using SWIER15 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 15, 1, RW>;
        using SWIER16 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 16, 1, RW>;
        using SWIER17 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 17, 1, RW>;
        using SWIER18 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 18, 1, RW>;
        using SWIER19 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 19, 1, RW>;
        using SWIER20 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 20, 1, RW>;
        using SWIER21 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 21, 1, RW>;
        using SWIER22 = EmptyValues<MCU, STM32F4xxxx, EXTIBase::SWIER, 22, 1, RW>;
    };

    struct PR
    {
        using PR0 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 0, 1, RC_W1>;
        using PR1 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 1, 1, RC_W1>;
        using PR2 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 2, 1, RC_W1>;
        using PR3 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 3, 1, RC_W1>;
        using PR4 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 4, 1, RC_W1>;
        using PR5 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 5, 1, RC_W1>;
        using PR6 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 6, 1, RC_W1>;
        using PR7 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 7, 1, RC_W1>;
        using PR8 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 8, 1, RC_W1>;
        using PR9 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 9, 1, RC_W1>;
        using PR10 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 10, 1, RC_W1>;
        using PR11 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 11, 1, RC_W1>;
        using PR12 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 12, 1, RC_W1>;
        using PR13 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 13, 1, RC_W1>;
        using PR14 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 14, 1, RC_W1>;
        using PR15 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 15, 1, RC_W1>;
        using PR16 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 16, 1, RC_W1>;
        using PR17 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 17, 1, RC_W1>;
        using PR18 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 18, 1, RC_W1>;
        using PR19 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 19, 1, RC_W1>;
        using PR20 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 20, 1, RC_W1>;
        using PR21 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 21, 1, RC_W1>;
        using PR22 = Field<MCU, STM32F4xxxx, EXTIBase::PR, 22, 1, RC_W1>;
    };
};