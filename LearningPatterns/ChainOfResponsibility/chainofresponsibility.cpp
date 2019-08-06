#include "chainofresponsibility.h"

namespace ChainOfResponsibility {

Info* Info::GetHandler() {
	return m_handler;
}

void Info::SetHandler(Info& handler) {
	m_handler = &handler;
}

void CraftSystem::ShowInfo(const CraftType& type) {
	if (type == CraftType::None) return;
	
	if (type == this->m_craftType) {
		std::cout << "I'm " << m_name << "!" << std::endl;
	} else {
		if (GetHandler() != nullptr) {
			GetHandler()->ShowInfo(type);
		}
	}
}

Weapon::Weapon() {
	m_craftType = CraftType::Weapon;
	m_name = "Weapon";
}

Axe::Axe() {
	m_craftType = CraftType::Axe;
	m_name = "Axe";
}

OneHandedAxe::OneHandedAxe() {
	m_craftType = CraftType::OneHandedAxe;
	m_name = "OneHandedAxe";
}

CraftInfo::CraftInfo(CraftSystem& craftSystem)
	: m_craftSystem(&craftSystem) {}

void CraftInfo::ShowInfo(const CraftType& type) {
	m_craftSystem->ShowInfo(type);
}

} // namespace ChainOfResponsibility
