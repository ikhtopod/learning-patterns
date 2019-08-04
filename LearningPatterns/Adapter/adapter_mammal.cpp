#include "adapter_mammal.h"

namespace AdapterMammal {

void Human::Walk() {
	std::cout << "Human is walking." << std::endl;
}

void Hawk::Fly() {
	std::cout << "Hawk is flying." << std::endl;
}

void Python::Crawl() {
	std::cout << "Python is crawling." << std::endl;
}



HumanMoveAdapter::HumanMoveAdapter(Human* const human)
	: m_human(human) {}

void HumanMoveAdapter::Move() {
	m_human->Walk();
}

HawkMoveAdapter::HawkMoveAdapter(Hawk* const hawk)
	: m_hawk(hawk) {}

void HawkMoveAdapter::Move() {
	m_hawk->Fly();
}

PythonMoveAdapter::PythonMoveAdapter(Python* const python)
	: m_python(python) {}

void PythonMoveAdapter::Move() {
	m_python->Crawl();
}

} // namespace AdapterMammal
