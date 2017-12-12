
const int sampleWindow = 50;                              // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
float cal_min = 25;
float cal_max = 80;
int mic_min = 0;
int mic_max = 710;  //grove sensor arduino

void setup() 
{
   Serial.begin(9600);                                    //Serial comms for debugging
 }
  
void loop() 
{
   unsigned long startMillis= millis();                   // Start of sample window
   float peakToPeak = 0;                                  // peak-to-peak level
 
   unsigned int signalMax = 0;                            //minimum value
   unsigned int signalMin = 1024;                         //maximum value
 
                                                          // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);                             //get reading from microphone
      if (sample < 1024)                                  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;                           // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;                           // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;                    // max - min = peak-peak amplitude
   float db = map(peakToPeak,mic_min,mic_max,cal_min,cal_max);             //calibrate for deciBels
   Serial.print(db);                                     //write calibrated deciBels
   //Serial.println(" dB");                                  //write units

}
