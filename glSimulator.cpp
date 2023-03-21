/*************************************************************
 * 1. Name:
 *      Collin Squires, Shandler Rechenberger, Ebenezer Mensah
 * 2. Assignment Name:
 *      Lab 06: Apollo 11 Final
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part of this lab was to fix our fidelity issues
 *       in Lander and the cohesion in the update method in that
 *       class.  We decided to divide up some of our functionality
 *       amongst other classes to make sure update didn't do quite
 *       as much.  In doing so, sometimes we made extra methods in
 *       other classes we later realized we didn't need.  We tried
 *       to add a second player, but it got way too difficult to
 *       figure out so we stayed with our single player.
 * 5. How long did it take for you to complete the assignment?
 *      About 6 hours
 *****************************************************************/

/**********************************************************************
 * GL Simulator
 * Just a simple program to demonstrate how to create an Open GL window,
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "star.h"
#include "lander.h"
#include "acceleration.h"
#include <iomanip>
using namespace std;
#define GRAVITY -1.625

/*************************************************************************
 * Simulator
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{
public:
   Simulator(const Point& ptUpperRight) :
      lander(ptUpperRight.getX()-20, ptUpperRight.getY()-20),
      ground(ptUpperRight)
   {
      for(int i = 0; i < 50; i++)
      {
         stars[i] = Star(ptUpperRight);
      }
   }

   // this is just for test purposes.  Don't make member variables public!
   Lander lander;        // the lunar module
   Point ptUpperRight;   // size of the screen
   Ground ground;
   Star stars[50];
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   ogstream gout;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator* pSim = (Simulator*)p;

    pSim->lander.update(pUI->isDown(), pUI->isRight(), pUI->isLeft(), GRAVITY);

	// draw our little stars
   for(int i = 0; i < 50; i++) {
      gout.drawStar(pSim->stars[i].getPoint(), pSim->stars[i].addPhase());
   }

   // draw the ground
   pSim->ground.draw(gout);

   // draw the lander and its flames
   gout.drawLander(pSim->lander.getPosition() /*position*/, pSim->lander.getAngle() /*angle*/);
   gout.drawLanderFlames(pSim->lander.getPosition(), pSim->lander.getAngle(), /*angle*/
      pUI->isDown(), pUI->isLeft(), pUI->isRight());

   // put some text on the screen if win
   if(pSim->ground.onPlatform(pSim->lander.getPosition(), LANDERWIDTH) && pSim->lander.canLand())
      {
         pSim->lander.setLanded();
         gout.setPosition(Point(200.0, 200.0));
         gout << "YOU WIN!\n";
      }
   else if (pSim->ground.onPlatform(pSim->lander.getPosition(), LANDERWIDTH) && !pSim->lander.canLand())
   {
      pSim->lander.kill();
      gout.setPosition(Point(200.0, 200.0));
      gout << "You Died.\n";
   }
   // put some text on the screen if died
   if(pSim->ground.hitGround(pSim->lander.getPosition(), LANDERWIDTH))
      {
      pSim->lander.kill();
      gout.setPosition(Point(200.0, 200.0));
      gout << "You Died.\n";
      }

   // put some text on the screen
   gout.setPosition(Point(15.0, 370.0));
   gout << "Fuel: " << pSim->lander.getFuel() << "lbs" << "\n";
   gout << "Altitude: " << (int)pSim->lander.getPosition().getY()  << "\n";
   gout << "Speed: " << fixed << setprecision(2) << pSim->lander.getVelocity().getTotalVelocity() << "m/s \n";
   
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL,
      "Open GL Demo",
      ptUpperRight);

   // Initialize the game class
   Simulator demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);

   return 0;
}
