




#include <Adafruit_NeoPixel.h>
#define pin 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, pin, NEO_GRB + NEO_KHZ800);

void setup() 
  {
//  Serial.begin(9600);
  strip.begin();
   strip.setPixelColor(0,255,255,255);
  strip.show();   
  }

void loop() 
  {
  //show all RED
  for(byte i=0;i<8;++i) {
      strip.setPixelColor(i,255,0,0);
      
      strip.show();  
      delay(100);
  }

  //now clear red out one pixel at a time
  for(byte i=8;i>0;--i) {
      strip.setPixelColor(i,0,0,0);
      strip.show();  
      delay(100);
  }
strip.clear();
strip.show();

  //now show a random color
  for(byte i=0;i<8;++i) { 
     byte f=random(1,254);
      strip.setPixelColor(i,Wheel(f));
      strip.show();  
      delay(100);
  }
  //and again
  for(byte i=8;i>0;--i) {
      byte f=random(1,254);
      strip.setPixelColor(i,Wheel(f));
      strip.show();  
      delay(100);
  }
  
strip.clear();
strip.show();

 }




  
/*

    
unsigned long t = 0;
   t=5;
    
    for(byte b = 0;b<30;++b)
      {
       byte c = random(0,255); 
    
        for(byte pix = 0+b;pix < 60-b;++pix)
          {
       
          strip.setPixelColor(pix,Wheel(c));
          strip.show();
      delay(t);  
     
          strip.setPixelColor(pix,0,0,0);
      delay(t);  
          }
      
              for(byte pix = 60-b;pix > 0+b;--pix)
          {
       //byte c = random(0,255);
          strip.setPixelColor(pix,Wheel(c));
          strip.show();
      delay(t);  
     
          strip.setPixelColor(pix,0,0,0);
      delay(t);  
          }
    /*  
      byte f = random(0,60);
      for(byte p = 0;p<255;++p){
        strip.setPixelColor(f,Wheel(p));
        strip.show();
        delay(t);
      }
      
      }
      
   }

*/

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
