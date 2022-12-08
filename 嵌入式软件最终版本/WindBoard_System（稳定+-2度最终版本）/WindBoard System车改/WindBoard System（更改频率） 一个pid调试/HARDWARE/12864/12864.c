# include "12864.h"
# include "delay.h"

const u8 HZ[] ={
							0x00,0xFE,0x12,0x22,0xC2,0x22,0x1A,0x02,0xFE,0x00,0x00,0x00,
							0x08,0x07,0x02,0x01,0x00,0x01,0x02,0x00,0x03,0x04,0x0F,0x00,/*"风"0*/
							0x88,0x68,0xFF,0x28,0x40,0xFE,0x12,0xF2,0x12,0x91,0x71,0x00,
							0x00,0x00,0x0F,0x08,0x04,0x03,0x08,0x05,0x02,0x05,0x08,0x00,/*"板"1*/
							0x88,0xFF,0x48,0x00,0x4C,0xA4,0x95,0x86,0x94,0xA4,0x4C,0x00,
							0x08,0x0F,0x00,0x00,0x08,0x08,0x08,0x0F,0x08,0x08,0x08,0x00,/*"控"2*/
							0x18,0xD6,0x54,0xFF,0x54,0xD4,0x10,0xFC,0x00,0x00,0xFF,0x00,
							0x00,0x07,0x00,0x0F,0x04,0x07,0x00,0x01,0x08,0x08,0x0F,0x00,/*"制"3*/
							0x00,0x82,0x92,0xDA,0xD6,0xB2,0xB1,0x91,0x89,0xC1,0x80,0x00,
							0x08,0x04,0x02,0x00,0x08,0x0F,0x00,0x00,0x02,0x04,0x09,0x00,/*"系"4*/
							0x98,0xD4,0xB3,0x88,0x00,0x64,0xD4,0x4D,0xC6,0x54,0xE4,0x00,
							0x04,0x04,0x02,0x02,0x08,0x04,0x03,0x00,0x07,0x08,0x0C,0x00,/*"统"5*/
							0x82,0x82,0xFF,0xAA,0xAA,0xAA,0xAA,0xAA,0xFF,0x82,0x82,0x00,
							0x0A,0x09,0x0A,0x0A,0x0A,0x0F,0x0A,0x0A,0x0A,0x09,0x0A,0x00,/*"基"6*/
							0x42,0xF2,0x2E,0x22,0xE2,0x00,0xBC,0x20,0xFF,0x20,0xBC,0x00,
							0x00,0x07,0x02,0x02,0x07,0x00,0x07,0x04,0x07,0x04,0x0F,0x00,/*"础"7*/
							0x88,0x88,0xFF,0x48,0x08,0x5F,0x55,0xD5,0x55,0x5F,0x40,0x00,
							0x00,0x08,0x0F,0x00,0x08,0x07,0x08,0x0F,0x09,0x09,0x08,0x00,/*"提"8*/
							0x82,0x82,0xBA,0xAA,0xAA,0xAB,0xAA,0xAA,0xBA,0x82,0x82,0x00,
							0x0F,0x00,0x00,0x0E,0x0A,0x0A,0x0A,0x0E,0x00,0x08,0x0F,0x00, /*"高"9*/
							0x08,0xF4,0x53,0x52,0x52,0xF2,0x5A,0x56,0x50,0xF0,0x00,0x00,
							0x08,0x07,0x01,0x01,0x01,0x07,0x01,0x01,0x09,0x0F,0x00,0x00,/*"角",:*/
							0x00,0xFE,0x0A,0x8A,0xBE,0xAA,0xAB,0xAA,0xBE,0x8A,0x0A,0x00,
							0x08,0x07,0x00,0x08,0x09,0x0A,0x04,0x04,0x0A,0x09,0x08,0x00,/*"度",;*/
							0x10,0x11,0xF2,0x00,0x50,0xCF,0x41,0x41,0x4F,0xD0,0x10,0x00,
							0x00,0x00,0x07,0x02,0x08,0x08,0x05,0x02,0x05,0x08,0x08,0x00,/*"设",<*/
							0x10,0x17,0xD5,0x55,0x57,0x7D,0x57,0x55,0xD5,0x17,0x10,0x00,
							0x08,0x08,0x0F,0x08,0x08,0x0E,0x08,0x08,0x0F,0x08,0x08,0x00,/*"置",=*/
							0x40,0x42,0x42,0xFE,0x42,0x42,0x42,0xFE,0x42,0x42,0x40,0x00,
					    0x00,0x08,0x06,0x01,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,/*"开",>*/
							0x88,0x78,0x0F,0xF8,0x00,0xD8,0x54,0x53,0x50,0xD8,0x30,0x00,
							0x08,0x05,0x02,0x0D,0x00,0x0F,0x04,0x04,0x04,0x0F,0x00,0x00,/*"始",?*/

};

