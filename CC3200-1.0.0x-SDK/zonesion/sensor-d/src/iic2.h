/*********************************************************************************************
* 文件：iic.h
* 作者：zonesion
* 说明：iic头文件
* 修改：
* 注释：
*********************************************************************************************/
#ifndef _IIC_H_
#define _IIC_H_

#include "hw_ints.h"
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_common_reg.h"
#include "prcm.h"
#include "pinmux.h"
#include "rom.h"
#include "rom_map.h"
#include "gpio.h"
#include "pin.h"

/*********************************************************************************************
* 外部原型函数
*********************************************************************************************/
void iic2_init(void);
void iic2_start(void);
void iic2_stop(void);

unsigned char iic2_write_byte(unsigned char data);
unsigned char iic2_read_byte(unsigned char ack);

int iic2_write_buf(char addr, char r, char *buf, int len);
int iic2_read_buf(char addr, char r, char *buf, int len);


#endif 