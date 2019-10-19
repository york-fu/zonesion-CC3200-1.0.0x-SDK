/*********************************************************************************************
* 文件：Infrared.h
* 作者：Lixm 2017.10.17
* 说明：可燃气体传感器驱动代码头文件  
* 修改：
* 注释：
*********************************************************************************************/

/*********************************************************************************************
* 宏条件编译
*********************************************************************************************/
#ifndef __MP_4_H__
#define __MP_4_H__

/*********************************************************************************************
* 头文件
*********************************************************************************************/
#include "systick_if.h"
#include "pin.h"
#include "hw_memmap.h"
#include "rom_map.h"

#ifndef HW_VERSION_1_2
#ifndef HW_VERSION_1_4
#define HW_VERSION_1_4
#warning Hardware version not specified,Default HW_VERSION_1_4
#endif
#endif

#ifdef HW_VERSION_1_2
#ifdef HW_VERSION_1_4
#error Hardware version definition conflict
#endif
#endif

#ifdef HW_VERSION_1_2
#define VOLTAGE_THRESHOLD 1.46
#endif

#ifdef HW_VERSION_1_4
#define VOLTAGE_THRESHOLD 0.9
#endif

/*********************************************************************************************
* 内部原型函数
*********************************************************************************************/
void combustiblegas_init(void);                          		//可燃气体传感器初始化
unsigned int get_combustiblegas_data(void);            			//获取可燃气体传感器状态

#endif /*__MP_4_H__*/

