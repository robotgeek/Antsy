#include "ActivityTimer.h"

ActivityTimer myActivityTimer;

void ActivityTimer::setTimeoutThreshold( unsigned long seconds )
{
	_activitiyTimeoutThreshold = seconds * 1000; //store as milliseconds
}

void ActivityTimer::updateActivityTimer()
{
	_lastActivityTimestamp = millis();
}

bool ActivityTimer::checkActivityTimer()
{
	//Returning true if we have updated activity timer within the threshold period
	//Returning false if last activity update and timeout threshold are greater than the time now
	return ( _lastActivityTimestamp + _activitiyTimeoutThreshold > millis() );
}
