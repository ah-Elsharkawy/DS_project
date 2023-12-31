#include "CSquare.h"
#include <iostream>

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}

bool CSquare::ContainPoint(int x, int y)
{
	
	if (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length && y >= TopLeftCorner.y && y <= TopLeftCorner.y + length)
	{
		//cout << "Found" << endl;
		//cout << "Selected attr = " << Selected << endl;
		return true;
	}
		
	else
	{
		//cout << "Not Found" << endl;
		return false;
	}
}