#include<windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define PI 3.14159
#include<string>
#include "ROCKET.h"
#include "STARS.h"
#include "CIRCLE.h"
#include "SEMICIRCLE.h"
#include "ROCKET_FUMEIN.h"
#include "ROCKET_FUMEOUT.h"
#include "CLOUD.h"
#include "BLINKING_STARS.h"
#include "SPINDISPLAY.h"
#include "PRINTTEXT.h"

using namespace std;
const float DEG2RAD = 3.14159/180;
void display();
int p;
void introduction();
void static_rocket();
void rocket_to_cam_pos();
void	spindisplay();
void rocket_in_motion();
void mars(float radius);
void break_rocket();
void landing_moon();

float i,j,
    prt = 1,
	count0=0,    /*used to count delay in launching*/
	count1=0,  /*used to count blue sky delay*/
	count3=0,  /*used to count black sky delay*/
	flag=0,flag1=0,flag3=0,cx =0.0,state=0.0,
	t1=10   /* used to translate rocket initially*/
	;
//////////////////////////////////////////////
///background///
void background()
{
        //green ground
    	glColor3f(0.0,0.69,0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0.0,0.0);
		glVertex2f(0.0,250.0);
		glVertex2f(500.0,250.0);
		glVertex2f(500.0,50.0);
		glVertex2f(500.0,0.0);
		glEnd();

		//Bangladesh Flag

		//rectangle
		 glColor3f(0.0,0.5,0.0);
            glBegin(GL_POLYGON);
                glVertex2f(300,400);
                glVertex2f(360,400);
                glVertex2f(360,350);
                glVertex2f(300,350);
            glEnd();

            //circle
            glPushMatrix();
            glTranslatef(330,375,0);
            glColor3f(0.8,0.0,0.0);
            circle(10,50);
            glPopMatrix();

            //flag stand
             glColor3f(0.0,0.0,0.0);
            glBegin(GL_POLYGON);
                glVertex2f(297,400);
                glVertex2f(300,400);
                glVertex2f(300,230);
                glVertex2f(297,230);
            glEnd();




        //left cloud
        cloud(10,440,17);

		cloud(100,445,20);
		//right cloud
		cloud(400,445,20);
		//center cloud
		cloud(250,460,18);
		spindisplay();

        //tower1 antena
		semicircle(25,100,290);
        //tower ball
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(0.0,0.0,0.0,1.0);
        glPushMatrix();
        glTranslatef(115,315,0);
        circle(4,50);
        glPopMatrix();

        glColor3f(1.0,0.0,0.0);
		glBegin(GL_POLYGON);
		glVertex2f(100,290);
		glVertex2f(105,285);
		glVertex2f(115,312);
		glEnd();

		//tower pick
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_POLYGON);
		glVertex2f(90,250);
		glVertex2f(100,250);
		glVertex2f(100,268);
		glEnd();

		//tower rectangle
        glColor3f(0.0,0.5,0.50);
		glBegin(GL_POLYGON);
		glVertex2f(65,250);
		glVertex2f(125,250);
		glVertex2f(125,230);
		glVertex2f(65,230);
		glEnd();

		//control room
		  glColor3f(0.5,0.4,0.);
		glBegin(GL_POLYGON);
		glVertex2f(350,300);
		glVertex2f(440,300);
		glVertex2f(440,200);
		glVertex2f(350,200);
		glEnd();

		//control room window
		  glColor3f(0.0,0.0,0.);
		  glShadeModel(GL_SMOOTH);
		glBegin(GL_POLYGON);
		glVertex2f(360,280);
		glVertex2f(370,280);
		glVertex2f(370,260);
		glVertex2f(360,260);
		glEnd();

			glBegin(GL_POLYGON);
		glVertex2f(380,280);
		glVertex2f(390,280);
		glVertex2f(390,260);
		glVertex2f(380,260);
		glEnd();

			glBegin(GL_POLYGON);
		glVertex2f(400,280);
		glVertex2f(420,280);
		glVertex2f(420,260);
		glVertex2f(400,260);
		glEnd();

		//control room rooftop
    glColor3f(0.78,0,0);
    glPushMatrix();
    glTranslatef(395,300,0);
    circle(45,100);
    glPopMatrix();

    //Link to the control room
      glColor3f(0.0,0.0,0.0);
		glBegin(GL_POLYGON);
		glVertex2f(93,230);
		glVertex2f(97,230);
		glVertex2f(97,210);
		glVertex2f(93,210);
		glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(93,210);
        glVertex2f(350,210);
		glVertex2f(350,200);
		glVertex2f(93,200);
		glEnd();


}
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
void spindisplay()
{

      cx = cx + .20;
    if(cx>80)
        cx = -70;

    glutPostRedisplay();
}

