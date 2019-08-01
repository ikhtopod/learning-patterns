#include "run.h"

#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>
#include <random>
#include <chrono>
#include <ratio>

namespace Flyweight {

using namespace std::chrono;

#define TRANSFORM_FIELD_N(field, n) transform.field.n = urd(dre)

#define TRANSFORM_FIELD(field)		\
	TRANSFORM_FIELD_N(field, x);	\
	TRANSFORM_FIELD_N(field, y);	\
	TRANSFORM_FIELD_N(field, z)

#define TRANSFORM_SET			\
	TRANSFORM_FIELD(position);	\
	TRANSFORM_FIELD(rotation)

void Run() {
	ObjectFactory objectFactory {};

	nanoseconds nowTime_ns = steady_clock::now().time_since_epoch();
	uint32_t seed = duration_cast<duration<uint32_t, std::milli>>(nowTime_ns).count();
	std::default_random_engine dre { seed };
	std::uniform_real_distribution<float> urd { -10'000, 10'000 };

	Transform transform {};
	std::string ids { "abcdefghi" };
	do {
		objectFactory.Get(ids);
	} while (std::next_permutation(std::begin(ids), std::end(ids)));

	std::cout << objectFactory.Size() << std::endl;
	std::cin.get();

	/*while (urd(dre) != 66.6f) {
		TRANSFORM_SET;

		Object* object = objectFactory.Get(ids);
		object->Transformation(transform);
	}*/

	std::cin.get();
}

} // namespace Flyweight
