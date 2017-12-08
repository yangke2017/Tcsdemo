#include "tcsbox.h"

TcsBox::TcsBox()
{

}
TcsBox::TcsBox(bool iscolor)
{
        this->iscolor = iscolor;
}

bool TcsBox::isIscolor()
{
        return this->iscolor;
}

void TcsBox::setIscolor(bool iscolor)
{
        this->iscolor = iscolor;
}

bool TcsBox::operator ==(TcsBox box)
{
    if(iscolor == box.isIscolor())
        return true;
    else
        return false;
}


