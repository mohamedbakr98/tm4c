#include "GPIO.h"
#include "GPIO_Cfg.h"
const GPIO_CfgType GPIO_ConfigParam [GPIO_GROUPS_NUMBER] =
{
    {
        0x05,1<<1,
        0,0,0,
        0xff,
        0x00,0xff,0x00,
        0xff,0x00,0x00,
        0xff,
        0


    },
    {
        0x05,1<<0,
        0,0,0,
        0x00,
        0xff,0x00,0x00,
        0x00,0x00,0x00,
        0xff,
        0
    },
    {
        0x05,1<<4,
        0,0,0,
        0x00,
        0xff,0x00,0x00,
        0x00,0x00,0x00,
        0xff,
        0
    }

};
