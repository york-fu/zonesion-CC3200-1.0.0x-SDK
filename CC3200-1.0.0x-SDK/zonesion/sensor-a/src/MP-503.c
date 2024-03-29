/*********************************************************************************************
* 文件：MP-503.c
* 作者：Lixm 2017.10.17
* 说明：空气质量驱动代码
* 修改：
* 注释：
*********************************************************************************************/

/*********************************************************************************************
* 头文件
*********************************************************************************************/
#include "MP-503.h"
#include "adc.h"
/*********************************************************************************************
* 名称：airgas_init()
* 功能：空气质量传感器初始化
* 参数：无
* 返回：无
* 修改：
* 注释：
*********************************************************************************************/
void airgas_init(void)
{
  PinTypeADC(PIN_60,PIN_MODE_255);
  ADCTimerConfig(ADC_BASE, 2^17);       //配置ADC内部定时器
  ADCTimerEnable(ADC_BASE);             //使能内部定时器 
  ADCChannelEnable(ADC_BASE,ADC_CH_3);
  ADCEnable(ADC_BASE);
}

/*********************************************************************************************
* 名称：unsigned int get_airgas_data(void)
* 功能：获取空气质量传感器状态
* 参数：无
* 返回：无
* 修改：
* 注释：
*********************************************************************************************/
unsigned int get_airgas_data(void)
{ 
  unsigned int  value;
  while(!ADCFIFOLvlGet(ADC_BASE, ADC_CH_3));
  value = ((ADCFIFORead(ADC_BASE,ADC_CH_3)>>2)&0xfff)>>4;
  return value;                                                 //返回有效值
}