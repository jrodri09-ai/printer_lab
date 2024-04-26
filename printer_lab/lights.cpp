#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <colors.h>


bool prev_button_state;
bool cur_button_state;
bool lights_on;


const int PIXELPIN = D3;
const int PIXELCOUNT = 30;
const int BUTTONPIN = D2;


Adafruit_NeoPixel pixel(PIXELCOUNT,PIXELPIN,NEO_GRB + NEO_KHZ800 );


void lights_setup()
{

    pixel.begin();
    pixel.show();
    pixel.setBrightness(5); 
    pinMode(D2, INPUT_PULLUP);
    lights_on = false;
    prev_button_state = false;
    cur_button_state = digitalRead(BUTTONPIN);

}

void lights_loop()
{
  cur_button_state = digitalRead(BUTTONPIN);

  Serial.printf("lights state %i\n", lights_on);
  // Serial.printf("prev state %i\n", prev_button_state);

  //if button is pressed and it wasn't before
  if ((cur_button_state == LOW) && (prev_button_state!= cur_button_state)) 
  {
    Serial.printf("Button is pressed \n");

    // keep track of button press state
    prev_button_state=cur_button_state;

    if (lights_on == true)
      lights_on = false;

    else if (lights_on == false)
      lights_on = true;
  }
  
    else if(cur_button_state == HIGH && (prev_button_state!=cur_button_state))
    {
       Serial.printf("Button is released \n");
        prev_button_state=cur_button_state;
    }

    if(lights_on==true)
    {
      for (int i =0; i< PIXELCOUNT;i++) {
        pixel.setPixelColor(i,255,255,255);
      }
    }
    else if(lights_on==false)
    {  
      pixel.clear();
    }
      
    pixel.show();
}