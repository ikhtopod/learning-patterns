#include "run.h"

#include "observer.h"


namespace Observer {

void Run() {
	Event startEvent = Event::OFF;

	Monitor monitor { startEvent };
	LogSystem logSystem { startEvent };

	AlarmManager alarm { startEvent };
	alarm.Attach(monitor);
	alarm.Attach(logSystem);

	monitor.ShowState();
	logSystem.ShowLog();

	alarm.SetEvent(Event::ON);
	monitor.ShowState();
	logSystem.ShowLog();

	alarm.Detach(monitor);

	alarm.SetEvent(Event::ALARM);
	logSystem.ShowLog();
}


} // namespace Observer
