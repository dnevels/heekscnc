// defines all the exported functions for HeeksCAD

#include "stdafx.h"
#include "Interface.h"

class Property;

void OnStartUp(CHeeksCADInterface* h)
{
	theApp.OnStartUp(h);
}

void OnNewOrOpen(int open)
{
	theApp.OnNewOrOpen(open != 0);
}

void GetOptions(void(*callbackfunc)(Property*))
{
	std::list<Property*> list;
	theApp.GetOptions(&list);
	for(std::list<Property*>::iterator It = list.begin(); It != list.end(); It++){
		Property* p = *It;
		(*callbackfunc)(p);
	}
}

void OnFrameDelete()
{
	theApp.OnFrameDelete();
}
