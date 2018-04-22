#include <iostream>
#include "CColor.h"

CColor average(CColor color0, CColor color1, CColor color2);

using namespace std;

int main()
{
    CColor a(255/*red*/, 128/*green*/, 192/*blue*/);
    CColor b(0x00667755); //red: 0x66, green: 0x77, blue: 0x55
    CColor c(0x0000FFFF);
    cout << "a color = " << a << " " << a("hex") << endl; //should prints (255, 128, 192)
    cout << "b color = " << b << " " << b("hex") << endl; //should prints 0x00667755
    cout << "c color = " << c << " " << c("hex") << endl;
    //Make y = average of a and b and c
    CColor y = average(a, b, c);
    cout << "y color = " << y << " " << y("hex") << endl;
    return 0;
}

CColor average(CColor color0, CColor color1, CColor color2)
{
    CColor temp;
    temp.setGreen((color0.getGreen()+color1.getGreen()+color2.getGreen())/3);
    temp.setBlue((color0.getBlue()+color1.getBlue()+color2.getBlue())/3);
    temp.setRed((color0.getRed()+color1.getRed()+color2.getRed())/3);

    temp.setRgbtTriple(0x00000000);
    temp.setRgbtTriple(temp.getRgbtTriple() | temp.getBlue());
    temp.setRgbtTriple(temp.getRgbtTriple() | (temp.getGreen()<<8));
    temp.setRgbtTriple(temp.getRgbtTriple() | (temp.getGreen()<<16));

    return temp;

}