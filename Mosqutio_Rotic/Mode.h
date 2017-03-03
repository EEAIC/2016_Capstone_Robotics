


void Mode_Select(){
  while(1){
  Display_Main_Select();
  Forward(0);
  digitalWrite(VBoost, HIGH);
  digitalWrite(UVLED, HIGH);
  if (Serial3.available()){
    order=Serial3.read();
      if(order=='0'||order=='1'||order=='2'||order=='3'||order=='4'||order=='9'){
      break;
      }
    }
  }
}
void Mode_OFF(){
  digitalWrite(VBoost, LOW);
  digitalWrite(UVLED, LOW);
  Forward(0);
  while(1){
    Display_Page_OFF();
    if (Serial3.available()){
     order= Serial3.read();
      break; 
    }   
  }
}

void Mode_Auto_R(){
  digitalWrite(VBoost, HIGH);
  digitalWrite(UVLED, HIGH);
   
  while(1){  
    Display_Main_M1();
    B_ST_L=digitalRead(Bumper_L);
    B_ST_F=digitalRead(Bumper_F);
    B_ST_R=digitalRead(Bumper_R);
    val[0]=analogRead(VB_A1);
    val[1]=analogRead(VB_A2);
    val[2]=analogRead(VB_A3);  
    
    /*if(val[0]>30||val[1]>30||val[2]>30){
      digitalWrite(VBoost, LOW);
      digitalWrite(UVLED, LOW);
      Forward(0);
      Buzzer_alarm();
      delay(3000);
      Back(80);
      delay(100);
      Forward(0);
      digitalWrite(VBoost, HIGH);
      digitalWrite(UVLED, HIGH);
      }*/
    if(!B_ST_L==1){
      Back(80);
      delay(200);
      Right(80);
      delay(200);
      }
     else if(!B_ST_F==1){
      Back(80);
      delay(200);
      Left(80);
      delay(300);
      }
     else if(!B_ST_R==1){
      Back(80);
      delay(200);
      Left(80);
      delay(200);
      }
     /* else if(B_ST_L==1&&B_ST_R==1&&B_ST_F==0){
      Back(80);
      delay(200);
      Left(80);
      delay(200);
      }else if(B_ST_L==0&&B_ST_R==1&&B_ST_F==1){
      Back(80);
      delay(200);
      Right(80);
      delay(200);
      }
      else if(B_ST_L==1&&B_ST_R==1&&B_ST_F==1){
      Back(80);
      delay(200);
      Right(80);
      delay(300);
      }*/
     else if(ultra_F.Ranging(CM)<=10){
      Forward(0);
      Right(80);
      delay(500);
      }
     else if(ultra_FL.Ranging(CM)<=10){
      Forward(0);
      Right(80);
      delay(100);
      }
     else if(ultra_L.Ranging(CM)<10){
      Forward(0);
      Right(80);
      }
      else if(ultra_FR.Ranging(CM)<=10){
       Forward(0);
       Left(80);
       delay(100); 
      }
      else if(ultra_R.Ranging(CM)<10){
        Forward(0);
        Left(80);
      }
      else if(Serial3.available()){
        order=Serial3.read();
         break;
      }
      else{
        Forward(80);
        delay(100);
      }
        
    }    
}  

void Mode_Auto_L(){
    while(1){  
    Display_Main_M2();
    val[0]=analogRead(VB_A1);
    val[1]=analogRead(VB_A2);
    val[2]=analogRead(VB_A3);
    B_ST_L=digitalRead(Bumper_L);
    B_ST_F=digitalRead(Bumper_F);
    B_ST_R=digitalRead(Bumper_R);
    /*if(val[0]>30||val[1]>30||val[2]>30){
      digitalWrite(VBoost, LOW);
      digitalWrite(UVLED, LOW);
      Forward(0);
      Buzzer_alarm();
      delay(3000);
      digitalWrite(VBoost, HIGH);
      digitalWrite(UVLED, HIGH);
      }*/
     if(!B_ST_L==1){
      Back(50);
      Forward_Right(50);
      delay(200);
      Left(50);
      delay(200);
      }
     else if(!B_ST_F==1){
      Back(50);
      Forward_Left(50);
      delay(200);
      Right(50);
      delay(200);
      }
     else if(!B_ST_R==1){
      Back(50);
      Forward_Left(50);
      delay(200);
      Right(50);
      delay(200);
      }
     else if(ultra_F.Ranging(CM)<=10){
      Forward(0);
      Left(50);
      delay(300);
      }
     else if(ultra_FL.Ranging(CM)<=10){
      Forward(0);
      Right(50);
      delay(100);
      }
     else if(ultra_L.Ranging(CM)<10){
      Forward(0);
      Right(50);
      delay(100);
      }
      else if(ultra_FR.Ranging(CM)<=10){
       Forward(0);
       Left(50);
       delay(100); 
      }
      else if(ultra_R.Ranging(CM)<10){
        Forward(0);
        Left(50);
        delay(100);
      }
      else if(ultra_F.Ranging(CM)<=10){
        Right(50);
        delay(100);
      }
      else if(Serial3.available()){
        order=Serial3.read();
         break;
      }
      else{
        Forward(100);
        delay(100);
      }
        
    }    

    
}

void Mode_Manual(){
  digitalWrite(VBoost, HIGH);
  digitalWrite(UVLED, HIGH);
  Forward(0);
  while(1){
    Display_Main_Manual();   
         if(Serial3.available()){
          order=Serial3.read();
          if(order=='9'||order=='0'||order=='1'||order=='2'||order=='3'||order=='4'){
            break;
          }
            switch(order){
            case('@'):
              Forward(200);
              delay(20);
              Forward(0);
              order='.';
              break;
            case('!'):
              Back(200);
              delay(20);
              Forward(0);
              order='.';
              break;
            case('<'):
              Left(200);
              delay(20);
              Forward(0);
              order='.';
              break;
            case('>'):
              Right(200);
              delay(20);
              Forward(0);
              order='.';
              break;
          }
         }           
   }
}

void Mode_Data_Print(){
  while(1){
  Display_Page_Data();
  
  break;
  }
}

void Set_Time(){
  int Time[18];
 while(1){ 
    Display_Time_Set();
      if(Serial3.available()){
        for(int i=0;i<=17;i++){
        Time[i]=Serial3.read();
        Time[i]-=48;
        delay(1);
        }
         
      int H=10*Time[11]+Time[12];
      int Min=10*Time[14]+Time[15];
      int S=10*Time[17]+Time[18];
      int Mon=10*Time[0]+Time[1];
      int D=10*Time[3]+Time[4];
      int Y=1000*Time[6]+100*Time[7]+10*Time[8]+Time[9];
      setTime(H,Min,S,D,Mon,Y);
      order=9;
      break;
      }
    }
}


