#include "bridge.h"

namespace Bridge {

/* TV */

bool TV::IsEnabled() const { return m_enabled; }

void TV::Enable() { m_enabled = true; }

void TV::Disable() { m_enabled = false; }

Volume TV::GetVolume() const { return m_volume; }

void TV::SetVolume(const Volume& volume) { m_volume = volume; }

Channel TV::GetChannel() const { return m_channel; }

void TV::SetChannel(const Channel& channel) { m_channel = channel; }


/* Radio */

bool Radio::IsEnabled() const {
	return m_enabled;
}

void Radio::Enable() { m_enabled = true; }

void Radio::Disable() { m_enabled = false; }

Volume Radio::GetVolume() const { return m_volume; }

void Radio::SetVolume(const Volume& volume) { m_volume = volume; }

Channel Radio::GetChannel() const { return m_channel; }

void Radio::SetChannel(const Channel& channel) { m_channel = channel; }


/* Remote */

Remote::Remote(Device& device) : m_device(device) {}

void Remote::TogglePower() {
	if (m_device.IsEnabled()) {
		m_device.Disable();
	} else {
		m_device.Enable();
	}

	std::cout << "TogglePower: enable is " << std::boolalpha << m_device.IsEnabled() << std::endl;
}

void Remote::VolumeDown() {
	m_device.SetVolume(m_device.GetVolume().Get() - 10);

	std::cout << "VolumeDown: " << m_device.GetVolume().Get() << std::endl;
}

void Remote::VolumeUp() {
	m_device.SetVolume(m_device.GetVolume().Get() + 10);

	std::cout << "VolumeUp: " << m_device.GetVolume().Get() << std::endl;
}

void Remote::ChannelDown() {
	m_device.SetChannel(m_device.GetChannel().Get() - 1);

	std::cout << "ChannelDown: " << m_device.GetChannel().Get() << std::endl;
}

void Remote::ChannelUp() {
	m_device.SetChannel(m_device.GetChannel().Get() + 1);

	std::cout << "ChannelUp: " << m_device.GetChannel().Get() << std::endl;
}

/* AdvancedRemote */

void AdvancedRemote::mute() {
	m_device.SetVolume(0);

	std::cout << "Volume muted: " << m_device.GetVolume().Get() << std::endl;
}


} // namespace Bridge
