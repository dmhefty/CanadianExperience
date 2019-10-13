#include "pch.h"
#include "MakePenActiveVisitor.h"
#include <math.h>

using namespace std;

void CMakePenActiveVisitor::VisitHaroldPen(CHaroldPen* HaroldPen)
{
	HaroldPen->UnAttach();
	HaroldPen->SetVelocity(CVector(1000.0f * sin(mAngle), -1000.5f * cos(mAngle)));
}
