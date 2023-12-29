#pragma once
#include "CFigure.h"
#include "..\ApplicationManager.h"

class CHexagon : public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;
	int VerticalLen;
	int HorizentalLen;
public:
	ApplicationManager* pManager = NULL;	//Actions needs AppMngr to do their job
	int Area;
	CHexagon(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool ContainPoint(int x, int y);
	string getShapeType();

};