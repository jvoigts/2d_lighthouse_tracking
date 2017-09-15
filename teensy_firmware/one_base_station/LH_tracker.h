/*
  LH_tracker.h - Simple Library for valve lighthouse tracking.
  Sept 2017 jvoigts@mit.edu
  see http://jvoigts.scripts.mit.edu/blog/?p=1449 for more docu
*/
#ifndef LH_tracker_h
#define LH_tracker_h

#include "Arduino.h"
#include "elapsedCycles.h"

class LH_tracker
{
  public:
    LH_tracker(int pin);
    void check();
    unsigned int y;
	unsigned int x;
	int fresh_sync_pulse;
	int fresh_y_pulse;
	int fresh_x_pulse;
  elapsedCycles _main_timer;
  private:
    int _pin;
    
	elapsedCycles _blip_timer;
	int _xy; // what sweep are we on?
	int _lasttrs;
	unsigned long _blip_duration;
	unsigned long _main_blip_dur;	

};

#endif