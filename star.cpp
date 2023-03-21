/***********************************************************************
 * CPP File:
 *    Acceleration : The representation of the star at the background
 * Author:
 *    Shandler Rechenberger, Collin Squires, Ebenezer Mensah
 * Summary:
 *    All the position of the stars and how is blinks.
 ************************************************************************/


#include "star.h"

/******************************************************************************
 * STAR
 *
 * Set a random star at a random location.
 *****************************************************************************/
Star::Star(const Point& ptUpperRight)
{
   int xpt = ptUpperRight.getX();
   int ypt = ptUpperRight.getY();
   phase = rand() % 256;
   pt.setX(rand() % xpt);
   pt.setY(rand() % ypt);
}

/******************************************************************************
 * STAR
 *
 * Put star in the screen, set for X and Y.
 *****************************************************************************/
Star::Star()
{
   pt.setX(0);
   pt.setY(0);
   phase = 0;
}

/******************************************************************************
 * ADD PHASE
 *
 * The phase that the stars need to be.
 *****************************************************************************/
unsigned char Star::addPhase()
{
   phase++;
   return phase;
}