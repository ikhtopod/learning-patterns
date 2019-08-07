#pragma once

#ifndef DECORATOR_DECORATOR_H
#define DECORATOR_DECORATOR_H

#include <cstdint>
#include <iostream>
#include <map>

namespace Decorator {

class Formula {
public:
	virtual void Draw() const = 0;
};

#pragma region Element Begin

class Element : public Formula {};

enum class OperatorType {
	ADD, SUB,
	MUL, DIV,
	EQUALS
};

class Operator final : public Element {
private:
	using MapType = std::map<OperatorType, uint8_t>;
	static const MapType mc_types;

private:
	OperatorType m_operatorType;

public:
	Operator(const OperatorType& operatorType);

	virtual void Draw() const override;
};


template <typename T = int>
class Operand final : public Element {
private:
	T m_operand;

public:
	explicit Operand(const T& operand) : m_operand(operand) {};

	virtual void Draw() const override {
		std::cout << m_operand;
	}
};

#pragma endregion Element


#pragma region Decorator Begin

class FormulaDecorator : public Formula {
protected:
	Formula* m_formula;

public:
	explicit FormulaDecorator(Formula& formula);

	virtual void Draw() const override;

};

#pragma region Wrapper Begin

class WrapperDecorator : public FormulaDecorator {
public:
	explicit WrapperDecorator(Formula& formula);
};

class BracketsDecorator final : public WrapperDecorator {
public:
	explicit BracketsDecorator(Formula& formula);

	virtual void Draw() const override;
};

class SpacesDecorator final : public WrapperDecorator {
public:
	explicit SpacesDecorator(Formula& formula);

	virtual void Draw() const override;
};

#pragma endregion Wrapper

#pragma region Join Begin

class JoinDecorator : public FormulaDecorator {
protected:
	Formula* m_join;

public:
	explicit JoinDecorator(Formula& formula, Formula& join);

	virtual void Draw() const override = 0;
};

class HeadDecorator final : public JoinDecorator {
public:
	explicit HeadDecorator(Formula& formula, Formula& join);

	virtual void Draw() const override;
};

class TailDecorator final : public JoinDecorator {
public:
	explicit TailDecorator(Formula& formula, Formula& join);

	virtual void Draw() const override;
};

#pragma endregion Join

#pragma endregion Decorator


} // namespace Decorator

#endif // !DECORATOR_DECORATOR_H
