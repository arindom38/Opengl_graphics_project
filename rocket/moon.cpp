#include<windows.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.14159
const float DEG2RAD = 3.14159/180;
float f=0.0,t=0.0;
void mars(float radius)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);

   for (int i=0; i<=359; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(300+f+cos(degInRad)*radius,500-t+(sin(degInRad))*radius);
      //100,100 specifies centre of the circle
   }

   glEnd();
   t=t+0.1;
   f=f+0.1;
}
