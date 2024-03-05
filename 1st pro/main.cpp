#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glPointSize(4);

    glBegin(GL_POINTS);
        glVertex2i(320,240);
        glVertex2i(335,240);
        glVertex2i(320,220);
    glEnd();

    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Welcome to OpenGL");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}
