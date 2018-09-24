#include<windows.h>
#include <GL/glut.h>
///rocket body function///
void rocket(float k)
{
    glColor3f(0.9,0.498039 ,0.196078);
	glBegin(GL_POLYGON);//core
		glVertex2f(237.5,20.0+k);
		glVertex2f(262.5,20.0+k);
		glVertex2f(262.5,120.0+k);
		glVertex2f(237.5,120.0+k);
    glEnd();
        //break line
    glColor3f(0.3,0.3,0.3);
     glBegin(GL_POLYGON);
        glVertex2f(237.5,75.0+k);
        glVertex2f(262.5,75.0+k);
        glVertex2f(262.5,77.0+k);
        glVertex2f(237.5,77.0+k);
    glEnd();

        //rectangle line
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_POLYGON);
        glVertex2f(248.75,23.0+k);
        glVertex2f(250.75,23.0+k);
        glVertex2f(250.75,40.0+k);
        glVertex2f(248.75,40.0+k);
    glEnd();

	glColor3f(.90,.0,.0);//bonnet
	glBegin(GL_POLYGON);//front
        glVertex2f(237.5,120.0+k);
        glVertex2f(262.5,120.0+k);
        glVertex2f(250,170.0+k);
	glEnd();

    glColor3f(.4,.4,.4);
    glBegin(GL_POLYGON);//left_side_bottom
        glVertex2f(237.5,20.0+k);
        glVertex2f(217.5,10.0+k);
        glVertex2f(217.5,20.0+k);
        glVertex2f(237.5,70.0+k);
	glEnd();

    glBegin(GL_POLYGON);//right_side_bottom
        glVertex2f(262.5,20.0+k);
        glVertex2f(282.5,10.0+k);
        glVertex2f(282.5,20.0+k);
        glVertex2f(262.5,70.0+k);
	glEnd();

	//Rocket exhaust design
	glColor3f(0.0 ,0.0  ,0.0);
    glBegin(GL_POLYGON);//
        glVertex2f(242.5,20.0+k);
        glVertex2f(257.5,20.0+k);
         glVertex2f(261.5,7.0+k);
        glVertex2f(238.5,7.0+k);
	glEnd();

}
