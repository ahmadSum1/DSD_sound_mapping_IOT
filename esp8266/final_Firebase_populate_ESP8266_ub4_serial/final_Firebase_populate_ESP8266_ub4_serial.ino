//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.
/*
 * adopted from the FireBase arduino library example to fit my project 
 * titled "IoT Based Real Time Noise Mapping System for Urban Sound Pollution Study"
 * Sakib Ahmed @ahmadSum1
 * 28-nov-2017

*/

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run
#define FIREBASE_HOST "iot-noise-level-dsd.firebaseio.com"
#define FIREBASE_AUTH "VCjLtgWIOm9R3DgOdO2FJ3MyBhcCLBSoqdgIdxaS"
#define WIFI_SSID "z5skb"
#define WIFI_PASSWORD "1234567809"
#define UB4_lat "23.78074"
#define UB4_lng "90.4076021"
String name = "Sensor_UB4";

long n = 0;

int LED = 2;   //builtin blue led
String data = "";
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  //randomSeed(analogRead(A0)); // randomSeed() will shuffle the random function on  A0


  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  init_firebase();
}

void loop() {
   if(Serial.available()){
      while (Serial.available() > 0){
        char inByte = Serial.read();
        data.concat(inByte);
    //    Serial.write(inByte);
      }
      Serial.print(data);
      fireBaseUp(data.toFloat());
      data = "";
      
    } 

  
}

///////////////functions///////////////////////
 void init_firebase(){
  
  // set centre value
  Firebase.setString(name+"/center/lat", UB4_lat);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(500);
  Firebase.setString(name+"/center/lng", UB4_lng);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(500); 
  
  // update counter at startup 
  Serial.print("count: ");
  Serial.println(n=(int)Firebase.getInt(name+"/count"));
  delay(1000);

}

void fireBaseUp(float db){
  
    // increment counter value
  Firebase.setInt(name+"/count", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(500);
  
   //set value
//   int r=random(35, 55);
  Firebase.setFloat(name+"/currentNoise", db);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(500);
  // append a new value to /fakelogs
  Firebase.pushFloat(name+"/log/", db);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }


  delay(1000);
  digitalWrite(LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delayMicroseconds(200);                      // Wait for a second
  digitalWrite(LED, HIGH);  // Turn the LED off by making the voltage HIGH
  
  }
