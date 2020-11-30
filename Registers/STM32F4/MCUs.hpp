#pragma once

// Контроллеры серий STM32F40_41xxx.
struct STM32F405RG {};	struct STM32F405VG {};	struct STM32F405ZG {};
struct STM32F415RG {};	struct STM32F415VG {};	struct STM32F415ZG {};
struct STM32F407VG {};	struct STM32F407VE {};	struct STM32F407ZG {};
struct STM32F407ZE {};	struct STM32F407IG {};	struct STM32F407IE {};
struct STM32F417VG {};	struct STM32F417VE {};	struct STM32F417ZG {};
struct STM32F417ZE {};	struct STM32F417IG {};	struct STM32F417IE {};
						
// Контроллеры серий STM32F427_437xx.				
struct STM32F427VG {};	struct STM32F427VI {};	struct STM32F427ZG {}; 
struct STM32F427ZI {}; 	struct STM32F427IG {}; 	struct STM32F427II {};
struct STM32F437VG {}; 	struct STM32F437VI {}; 	struct STM32F437ZG {}; 
struct STM32F437ZI {}; 	struct STM32F437IG {}; 	struct STM32F437II {};
						
// Контроллеры серий STM32F427_437xx.
struct STM32F429VG {}; 	struct STM32F429VI {}; 	struct STM32F429ZG {}; 
struct STM32F429ZI {}; 	struct STM32F429BG {}; 	struct STM32F429BI {};
struct STM32F429NG {}; 	struct STM32F439NI {}; 	struct STM32F429IG {}; 
struct STM32F429II {}; 	struct STM32F439VG {}; 	struct STM32F439VI {};
struct STM32F439ZG {}; 	struct STM32F439ZI {}; 	struct STM32F439BG {}; 
struct STM32F439BI {}; 	struct STM32F439NG {}; 	struct STM32F439IG {}; 	
struct STM32F439II {}; 
						
// Объединение контроллеров согласно макросам STD Periph Lib.
struct STM32F40_41xxx: 	public STM32F405RG,	public STM32F405VG, public STM32F405ZG,
						public STM32F415RG,	public STM32F415VG,	public STM32F415ZG,
						public STM32F407VG,	public STM32F407VE,	public STM32F407ZG,
						public STM32F407ZE,	public STM32F407IG,	public STM32F407IE,
						public STM32F417VG,	public STM32F417VE,	public STM32F417ZG,
						public STM32F417ZE,	public STM32F417IG,	public STM32F417IE {};
						
struct STM32F427_437xx: public STM32F427VG,	public STM32F427VI,	public STM32F427ZG, 
						public STM32F427ZI, public STM32F427IG, public STM32F427II,
						public STM32F437VG, public STM32F437VI, public STM32F437ZG, 
						public STM32F437ZI, public STM32F437IG, public STM32F437II {};
						
struct STM32F429_439xx: public STM32F429VG, public STM32F429VI,	public STM32F429ZG, 
						public STM32F429ZI,	public STM32F429BG, public STM32F429BI,
						public STM32F429NG,	public STM32F439NI, public STM32F429IG, 
						public STM32F429II,	public STM32F439VG, public STM32F439VI,
						public STM32F439ZG,	public STM32F439ZI, public STM32F439BG, 
						public STM32F439BI,	public STM32F439NG,	public STM32F439IG,	
						public STM32F439II {};

// Объединение контроллеров согласно даташиту.
struct STM32F42_43xxx: public STM32F427_437xx, public STM32F429_439xx {};

// Все семейство STM32F4
struct STM32F4xxxx: public STM32F42_43xxx, public STM32F40_41xxx {};

using Target = STM32F407VE;