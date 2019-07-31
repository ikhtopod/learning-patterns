#include "command.h"

namespace Command {

/* Value */

Value::Value(int value) : m_value(value) {}

int Value::Get() const { return m_value; }
void Value::Add(int value) { m_value += value; }
void Value::Sub(int value) { m_value -= value; }


/* ValueArithmeticOperation */

ValueArithmeticOperation::ValueArithmeticOperation(Value* value) : m_value(value) {}

ValueArithmeticOperation::~ValueArithmeticOperation() {
	m_value = nullptr;
}


/* ValueAddOperation */

ValueAddOperation::ValueAddOperation(Value* value) : ValueArithmeticOperation(value) {}

void ValueAddOperation::Run(int value) {
	m_value->Add(value);
}


/* ValueSubOperation */

ValueSubOperation::ValueSubOperation(Value* value) : ValueArithmeticOperation(value) {}

void ValueSubOperation::Run(int value) {
	m_value->Sub(value);
}


/* HandlerOperations */

void HandlerOperations::Insert(const Request& request) {
	m_queue.push(request);
}

bool HandlerOperations::Next() {
	if (m_queue.empty()) return false;

	m_queue.front().operation->Run(m_queue.front().value);
	m_queue.pop();

	return true;
}

} // Command
