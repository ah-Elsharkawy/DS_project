#pragma once
#include "CFigure.h"
#include "..\ApplicationManager.h"
class CEllipse :public CFigure
{
private:
	Point P1, P2;

public:
	ApplicationManager* pManager = NULL;	//Actions needs AppMngr to do their job

	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool ContainPoint(int x, int y);
	string getShapeType();


};