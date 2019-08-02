#pragma once

#ifndef STATE_STATE_H
#define STATE_STATE_H

#include <iostream>
#include <memory>
#include <unordered_map>

namespace State {

enum class CameraState {
	TARGET, FREE
};

class Camera {
public:
	virtual void Move() = 0;
	virtual void Look() = 0;
};

class TargetCamera final : public Camera {
public:
	virtual void Move() override;
	virtual void Look() override;
};

class FreeCamera final : public Camera {
public:
	virtual void Move() override;
	virtual void Look() override;
};

class CameraSwitcher final {
private:
	static const CameraState DEFAULT_STATE;

private:
	CameraState m_state;
	std::unordered_map<CameraState, std::shared_ptr<Camera>> m_cameras {
		{ CameraState::TARGET, std::shared_ptr<Camera> { new TargetCamera{} } },
		{ CameraState::FREE, std::shared_ptr<Camera> { new FreeCamera{} } },
	};

public:
	CameraSwitcher();
	explicit CameraSwitcher(const CameraState& state);

	CameraState GetState() const;
	const std::shared_ptr<Camera> GetCamera() const;

	void Switch();
};

} // namespace State

#endif // !STATE_STATE_H
