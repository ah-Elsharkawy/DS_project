#include "CEllipse.h"
#include "CFigure.h"

#include <iostream>

CEllipse::CEllipse(Point _P1, Point _P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = _P1;
	P2 = _P2;

}
//CEllipse::CEllipse() {}

void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawCircle to draw a Circle on the screen	
	pGUI->DrawEllipse(P1, P2, FigGfxInfo, Selected);

}

bool CEllipse::ContainPoint(int x, int y)
{
	return false;
};
string CEllipse::getShapeType() {
	return "Ellipse";
}