#pragma once

#ifndef COMPOSITE_CATERING_H
#define COMPOSITE_CATERING_H

#include <memory>
#include <vector>
#include <numeric>
#include <functional>

#include "composite.h"

namespace Composite {

class Order final {
private:
	std::vector<std::shared_ptr<Price>> m_prices {};

public:
	void AddPrice(const std::shared_ptr<Price>& price);
	double GetPrices() const;
};

class Catering {
private:
	std::vector<Order> m_orders {};

public:
	void AddOrder(const Order& order);
	Order& GetFirst();
	Order& GetLast();
};

class Bar : public Catering {};
class Cafe : public Catering {};
class Restaurant : public Catering {};

} // namespace Composite

#endif // !COMPOSITE_CATERING_H
