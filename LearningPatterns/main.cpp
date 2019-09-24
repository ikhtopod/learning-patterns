#include "pattern_structure_generator.h"

#include "AbstractFactory/run.h"
#include "Composite/run.h"
#include "Iterator/run.h"
#include "Prototype/run.h"
#include "Command/run.h"
#include "Flyweight/run.h"
#include "State/run.h"
#include "Adapter/run.h"
#include "Bridge/run.h"
#include "Observer/run.h"
#include "Builder/run.h"
#include "ChainOfResponsibility/run.h"
#include "Decorator/run.h"
#include "Facade/run.h"
#include "FactoryMethod/run.h"
#include "Interpreter/run.h"
#include "Mediator/run.h"
#include "Memento/run.h"
#include "Proxy/run.h"
#include "TemplateMethod/run.h"
#include "Singleton/run.h"
#include "Strategy/run.h"
#include "Visitor/run.h"

void initPatterns() {
	PatternStructureGenerator psg { PatternStructureGenerator::SetOfString {} };
	psg.AddPatternName("FactoryMethod");
	psg.AddPatternName("Interpreter");
	psg.AddPatternName("Mediator");
	psg.AddPatternName("Memento");
	psg.AddPatternName("Proxy");
	psg.AddPatternName("Visitor");
	psg.Generate();
}

int main() {
	initPatterns();

	// AbstractFactory::Run();
	// Composite::Run();
	// Iterator::Run();
	// Prototype::Run();
	// Command::Run();
	// Flyweight::Run();
	// State::Run();
	// Adapter::Run();
	// Bridge::Run();
	// Builder::Run();
	// ChainOfResponsibility::Run();
	// Decorator::Run();
	// Facade::Run();
	// TemplateMethod::Run();
	// Strategy::Run();
	FactoryMethod::Run();
	Interpreter::Run();
	Mediator::Run();
	Memento::Run();
	Proxy::Run();
	Singleton::Run();
	Visitor::Run();

	return 0;
}
