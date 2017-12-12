/*
 * Arduino Spectrum Analizer
 * 
 * learnelectronics
 * 27 April 2017
 * black magic stolen from CBM80Amiga
 * 
 * www.youtube.com/c/learnelectronics
 * arduino1069@gmail.com
 * 
 * Fix_FFT library available @ https://github.com/kosme/arduinoFFT
 */


#include "fix_fft.h"                                  //library to perfom the Fast Fourier Transform

char im[128], data[128];                              //variables for the FFT
int i = 0, val;                                       //counters

void setup()
{
  Serial.begin(115200);                                 //serial comms for debuging

  analogReference(DEFAULT);                           // Use default (5v) aref voltage.
}

void loop()
{
  int min=0, max=710;                                //set minumum & maximum ADC values
  for (i = 0; i < 128; i++) {                         //take 128 samples
    val = analogRead(A0);                             //get audio from Analog 0
    data[i] = val / 4 - 128;                          //each element of array is val/4-128
    im[i] = 0;                                        //
    if(val>max) max=val;                              //capture maximum level
    if(val<min) min=val;                              //capture minimum level
  };
    
  fix_fft(data, im, 7, 0);                            //perform the FFT on data
  
  for (i = 1; i < 64; i++) {                          // In the current design, 60Hz and noise
    int dat = sqrt(data[i] * data[i] + im[i] * im[i]);//filter out noise and hum
    Serial.print(dat); // draw bar graphics for freqs above 500Hz to buffer
    Serial.print("  ");
  }
  Serial.println();                                                
};

