#include "startup.hpp"

extern "C" void __iar_program_start(void);

using pFunc = void(*)();
using pVect = union{pFunc fun; void *ptr;};

#pragma segment = "CSTACK"
#pragma location = ".intvec"

const pVect __VECTOR_TABLE[] = 
{
  	{ .ptr = __sfe( "CSTACK" ) },
  	__iar_program_start,
  	IRQ::NMI_Handler,
	IRQ::HardFault_Handler,
	IRQ::MemManage_Handler,
	IRQ::BusFault_Handler,
	IRQ::UsageFault_Handler,
	0,
	0,
	0,
	0,
	IRQ::SVC_Handler,
	IRQ::DebugMon_Handler,
	0,
	IRQ::PendSV_Handler,
	IRQ::SysTick_Handler,
	
	IRQ::WWDG_IRQHandler,
	IRQ::PVD_IRQHandler,
	IRQ::TAMP_STAMP_IRQHandler,
	IRQ::RTC_WKUP_IRQHandler,
	IRQ::FLASH_IRQHandler,
	IRQ::RCC_IRQHandler,
	IRQ::EXTI0_IRQHandler,
	IRQ::EXTI1_IRQHandler,
	IRQ::EXTI2_IRQHandler,
	IRQ::EXTI3_IRQHandler,
	IRQ::EXTI4_IRQHandler,
	IRQ::DMA1_Stream0_IRQHandler,
	IRQ::DMA1_Stream1_IRQHandler,
	IRQ::DMA1_Stream2_IRQHandler,
	IRQ::DMA1_Stream3_IRQHandler,
	IRQ::DMA1_Stream4_IRQHandler,
	IRQ::DMA1_Stream5_IRQHandler,
	IRQ::DMA1_Stream6_IRQHandler,
	IRQ::ADC_IRQHandler,
	IRQ::CAN1_TX_IRQHandler,
	IRQ::CAN1_RX0_IRQHandler,
	IRQ::CAN1_RX1_IRQHandler,
	IRQ::CAN1_SCE_IRQHandler,
	IRQ::EXTI9_5_IRQHandler,
	IRQ::TIM1_BRK_TIM9_IRQHandler,
	IRQ::TIM1_UP_TIM10_IRQHandler,
	IRQ::TIM1_TRG_COM_TIM11_IRQHandler,
	IRQ::TIM1_CC_IRQHandler,
	IRQ::TIM2_IRQHandler,
	IRQ::TIM3_IRQHandler,
	IRQ::TIM4_IRQHandler,
	IRQ::I2C1_EV_IRQHandler,
	IRQ::I2C1_ER_IRQHandler,
	IRQ::I2C2_EV_IRQHandler,
	IRQ::I2C2_ER_IRQHandler,
	IRQ::SPI1_IRQHandler,
	IRQ::SPI2_IRQHandler,
	IRQ::USART1_IRQHandler,
	IRQ::USART2_IRQHandler,
	IRQ::USART3_IRQHandler,
	IRQ::EXTI15_10_IRQHandler,
	IRQ::RTC_Alarm_IRQHandler,
	IRQ::OTG_FS_WKUP_IRQHandler,
	IRQ::TIM8_BRK_TIM12_IRQHandler,
	IRQ::TIM8_UP_TIM13_IRQHandler,
	IRQ::TIM8_TRG_COM_TIM14_IRQHandler,
	IRQ::TIM8_CC_IRQHandler,
	IRQ::DMA1_Stream7_IRQHandler,
	IRQ::FSMC_IRQHandler,
	IRQ::SDIO_IRQHandler,
	IRQ::TIM5_IRQHandler,
	IRQ::SPI3_IRQHandler,
	IRQ::UART4_IRQHandler,
	IRQ::UART5_IRQHandler,
	IRQ::TIM6_DAC_IRQHandler,
	IRQ::TIM7_IRQHandler,
	IRQ::DMA2_Stream0_IRQHandler,
	IRQ::DMA2_Stream1_IRQHandler,
	IRQ::DMA2_Stream2_IRQHandler,
	IRQ::DMA2_Stream3_IRQHandler,
	IRQ::DMA2_Stream4_IRQHandler,
	IRQ::ETH_IRQHandler,
	IRQ::ETH_WKUP_IRQHandler,
	IRQ::CAN2_TX_IRQHandler,
	IRQ::CAN2_RX0_IRQHandler,
	IRQ::CAN2_RX1_IRQHandler,
	IRQ::CAN2_SCE_IRQHandler,
	IRQ::OTG_FS_IRQHandler,
	IRQ::DMA2_Stream5_IRQHandler,
	IRQ::DMA2_Stream6_IRQHandler,
	IRQ::DMA2_Stream7_IRQHandler,
	IRQ::USART6_IRQHandler,
	IRQ::I2C3_EV_IRQHandler,
	IRQ::I2C3_ER_IRQHandler,
	IRQ::OTG_HS_EP1_OUT_IRQHandler,
	IRQ::OTG_HS_EP1_IN_IRQHandler,
	IRQ::OTG_HS_WKUP_IRQHandler,
	IRQ::OTG_HS_IRQHandler,
	IRQ::DCMI_IRQHandler,
	IRQ::CRYP_IRQHandler,
	IRQ::HASH_RNG_IRQHandler,
	IRQ::FPU_IRQHandler,
};

