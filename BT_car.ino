char val;

#define M1F 2  //left motor >>      IN1      
#define M1R 4  //left motor <<      IN2
#define M1S 3  //left motor speed   ENA
#define M2F 8  //Right motor >>     IN3
#define M2R 7  //Right motor <<     IN4
#define M2S 5  //Right motor speed  ENB 

void setup() {
  pinMode(M1F, OUTPUT);
  pinMode(M1R, OUTPUT);
  pinMode(M1S, OUTPUT);
  pinMode(M2F, OUTPUT);
  pinMode(M2R, OUTPUT);
  pinMode(M2S, OUTPUT);
  
  Serial.begin(9600);
  motordrive(0,0);
}

void loop() {

    if(Serial.available()){
    val= Serial.read();
    Serial.println(val);  
    }
    
    if (val=='F'){ //forward
      motordrive(255,255);
    }
    if (val=='B'){//reverse
      motordrive(-255,-255);
    }
    if (val=='L'){//left
      motordrive(0,255);
    }
    if (val=='R'){//right
      motordrive(255,0);
    }
    if (val=='S'){//stop
      motordrive(0,0);
    }
}  


void motordrive(int m1, int m2){
  if(m1>0){
    if (m1 > 255){
      m1=255;
    }
    digitalWrite(M1F,HIGH);
    digitalWrite(M1R,LOW);
    analogWrite(M1S,m1);
    //Left m >>
  }else if (m1<0){
    if (m1< -255){
      m1= -255;
    }
    digitalWrite(M1F,LOW);
    digitalWrite(M1R,HIGH);
    analogWrite(M1S,m1*(-1));
    //Left m <<
  }else if (m1==0){
    digitalWrite(M1F,LOW);
    digitalWrite(M1R,LOW);
    analogWrite(M1S,m1);
  }
  
  if(m2>0){
    if (m2 > 255){
      m1=255;
    }
    digitalWrite(M2F,HIGH);
    digitalWrite(M2R,LOW);
    analogWrite(M2S,m2);
    //Right m >>
  }else if (m2<0){
    if (m2< -255){
      m2= -255;
    }
    digitalWrite(M2F,LOW);
    digitalWrite(M2R,HIGH);
    analogWrite(M2S,m2*(-1));
    //Right m <<
  }else if (m2==0) {
    digitalWrite(M2F,LOW);
    digitalWrite(M2R,LOW);
    analogWrite(M2S,m2);
  }
}
