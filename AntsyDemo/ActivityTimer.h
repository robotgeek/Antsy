#ifndef ACTIVITYTIMER_H
#define ACTIVITYTIMER_H

#include <Arduino.h>

class ActivityTimer
{
	public:
		ActivityTimer() {}
		void setTimeoutThreshold( unsigned long seconds );
		void updateActivityTimer();
		bool checkActivityTimer();
	private:
		unsigned long _activitiyTimeoutThreshold = 10000; //10 seconds
		unsigned long _lastActivityTimestamp = millis();
};


extern ActivityTimer myActivityTimer;

#endif