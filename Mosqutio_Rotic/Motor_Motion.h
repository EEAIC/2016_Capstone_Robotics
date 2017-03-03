void Forward(int Speed){
  digitalWrite(M_IN1, HIGH);
  digitalWrite(M_IN2, LOW);
  digitalWrite(M_IN3, HIGH);
  digitalWrite(M_IN4, LOW);
  analogWrite(M_ENA, Speed);
  analogWrite(M_ENB, Speed);
  
  }
  
void Back(int Speed){
  digitalWrite(M_IN1, LOW);
  digitalWrite(M_IN2, HIGH);
  digitalWrite(M_IN3, LOW);
  digitalWrite(M_IN4, HIGH);
  analogWrite(M_ENA, Speed);
  analogWrite(M_ENB, Speed);
  
  }

void Right(int Speed){
  digitalWrite(M_IN1, HIGH);
  digitalWrite(M_IN2, LOW);
  digitalWrite(M_IN3, LOW);
  digitalWrite(M_IN4, HIGH);
  analogWrite(M_ENA, Speed);
  analogWrite(M_ENB, Speed);
}

void Left(int Speed){
  digitalWrite(M_IN1, LOW);
  digitalWrite(M_IN2, HIGH);
  digitalWrite(M_IN3, HIGH);
  digitalWrite(M_IN4, LOW);
  analogWrite(M_ENA, Speed);
  analogWrite(M_ENB, Speed);
  }

void Forward_Right(int Speed){  
  digitalWrite(M_IN1, HIGH);
  digitalWrite(M_IN2, LOW);
  digitalWrite(M_IN3, LOW);
  digitalWrite(M_IN4, HIGH);
  analogWrite(M_ENA, Speed+50);
  analogWrite(M_ENB, Speed);
  }

void Forward_Left(int Speed){
  digitalWrite(M_IN1, LOW);
  digitalWrite(M_IN2, HIGH);
  digitalWrite(M_IN3, HIGH);
  digitalWrite(M_IN4, LOW);
  analogWrite(M_ENA, Speed);
  analogWrite(M_ENB, Speed+50);  
  }  
