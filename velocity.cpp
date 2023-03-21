/***********************************************************************
 * CPP File:
 *    Velocity : The representation the correct movement of the ship
 * Author:
 *    Shandler Rechenberger, Collin Squires, Ebenezer Mensah
 * Summary:
 *    All the physics regrarding the movement of the ship through space.
 ************************************************************************/

#include "velocity.h"
#include <math.h>

/******************************************************************************
 * COMPUTE VELOCITIES
 *
 * Calculate the velocity for DX and DY.
 *****************************************************************************/
void Velocity::computeVelocity(double t, Acceleration a)
{
   dx = dx + (a.getDdx() * t);
   dy = dy + (a.getDdy() * t);
}

/******************************************************************************
 * GET TOTAL VELOCITY
 *
 * Calculate the total velocity for the ship.
 *****************************************************************************/
double Velocity::getTotalVelocity() const
{
   double v;
   v = (dx * dx) + (dy * dy);
   v = sqrt(v);
   return v;
}