///end background///
//////////////////////////////////////////////
///Display function///
void display()
{
count1++;
   if(prt > 0 && prt <2000)
            introduction();
   else if(flag ==0 && count1<2900)
       static_rocket();
    else if( (count1==2901)||(count1==2901))
       rocket_to_cam_pos();
    else if(count1>2901 && count0<701)
      rocket_in_motion();
    else if(count0 >700 && count0 <1000)
        break_rocket();
    else
            landing_moon();
}
///end display///
/////////////////////////////////////////
void introduction()
{
    prt++;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0,0.0,0.5);
	//glEnable(GL_DEPTH_TEST);
    char string[64];
    sprintf(string, "Bangladesh-1 is launching for its first mission to MOON ");
    printtext(200,400,string);
    sprintf(string, "YEAR , 2030..........");
    printtext(200,450,string);

   glutSwapBuffers();
   	glutPostRedisplay();
  	glFlush();
}

///static rocket fun///
void static_rocket()
{

count1++;
if(count1>2900) //rocket go to cam position
    flag=1;
if(flag==0) // rocket in ground
  {
	glClearColor(0.196078  ,0.6 ,0.8,1.0); //clear the color buffer and then set it to this values
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

if(t1>230)
{
     glPushMatrix();
	glTranslatef(0,-t1+230,0);
}

    background(); // background of the launching ground


state++;                //make launching delay
glPushMatrix();
if(state >150)
{
        glTranslatef(0,t1,0);
        t1++;                                     //keep rocket static
}
                                                    //call rocket body
	rocket(0);
	for(j=0;j<=10000000;j++)   //control rocket launching speed
		;
glPopMatrix();

glPushMatrix();           //matrix for stand holder left
glTranslatef(200,0,0);
glRotatef(t1,0,0,1);
glTranslatef(-200,0,0);

    glBegin(GL_POLYGON);//left_stand_holder
        glVertex2f(182.5,85.0);
        glVertex2f(182.5,0.0);
        glVertex2f(187.5,0.0);
        glVertex2f(187.5,80.0);
        glVertex2f(237.5,80.0);
        glVertex2f(237.5,85.0);
        glVertex2f(182.5,85.0);
    glEnd();

glPopMatrix();

glPushMatrix();                 //matrix for stand holder right
glTranslatef(300,0,0);
glRotatef(-t1,0,0,1);
glTranslatef(-300,0,0);

    glBegin(GL_POLYGON);
        glVertex2f(312.5,85.0);//right_stand_holder
        glVertex2f(312.5,0.0);
        glVertex2f(307.5,0.0);
        glVertex2f(307.5,80.0);
        glVertex2f(262.5,80.0);
        glVertex2f(262.5,85.0);
        glVertex2f(312.5,85.0);
    glEnd();

glPopMatrix();

if(t1>230)
	glPopMatrix();
}
    glutSwapBuffers();
  	glutPostRedisplay();
  	glFlush();
}
///end static rocket//
//////////////////////////////////////////////
///rocket cam pos///
void rocket_to_cam_pos()
{
	count0++;

for(i=0;i<=200;i++)
{
    if(count1==2901)
        glClearColor(0.0  ,0 ,1-(i)/200,1.0);
    else glClearColor(0.0  ,0 ,0.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    rocket(i);
	if((p%2)==0)
                glColor3f(1.0,0.25,0.0);
    else
                glColor3f(1.0,0.816,0.0);

     rocket_fumeout(i);

        if((p%2)==0)
				 glColor3f(1.0,0.816,0.0);
        else
                 glColor3f(1.0,0.25,0.0);

		rocket_fumein(i);
		p=p+1;
        for(j=0;j<=10000000;j++)
		;

	glutSwapBuffers();
    glutPostRedisplay();
	glFlush();
}
}
///end rocket cam pos//
//////////////////////////////////////////////
///rocket in motion fun///
void rocket_in_motion()
{
	count0++;
for(i=195;i<=200;i++)
{
     if(count0>=5)
	 {
            glClearColor(0.0 ,0.0 ,0.0,1.0);
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            if(flag1==0)
                {
                    stars();
                    flag1=1;
                }
            else
                {
                    blinking_stars();

                    flag1=0;
                }

	 }
	 else
             {
            glClearColor(0.0  ,0.0 ,0.0,1.0);
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
             }
	 if(count0>=150)
        mars(20.0);
	// call rocket body
	rocket(i);

	if((p%2)==0)
            glColor3f(1.0,0.25,0.0);
    else
            glColor3f(1.0,0.816,0.0);

        // rocket outer fume
        rocket_fumeout(i);

        if((p%2)==0)
            glColor3f(1.0,0.816,0.0);
        else
            glColor3f(1.0,0.25,0.0);

        //rocket  inner fume
        rocket_fumein(i);
		p=p+1;


	for(j=0;j<=1000000;j++)
		;
	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();
}
}
///end rocket in motion fun///
//////////////////////////////////////////////
///break rocket fun///
void break_rocket()
{
    count0++;
    for(i = 150 ;i <=155;i++)           //vibrate the rocket within 5 pixels
    {
        if (count0>701 && count0<850)
        {
            glClearColor(0.0  ,0.0 ,0.0,1.0);
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            if(flag1==0)
                {
                    stars();
                    flag1=1;
                }
            else
                {
                    blinking_stars();

                    flag1=0;
                }

            rocket(i);
        }
        else
        {
            glClearColor(0.0  ,0.0 ,0.0,1.0);
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


             char string[64];
                    sprintf(string, "The rocket lands on the MOON.");
                    glColor3f(1,1,1);
                    printtext(200,350,string);
        }

        for(j=0;j<=1000000;j++)
		;
		glutSwapBuffers();
        glutPostRedisplay();
        glFlush();
    }
}
///end break rocket///
/////////////////////////////////
void landing_moon()
{

            glClearColor(0.0  ,0.0 ,0.0,1.0);
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            stars();

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
            glColor4f(1.0,1.0,1.0,0.5);

            //Moon SURFACE
            glPushMatrix();
            glTranslatef(250,10,0);
            circle(250,25);
            glPopMatrix();

            glColor3f(0.0,0.0,0.0);
            glPointSize(3.0);
            glBegin(GL_POINTS);
            glVertex2f(20,15);
            glVertex2f(20,35);
            glVertex2f(30,45);
            glVertex2f(15,105);
            glVertex2f(50,15);
            glVertex2f(100,200);
            glVertex2f(110,60);
            glVertex2f(270,15);
            glVertex2f(380,105);
            glVertex2f(370,75);
            glVertex2f(390,85);
            glVertex2f(390,15);
            glVertex2f(390,40);
            glVertex2i(345,420);
            glVertex2i(130,360);
            glVertex2i(333,120);
            glVertex2i(250,22);
            glVertex2i(242,11);
            glVertex2i(280,332);
            glVertex2i(233,40);
            glVertex2i(210,418);
            glVertex2i(256,12);
            glVertex2i(288,232);
            glVertex2i(247,36);
            glVertex2i(229,342);
            glVertex2i(257,47);
            glVertex2i(290,63);
            glVertex2i(232,72);
            glVertex2i(243,143);
            glVertex2i(100,200);
            glVertex2i(90,250);
            glVertex2i(80,225);
            glVertex2i(50,333);
            glVertex2i(60,350);
            glVertex2i(243,143);
            glVertex2i(243,143);
            glEnd();

            //Little earth
            glColor4f(0.0,.5,1.0,0.5);
            glPushMatrix();
            glTranslatef(330,400,0);
            circle(30,50);
            glPopMatrix();
            rocket(50);

            //Bangladesh Flag
            //rectangle
		 glColor3f(0.0,0.5,0.0);
            glBegin(GL_POLYGON);
                glVertex2f(350,160);
                glVertex2f(410,160);
                glVertex2f(410,120);
                glVertex2f(350,120);
            glEnd();

            //circle
            glPushMatrix();
            glTranslatef(380,140,0);
            glColor3f(0.8,0.0,0.0);
            circle(10,50);
            glPopMatrix();

            //flag stand
             glColor3f(0.0,0.0,0.0);
            glBegin(GL_POLYGON);
                glVertex2f(347,160);
                glVertex2f(350,160);
                glVertex2f(350,80);
                glVertex2f(347,80);
            glEnd();



        glutSwapBuffers();
        glutPostRedisplay();
        glFlush();
}
///myInit fun///
void myinit()
{
	glClearColor(0.196078  ,0.6 ,0.8,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
	glOrtho(0.0, 499.0, 0.0, 499.0, -1.0,1.0);   //set projection view (L,R,B,T,near_val,far_val)
}
///end my init fun///
//////////////////////////////////////////////
///* * *main function* * *///
int main(int argc,char*argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(200,0);
	glutInitWindowSize(1000,700);
	glutCreateWindow("rocket");
    myinit();
	//glutIdleFunc(display);
	glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
