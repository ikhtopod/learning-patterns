#pragma once

#ifndef CHAINOFRESPONSIBILITY_CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_CHAINOFRESPONSIBILITY_H

#include <iostream>
#include <string>

namespace ChainOfResponsibility {

enum class CraftType {
	None,
	Weapon,
	Axe,
	OneHandedAxe
};

class Info {
private:
	Info* m_handler = nullptr;

public:
	Info* GetHandler();
	void SetHandler(Info& handler);

	virtual void ShowInfo(const CraftType& type) = 0;
};


class CraftSystem : public Info {
protected:
	CraftType m_craftType { CraftType::None };
	std::string m_name { "CraftSystem" };

public:
	virtual void ShowInfo(const CraftType& type) override;
};

class Weapon : public CraftSystem {
public:
	Weapon();
};

class Axe : public Weapon {
public:
	Axe();
};

class OneHandedAxe : public Axe {
public:
	OneHandedAxe();
};

class CraftInfo {
private:
	CraftSystem* m_craftSystem;

public:
	explicit CraftInfo(CraftSystem& craftSystem);

	void ShowInfo(const CraftType& type);
};

} // namespace ChainOfResponsibility

#endif // !CHAINOFRESPONSIBILITY_CHAINOFRESPONSIBILITY_H
