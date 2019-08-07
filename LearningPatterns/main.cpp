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

void initPatterns() {
	PatternStructureGenerator psg { PatternStructureGenerator::SetOfString {} };
	psg.AddPatternName("Decorator");
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
	Decorator::Run();

	return 0;
}
