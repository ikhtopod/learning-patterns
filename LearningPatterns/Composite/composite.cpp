#include "composite.h"

namespace Composite {

ConcretePrice::ConcretePrice(double price) : m_price(price) {}

double ConcretePrice::Get() {
	return m_price;
}

/* Composite */

void CommonFood::AddComponent(std::shared_ptr<Price> component) {
	m_components.push_back(component);
}

double CommonFood::Get() {
	double result = 0.0;

	for (const auto& component : m_components) {
		result += component->Get();
	}

	return result;
}

/* Liaf */

Juice::Juice(double price) : Drink(price) {}
Coffee::Coffee(double price) : Drink(price) {}
Tea::Tea(double price) : Drink(price) {}
Salt::Salt(double price) : Spice(price) {}
Pepper::Pepper(double price) : Spice(price) {}
Cucumber::Cucumber(double price) : Vegetable(price) {}
Tomato::Tomato(double price) : Vegetable(price) {}
Banana::Banana(double price) : Fruit(price) {}
Pineapple::Pineapple(double price) : Fruit(price) {}

} // namespace Composite