const u8 ASCALL[]=              // ASCII
{
			
	0x00,0x00,0x00,0x00,0x00, // - -
	0x00,0x00,0x5F,0x00,0x00, // -!-
	0x00,0x07,0x00,0x07,0x00, // -"-
	0x14,0x7F,0x14,0x7F,0x14, // -#-
	0x24,0x2E,0x7B,0x2A,0x12, // -$-
	0x23,0x13,0x08,0x64,0x62, // -%-
	0x36,0x49,0x56,0x20,0x50, // -&-
	0x00,0x04,0x03,0x01,0x00, // -'-
	0x00,0x1C,0x22,0x41,0x00, // -(-
	0x00,0x41,0x22,0x1C,0x00, // -)-
	0x22,0x14,0x7F,0x14,0x22, // -*-
	0x08,0x08,0x7F,0x08,0x08, // -+-
	0x40,0x30,0x10,0x00,0x00, // -,-
	0x08,0x08,0x08,0x08,0x08, // ---
	0x00,0x60,0x60,0x00,0x00, // -.-
	0x20,0x10,0x08,0x04,0x02, // -/-
	0x3E,0x51,0x49,0x45,0x3E, // -0-
	0x00,0x42,0x7F,0x40,0x00, // -1-
	0x62,0x51,0x49,0x49,0x46, // -2-
	0x21,0x41,0x49,0x4D,0x33, // -3-
	0x18,0x14,0x12,0x7F,0x10, // -4-
	0x27,0x45,0x45,0x45,0x39, // -5-
	0x3C,0x4A,0x49,0x49,0x31, // -6-
	0x01,0x71,0x09,0x05,0x03, // -7-
	0x36,0x49,0x49,0x49,0x36, // -8-
	0x46,0x49,0x49,0x29,0x1E, // -9-
	0x00,0x36,0x36,0x00,0x00, // -:-
	0x40,0x36,0x36,0x00,0x00, // -;-
	0x08,0x14,0x22,0x41,0x00, // -<-
	0x14,0x14,0x14,0x14,0x14, // -=-
	0x00,0x41,0x22,0x14,0x08, // ->-
	0x02,0x01,0x59,0x05,0x02, // -?-
	0x3E,0x41,0x5D,0x55,0x5E, // -@-
	0x7C,0x12,0x11,0x12,0x7C, // -A-
	0x7F,0x49,0x49,0x49,0x36, // -B-
	0x3E,0x41,0x41,0x41,0x22, // -C-
	0x7F,0x41,0x41,0x41,0x3E, // -D-
	0x7F,0x49,0x49,0x49,0x41, // -E-
	0x7F,0x09,0x09,0x09,0x01, // -F-
	0x3E,0x41,0x51,0x51,0x72, // -G-
	0x7F,0x08,0x08,0x08,0x7F, // -H-
	0x00,0x41,0x7F,0x41,0x00, // -I-
	0x20,0x40,0x41,0x3F,0x01, // -J-
	0x7F,0x08,0x14,0x22,0x41, // -K-
	0x7F,0x40,0x40,0x40,0x40, // -L-
	0x7F,0x02,0x0C,0x02,0x7F, // -M-
	0x7F,0x04,0x08,0x10,0x7F, // -N-
	0x3E,0x41,0x41,0x41,0x3E, // -O-
	0x7F,0x09,0x09,0x09,0x06, // -P-
	0x3E,0x41,0x51,0x21,0x5E, // -Q-
	0x7F,0x09,0x19,0x29,0x46, // -R-
	0x26,0x49,0x49,0x49,0x32, // -S-
	0x01,0x01,0x7F,0x01,0x01, // -T-
	0x3F,0x40,0x40,0x40,0x3F, // -U-
	0x1F,0x20,0x40,0x20,0x1F, // -V-
	0x7F,0x20,0x18,0x20,0x7F, // -W-
	0x63,0x14,0x08,0x14,0x63, // -X-
	0x03,0x04,0x78,0x04,0x03, // -Y-
	0x61,0x51,0x49,0x45,0x43, // -Z-
	0x7F,0x7F,0x41,0x41,0x00, // -[-
	0x02,0x04,0x08,0x10,0x20, // -\-
	0x00,0x41,0x41,0x7F,0x7F, // -]-
	0x04,0x02,0x7F,0x02,0x04, // -^-
	0x08,0x1C,0x2A,0x08,0x08, // -_-
	0x00,0x00,0x01,0x02,0x04, // -`-
	0x24,0x54,0x54,0x38,0x40, // -a-
	0x7F,0x28,0x44,0x44,0x38, // -b-
	0x38,0x44,0x44,0x44,0x08, // -c-
	0x38,0x44,0x44,0x28,0x7F, // -d-
	0x38,0x54,0x54,0x54,0x08, // -e-
	0x08,0x7E,0x09,0x09,0x02, // -f-
	0x98,0xA4,0xA4,0xA4,0x78, // -g-
	0x7F,0x08,0x04,0x04,0x78, // -h-
	0x00,0x00,0x79,0x00,0x00, // -i-
	0x00,0x80,0x88,0x79,0x00, // -j-
	0x7F,0x10,0x28,0x44,0x40, // -k-
	0x00,0x41,0x7F,0x40,0x00, // -l-
	0x78,0x04,0x78,0x04,0x78, // -m-
	0x04,0x78,0x04,0x04,0x78, // -n-
	0x38,0x44,0x44,0x44,0x38, // -o-
	0xFC,0x24,0x24,0x24,0x18, // -p-
	0x18,0x24,0x24,0x24,0xFC, // -q-
	0x04,0x78,0x04,0x04,0x08, // -r-
	0x48,0x54,0x54,0x54,0x24, // -s-
	0x04,0x3F,0x44,0x44,0x24, // -t-
	0x3C,0x40,0x40,0x3C,0x40, // -u-
	0x1C,0x20,0x40,0x20,0x1C, // -v-
	0x3C,0x40,0x3C,0x40,0x3C, // -w-
	0x44,0x28,0x10,0x28,0x44, // -x-
	0x9C,0xA0,0xA0,0x90,0x7C, // -y-
	0x44,0x64,0x54,0x4C,0x44, // -z-
	0x08,0x36,0x41,0x00,0x00, // -{-
	0x00,0x00,0x77,0x00,0x00, // -|-
	0x00,0x00,0x41,0x36,0x08, // -}-
	0x06,0x09,0x09,0x06,0x00, // -�-
	0x08,0x04,0x08,0x10,0x08, // -~-
	0x55,0x2A,0x55,0x2A,0x55, // --
};


