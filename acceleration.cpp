/***********************************************************************
 * CPP File:
 *    Acceleration : The representation of the movement of the ship
 * Author:
 *    Shandler Rechenberger, Collin Squires, Ebenezer Mensah
 * Summary:
 *    All the physics regrarding the movement of the ship.
 ************************************************************************/




#include "acceleration.h"
#include <math.h>


 /******************************************
  * ACCELERATION : CONSTRUCTOR WITH DDX,DDY
  * Initialize the point to the passed acceleration
  *****************************************/
Acceleration::Acceleration()
{
   ddx = 0;
   ddy = 0;  
}


 /******************************************
  * ACCELERATION : 
  * SET the point to DDX and DDy
  *****************************************/
Acceleration::Acceleration(double ddx, double ddy)
{
   setDdx(ddx);
   setDdy(ddy);
}


/******************************************
 * SETDdx :
 * SET the point to DDX 
 *****************************************/
void Acceleration::setDdx(double ddx)
{
   this->ddx = ddx;
}


/******************************************
 * SETDdx :
 * SET the point to DDy
 *****************************************/
void Acceleration::setDdy(double ddy)
{
   this->ddy = ddy;
}


/******************************************
 * COMPUTEHORIZONTALCOMPONENT : ddx = totalAccel * sin(radians);
 * SET the computeHorizontalComponent using radains and totalAccel
 *****************************************/
void Acceleration::computeHorizontalComponent(double radians, double totalAccel)
{
   ddx = totalAccel * sin(radians);
}


/******************************************
 * COMPUTEHORIZONTALCOMPONENT : ddx = totalAccel * sin(radians);
 * SET the computeHorizontalComponent using radains and totalAccel
 *****************************************/
void Acceleration::computeVerticalComponent(double radians, double totalAccel)
{
   ddy = totalAccel * cos(radians);
}