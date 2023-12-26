#include "CEllipse.h"

CEllipse::CEllipse(Point P1, int len, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	length = len;

}

void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawElipse to draw an Ellipse on the screen	
	pGUI->DrawElipse(center, length, FigGfxInfo);


}