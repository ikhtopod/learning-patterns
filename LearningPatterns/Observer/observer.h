#pragma once

#ifndef OBSERVER_OBSERVER_H
#define OBSERVER_OBSERVER_H

#include <iostream>
#include <set>

namespace Observer {

enum class Event : int8_t {
	ON = -1, OFF, ALARM
};

class EventListener;

class EventManager {
protected:
	std::set<EventListener*> m_listeners {};

public:
	virtual void Attach(EventListener& listener);
	virtual void Detach(EventListener& listener);

	virtual void Notify() = 0;
};

struct ResponseEventManager {
	Event event;
	explicit ResponseEventManager(const Event& event);
};

class EventListener {
protected:
	Event m_currentEvent;

public:
	explicit EventListener(const Event& event);

	virtual void Update(const ResponseEventManager& response) = 0;
};


class AlarmManager : public EventManager {
private:
	Event m_event;

public:
	explicit AlarmManager(const Event& event);

	Event GetEvent() const;
	void SetEvent(const Event& event);

	virtual void Notify() override;
};

class Monitor : public EventListener {
public:
	using EventListener::EventListener;

	virtual void Update(const ResponseEventManager& response) override;

	void ShowState() const;
};

class LogSystem : public EventListener {
public:
	using EventListener::EventListener;

	virtual void Update(const ResponseEventManager& response) override;

	void ShowLog() const;
};

} // namespace Observer

#endif // !OBSERVER_OBSERVER_H
