//
// Created by Ahmed Khaled on 12/3/2017.
//

#ifndef CCOLOR_CCOLOR_H
#define CCOLOR_CCOLOR_H

#include <ostream>
#include <bitset>
#include "string.h"

using namespace std;


class CColor {

    unsigned int rgbtTriple;

    int Red;
    int Green;
    int Blue;


public:
    CColor();

    virtual ~CColor();

    CColor(unsigned int Triple);

    CColor(int Red, int Green, int Blue);

    friend std::ostream &operator<<(std::ostream &os, const CColor &color);

    void setRed(int Red);

    void setGreen(int Green);

    void setBlue(int Blue);

    int getRed() const;

    int getGreen() const;

    int getBlue() const;

    string operator () (char *Type);

    unsigned int getRgbtTriple() const;

    void setRgbtTriple(unsigned int rgbtTriple);

};


#endif //CCOLOR_CCOLOR_H
