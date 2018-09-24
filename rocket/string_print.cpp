#include<windows.h>
#include <GL/glut.h>
void string_print(string str,
                     GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLint x, GLint y,
                     GLfloat w,GLfloat h,
                     GLfloat strokesize)
{
    glPushMatrix();

    glColor4f(r, g, b, a);
    glTranslatef(x, y , 0);
    glScalef(w, h, 0);

    glPointSize(strokesize);
    glLineWidth(strokesize);

    int i=0;
    while(i<str.size())
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, str[i]);

    glPopMatrix();

    glPointSize(1);
    glLineWidth(1);
}
