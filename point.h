/***********************************************************************
 * Header File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Shandler Rechenberger, Collin Squires, Ebenezer Mensah
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/


#pragma once
#include "velocity.h"
#include <iostream>

/*********************************************
 * POINT
 * A single position.  
 *********************************************/
class Point
{
public:
   // constructors
   Point()            : x(0.0), y(0.0)  {}
   Point(double x, double y);
   Point(const Point & pt) : x(pt.x), y(pt.y) {}

   // getters
   double getX()       const { return x; }
   double getY()       const { return y; }
   bool operator == (const Point & rhs) const
   {
      return x == rhs.x && y == rhs.y;
   }
   bool operator != (const Point & rhs) const
   {
      return x != rhs.x || y != rhs.y;
   }

   // setters
   void setX(double x)       { this->x = x; }
   void setY(double y)       { this->y = y; }
   void addX(double x) { this->x += x; }
   void addY(double y) { this->y += y; }
   Point & operator = (const Point & rhs)
   {
      x = rhs.x;
      y = rhs.y;
      return *this;
   }

   void computeDistance(Velocity v, double t, Acceleration a);


private:
   double x;           // horizontal position
   double y;           // vertical position
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Point & pt);
std::istream & operator >> (std::istream & in,        Point & pt);

