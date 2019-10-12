#pragma once

#include <vector>
#include <memory>
#include <string>

#include "UMLAttribute.h"
#include "BadUMLAttribute.h"

#include "Item.h"
#include "UML.h"
#include "BadUML.h"
#include "GoodUML.h"

#include "PowerItem.h"
#include "PowerSlow.h"
#include "PowerFast.h"
#include "PowerAllBad.h"
#include "PowerAllGood.h"
#include "PowerAllGone.h"
#include "PowerRapidFire.h"


class CEmitter
{
public:
	CEmitter() {};
	void Load(const std::wstring& filePath);
	std::shared_ptr<CUML> AddUML();

private:
	//pointer to the game this emitter is a part of
	//std::shared_ptr<CGame> mGame;
	//lists to store uml components
	///list of possible good uml names
	std::vector<std::shared_ptr<CUMLAttribute> > mNames;
	///list of possible bad uml names
	std::vector<std::shared_ptr<CUMLAttribute> > mNamesBad;
	///list of possible good uml attributes
	std::vector<std::shared_ptr<CUMLAttribute> > mAttributes;
	///list of possible bad uml attributes
	std::vector<std::shared_ptr<CUMLAttribute> > mAttributesBad;
	///list of possible good uml operations
	std::vector<std::shared_ptr<CUMLAttribute> > mOperations;
	///list of possible bad uml operations
	std::vector<std::shared_ptr<CUMLAttribute> > mOperationsBad;
};

