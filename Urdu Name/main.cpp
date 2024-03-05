// M.Afnan name 201155 in urdu,using circle
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define PI 3.1415926
void delay(int duration)
{

    int end=clock()+duration;
    while(clock()<=end);
}

void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}
void DDALine(GLint x0,GLint y0, GLint xEnd, GLint yEnd)
{
    GLint k;
    GLint dx=xEnd -x0;
    GLint dy=yEnd-y0;
    GLfloat xinc,yinc,x=x0,y=y0,steps;

    if (fabs (dx) > fabs (dy))
        steps = fabs (dx);
    else
        steps = fabs (dy);

    xinc = dx/steps;
    yinc = dy/steps;
    glColor3f(1,1,1);
    for (k = 0; k < steps; k++) {
        x += xinc;
        y += yinc;

        glBegin(GL_POINTS);
            glVertex2i (round (x), round (y));
        glEnd();


    glFlush();
    delay(5);

    }

glFlush();
}
void acircle(float xc,float yc,float radius)
{
    float x,y,angle;
    for(angle=PI/4;angle>=-PI/2;angle-=1/radius)
    {
         x=xc+radius*cos(angle);
         y=yc+radius*sin(angle);
     glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    glFlush();
    delay(5);
    }
}
void bcircle(float xc,float yc,float radius)
{
    float x,y,angle;
    for(angle=0;angle<=2*PI;angle+=1/radius)
    {
         x=xc+radius*cos(angle);
         y=yc+radius*sin(angle);
     glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    glFlush();
    delay(5);
    }
}
void ccircle(float xc,float yc,float radius)
{
    float x,y,angle;
    for(angle=PI/12;angle>=-13*PI/12;angle-=1/radius)
    {
         x=xc+radius*cos(angle);
         y=yc+radius*sin(angle);
     glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    glFlush();
    delay(5);
    }
}
void fcircle(float xc,float yc, float radius)
{
    float x,y,angle;

//    Draw a filled circle using Triangle Fan
    glBegin(GL_TRIANGLE_FAN);
    for(angle=0;angle<=2*PI;angle+=1/radius)
    {
        x=xc+radius*cos(angle);
        y=yc+radius*sin(angle);
        glVertex2i(x,y);
    }
    glEnd();
    glFlush();
    delay(50);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glPointSize(5);

    DDALine(530,320,530,175);
    bcircle(480,210,20);

    ccircle(458,210,40);
    ccircle(382,210,40);
    DDALine(342,220,342,350);
    ccircle(250,230,70);
    fcircle(480,255,7);
    fcircle(390,255,7);
    fcircle(250,255,7);

}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Afnan name in urdu ");

    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
