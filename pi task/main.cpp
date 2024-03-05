#include <gl/gl.h>
#include <gl/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void sleep2(int duration)
{
    int end=clock()+duration;
    while(clock()<=end);
}

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,500);
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

    //glPointSize(4);


    glColor3f(1,0,0);
    //glVertex2i(round (x), round (y));

    for (k = 0; k < steps; k++) {
        x += xinc;
        y += yinc;

        glBegin(GL_POINTS);
            glVertex2i (round (x), round (y));
        glEnd();


    glFlush();
    sleep2(1);

    }

glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    GLubyte bitmap[]={0x00,0x3,0x1F,0x1C,0x76,0x00};
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    glRasterPos2i(50,100);
    glBitmap(8,8,0,0,10,10,bitmap);







glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,600);
    glutCreateWindow("DDA Line Demo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

}
