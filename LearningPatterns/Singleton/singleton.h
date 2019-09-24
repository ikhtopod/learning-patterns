#pragma once

#ifndef SINGLETON_SINGLETON_H
#define SINGLETON_SINGLETON_H

#include <string>

namespace Singleton {

template <typename T>
class SingletonBase {
private:
	static T* m_instance;

public:
	SingletonBase() {
		if (m_instance == nullptr) {
			m_instance = static_cast<T*>(this);
		}
	}

	~SingletonBase() {
		m_instance = nullptr;
	}

	static T* GetInstance() {
		return m_instance;
	}
};

template <typename T>
T* SingletonBase<T>::m_instance = nullptr;


class PlayerManager : public SingletonBase<PlayerManager> {
private:
	std::string m_name { "noname" };
	bool m_canMoving = true;
	float m_currentSpeed = 7.0f;

public:
	PlayerManager() : SingletonBase<PlayerManager>() {}

public:
	std::string GetName() const {
		return m_name;
	}

	bool CanMoving() const {
		return m_canMoving;
	}

	float CurrentSpeed() const {
		return m_currentSpeed;
	}
};

} // namespace Singleton

#endif // !SINGLETON_SINGLETON_H
