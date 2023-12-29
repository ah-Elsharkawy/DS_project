#include "CHexagon.h"

#include <iostream>
#include "..\ApplicationManager.h"
CHexagon::CHexagon(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	BottomRightCorner = P2;
	VerticalLen = abs(P1.y - P2.y);
	HorizentalLen = abs(P1.x - P2.x);
	//ID = newID++;

}
//CHexagon::CHexagon() {};
void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawHexagon(TopLeftCorner, BottomRightCorner, FigGfxInfo, Selected);
}
bool CHexagon::ContainPoint(int x, int y)
{
	return false;
};
string CHexagon::getShapeType() {
	return "Hexagon";
}
