#include "run.h"

namespace Bridge {

void Run() {
	std::cout << "TV" << std::endl;
	Device* tv = new TV {};
	Remote* remoteTv = new Remote { *tv };
	remoteTv->TogglePower();
	remoteTv->VolumeUp();
	remoteTv->ChannelUp();
	remoteTv->ChannelUp();
	remoteTv->ChannelDown();
	remoteTv->ChannelDown();
	remoteTv->VolumeDown();
	remoteTv->TogglePower();
	delete tv;

	std::cout << "\nRadio" << std::endl;
	Device* radio = new Radio {};
	AdvancedRemote* remoteRadio = new AdvancedRemote { *radio };
	remoteRadio->TogglePower();
	remoteRadio->VolumeUp();
	remoteRadio->VolumeUp();
	remoteRadio->VolumeUp();
	remoteRadio->VolumeUp();
	remoteRadio->ChannelUp();
	remoteRadio->ChannelUp();
	remoteRadio->mute();
	remoteRadio->TogglePower();
	delete radio;
}

} // namespace Bridge
