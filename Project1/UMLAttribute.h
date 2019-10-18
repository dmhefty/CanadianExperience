/**
 * \file UMLAttribute.h
 *
 * \author team Sarson
 *
 * Class for attributes of UML items
 */

#pragma once
#include <string>
class CUMLAttribute
{
private:
	/// The attribute text
	std::wstring mAttribute;
	/// UML error for this attribute
	std::wstring mError = L"";
public:
	/// Creates the attribute
	/// \param att The attribute we are working with
	CUMLAttribute(std::wstring att) : mAttribute(att) {}

	/// Returns the uml attribute stored in this item
	/// \return the attribute text
	std::wstring GetAtt() { return mAttribute; }

	/// sets the attribute of the uml
	/// \param att The attribute we are passing to the uml object
	void SetAtt(std::wstring att) { mAttribute = att; }
};