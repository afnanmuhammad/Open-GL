
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
    glClearColor(1,1,1,0);
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

    glPointSize(4);
   DDALine(500,200,500,400);
   DDALine(470,200,470,260);
   DDALine(470,260,420,260);

//use for dot
   DDALine(440,280,450,280);
   DDALine(450,280,450,290);
   DDALine(450,290,440,290);
   DDALine(440,290,440,280);


   DDALine(420,260,420,200);
   //DDALine(420,200,470,200);

   DDALine(470,200,350,200);
   DDALine(350,200,350,250);
   DDALine(350,200,300,200);

   //senod dot
   DDALine(330,310,330,290);
   DDALine(330,290,310,290);
   DDALine(310,290,310,310);
   DDALine(310,310,330,310);

   DDALine(300,200,300,400);


   //use for non
   DDALine(250,200,250,300);
   //non dots
    DDALine(200,300,200,280);
    DDALine(200,280,180,280);
    DDALine(180,280,180,300);
    DDALine(180,300,200,300);

   DDALine(250,200,150,200);
   DDALine(150,200,150,300);







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
