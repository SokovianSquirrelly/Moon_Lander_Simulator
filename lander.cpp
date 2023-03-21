/***********************************************************************
 * CPP File:
 *    Lander : The representation of how the ship will land.
 * Author:
 *    Shandler Rechenberger, Collin Squires, Ebenezer Mensah
 * Summary:
 *    All the physics regrarding the place the ship should land.
 ************************************************************************/

#include "lander.h"

using namespace std;

/******************************************************************************
 * LANDER
 *
 * Non-Default Constructor
 *****************************************************************************/
Lander::Lander(double x, double y)
{
   fuelWeight = 5000;
   position = Point(x, y);
   velocity = Velocity();
   angle = 0.0;
   state = alive;
}

/******************************************************************************
 * LANDER
 *
 * Default Constructor
 *****************************************************************************/
Lander::Lander()
{
   fuelWeight = 5000;
   position = Point(0.0, 0.0);
   velocity = Velocity();
   angle = 0.0;
   state = alive;
}

/******************************************************************************
 * CHECK FUEL
 *
 * Checks to make sure there's enough fuel to fire a thruster.   
 *****************************************************************************/
bool Lander::checkFuel(int amount) const
{
   if(fuelWeight >= amount)
      return true;
   else
      return false;
}

/******************************************************************************
 * USE FUEL
 *
 * Consumes fuel based on what thrusters are being fired.  The down thruster
 * uses 10 pounds of fuel per frame.  The side thrusters only use 1 pound per
 * frame.
 *****************************************************************************/
void Lander::useFuel(bool isDown, bool isLeft, bool isRight)
{
   if (isDown && checkFuel(10))  // Down Thruster (10 pounds) 
      fuelWeight -= 10;

   if (isLeft && checkFuel(1))   // Left Thruster (1 pound)
      fuelWeight -= 1;

   if (isRight && checkFuel(1))  // Right Thruster (1 pound)
      fuelWeight -= 1;
}

/*****************************************************************************
 * CAN LAND
 * 
 * Checks the impact of the ship to be less than 4.0.
 *****************************************************************************/
bool Lander::canLand() const
{
   if (getVelocity().getTotalVelocity() < 4.0)
      return true;
   else
      return false;
}

/*****************************************************************************
 * ADD NEW ANGLE
 * 
 * Sets the new angle depending on the user inputs.
 *****************************************************************************/
void Lander::addNewAngle(double rotation)
{
   angle += rotation;
}

/*****************************************************************************
 * KILL
 *
 * Turns the lander upside-down and immobile when it crashes.
 *****************************************************************************/
void Lander::kill()
{
   state = dead;
   angle = -3.14;
}

/******************************************************************************
 * UPDATE
 *
 * Updates the lander every frame utilizing user input
 *****************************************************************************/
void Lander::update(bool isDown, bool isLeft, bool isRight, double gravity)
{
   if(state == alive)
   {
      double t = 0.1; // Each frame accounts for 0.1 seconds 
   
      /*
      --Once in Simulation--
         * Compute Accel Thrust

      --Loop in Simulation--
         ==Check Fuel==
            * Check Fuel
            * Update Fuel
      
         ==Compute new Accel==
            * computeHorizontalComp. of Accel
            * computeVerticalComp. of Accel

         ==compute new Velocities==
            * computeVelocity for x
            * computeVelocity for y

         ==compute positions==
            * computeDistance for x
            * computeDistance for y
   */
      double angleValue = angle * -1.0;
      Acceleration thrust;
      if (isRight && checkFuel(1))
      {
         // If we have fuel, the lander should be able to rotate right
         addNewAngle(-0.1);
         useFuel(false, false, true);
      }
      if (isLeft && checkFuel(1))
      {
         // If we have fuel, the lander should be able to rotate left
         addNewAngle(0.1);
         useFuel(false, true, false);
      }

      if (isDown && checkFuel(10))
      {
         // If we have fuel, the lander should be able to move up
         useFuel(true, false, false);
		
         // Old X Accel
         thrust.computeHorizontalComponent(angleValue, THRUSTACCEL);
         // Old Y Accel
		   thrust.computeVerticalComponent(angleValue, THRUSTACCEL);
      }
      else
      {
         //if we don't have fuel to move up, then our acceleraltion should stop  
         thrust.setDdx(0);
         thrust.setDdy(0);
      }

      double ddx = thrust.getDdx();
      double ddy = thrust.getDdy() + gravity; // Apply Gravity

      Acceleration totalAccel = Acceleration(ddx, ddy);

      velocity.computeVelocity(t, totalAccel);
  
      position.computeDistance(velocity, t, totalAccel);
   }
}