/**
 * \file HaroldPen.cpp
 *
 * \author David Hefty
 */

#pragma once
#include "pch.h"
#include "HaroldPen.h"
#include <string>
using namespace std;

/// Pen filename 
const wstring PEN_IMAGE_NAME = L"images/redpen.png";

 /**
  * \brief Constructor for CHaroldPen class
  *
  * \param position takes in a position in the form of a CVector
  * \param velocity takes in a velocity in the form of a CVector
  */
CHaroldPen::CHaroldPen(CVector position, CVector velocity) : CItem(position, velocity, PEN_IMAGE_NAME)
{
	mIsAttached = false; // false for now since we dont have a real attachment to Harold
}

void CHaroldPen::Draw(Gdiplus::Graphics* graphics, CVector position)
{
	CItem::Draw(graphics, position);
}

void CHaroldPen::Update(double elapsedTime)
{
	if (!mIsAttached)
	{
		CItem::Update(elapsedTime);
	}
	else
	{
		//TODO -> for updating with OnMouseMove in coordination with Harold
	}
}


// TODO once visitors are set up
/**
 * \brief Acceptor for the HaroldPen visitors
 *
 * \param visitor the visitor item that is doing work
 */
 /*
 CHaroldPen::Accept(Visitor visitor)
 {
	 visitor.VisitHaroldPen(this);
 }
 */