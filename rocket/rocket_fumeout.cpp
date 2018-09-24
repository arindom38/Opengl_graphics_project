#include<windows.h>
#include <GL/glut.h>
void rocket_fumeout(float i)
{
       glBegin(GL_POLYGON);//outer fume
            glVertex2f(257.5,20+i);
            glVertex2f(234.16,16.66+i);
            glVertex2f(230.82,13.32+i);
            glVertex2f(227.48,9.98+i);
            glVertex2f(224.14,6.64+i);
            glVertex2f(220.8,3.3+i);
            glVertex2f(217.5,0+i);
            glVertex2f(221.56,-5+i);
            glVertex2f(225.62,-10+i);
            glVertex2f(229.68,-15+i);
            glVertex2f(233.74,-20+i);
            glVertex2f(237.8,-25+i);
            glVertex2f(241.86,-30+i);
            glVertex2f(245.92,-35+i);
            glVertex2f(250,-40+i);
            glVertex2f(254.06,-35+i);
            glVertex2f(258.12,-30+i);
            glVertex2f(262.18,-25+i);
            glVertex2f(266.24,-20+i);
            glVertex2f(270.3,-15+i);
            glVertex2f(274.36,-10+i);
            glVertex2f(278.42,-5+i);
            glVertex2f(282.5,0+i);
            glVertex2f(278.5,4+i);
            glVertex2f(274.5,8+i);
            glVertex2f(270.5,12+i);
            glVertex2f(266.5,16+i);
            glVertex2f(262.5,20+i);//28 points
		glEnd();
}
