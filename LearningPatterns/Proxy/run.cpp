#include <memory>

#include "proxy.h"

#include "run.h"

namespace Proxy {

void Run() {
	std::shared_ptr<Image> img_01 { new Image { "Image.001" } };
	std::shared_ptr<Image> img_02 { new Image { "Image.002" } };

	ImageProxy imgProxy_01 { img_01 };
	ImageProxy imgProxy_02 { img_02 };

	Widget widget {};

	widget.Draw();

	widget.AddComponent(img_01);
	widget.Draw();

	widget.AddComponent(img_02);
	widget.Draw();
}

} // namespace Proxy
