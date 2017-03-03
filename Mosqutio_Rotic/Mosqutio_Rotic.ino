int B_ST_L;
int B_ST_F;
int B_ST_R;
int val[3]={0,0,0};


#include<Ultrasonic.h>
#include <SPI.h>
#include <Wire.h>
#include <TimeLib.h>
#include <MsTimer2.h>

#include "Mega_Pin_out.h"
#include "pitches.h"
#include "Oled_print.h"
#include "Motor_Motion.h"
#include "Mode.h"



void setup() {
 Mega_pinMode();
 Serial.begin(9600); 
 Serial3.begin(9600);
 display.begin(SSD1306_SWITCHCAPVCC);
 Display_Page_Start();
 Buzzer_Compose();
 Set_Time();
 order='9';
}

void loop() {
     switch(order){ 
      case('0'):
        Mode_OFF(); 
        break;
      case('1'):
        Mode_Auto_R();
        break;
      case('2'):
        Mode_Auto_L();
        break;
      case('3'):
        Mode_Manual();
        break;
      case('4'):
        Mode_Data_Print();
        break;
      case('9'):
        Mode_Select();
        break;      
      default:
         order='9'; 
         break;
         }  
}    


