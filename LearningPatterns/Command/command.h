#pragma once

#ifndef COMMAND_COMMAND_H
#define COMMAND_COMMAND_H

#include <memory>
#include <queue>

namespace Command {

class Value final { // Receiver
private:
	int m_value;

public:
	explicit Value(int value);

	int Get() const;

	void Add(int value);
	void Sub(int value);
};


class Operation { // Command
public:
	virtual void Run(int value) = 0;

protected:
	Operation() {}
};


class ValueArithmeticOperation : public Operation { // Concrete Command
protected:
	Value* m_value;

public:
	ValueArithmeticOperation(Value* value);
	virtual ~ValueArithmeticOperation();
};

class ValueAddOperation : public ValueArithmeticOperation {
public:
	ValueAddOperation(Value* value);
	virtual void Run(int value) override;
};

class ValueSubOperation : public ValueArithmeticOperation {
public:
	ValueSubOperation(Value* value);
	virtual void Run(int value) override;
};


struct Request { // Request for Invoker
	std::shared_ptr<Operation> operation { nullptr };
	int value { 0 };
};

class HandlerOperations final { // Invoker
private:
	std::queue<Request> m_queue {};

public:
	void Insert(const Request& request);
	bool Next();
};


} // Command

#endif // !COMMAND_COMMAND_H
