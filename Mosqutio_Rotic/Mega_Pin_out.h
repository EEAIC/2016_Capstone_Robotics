#define UVLED 5

#define BUZZER 6
#define M_ENA 8
#define M_ENB 9
#define M_IN1 11
#define M_IN2 10
#define M_IN3 12
#define M_IN4 13

#define VB_A1 13
#define VB_A2 14
#define VB_A3 15

#define Bumper_R 35
#define Bumper_F 29
#define Bumper_L 23

#define VBoost 27

#define OLED_MOSI  51
#define OLED_CLK   53
#define OLED_DC    47
#define OLED_CS    45
#define OLED_RESET 49

Ultrasonic ultra_R(24,26);
Ultrasonic ultra_FR(28,30);
Ultrasonic ultra_F(36,38);
Ultrasonic ultra_FL(44,46);
Ultrasonic ultra_L(48,50);

void Mega_pinMode(){
 pinMode(UVLED, OUTPUT);
 pinMode(BUZZER, OUTPUT);
 pinMode(VBoost, OUTPUT);
 pinMode(M_IN1, OUTPUT);
 pinMode(M_IN2, OUTPUT);
 pinMode(M_IN3, OUTPUT);
 pinMode(M_IN4, OUTPUT);
 pinMode(Bumper_R, INPUT_PULLUP);
 pinMode(Bumper_F, INPUT_PULLUP);
 pinMode(Bumper_L, INPUT_PULLUP);
  
  }
char order;

