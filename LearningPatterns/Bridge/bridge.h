#pragma once

#ifndef BRIDGE_BRIDGE_H
#define BRIDGE_BRIDGE_H

#include <cstdint>
#include <iostream>
#include <iomanip>

namespace Bridge {


template <class T>
class Alterable {
protected:
	T m_value;

public:
	Alterable() : Alterable(0) {}
	Alterable(const T& value) : m_value(value) {}

	virtual T Get() { return m_value; }
	virtual void Set(const T& value) { m_value = value; }
};

class Channel : public Alterable<uint32_t> {
public:
	using Alterable::Alterable;
};

class Volume : public Alterable <uint16_t> {
public:
	using Alterable::Alterable;
};


class Device { // interface of implementation
protected:
	bool m_enabled = false;
	Volume m_volume { 0 };
	Channel m_channel { 0 };

public:
	virtual bool IsEnabled() const = 0;
	virtual void Enable() = 0;
	virtual void Disable() = 0;
	virtual Volume GetVolume() const = 0;
	virtual void SetVolume(const Volume& volume) = 0;
	virtual Channel GetChannel() const = 0;
	virtual void SetChannel(const Channel& channel) = 0;
};

class TV : public Device {
public:
	virtual bool IsEnabled() const override;
	virtual void Enable() override;
	virtual void Disable() override;
	virtual Volume GetVolume() const override;
	virtual void SetVolume(const Volume& volume) override;
	virtual Channel GetChannel() const override;
	virtual void SetChannel(const Channel& channel) override;

};

class Radio : public Device {
public:
	virtual bool IsEnabled() const override;
	virtual void Enable() override;
	virtual void Disable() override;
	virtual Volume GetVolume() const override;
	virtual void SetVolume(const Volume& volume) override;
	virtual Channel GetChannel() const override;
	virtual void SetChannel(const Channel& channel) override;
};



class Remote { // Abstract
protected:
	Device& m_device;

public:
	explicit Remote(Device& device);

	virtual void TogglePower();
	virtual void VolumeDown();
	virtual void VolumeUp();
	virtual void ChannelDown();
	virtual void ChannelUp();
};

class AdvancedRemote : public Remote { // Abstract
public:
	using Remote::Remote;

	virtual void mute();
};


} // namespace Bridge

#endif // !BRIDGE_BRIDGE_H
