/**
 * \file GoodUML.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "GoodUML.h"
#include "Game.h"

CGoodUML::CGoodUML(std::shared_ptr<CUMLAttribute> name,
	std::vector<std::shared_ptr<CUMLAttribute>> attributes,
	std::vector<std::shared_ptr<CUMLAttribute>> operations,
	CVector position, CVector velocity, CGame* game) :
	CUML::CUML(name, attributes, operations, position, velocity, game)
{

}

void CGoodUML::Effect()
{
	GetGame()->RemoveThisItem(this);
	GetGame()->IncrementScore(-1);
}
