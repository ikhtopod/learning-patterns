#pragma once

#ifndef COMPOSITE_ORDER_H
#define COMPOSITE_ORDER_H

#include <memory>
#include <vector>
#include <numeric>
#include <functional>

namespace Composite {

/* Component */

class Price {
public:
	virtual double Get() = 0;
};

class ConcretePrice : public Price {
protected:
	double m_price;

public:
	ConcretePrice(double price);

	virtual double Get() override;
};

/* Composite */

class CommonFood : public Price {
private:
	std::vector<std::shared_ptr<Price>> m_components {};

public:
	void AddComponent(std::shared_ptr<Price> component);
	virtual double Get() override;
};

class SolidFood : public CommonFood {};
class Dish : public CommonFood {};
class Salad : public CommonFood {};
class ComplicatedDish : public CommonFood {};

/* Liaf */

class Meat : public ConcretePrice {
public:
	using ConcretePrice::ConcretePrice;
};

class Bread : public ConcretePrice {
public:
	using ConcretePrice::ConcretePrice;
};


class Drink : public ConcretePrice {
public:
	using ConcretePrice::ConcretePrice;
};
class Juice : public Drink {
public:
	Juice(double price);
};
class Coffee : public Drink {
public:
	Coffee(double price);
};
class Tea : public Drink {
public:
	Tea(double price);
};


class Spice : public ConcretePrice {
public:
	using ConcretePrice::ConcretePrice;
};
class Salt : public Spice {
public:
	Salt(double price);
};
class Pepper : public Spice {
public:
	Pepper(double price);
};


class Vegetable : public ConcretePrice {
public:
	using ConcretePrice::ConcretePrice;
};
class Cucumber : public Vegetable {
public:
	Cucumber(double price);
};
class Tomato : public Vegetable {
public:
	Tomato(double price);
};


class Fruit : public ConcretePrice {
public:
	using ConcretePrice::ConcretePrice;
};
class Banana : public Fruit {
public:
	Banana(double price);
};
class Pineapple : public Fruit {
public:
	Pineapple(double price);
};

} // namespace Composite

#endif // !COMPOSITE_ORDER_H
