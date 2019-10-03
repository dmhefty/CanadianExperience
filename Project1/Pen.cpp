/**
 * \file Pen.cpp
 *
 * \author David Hefty
 */

#pragma once
#include "pch.h"
#include "Pen.h"

/**
 * \brief Constructor for CPen class
 *
 * \param position takes in a position in the form of a CVector
 * \param velocity takes in a velocity in the form of a CVector
 */
CPen::CPen(CVector position, CVector velocity) : CItem(position, velocity)
{
}


// TODO once visitors are set up
/**
 * \brief Acceptor for the Pen visitors
 *
 * \param visitor the visitor item that is doing work
 */
/*
CPen::Accept(Visitor visitor)
{
	visitor.VisitPen(this);
}
*/