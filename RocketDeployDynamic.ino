#include <Servo.h>

#define SERVO 3
Servo servo;

#define LED 13
#define HOLD 3000
#define ANGLE 90
#define WAITCYCLES 1000

int pos = 0;
int state = 0;
long chuteDelay = 3500;

void setup() 
{ 
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

  servo.attach(SERVO); 
  servo.write(0);
} 

char State[256] = {};
int StateIndex = 0;
int ReceiveCounter = 0;
void loop() 
{ 
  while (Serial.available() > 0)
  {
    int val = Serial.read();
    State[StateIndex++] = val;
    ReceiveCounter = 0;
  }

  if (Serial.available() <= 0 && StateIndex > 0 && ReceiveCounter > WAITCYCLES)
  {  
    int num = atoi(State);
    if (num == 1) {
      digitalWrite(LED, HIGH);
      Serial.println("DEPLOYMENT PRIMED");
      Serial.println("Rocket Launch in T-minus")
      for (int i = 5; i > 0; --i)
      {
        delay(1000);
        Serial.println(i);
      }
      Serial.println("Deploying Parachute in...");
      long l = chuteDelay;
      for (l; l >= 1000; l -= 1000)
      {
        delay(1000);
        Serial.println(l / 1000);
      }
      delay(l);
      
      servo.write(ANGLE);
      Serial.println("Chute deployed!");
      delay(HOLD/2);
      servo.detach();
      delay(HOLD/2);
      servo.attach(SERVO);
      digitalWrite(LED, LOW);


      state = 0;
    }
    else if (num != 0)
    {
      chuteDelay = atol(State);
      Serial.print("==> Setting delay to ");
      Serial.print(chuteDelay);
      Serial.print(".\n");
    }
    memset(State, 0, 256);
    StateIndex = 0;
  }

  ++ReceiveCounter;
} 
