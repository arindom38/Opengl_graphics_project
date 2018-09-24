#include<windows.h>
#include <GL/glut.h>
#include "CIRCLE.h"

void cloud(GLint x,GLint y,GLint radi)
{
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(x+cx,y+5,0);
    circle(radi,50);
    glPopMatrix();

    //left

    glPushMatrix();
    glTranslatef(cx+x-15,y,0);
    circle(radi-5,50);
    glPopMatrix();

    //right

    glPushMatrix();
    glTranslatef(cx+x+15,y,0);
    circle(radi-6,50);
    glPopMatrix();

    //top right

    glPushMatrix();
    glTranslatef(cx+x+30,y,0);
    circle(radi-10,50);
    glPopMatrix();

    //middle

    glPushMatrix();

}
