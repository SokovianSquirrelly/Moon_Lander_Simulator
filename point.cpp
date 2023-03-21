/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Shandler Rechenberger, Collin Squires, Ebenezer Mensah
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "point.h"
#include <cassert>

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y
 * Initialize the point to the passed position
 *****************************************/
Point::Point(double x, double y) : x(0.0), y(0.0)
{
   setX(x);
   setY(y);
}

/******************************************
 * POINT insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream & operator << (std::ostream & out, const Point & pt)
{
   out << "(" << pt.getX() << ", " << pt.getY() << ")";
   return out;
}

/*******************************************
 * POINT extraction
 *       Prompt for coordinates
 ******************************************/
std::istream & operator >> (std::istream & in, Point & pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setX(x);
   pt.setY(y);

   return in;
}
   
/******************************************************************************
 * COMPUTE DISTANCE
 *
 * To calculate the distance which the ship has traveled.
 *****************************************************************************/
void Point::computeDistance(Velocity v, double t, Acceleration a)
{
   x = (x + (v.getDx() * t)) + (0.5 * a.getDdx() * t * t);
   y = (y + (v.getDy() * t)) + (0.5 * a.getDdy() * t * t);
}