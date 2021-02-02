
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

int neoPixelPin = 10;
int numPixels = 64;
int brightness = 5; 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

int r=0; int g=0; int b=0;
int i;
int dt=500;
int r0; int r1;
int r2; int r3;
int r4; int r5;
int r6; int r7;


void setup() {

}//***********End Setup*************



void loop(){//**********LOOP*********

// IMAGE 1
//space invader arms down
clear_matrix(); r=255;
r0 = 36;
r1 = 36;
r2 = 126;
r3 = 153;
r4 = 153;
r5 = 255;
r6 = 165;
r7 = 36;
image();

//Set Eyes in yellow
r=255;g=255;
r3 = 34;
image();delay(dt);


// IMAGE2

//space invader arms up
clear_matrix(); r=255;
r0 = 36;
r1 = 165;
r2 = 255;
r3 = 153;
r4 = 153;
r5 = 255;
r6 = 36;
r7 = 66;
image();



//Set Eyes in yellow
r=255;g=255;
r3 = 68;
image();delay(dt);

}//********end loop******







//*****************Subs******************
void image(){
      for(int i = 0; i < 8; i++){
         if (bitRead(r0,i)==1) strip.setPixelColor(i,r,g,b);
         if (bitRead(r1,i)==1) strip.setPixelColor(i+8,r,g,b);
         if (bitRead(r2,i)==1) strip.setPixelColor(i+16,r,g,b);
         if (bitRead(r3,i)==1) strip.setPixelColor(i+24,r,g,b);
         if (bitRead(r4,i)==1) strip.setPixelColor(i+32,r,g,b);
         if (bitRead(r5,i)==1) strip.setPixelColor(i+40,r,g,b);
         if (bitRead(r6,i)==1) strip.setPixelColor(i+48,r,g,b);
         if (bitRead(r7,i)==1) strip.setPixelColor(i+56,r,g,b);
      }//close for i

strip.setBrightness(brightness);  
strip.show();

r0 = 0;r1 = 0;r2 = 0;r3 = 0;r4 = 0;r5 = 0;r6 = 0;r7 = 0;
r=0;g=0;b=0;
}  //********************************************



void clear_matrix(){
r=0; g=0; b=0;
strip.begin();  // initialize the strip
strip.clear();  // Initialize all pixels to 'off'
strip.show();   // make sure it is visible
}
//****************End SUB*****************