__weak void IRQ::NMI_Handler()						{while(1);}
__weak void IRQ::HardFault_Handler()				{while(1);}
__weak void IRQ::MemManage_Handler()				{while(1);}
__weak void IRQ::BusFault_Handler()					{while(1);}
__weak void IRQ::UsageFault_Handler()				{while(1);}
__weak void IRQ::SVC_Handler()						{while(1);}
__weak void IRQ::DebugMon_Handler()					{while(1);}
__weak void IRQ::PendSV_Handler()					{while(1);}
__weak void IRQ::SysTick_Handler()					{while(1);}
__weak void IRQ::WWDG_IRQHandler()					{while(1);}
__weak void IRQ::PVD_IRQHandler()					{while(1);}
__weak void IRQ::TAMP_STAMP_IRQHandler()			{while(1);}
__weak void IRQ::RTC_WKUP_IRQHandler()				{while(1);}
__weak void IRQ::FLASH_IRQHandler()					{while(1);}
__weak void IRQ::RCC_IRQHandler()					{while(1);}
__weak void IRQ::EXTI0_IRQHandler()					{while(1);}
__weak void IRQ::EXTI1_IRQHandler()					{while(1);}
__weak void IRQ::EXTI2_IRQHandler()					{while(1);}
__weak void IRQ::EXTI3_IRQHandler()					{while(1);}
__weak void IRQ::EXTI4_IRQHandler()					{while(1);}
__weak void IRQ::DMA1_Stream0_IRQHandler()			{while(1);}
__weak void IRQ::DMA1_Stream1_IRQHandler() 			{while(1);}
__weak void IRQ::DMA1_Stream2_IRQHandler() 			{while(1);}
__weak void IRQ::DMA1_Stream3_IRQHandler() 			{while(1);}
__weak void IRQ::DMA1_Stream4_IRQHandler() 			{while(1);}
__weak void IRQ::DMA1_Stream5_IRQHandler() 			{while(1);}
__weak void IRQ::DMA1_Stream6_IRQHandler() 			{while(1);}
__weak void IRQ::ADC_IRQHandler()					{while(1);}
__weak void IRQ::CAN1_TX_IRQHandler()				{while(1);}
__weak void IRQ::CAN1_RX0_IRQHandler()				{while(1);}
__weak void IRQ::CAN1_RX1_IRQHandler()				{while(1);}
__weak void IRQ::CAN1_SCE_IRQHandler()				{while(1);}
__weak void IRQ::EXTI9_5_IRQHandler()				{while(1);}
__weak void IRQ::TIM1_BRK_TIM9_IRQHandler()			{while(1);}
__weak void IRQ::TIM1_UP_TIM10_IRQHandler()			{while(1);}
__weak void IRQ::TIM1_TRG_COM_TIM11_IRQHandler()	{while(1);}
__weak void IRQ::TIM1_CC_IRQHandler()				{while(1);}
__weak void IRQ::TIM2_IRQHandler()					{while(1);}
__weak void IRQ::TIM3_IRQHandler()					{while(1);}
__weak void IRQ::TIM4_IRQHandler()					{while(1);}
__weak void IRQ::I2C1_EV_IRQHandler()				{while(1);}
__weak void IRQ::I2C1_ER_IRQHandler()				{while(1);}
__weak void IRQ::I2C2_EV_IRQHandler()				{while(1);}
__weak void IRQ::I2C2_ER_IRQHandler()				{while(1);}
__weak void IRQ::SPI1_IRQHandler()					{while(1);}
__weak void IRQ::SPI2_IRQHandler()					{while(1);}
__weak void IRQ::USART1_IRQHandler()				{while(1);}
__weak void IRQ::USART2_IRQHandler()				{while(1);}
__weak void IRQ::USART3_IRQHandler()				{while(1);}
__weak void IRQ::EXTI15_10_IRQHandler()				{while(1);}
__weak void IRQ::RTC_Alarm_IRQHandler()				{while(1);}
__weak void IRQ::OTG_FS_WKUP_IRQHandler()			{while(1);}
__weak void IRQ::TIM8_BRK_TIM12_IRQHandler()		{while(1);}
__weak void IRQ::TIM8_UP_TIM13_IRQHandler()			{while(1);}
__weak void IRQ::TIM8_TRG_COM_TIM14_IRQHandler()	{while(1);}
__weak void IRQ::TIM8_CC_IRQHandler()				{while(1);}
__weak void IRQ::DMA1_Stream7_IRQHandler()			{while(1);}
__weak void IRQ::FSMC_IRQHandler()					{while(1);}
__weak void IRQ::SDIO_IRQHandler()					{while(1);}
__weak void IRQ::TIM5_IRQHandler()					{while(1);}
__weak void IRQ::SPI3_IRQHandler()					{while(1);}
__weak void IRQ::UART4_IRQHandler()					{while(1);}
__weak void IRQ::UART5_IRQHandler()					{while(1);}
__weak void IRQ::TIM6_DAC_IRQHandler()				{while(1);}
__weak void IRQ::TIM7_IRQHandler()					{while(1);}
__weak void IRQ::DMA2_Stream0_IRQHandler() 			{while(1);}
__weak void IRQ::DMA2_Stream1_IRQHandler() 			{while(1);}
__weak void IRQ::DMA2_Stream2_IRQHandler() 			{while(1);}
__weak void IRQ::DMA2_Stream3_IRQHandler() 			{while(1);}
__weak void IRQ::DMA2_Stream4_IRQHandler() 			{while(1);}
__weak void IRQ::ETH_IRQHandler()					{while(1);}
__weak void IRQ::ETH_WKUP_IRQHandler()				{while(1);}
__weak void IRQ::CAN2_TX_IRQHandler()				{while(1);}
__weak void IRQ::CAN2_RX0_IRQHandler()				{while(1);}
__weak void IRQ::CAN2_RX1_IRQHandler()				{while(1);}
__weak void IRQ::CAN2_SCE_IRQHandler()				{while(1);}
__weak void IRQ::OTG_FS_IRQHandler()				{while(1);}
__weak void IRQ::DMA2_Stream5_IRQHandler() 			{while(1);}
__weak void IRQ::DMA2_Stream6_IRQHandler() 			{while(1);}
__weak void IRQ::DMA2_Stream7_IRQHandler() 			{while(1);}
__weak void IRQ::USART6_IRQHandler() 				{while(1);}
__weak void IRQ::I2C3_EV_IRQHandler() 				{while(1);}
__weak void IRQ::I2C3_ER_IRQHandler() 				{while(1);}
__weak void IRQ::OTG_HS_EP1_OUT_IRQHandler()		{while(1);}
__weak void IRQ::OTG_HS_EP1_IN_IRQHandler() 		{while(1);}
__weak void IRQ::OTG_HS_WKUP_IRQHandler() 			{while(1);}
__weak void IRQ::OTG_HS_IRQHandler() 				{while(1);}
__weak void IRQ::DCMI_IRQHandler() 					{while(1);}
__weak void IRQ::CRYP_IRQHandler() 					{while(1);}
__weak void IRQ::HASH_RNG_IRQHandler() 				{while(1);}
__weak void IRQ::FPU_IRQHandler() 					{while(1);}

extern "C" void __cmain(void);

#pragma required = __vector_table
void __iar_program_start(void) 
{
  	__cmain();
}