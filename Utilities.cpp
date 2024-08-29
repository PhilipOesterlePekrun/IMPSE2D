#include <iostream>
#include <limits>
#include <cmath>
#include <numbers>
#include <string>

#include "Utilities.h"

namespace Utilities
{

    // // misc utilities


    // // math utilities
    double xYToAngle(double x, double y) // returns angle in degrees, >= 0 and < 360
    {
        if (x == 0)
        {
            if (y > 0)
            {
                return 90;
            }
            else if (y < 0)
            {
                return 270;
            }
            else
            {
                return 0;
            }
        }
        if (x > 0) // == else if
        {
            if(y>0)
            {
                return 180 / std::numbers::pi * atan(y / x);
            }
            else if (y < 0) {
                return 270-180 / std::numbers::pi * atan(y / x);
            }
            else {
                return 0;
            }
        }
        else // == else if(x < 0)
        {
            if (y == 0)
            {
                return 180;
            }
            else
            {
                return 180 + 180 / std::numbers::pi * atan(y / x);
            }
        }
    }

    // // string utilities
    int* checkForIn(std::string checkFor, std::string checkIn)
    {
        int* returnArray = new int[20];
        for (int i = 0; i <20; i++)
        {
            returnArray[i] = -1;
        }
        std::string checkInTemp = checkIn;
        int arrayPos = 0;
        if (checkFor.length()<= checkIn.length())
        {
            for (int i = 0; i <= checkIn.length() - checkFor.length(); i++)
            {
                //checkInTemp = deleteInterval(checkInTemp, i, checkInTemp.Length);
                for (int j = 0; j < checkFor.length(); j++)
                {
                    if (checkFor[j] != checkIn[i + j])
                    {
                        break;
                    }
                    if (j == checkFor.length() - 1)
                    {
                        returnArray[arrayPos] = i;
                        arrayPos++;
                    }
                }
            }
        }
        return returnArray;
    }
    std::string deleteInterval(std::string text, int from, int to) //can be composed easily; from==0 --> char 0 deleted, to>=length --> last char deleted; from==to --> one char at that pos deleted
    {
        std::string temp = "";
        //int j = 0;
        for (int i = 0; i < text.length(); i++)
        {
            if (!(i >= from && i <= to))
            {
                temp = temp + text[i];
                //temp[j] = text[i];
                //j++;
            }
        }
        return temp;
    }
}