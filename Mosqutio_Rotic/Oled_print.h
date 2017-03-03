#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>



Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


unsigned char Rotic_logo[]={
  B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000

  };

unsigned char BlueTooth_Logo[]{
  B0011000,
  B1010110,
  B0110011,
  B0011100,
  B0110011,
  B1010110,
  B0011000
  };

void printDigits(int digits){
   // utility function for digital clock display: prints preceding colon and leading 0
  
   if(digits < 10){
     display.print('0');
     display.print(digits);
   }else
     display.print(digits);
}

void write_time(int Hour, int Minute, int Second){
   String Second_mark;
   if(Second%2 == 0) //초 나타낼때 깜빡임
      Second_mark = ":";
   else
      Second_mark = " ";
   
   display.setTextSize(1);
   display.setCursor(35,0); //픽셀단위
   display.setTextColor(BLACK,WHITE);
   printDigits(Hour);
   display.print(Second_mark);
   printDigits(Minute);  
}

void write_date(int Year, int Month, int Day){
   display.setTextSize(1);
   display.setCursor(0,0); //픽셀단위
   display.setTextColor(BLACK,WHITE);
   printDigits(Month);
   display.print("/");
   printDigits(Day);  
}  
  
void Display_Page_Start(){
  display.clearDisplay();
  display.drawBitmap(10,10,Rotic_logo,16,16,WHITE);
  display.setCursor(30,10);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("Robotics");
  display.display();
  
}

void Display_Page_OFF(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE);
  display.println("                     ");
  display.drawBitmap(115,0,BlueTooth_Logo,7,7,BLACK);
  display.setCursor(0,16);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("M: OFF");
  write_date(year(),month(),day());
  write_time(hour(), minute(), second());
  display.display(); 
  }

  
  
   
  
void Display_Main_M1(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE);
  display.println("                     ");
  display.drawBitmap(115,0,BlueTooth_Logo,7,7,BLACK);
  display.setCursor(0,16);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("M: AUTO(R)");
  write_date(year(),month(),day());
  write_time(hour(), minute(), second());
  display.display();  
}

void Display_Main_M2(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE);
  display.println("                     ");
  display.drawBitmap(115,0,BlueTooth_Logo,7,7,BLACK);
  display.setCursor(0,16);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("M: AUTO(L)");
  write_date(year(),month(),day());
  write_time(hour(), minute(), second());
  display.display();
 }

void Display_Main_Select(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE);
  display.println("                     ");
  display.drawBitmap(115,0,BlueTooth_Logo,7,7,BLACK);
  display.setCursor(0,16);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("M: Select");
  write_date(year(),month(),day());
  write_time(hour(), minute(), second());
  display.display();
  
  
}
void Display_Main_Manual(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE);
  display.println("                     ");
  display.drawBitmap(115,0,BlueTooth_Logo,7,7,BLACK);
  display.setCursor(0,16);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("M: Manual");
  write_date(year(),month(),day());
  write_time(hour(), minute(), second());
  display.display();
  
  }  

void Display_Page_Data(){
  while(1){
    if(order=='4'||order=='@'){
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    val[0]=analogRead(VB_A1);
    val[1]=analogRead(VB_A2);
    val[2]=analogRead(VB_A3);
    display.print("VB_A1:");
    display.print(val[0],DEC);
    display.print("   VB_A2:");
    display.println(val[1],DEC);
    display.print("VB_A3:");
    display.print(val[2],DEC);
    display.print("   R:");
    display.print(ultra_R.Ranging(CM));
    display.println("cm");
    display.print("FR:");
    display.print(ultra_FR.Ranging(CM));
    display.print("cm");
    display.print("   F:");
    display.print(ultra_F.Ranging(CM));
    display.println("cm");
    display.print("FL:");
    display.print(ultra_FL.Ranging(CM));
    display.print("cm");
    display.print("   L:");
    display.print(ultra_L.Ranging(CM));
    display.println("cm");
    display.display();
    }
    if(order=='!'){
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("B_L:");
    B_ST_L=digitalRead(Bumper_L);
    display.print(!B_ST_L);
    display.print("   B_F:");
    B_ST_F=digitalRead(Bumper_F);
    display.print(!B_ST_F);
    display.print("   B_R:");
    B_ST_R=digitalRead(Bumper_R);
    display.println(!B_ST_R);
    display.display();
    delay(100);
    }
    if (Serial3.available()){
    order=Serial3.read();
        if(order=='9'||order=='0'||order=='1'||order=='2'||order=='3'){
        break;
        }
    }
   }
}



void Display_Time_Set(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE);
  display.println("                     ");
  display.drawBitmap(115,0,BlueTooth_Logo,7,7,BLACK);
  display.setCursor(0,16);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("SET TIME");
  write_date(year(),month(),day());
  write_time(hour(), minute(), second());
  display.display();
  }



