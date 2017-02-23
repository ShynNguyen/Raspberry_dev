#include "LCD.h"
#include "I2C.h"
#include "Basic_config.h"
#include <msp430.h>
int sec, min, hour, day , date , month, year;
char  dayc,Sun,Mon,Tues,Wed,Thurs,Fri,Sat;
unsigned char datawr[]={0x00,0x20,0x10,0x01,0x15,0x07,0x13};
   // khai báo data write
   unsigned char datarev[8];
   //khai báo data read
 void main()
 {
  
   Config_stop_WDT(); // stop WDT, see description in Basic_config.c
   Config_Clocks();
   P2SEL &=  ~BIT6 + ~BIT7; // 2.6,2.7 are GPIO
   P2SEL2 &=  ~BIT6 + ~BIT7;
   
   lcd_init(1);
   lcd_backlight(1); // turn on LCD backlight
   i2c_init(0x68);
   i2c_write(0x00,7, datawr); //write multi – byte
   
   while(1)
  {
  i2c_read(0x00,7,datarev);
  sec  =((datarev[0]&0xf0)>>4)*10 + (datarev[0]&0x0f); 
  min  =((datarev[1]&0xf0)>>4)*10 + (datarev[1]&0x0f);
  hour =((datarev[2]&0xf0)>>4)*10 + (datarev[2]&0x0f);
  day  =((datarev[3]&0xf0)>>4)*10 + (datarev[3]&0x0f);
  date =((datarev[4]&0xf0)>>4)*10 + (datarev[4]&0x0f);
  month=((datarev[5]&0xf0)>>4)*10 + (datarev[5]&0x0f);
  year =((datarev[6]&0xf0)>>4)*10 + (datarev[6]&0x0f);
  lcd_clear (); // clear LCD
  lcd_delay_ms(10);
  lcd_put_num(hour,0,0);
  lcd_gotoxy(2,0);
  lcd_puts(":");
  lcd_gotoxy(3,0);
  lcd_put_num(min,0,0);
  lcd_gotoxy(5,0);
  lcd_puts(":");
  lcd_gotoxy(6,0);
  lcd_put_num(sec,0,0);
  lcd_gotoxy(10,0);
  switch (day)
  {
  case (1):lcd_puts("Sun");break;
  case (2):lcd_puts("Mon");break;
  case (3):lcd_puts("Tue");break;
  case (4):lcd_puts("Wed");break;
  case (5):lcd_puts("Thu");break;
  case (6):lcd_puts("Fri");break;
  case (7):lcd_puts("Sat");break;
  }
  lcd_gotoxy(0,1);
  lcd_put_num(date,0,0);
  lcd_gotoxy(2,1);
  lcd_puts("/");
  lcd_gotoxy(3,1);
  lcd_put_num(month,0,0);
  lcd_gotoxy(5,1);
  lcd_puts("/");
  lcd_gotoxy(6,1);
  lcd_put_num(20,0,0);
  lcd_gotoxy(8,1);
  lcd_put_num(year,0,0);
  lcd_delay_ms(60);
   
  }
 }
