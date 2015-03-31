/*
  _____        _____            _____ _    _ _    _ _______ ______     
 |  __ \ /\   |  __ \     /\   / ____| |  | | |  | |__   __|  ____|    
 | |__) /  \  | |__) |   /  \ | |    | |__| | |  | |  | |  | |__       
 |  ___/ /\ \ |  _  /   / /\ \| |    |  __  | |  | |  | |  |  __|      
 | |  / ____ \| | \ \  / ____ \ |____| |  | | |__| |  | |  | |____     
 |_|_/_/ ___\_\_|__\_\/_/    \_\_____|_| _|_|\____/___|_|_ |______|___ 
 |  __ \|  ____|  __ \| |    / __ \ \   / /  \/  |  ____| \ | |__   __|
 | |  | | |__  | |__) | |   | |  | \ \_/ /| \  / | |__  |  \| |  | |   
 | |  | |  __| |  ___/| |   | |  | |\   / | |\/| |  __| | . ` |  | |   
 | |__| | |____| |    | |___| |__| | | |  | |  | | |____| |\  |  | |   
 |_____/|______|_|    |______\____/  |_|  |_|  |_|______|_| \_|  |_|   
 
 Developed by U. Jamil for Leslie's Engineering 2 Bottle Rockets 2014-15
 
 */
#include <Servo.h>
Servo servo1;
int state = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(5);
  servo1.write(0);
  delay(500);
}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
  }
  if (state == '1') { // if the state is 1 the parachute will deploy
    Serial.println("DEPLOYMENT PRIMED");
    delay(500);
    Serial.println("Initiating Countdown");
    delay(2000);
    Serial.println("5");
    delay(1000);
    Serial.println("4");
    delay(1000);
    Serial.println("3");
    delay(1000);
    Serial.println("2");
    delay(1000);
    Serial.println("1");
    delay(1000); // insert time in millis until deployment
    Serial.println("FIRE!!!");
    delay(4500);
    servo1.write(120); // move servo to 120deg
    delay(100);
    servo1.detach(); // keep servo in position
    return;
  }
}
