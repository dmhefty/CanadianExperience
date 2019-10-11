#include "pch.h"
#include "MakePenActiveVisitor.h"
#include <math.h>

using namespace std;

void CMakePenActiveVisitor::VisitHaroldPen(CHaroldPen* HaroldPen)
{
	HaroldPen->UnAttach();
	HaroldPen->SetVelocity(CVector(50.0f * sin(mAngle), -50.5f * cos(mAngle)));
}
