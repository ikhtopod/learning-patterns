#include "catering.h"

namespace Composite {

void Order::AddPrice(const std::shared_ptr<Price>& price) {
	m_prices.push_back(price);
}

double Order::GetPrices() const {
	double result = 0.0;

	for (const auto& price : m_prices) {
		result += price->Get();
	}

	return result;
}

void Catering::AddOrder(const Order& order) {
	m_orders.push_back(order);
}

Order& Catering::GetFirst() {
	return m_orders.front();
}

Order& Catering::GetLast() {
	return m_orders.back();
}

} // namespace Composite
