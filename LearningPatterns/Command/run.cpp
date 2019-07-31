#include "run.h"

namespace Command {

#define SEED duration_cast<duration<uint32_t, std::micro>>(steady_clock::now().time_since_epoch()).count()

void Run() {
	{
		HandlerOperations handler {};

		Value value { 23 };

		std::cout << value.Get() << std::endl << std::endl;

		handler.Insert(Request { std::make_shared<ValueAddOperation>(&value), 7 }); // 30

		if (handler.Next()) {
			std::cout << value.Get() << std::endl;
		}
	}

	std::cout << std::string().assign(4, '-') << std::endl;

	{
		HandlerOperations handler {};

		Value value { 23 };

		std::cout << value.Get() << std::endl << std::endl;

		handler.Insert(Request { std::make_shared<ValueAddOperation>(&value), 7 }); // 30
		handler.Insert(Request { std::make_shared<ValueAddOperation>(&value), 2 }); // 32

		while (handler.Next()) {
			std::cout << value.Get() << std::endl;
		}
	}

	std::cout << std::string().assign(4, '-') << std::endl;

	{
		HandlerOperations handler {};

		Value value { 23 };

		std::cout << value.Get() << std::endl << std::endl;

		handler.Insert(Request { std::make_shared<ValueAddOperation>(&value), 7 });  // 30
		handler.Insert(Request { std::make_shared<ValueAddOperation>(&value), 2 });  // 32
		handler.Insert(Request { std::make_shared<ValueSubOperation>(&value), 18 }); // 14

		while (handler.Next()) {
			std::cout << value.Get() << std::endl;
		}
	}

	std::cout << std::string().assign(4, '-') << std::endl;

	{
		using namespace std::chrono;

		std::default_random_engine dre { SEED };
		std::uniform_int_distribution uid_value { -20, 20 };
		std::uniform_int_distribution uid_amount_operations { 0, 15 };
		std::bernoulli_distribution bernoulli {};

		HandlerOperations handler {};

		Value value { uid_value(dre) };

		std::cout << value.Get() << std::endl << std::endl;

		int amount_operations = uid_amount_operations(dre);
		for (int i = 0; i < amount_operations; ++i) {
			Request request;
			request.value = uid_value(dre);

			if (bernoulli(dre)) {
				request.operation = std::make_shared<ValueAddOperation>(&value);
			} else {
				request.operation = std::make_shared<ValueSubOperation>(&value);
			}

			handler.Insert(request);
		}

		while (handler.Next()) {
			std::cout << value.Get() << std::endl;
		}
	}

	/*{
		using namespace std::chrono;

		std::default_random_engine dre { SEED };
		std::uniform_int_distribution uid_value { -20, 20 };
		std::uniform_int_distribution uid_amount_operations { 0, 15 };
		std::bernoulli_distribution bernoulli {};

		HandlerOperations handler {};

		Value value { uid_value(dre) };

		std::cout << value.Get() << std::endl << std::endl;

		while (true) {
			int amount_operations = uid_amount_operations(dre);
			for (int i = 0; i < amount_operations; ++i) {
				Request request;
				request.value = uid_value(dre);

				if (bernoulli(dre)) {
					request.operation = std::make_shared<ValueAddOperation>(&value);
				} else {
					request.operation = std::make_shared<ValueSubOperation>(&value);
				}

				handler.Insert(request);
			}

			while (handler.Next()) {
				std::cout << value.Get() << std::endl;
			}
		}
	}*/
}

} // Command
