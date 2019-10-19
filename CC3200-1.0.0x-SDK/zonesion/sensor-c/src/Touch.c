/*********************************************************************************************
* 文件：touch.c
* 作者：Lixm 2017.10.17
* 说明：触摸驱动代码
* 修改：
* 注释：
*********************************************************************************************/

/*********************************************************************************************
* 头文件
*********************************************************************************************/
#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_apps_rcm.h"
#include "touch.h"

/*********************************************************************************************
* 名称：touch_init()
* 功能：触摸传感器初始化
* 参数：无
* 返回：无
* 修改：
* 注释：
*********************************************************************************************/
void touch_init(void)
{
  PRCMPeripheralClkEnable(PRCM_GPIOA1, PRCM_RUN_MODE_CLK);      //使能时钟
  PinTypeGPIO(PIN_04,PIN_MODE_0,false);                         //选择引脚为GPIO模式（gpio16）
  GPIODirModeSet(GPIOA1_BASE, G13_UCPINS, GPIO_DIR_MODE_IN);   //设置GPIO13为输入模式
  PinConfigSet(PIN_04,PIN_TYPE_STD_PU,PIN_MODE_0);              //上拉
}

/*********************************************************************************************
* 名称：unsigned char get_touch_status(void)
* 功能：获取触摸传感器状态
* 参数：无
* 返回：无
* 修改：
* 注释：
*********************************************************************************************/
unsigned char get_touch_status(void)
{
  if((unsigned char)GPIOPinRead(GPIOA1_BASE,G13_UCPINS) > 0){                                                      //检测io口电平
      return 0;
  }
  else{
      return 1;
  }
}