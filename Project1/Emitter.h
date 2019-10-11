#pragma once
#include <vector>
#include <memory>
#include <string>
#include "UMLAttribute.h"
#include "BadUMLAttribute.h"
class CEmitter
{
public:
	void Load(const std::wstring& filePath);

private:
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

