#include "observer.h"

namespace Observer {

ResponseEventManager::ResponseEventManager(const Event& event)
	: event(event) {}

void Monitor::Update(const ResponseEventManager& response) {
	m_currentEvent = response.event;
}

void Monitor::ShowState() {
	std::cout << "Monitor shows ";

	switch (m_currentEvent) {
		case Event::OFF:
			std::cout << "OFF";
			break;
		case Event::ON:
			std::cout << "ON";
			break;
		case Event::ALARM:
			std::cout << "ALARM";
			break;
		default:
			break;
	}

	std::cout << std::endl;
}

void LogSystem::Update(const ResponseEventManager& response) {
	m_currentEvent = response.event;
}

void LogSystem::ShowLog() {
	std::cout << "Log: ";

	switch (m_currentEvent) {
		case Event::OFF:
			std::cout << "Alarm disabled";
			break;
		case Event::ON:
			std::cout << "Alarm enabled";
			break;
		case Event::ALARM:
			std::cout << "ALARM!!!";
			break;
		default:
			break;
	}

	std::cout << std::endl;
}

AlarmManager::AlarmManager(const Event& event) :
	m_event(event) {}

Event AlarmManager::GetEvent() const {
	return m_event;
}

void AlarmManager::SetEvent(const Event& event) {
	m_event = event;
	Notify();
}

void AlarmManager::Notify() {
	for (auto& listener : m_listeners) {
		listener->Update(ResponseEventManager { m_event });
	}
}

void EventManager::Attach(EventListener* listener) {
	m_listeners.insert(listener);
}

void EventManager::Detach(EventListener* listener) {
	m_listeners.erase(m_listeners.find(listener));
}


EventListener::EventListener(const Event& event) :
	m_currentEvent(event) {}

} // namespace Observer
