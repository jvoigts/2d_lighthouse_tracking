/*
   Simple 2d valve lighthouse tracking with one base station on teensy
   tested on teensy 3.6
  Sept 2017 jvoigts@mit.edu
  see http://jvoigts.scripts.mit.edu/blog/?p=1449 for more docu
*/


#include "elapsedCycles.h"
#include "LH_tracker.h"

const int ledPin = 13;

const int enSwitchPin = 9;
const int syncOutPin = 10;
int syncState=0;


unsigned long blip_duration;
unsigned long main_blip_dur;

unsigned int y_a; // 2 trackers
unsigned int x_a;
unsigned int y_b;
unsigned int x_b;


LH_tracker trackA(12);
LH_tracker trackB(11);

int xy; // what sweep are we on?
int lasttrs;

elapsedCycles main_timer;
elapsedCycles blip_timer;


void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(syncOutPin, OUTPUT);
  
  Serial.begin(115200);
}


void loop() {

trackA.check();
trackB.check();

if (enSwitchPin == HIGH) {}
  if (trackA.fresh_sync_pulse==1) {
    Serial.println(trackA.x);
    Serial.println(trackA.y);
    Serial.println(trackB.x);
    Serial.println(trackB.y);
    Serial.println(-1);

    if ( syncState==0) {
        syncState=1;
        digitalWrite(syncOutPin,HIGH)
      }else {
        syncState=0;
        digitalWrite(syncOutPin,LOW)
      }    
    }

  }
}




}

