/***********************************************************************
 * Header File:
 *    Point : Represents the acceleration of gravity as well as the thrust
 *    acceleration of the lunar module.
 * Author:
 *    Collin Squires, Ebenezar Mensah, Shandler Rechenberger
 * Summary:
 *    Everything we need to know in order to handle acceleration.
 ************************************************************************/

#pragma once

/*************************************************************************
* ACCELERATION
* Represents the potential acceleration of an object
*************************************************************************/
class Acceleration
{
private:
   double ddx;
   double ddy;

public:
   Acceleration();
   Acceleration(double ddx, double ddy);
   double getDdx() const { return ddx; }
   double getDdy() const { return ddy; }
   void setDdx(double ddx);
   void setDdy(double ddy);
   void computeHorizontalComponent(double radians, double totalAccel);
   void computeVerticalComponent(double radians, double totalAccel);
};