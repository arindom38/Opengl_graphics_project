#include<windows.h>
#include <GL/glut.h>

void rocket_fumein(float i)
{
    glBegin(GL_POLYGON);//inner fume
            glVertex2f(237.5,20+i);
            glVertex2f(236.5,17.5+i);
            glVertex2f(235.5,15+i);
            glVertex2f(234.5,12.5+i);
            glVertex2f(233.5,10+i);
            glVertex2f(232.5,7.5+i);
            glVertex2f(236,5+i);
            glVertex2f(239.5,2.5+i);
            glVertex2f(243,0+i);
            glVertex2f(246.5,-2.5+i);
            glVertex2f(250,-5+i);
            glVertex2f(253.5,-2.5+i);
            glVertex2f(257,0+i);
            glVertex2f(260.5,2.5+i);
            glVertex2f(264,5+i);
            glVertex2f(267.5,7.5+i);
            glVertex2f(266.5,10+i);
            glVertex2f(265.5,12.5+i);
            glVertex2f(264.5,15+i);
            glVertex2f(263.5,17.5+i);
            glVertex2f(262.5,20+i);//21 points
        glEnd();

}
