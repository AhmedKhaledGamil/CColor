//
// Created by Ahmed Khaled on 12/3/2017.
//

#include "CColor.h"
#include <iostream>
#include <bitset>
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include <sstream>



using namespace std;


CColor::CColor() {}

CColor::~CColor() {}


CColor::CColor(unsigned int Triple)
{
    rgbtTriple = Triple;

    int maskB = 0xFF;
    int maskG = 0xFF00;
    int maskR = 0xFF0000;

    int Blue = maskB & rgbtTriple;
    setBlue(Blue);

    int Red = maskR & rgbtTriple;
    Red = Red >> 16;
    setRed(Red);

    int Green = maskG & rgbtTriple;
    Green = Green >> 8;
    setGreen(Green);

}

CColor::CColor(int Red, int Green, int Blue) : Red(Red), Green(Green), Blue(Blue)
{
    rgbtTriple = 0x00000000;
    rgbtTriple = rgbtTriple | Blue;
    rgbtTriple = rgbtTriple | (Green<<8);
    rgbtTriple = rgbtTriple | (Red<<16);
}

std::ostream &operator<<(std::ostream &os, const CColor &color)
{
    os << "(" << color.Red << ", " << color.Green << ", " << color.Blue << ")";
    return os;
}

void CColor::setRed(int Red) {
    CColor::Red = Red;
}

void CColor::setGreen(int Green) {
    CColor::Green = Green;
}

void CColor::setBlue(int Blue) {
    CColor::Blue = Blue;
}

int CColor::getRed() const {
    return Red;
}

int CColor::getGreen() const {
    return Green;
}

int CColor::getBlue() const {
    return Blue;
}


string BinaryToHexDeciamlString(int decimalNumber)
{
    int remainder,quotient;
    int i=4,temp;
    string hexadecimalNumber;


    quotient = decimalNumber;

    while(quotient!=0)
    {
        temp = quotient % 16;

        //To convert integer into character
        switch (temp)
        {
            case 0: hexadecimalNumber += "0";
                break;
            case 1: hexadecimalNumber += "1";
                break;
            case 2: hexadecimalNumber += "2";
                break;
            case 3: hexadecimalNumber += "3";
                break;
            case 4: hexadecimalNumber += "4";
                break;
            case 5: hexadecimalNumber += "5";
                break;
            case 6: hexadecimalNumber += "6";
                break;
            case 7: hexadecimalNumber += "7";
                break;
            case 8: hexadecimalNumber += "8";
                break;
            case 9: hexadecimalNumber += "9";
                break;
            case 10: hexadecimalNumber += "A";
                break;
            case 11: hexadecimalNumber += "B";
                break;
            case 12: hexadecimalNumber += "C";
                break;
            case 13: hexadecimalNumber += "D";
                break;
            case 14: hexadecimalNumber += "E";
                break;
            case 15: hexadecimalNumber += "F";
                break;

        }
        quotient = quotient / 16;
    }
    hexadecimalNumber = string(hexadecimalNumber.rbegin(),hexadecimalNumber.rend());

    return hexadecimalNumber;
}

string CColor::operator()(char *Type)
{
    if (strcmp("hex",Type) == 0)
    {
        if (Red == 0 && Green == 0 && Blue == 0)
        {
            return "0x00000000";
        }
        else if (Red == 0 && Green == 0)
        {
            return "0x000000" + BinaryToHexDeciamlString(rgbtTriple);
        }
        else if (Red == 0)
        {
            return "0x0000" + BinaryToHexDeciamlString(rgbtTriple);
        }
        else
        {
            return "0x00" + BinaryToHexDeciamlString(rgbtTriple);
        };
    }
    else if (strcmp("bin",Type) == 0)
    {
        bitset <32> x (rgbtTriple);
        return x.to_string();
    }
    else if (strcmp("dec",Type) == 0)
    {
        return to_string(rgbtTriple);
    }
    return "";
}

unsigned int CColor::getRgbtTriple() const {
    return rgbtTriple;
}

void CColor::setRgbtTriple(unsigned int rgbtTriple) {
    CColor::rgbtTriple = rgbtTriple;
}


