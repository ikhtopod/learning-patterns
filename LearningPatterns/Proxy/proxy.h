#pragma once

#ifndef PROXY_PROXY_H
#define PROXY_PROXY_H

#include <memory>
#include <vector>
#include <string>

namespace Proxy {

class Showable {
public:
	virtual void Show() = 0;
};

class Image : public Showable {
private:
	std::string m_name {};

public:
	explicit Image(const std::string& name);

public: // Showable
	virtual void Show() override;
};

class ImageProxy : public Showable {
private:
	std::shared_ptr<Image> m_image {};

public:
	explicit ImageProxy(const std::shared_ptr<Image>& image);

public: // Showable
	virtual void Show() override;
};

class Widget {
	using VectorShowableSPtr = std::vector<std::shared_ptr<Showable>>;

private:
	VectorShowableSPtr m_components {};

public:
	void AddComponent(const std::shared_ptr<Showable>& component);
	void Draw();
};

} // namespace Proxy

#endif // !PROXY_PROXY_H
