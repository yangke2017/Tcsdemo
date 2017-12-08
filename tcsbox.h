#ifndef TCSBOX_H
#define TCSBOX_H


class TcsBox
{
public:
    TcsBox();
    TcsBox(bool);
    bool isIscolor();
    void setIscolor(bool);
    bool operator== (TcsBox);

    bool iscolor;

};

#endif // TCSBOX_H
