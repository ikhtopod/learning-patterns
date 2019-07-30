#include "run.h"

namespace Composite {

void Run() {
	Bar bar {};
	Order order_01 {};

	order_01.AddPrice(std::make_shared<Coffee>(88.0));

	std::shared_ptr<SolidFood> meatWithTomatoAndSpices = std::make_shared<SolidFood>();
	meatWithTomatoAndSpices->AddComponent(std::make_shared<Meat>(256.0));
	meatWithTomatoAndSpices->AddComponent(std::make_shared<Tomato>(25.0));
	meatWithTomatoAndSpices->AddComponent(std::make_shared<Salt>(0.1));
	meatWithTomatoAndSpices->AddComponent(std::make_shared<Pepper>(0.1));
	order_01.AddPrice(meatWithTomatoAndSpices);

	bar.AddOrder(order_01);

	std::cout <<
		"Coffee(88.0) + SolidFood(Meat(256.0) + Tomato(25.0) + Salt(0.1) + Pepper(0.1)) = " <<
		(88.0 + 256.0 + 25.0 + 0.1 + 0.1) << std::endl <<
		"Composite result = " << bar.GetLast().GetPrices() << std::endl;
}

}