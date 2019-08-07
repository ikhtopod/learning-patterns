#include "decorator.h"

namespace Decorator {

#pragma region Element Begin

const Operator::MapType Operator::mc_types {
	{ OperatorType::ADD, '+' },
	{ OperatorType::SUB, '-' },
	{ OperatorType::MUL, '*' },
	{ OperatorType::DIV, '/' },
	{ OperatorType::EQUALS, '=' },
};

Operator::Operator(const OperatorType& operatorType) :
	m_operatorType(operatorType) {}

void Operator::Draw() const {
	std::cout << mc_types.at(m_operatorType);
}

#pragma endregion Element


#pragma region Decorator Begin

FormulaDecorator::FormulaDecorator(Formula& formula) :
	m_formula(&formula) {}

void FormulaDecorator::Draw() const {
	m_formula->Draw();
}

#pragma region Wrapper Begin

WrapperDecorator::WrapperDecorator(Formula& formula) :
	FormulaDecorator(formula) {}


BracketsDecorator::BracketsDecorator(Formula& formula) :
	WrapperDecorator(formula) {}

void BracketsDecorator::Draw() const {
	std::cout << '(';
	WrapperDecorator::Draw();
	std::cout << ')';
}


SpacesDecorator::SpacesDecorator(Formula& formula) :
	WrapperDecorator(formula) {}

void SpacesDecorator::Draw() const {
	std::cout << ' ';
	WrapperDecorator::Draw();
	std::cout << ' ';
}

#pragma endregion Wrapper

#pragma region Join Begin

JoinDecorator::JoinDecorator(Formula& formula, Formula& join) :
	FormulaDecorator(formula), m_join(&join) {}


HeadDecorator::HeadDecorator(Formula& formula, Formula& join) :
	JoinDecorator(formula, join) {}

void HeadDecorator::Draw() const {
	m_join->Draw();
	FormulaDecorator::Draw();
}


TailDecorator::TailDecorator(Formula& formula, Formula& join) :
	JoinDecorator(formula, join) {}

void TailDecorator::Draw() const {
	FormulaDecorator::Draw();
	m_join->Draw();
}


#pragma endregion Join

#pragma endregion Decorator


} // namespace Decorator
