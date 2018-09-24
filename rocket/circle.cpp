#include<windows.h>
#include <GL/glut.h>
#define PI 3.14159
#include<math.h>
const float DEG2RAD = 3.14159/180;
void circle(GLdouble rad,GLint points)
{
    float i,j;
    GLdouble delTheta = ((2.0 * PI) /(GLdouble)points);
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