//向LCD发送8字节数据
void LCD_Send_8Bits(u8 dat)
{
    u8 i = 0;

    for (i=0; i<8; i++)
    {
        LCD_SCLK_0();
        if ( dat&0x80 )
        {
            LCD_DAT_1();
        }
        else
        {
            LCD_DAT_0();
        }
        LCD_SCLK_1();
        dat <<= 1;
    }
}

//向LCD写指令
void LCD_Send_Order(u8 cmd)
{
	LCD_RS_0();
  LCD_Send_8Bits(cmd);
}

//向LCD写数据
void LCD_Send_Data(u8 dat)
{
  LCD_RS_1();
  LCD_Send_8Bits(dat);
}

//显示汉字
void LCD_HZ(u8 x, u8 y,  u8 dat)
{
	  u8 i, j;
    LCD_CS_0();

    for (i=0; i<2; i++)
    {
        LCD_Add_XY(x+i, y);
        for (j=0; j<12; j++)
        {
            LCD_Send_Data(*(HZ + 24*(dat-'0') + 12*i + j));
        }
    }
    
    LCD_CS_1();
}

//汉字选中
void LCD_HZ_OP(u8 x, u8 y,  u8 dat)
{
	  u8 i, j;
    LCD_CS_0();

    for (i=0; i<2; i++)
    {
        LCD_Add_XY(x+i, y);
        for (j=0; j<12; j++)
        {
            LCD_Send_Data( ~(*(HZ + 24*(dat-'0') + 12*i + j)) );
        }
    }
    
    LCD_CS_1();
}

