#include<windows.h>
#include <GL/glut.h>
#define PI 3.14159
#include<math.h>
const float DEG2RAD = 3.14159/180;
void semicircle(float radius,float u,float v)
{
    float i,j;
	glColor3f(1.0 ,0.9 ,0.0);
   glBegin(GL_POLYGON);

   for (int i=135; i<=315; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(u+cos(degInRad)*radius,v+(sin(degInRad))*radius);//100,100 specifies centre of the circle
   }

   glEnd();
}
