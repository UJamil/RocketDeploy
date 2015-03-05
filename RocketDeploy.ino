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
 
 Developed by U. Jamil and A. Chronister for Leslie's Engineering 2 Bottle Rockets 2014-15
 
 */
#include <Servo.h>

#define SERVO 5
Servo servo;

int state = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO);
  servo.write(0);
  delay(500);
}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
  }
  if (state == '1') { // if the state is 1 the parachute will deploy
    Serial.println("DEPLOYMENT PRIMED");
    delay(2000); // insert time in millis until deployment
    servo.write(120); // move servo to 120deg
    delay(100);
    servo.detach(); // keep servo in position
  }
}
