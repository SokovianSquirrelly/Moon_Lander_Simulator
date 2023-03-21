/***********************************************************************
 * Header File:
 *    Point : The representation the velocity of the lunar module.
 * Author:
 *    Collin Squires, Ebenezar Mensah, Shandler Rechenberger
 * Summary:
 *    Everything we need to know about the speed and direction of the
 *		lunar module.
 ************************************************************************/

#pragma once
#include"acceleration.h" 
/*************************************************************************
* VELOCITY
* Represents the potential velocity of an object
*************************************************************************/
class Velocity
{
private:
	double dx;
	double dy;

public:
	Velocity(): dx(0.0), dy(0.0){}
	double getTotalVelocity() const;
	void computeVelocity(double t, Acceleration a);
	double getDx() const { return dx; }
	double getDy() const { return dy; }
};