/***********************************************************************
 * Header File:
 *    Star : Represents the stars that appear on screen.
 * Author:
 *    Collin Squires, Ebenezar Mensah, Shandler Rechenberger
 * Summary:
 *    Everything we need to know about the stars on the screen.
 ************************************************************************/

#pragma once
#include "point.h"
/*************************************************************************
* STAR
* A star that will change it's state depending on the phase 
*************************************************************************/
class Star
{
public:
   Star(const Point& ptUpperRight);
   Star();

   Point getPoint() const {return pt;}

   unsigned char addPhase(); 
   
   private:
      unsigned char phase;
      Point pt;
};