#pragma once

#include "dma_field_values.hpp"
#include "Register.hpp"

template<typename MCU = STM32F4xxxx, uint32_t address = 0>
class DMABase
{
private:
	static constexpr auto dma_address 	= address;
    static constexpr auto lisr_address  = dma_address + 0x00;
	static constexpr auto hisr_address 	= dma_address + 0x04;
    static constexpr auto lifcr_address = dma_address + 0x08;
    static constexpr auto hifcr_address = dma_address + 0x0C;

    // Таких 8 штук
    static constexpr auto scr_address      = dma_address + 0x10;
    static constexpr auto sndtr_address    = dma_address + 0x14;
    static constexpr auto spar_address     = dma_address + 0x18;
    static constexpr auto sm0ar_address    = dma_address + 0x1C;
    static constexpr auto sm1ar_address    = dma_address + 0x20;
    static constexpr auto sfcr_address     = dma_address + 0x24;

public://protected:
    struct LISR: public Register<MCU, STM32F4xxxx, lisr_address, 32, RO>
    {
        using FEIF0 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 0, 1, RO>;
        using DMEIF0 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 2, 1, RO>;
        using TEIF0 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 3, 1, RO>;
        using HTIF0 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 4, 1, RO>;
        using TCIF0 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 5, 1, RO>;
        using FEIF1 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 6, 1, RO>;
        using DMEIF1 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 8, 1, RO>;
        using TEIF1 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 9, 1, RO>;
        using HTIF1 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 10, 1, RO>;
        using TCIF1 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 11, 1, RO>;
        using FEIF2 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 16, 1, RO>;
        using DMEIF2 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 18, 1, RO>;
        using TEIF2 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 19, 1, RO>;
        using HTIF2 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 20, 1, RO>;
        using TCIF2 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 21, 1, RO>;
        using FEIF3 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 22, 1, RO>;
        using DMEIF3 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 24, 1, RO>;
        using TEIF3 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 25, 1, RO>;
        using HTIF3 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 26, 1, RO>;
        using TCIF3 =   EmptyValues<MCU, STM32F4xxxx, DMABase::LISR, 27, 1, RO>;
    };

    struct HISR: public Register<MCU, STM32F4xxxx, hisr_address, 32, RO>
    {
        using FEIF4 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 0, 1, RO>;
        using DMEIF4 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 2, 1, RO>;
        using TEIF4 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 3, 1, RO>;
        using HTIF4 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 4, 1, RO>;
        using TCIF4 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 5, 1, RO>;
        using FEIF5 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 6, 1, RO>;
        using DMEIF5 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 8, 1, RO>;
        using TEIF5 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 9, 1, RO>;
        using HTIF5 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 10, 1, RO>;
        using TCIF5 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 11, 1, RO>;
        using FEIF6 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 16, 1, RO>;
        using DMEIF6 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 18, 1, RO>;
        using TEIF6 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 19, 1, RO>;
        using HTIF6 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 20, 1, RO>;
        using TCIF6 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 21, 1, RO>;
        using FEIF7 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 22, 1, RO>;
        using DMEIF7 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 24, 1, RO>;
        using TEIF7 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 25, 1, RO>;
        using HTIF7 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 26, 1, RO>;
        using TCIF7 =   EmptyValues<MCU, STM32F4xxxx, DMABase::HISR, 27, 1, RO>;
    };

    struct LIFCR: public Register<MCU, STM32F4xxxx, lifcr_address, 32, WO>
    {
        using CFEIF0 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 0, 1, WO>;
        using CDMEIF0 = EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 2, 1, WO>;
        using CTEIF0 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 3, 1, WO>;
        using CHTIF0 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 4, 1, WO>;
        using CTCIF0 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 5, 1, WO>;
        using CFEIF1 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 6, 1, WO>;
        using CDMEIF1 = EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 8, 1, WO>;
        using CTEIF1 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 9, 1, WO>;
        using CHTIF1 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 10, 1, WO>;
        using CTCIF1 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 11, 1, WO>;
        using CFEIF2 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 16, 1, WO>;
        using CDMEIF2 = EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 18, 1, WO>;
        using CTEIF2 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 19, 1, WO>;
        using CHTIF2 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 20, 1, WO>;
        using CTCIF2 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 21, 1, WO>;
        using CFEIF3 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 22, 1, WO>;
        using CDMEIF3 = EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 24, 1, WO>;
        using CTEIF3 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 25, 1, WO>;
        using CHTIF3 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 26, 1, WO>;
        using CTCIF3 =  EmptyValues<MCU, STM32F4xxxx, DMABase::LIFCR, 27, 1, WO>;
    };

