#pragma once

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point center;
	int length;

public:
	CEllipse(Point, int, GfxInfo);
	virtual void DrawMe(GUI* pOut) const;
};