// Name: Giulia Piombo
// Date: June, 2021
// Subject: Read frequencies from a microphone and display on the LCD display
//          The microphone is not reading the frequencies properly 

#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

#include "arduinoFFT.h"
#define SAMPLES 128             //SAMPLES-pt FFT. Must be a base 2 number. Max 128 for Arduino Uno.
#define SAMPLING_FREQUENCY 2048 //Ts = Based on Nyquist, must be 2 times the highest expected frequency.
 
arduinoFFT FFT = arduinoFFT();
 
unsigned int samplingPeriod;
unsigned long microSeconds;
 
double vReal[SAMPLES]; //create vector of size SAMPLES to hold real values
double vImag[SAMPLES]; //create vector of size SAMPLES to hold imaginary values
 
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(1,0);
  Serial.begin(115200); //Baud rate for the Serial Monitor
  samplingPeriod = round(100000*(1.0/SAMPLING_FREQUENCY)); //Period in microseconds 
}

// recieving
void loop() {
  //lcd.print( recieve() );
  Serial.println((unsigned)receive());
}

unsigned long start = 500000;

char receive() {
  char c = (char)0;
  for (int i = 0; i < 8; i++) {
    //delay(500);
    while(micros()<start) {
      
    }
    start += 1500000;
    for(int j=0; j < SAMPLES; j++)
    {
      microSeconds = micros();    //Returns the number of microseconds since the Arduino board began running the current script. 
  
      vReal[j] = analogRead(0); //Reads the value from analog pin 0 (A0), quantize it and save it as a real term.
      vImag[j] = 0; //Makes imaginary term 0 always

      /*remaining wait time between samples if necessary*/
      while(micros() < (microSeconds + samplingPeriod))
      {
        //do nothing
      }
    }
    //delay(500);
    /*Perform FFT on samples*/
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
  
    /*Find peak frequency and print peak*/
    double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
    if (peak > 600) {
      //Serial.println(peak);
      c >>= 1;
      if (peak > 900) { // check for sound for 2000hz & peak gets the loudest frequency
        c |= 0b10000000;
        Serial.println("1");
      }
      else {
        Serial.println("0");  
        }
    } else  {
      i--;
    }
  }
  return c;
}
