#include "lights.h"



void setup() {
  Serial.begin(9600);
  
  lights_setup();

}

void loop() {
 lights_loop();
}