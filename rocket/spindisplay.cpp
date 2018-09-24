#include<windows.h>
#include <GL/glut.h>
void spindisplay(float cx)
{

      cx = cx + .15;
    if(cx>70)
        cx = -70;

    glutPostRedisplay();
}
