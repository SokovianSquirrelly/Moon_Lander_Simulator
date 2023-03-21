/***********************************************************************
 * Header File:
 *    Lander : Represents the lunar module.
 * Author:
 *    Collin Squires, Ebenezar Mensah, & Shandler Rechenberger
 * Summary:
 *    Runs and moves the lunar module.
 ************************************************************************/

#pragma once
#include "point.h"
#include "velocity.h"

#define WEIGHT 15103.0  // The weight, in kilograms, of the lander.
#define THRUST 45000.0  // The force, in newtons, of the main thruster.
#define THRUSTACCEL THRUST / WEIGHT // The thrust acceleration of the lunar
                                       //module in m/s/s
#define LANDERWIDTH 20.0 // The width of the lander in meters.

/******************************************************************************
* LANDER
* An instance of a lunar module.
*******************************************************************************/
class Lander
{
private:
   int fuelWeight;
   Point position;
   Velocity velocity;
   double angle;
   enum status { alive, dead, landed };
   status state;
   bool checkFuel(int amount) const;

public:
   Lander(double x, double y);
   Lander();
   void useFuel(bool isDown, bool isLeft, bool isRight);
   Point getPosition() const { return position; }
   Velocity getVelocity() const { return velocity; }
   double getAngle() const { return angle ;} 
   int getFuel() const { return fuelWeight; }
   void addNewAngle(double rotation);
   void update(bool isDown, bool isLeft, bool isRight, double gravity);
   void setLanded() { state = landed; }
   void kill();
   bool canLand() const;
};