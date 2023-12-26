#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	virtual void DrawMe(GUI* pOut) const;
	//bool ContainPoint(int x, int y);
	virtual bool ContainPoint(int x, int y);
};

#endif