//显示汉字
void LCD_HZS(u8 x,u8 y,u8 *string)
{
	u8 i=0;
	while(*(string+i))
	{
		LCD_HZ(x,y+13*i,*(string+i));
		i++;
	}
}

//选中汉字
void LCD_HZS_OP(u8 x,u8 y,u8 *string)
{
	u8 i=0;
	while(*(string+i))
	{
		LCD_HZ_OP(x,y+13*i,*(string+i));
		i++;
	}
}

//显示ASCII字符
void LCD_ASCALL(u8 c)
{
	u8 i;
	LCD_CS_0();
	for (i=0;i<5;i++)
	{	
		LCD_Send_Data(*(ASCALL+5*(c-' ')+i));/*????LCD,?????8???????????1*/
	}
	LCD_CS_1();
}

//选中ASCII字符
void LCD_ASCALL_OP(u8 c)
{
	u8 i;
	LCD_CS_0();
	for (i=0;i<5;i++)
	{
		LCD_Send_Data(~(*(ASCALL+5*(c-' ')+i)));/*????LCD,?????8???????????1*/
	}
	LCD_CS_1();
}

//显示字符串
void LCD_ASCALLS(u8 *string)
{
	u8 i=0;
	while(*(string+i))
	{
        LCD_ASCALL(*(string+i));
		i++;
	}
}

//选中字符串
void LCD_ASCALLS_OP(u8 *string)
{
	u8 i=0;
	while(*(string+i))
	{
        LCD_ASCALL_OP(*(string+i));
		i++;
	}
}

//显示整数
void LCD_int(int dat)
{
	u8 i=0;
	char string[10]={0};
	for(i=0;dat>0;i++)
	{
		string[i]=dat%10;
		dat/=10;
	}
	if(i==0)
	{
		LCD_ASCALL('0');
		return;
	}
	else
	{

		for(i--;;)
		{
			
			LCD_ASCALL('0'+string[i]);

			if(i>0)
                i--;
			else
                return;
		}
	}
}

//设置坐标
void LCD_Add_XY(u8 x, u8 y)
{
	LCD_CS_0();
    x--;
    y--;

    LCD_Send_Order(0xB0 + x);
    LCD_Send_Order(0x10 + (y>>4&0x0F));
    LCD_Send_Order(y&0x0F);
}

//初始化LCD
void LCD_Init(void)
{
  MYGPIO_Init();
  LCD_CS_0();
  LCD_RST_0();
  delay_us(20);
  LCD_RST_1();
  delay_us(20);
  LCD_Send_Order(0xe2);	 /*软复位*/
	delay_us(5);
	LCD_Send_Order(0x2c);  /*升压步骤1*/
	delay_us(5);
	LCD_Send_Order(0x2e);  /*升压步骤2*/
	delay_us(5);
	LCD_Send_Order(0x2f);  /*升压步骤3*/
	delay_us(5);
	LCD_Send_Order(0x23);  /*粗调对比度,可调范围0x20~0x27*/
	LCD_Send_Order(0x81);  /*微调对比度*/
	LCD_Send_Order(0x2f);  /*0x28,微调对比度的值,可调范围0x00~0x3f*/
	LCD_Send_Order(0xa2);  /*1/9偏压比(bias)*/
	LCD_Send_Order(0xc8);  /*行顺序扫描:自上而下*/
	LCD_Send_Order(0xa0);  /*列顺序扫描:自左而右*/
	LCD_Send_Order(0x40);  /*起始行:从第一行开始*/
	LCD_Send_Order(0xaf);  /*开显示*/
	LCD_Clear_Screen();
	LCD_CS_1();
}

//IO口初始化
void MYGPIO_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

//清屏
void LCD_Clear_Screen(void)
{
	  u8 i, j;
    LCD_CS_0();

    for (i=0; i<9; i++)
    {
    	LCD_Send_Order(0xb0+i);
    	LCD_Send_Order(0x10);
    	LCD_Send_Order(0x00);

        for (j=0; j<132; j++)
        {
            LCD_Send_Data(0x00);
        }
    }
    LCD_CS_1();
}

//清除行
void LCD_Clear_Line(u8 _X)
{
  unsigned char j;
  LCD_CS_0();
  LCD_Send_Order(0xb0+(_X-1));
  LCD_Send_Order(0x10);
  LCD_Send_Order(0x00);
  for(j=0;j<132;j++)
  {
    LCD_Send_Data(0x00);
  }

  LCD_CS_1();
}

