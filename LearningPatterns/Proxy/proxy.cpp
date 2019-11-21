#include <iostream>
#include <ratio>
#include <chrono>
#include <thread>

#include "proxy.h"

namespace Proxy {

Image::Image(const std::string& name) : m_name(name) {}

void Image::Show() {
	std::cout << "Image " << m_name << " is loading" << std::endl;
	std::this_thread::sleep_for(std::chrono::duration<float, std::ratio<1, 1>>(.8f));
	std::cout << "Image " << m_name << " is displayed" << std::endl;
}

ImageProxy::ImageProxy(const std::shared_ptr<Image>& image) : m_image(image) {}

void ImageProxy::Show() {
	std::cout << "ImageProxy is displayed" << std::endl;

	if (m_image != nullptr) {
		m_image->Show();
	}
}

void Widget::AddComponent(const std::shared_ptr<Showable>& component) {
	m_components.push_back(component);
}

void Widget::Draw() {
	std::cout << "Widget is drawing" << std::endl;

	for (std::shared_ptr<Showable>& component : m_components) {
		if (component != nullptr) {
			component->Show();
		}
	}

	std::cout << std::endl;
}

} // namespace Proxy
