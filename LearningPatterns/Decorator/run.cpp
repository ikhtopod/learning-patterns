#include "run.h"

namespace Decorator {

void Run() {
	{
		std::vector<Element*> elements {
			&Operand { 5 },
			&Operator { OperatorType::ADD },
			&Operand { 6 },
			&Operator { OperatorType::EQUALS },
			&Operand { 11 },
		};

		for (const auto& element : elements) {
			element->Draw();
		}
	}

	std::cout << std::endl;

	{
		Operand five { 5 };
		Operator add { OperatorType::ADD };
		Operand six { 6 };
		Operator equals { OperatorType::EQUALS };
		Operand eleven { 11 };

		std::vector<Formula*> elements {
			&five,
			&SpacesDecorator { add },
			&six,
			&SpacesDecorator { equals },
			&eleven
		};

		for (const auto& element : elements) {
			element->Draw();
		}
	}

	std::cout << std::endl;

	{
		Operand five { 5 };
		Operator add { OperatorType::ADD };
		Operand three { 3 };
		Operand neg_three { -3 };
		Operator equals { OperatorType::EQUALS };

		std::vector<Formula*> elements {
			&five,
			&SpacesDecorator { add },
			&three,
			&SpacesDecorator { add },
			&BracketsDecorator { neg_three },
			&SpacesDecorator { equals },
			&five
		};

		for (const auto& element : elements) {
			element->Draw();
		}
	}

}

} // namespace Decorator
