/*
  LH_tracker.cpp - Simple Library for valve lighthouse tracking.
  Sept 2017 jvoigts@mit.edu
  see http://jvoigts.scripts.mit.edu/blog/?p=1449 for more docu
*/

#include "Arduino.h"
#include "LH_tracker.h"

LH_tracker::LH_tracker(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}

void LH_tracker::check()
{
    fresh_sync_pulse=0;
    fresh_x_pulse=0;
    fresh_y_pulse=0;

  if (digitalRead(_pin)) { // start counting blip length
    if (_lasttrs == 0) {
      _blip_timer = 0;
      _lasttrs = 1;
    }
  
  } else {
    if (_lasttrs == 1) {  // end of blip
      _lasttrs = 0;

      _blip_duration = _blip_timer;

      if (_blip_duration < 6000) { // x/y pulse

        if (_xy == 1)
        {
          //Serial.println(main_timer + (blip_timer / 2));
          x=_main_timer + (_blip_timer / 2);
          fresh_x_pulse=1;
        } else {
          y=_main_timer + (_blip_timer / 2);
          fresh_y_pulse=1;
          // Serial.println(main_timer);
          //Serial.write(main_timer);
        };

      } else { // sync pulse
         
         fresh_sync_pulse=1;

        _main_timer = _blip_duration; // start counting from start of pulse
        if (_blip_duration < 14300) {
          if (_blip_duration < 12400) {
            _xy = 1;
          } else {
            _xy = 0;
          }
        } else {
          if (_blip_duration < 16100) {
            _xy = 1;
          } else {
            _xy = 0;
          }
        }


      }

    }
  }

}