    struct HIFCR: public Register<MCU, STM32F4xxxx, hifcr_address, 32, WO>
    {
        using CFEIF4 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 0, 1, WO>;
        using CDMEIF4 = EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 2, 1, WO>;
        using CTEIF4 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 3, 1, WO>;
        using CHTIF4 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 4, 1, WO>;
        using CTCIF4 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 5, 1, WO>;
        using CFEIF5 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 6, 1, WO>;
        using CDMEIF5 = EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 8, 1, WO>;
        using CTEIF5 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 9, 1, WO>;
        using CHTIF5 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 10, 1, WO>;
        using CTCIF5 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 11, 1, WO>;
        using CFEIF6 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 16, 1, WO>;
        using CDMEIF6 = EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 18, 1, WO>;
        using CTEIF6 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 19, 1, WO>;
        using CHTIF6 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 20, 1, WO>;
        using CTCIF6 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 21, 1, WO>;
        using CFEIF7 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 22, 1, WO>;
        using CDMEIF7 = EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 24, 1, WO>;
        using CTEIF7 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 25, 1, WO>;
        using CHTIF7 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 26, 1, WO>;
        using CTCIF7 =  EmptyValues<MCU, STM32F4xxxx, DMABase::HIFCR, 27, 1, WO>;
    };

    template<uint8_t num>
    struct SCR: public Register<MCU, STM32F4xxxx, scr_address + (num * 0x24), 32, RW>
    {
        static_assert(num < 8, "DMA channel must be less than 8");

        using EN =      EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 0, 1, RW>;
        using DMEIE =   EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 1, 1, RW>;
        using TEIE =    EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 2, 1, RW>;
        using HTIE =    EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 3, 1, RW>;
        using TCIE =    EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 4, 1, RW>;
        using PFCTRL =  EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 5, 1, RW>;
        using DIR =     EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 6, 2, RW>;
        using CIRC =    EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 8, 1, RW>;
        using PINC =    EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 9, 1, RW>;
        using MINC =    EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 10, 1, RW>;
        using PSIZE =   EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 11, 2, RW>;
        using MSIZE =   EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 13, 2, RW>;
        using PINCOS =  EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 15, 1, RW>;
        using PL =      EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 16, 2, RW>;
        using DBM =     EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 18, 1, RW>;
        using CT =      EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 19, 1, RW>;
        using PBURST =  EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 21, 2, RW>;
        using MBURST =  EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 23, 2, RW>;
        using CHSEL =   EmptyValues<MCU, STM32F4xxxx, DMABase::SCR<num>, 25, 3, RW>;
    };

    template<uint8_t num>
    struct SNDTR: public Register<MCU, STM32F4xxxx, sndtr_address + (num * 0x24), 32, RW>
    {
        static_assert(num < 8, "DMA channel must be less than 8");
    };

    template<uint8_t num>
    struct SPAR: public Register<MCU, STM32F4xxxx, spar_address + (num * 0x24), 32, RW>
    {
        static_assert(num < 8, "DMA channel must be less than 8");
    };

    template<uint8_t num>
    struct SM0AR: public Register<MCU, STM32F4xxxx, sm0ar_address + (num * 0x24), 32, RW>
    {
        static_assert(num < 8, "DMA channel must be less than 8");
    };

    template<uint8_t num>
    struct SM1AR: public Register<MCU, STM32F4xxxx, sm1ar_address + (num * 0x24), 32, RW>
    {
        static_assert(num < 8, "DMA channel must be less than 8");
    };

    template<uint8_t num>
    struct SFCR: public Register<MCU, STM32F4xxxx, sfcr_address + (num * 0x24), 32, RW>
    {
        static_assert(num < 8, "DMA channel must be less than 8");

        using FTH =     EmptyValues<MCU, STM32F4xxxx, DMABase::SFCR<num>, 0, 2, RW>;
        using DMDIS =   EmptyValues<MCU, STM32F4xxxx, DMABase::SFCR<num>, 2, 1, RW>;
        using FS =      EmptyValues<MCU, STM32F4xxxx, DMABase::SFCR<num>, 3, 3, RW>;
        using FEIE =    EmptyValues<MCU, STM32F4xxxx, DMABase::SFCR<num>, 7, 1, RW>;
    };
};