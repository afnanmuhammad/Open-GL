

//( MUHAMMAD AFNAN Rollno : 201155)

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#define PI 3.1415926

void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,1000,0,600);
}



float sunx = 500, suny = 300, earthx = 700, earthy = 300, Emoonx = 800, Emoony = 300,venusx = 650, venusy = 300,
marsx = 100, marsy = 200, Mmoon1x = 50, Mmoon1y = 200, Mmoon2x = 80, Mmoon2y = 200,
neptunex = 600, neptuney = 50, Nmoon1x = 50, Nmoon1y = 200, Nmoon2x = 80, Nmoon2y = 200,
saturnx = 100, saturny = 200, Smoon1x = 50, Smoon1y = 200, Smoon2x = 80, Smoon2y = 200;


float msdist = 80, msangle = 0, msinc = 1/750.0;

float vsdist = 100, mvangle = 0, mvinc = 1/160.0;

float esdist = 150, eangle = 0, einc = 1/650.0;
float medist = 50, mangle = 0, minc = 1/300.0;

float masdist = 180, maangle = 0, mainc = 1/450.0;
float Mm1dist = 40, Mm1angle = 0, Mm1inc = 1/100.0;
float Mm2dist = 40, Mm2angle = 0, Mm2inc = 1/300.0;


float nesdist = 260, neangle = 0, neinc = 1/950.0;
float Nm1dist = 50, Nm1angle = 0, Nm1inc = 1/100.0;
float Nm2dist = 50, Nm2angle = 0, Nm2inc = 1/300.0;


float sasdist = 260, saangle = 0, sainc = 1/650.0;
float Sm1dist = 50, Sm1angle = 0, Sm1inc = 1/200.0;
float Sm2dist = 50, Sm2angle = 0, Sm2inc = 1/300.0;






void delay(int duration)
{
    int end=clock()+duration;
    while(clock()<=end);
}


void drawcircle(float xc,float yc, float radius)
{
    float x,y,angle,inc=2*PI/16;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc,yc);
    for(angle=0;angle<=2*PI+inc;angle+=inc)
    {

        x=xc+radius*cos(angle);
        y=yc+radius*sin(angle);

        glVertex2f(x,y);
    }
    glEnd();
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(255,200,0);
    drawcircle(sunx, suny, 50);

    glColor3ub(0,150,50);
    drawcircle(earthx, earthy, 30);
    glColor3ub(100,100,100);
    drawcircle(Emoonx, Emoony, 10);


    glColor3ub(180,0,0);
    drawcircle(venusx, venusy, 20);

    glColor3ub(155,100,20);
    drawcircle(marsx, marsy, 20);
    glColor3ub(100,100,100);
    drawcircle(Mmoon1x, Mmoon1y, 10);



    glColor3ub(0,100,220);
    drawcircle(neptunex, neptuney, 30);
    glColor3ub(100,100,100);
    drawcircle(Nmoon1x, Nmoon1y, 10);
    glColor3ub(100,100,100);
    drawcircle(Nmoon2x, Nmoon2y, 10);




    glColor3ub(120,120,320);
    drawcircle(saturnx, saturny, 30);
    glColor3ub(100,100,100);
    drawcircle(Smoon1x, Smoon1y, 10);
    glColor3ub(100,100,100);
    drawcircle(Smoon2x, Smoon2y, 10);







    earthx = sunx + esdist*cos(eangle);
    earthy = suny + esdist*sin(eangle);
    Emoonx = earthx + medist*cos(mangle);
    Emoony = earthy + medist*sin(mangle);

    venusx = sunx + vsdist*cos(mvangle);
    venusy = suny + vsdist*sin(mvangle);


    marsx = sunx + masdist*cos(maangle);
    marsy = suny + masdist*sin(maangle);
    Mmoon1x = marsx + Mm1dist*cos(Mm1angle);
    Mmoon1y = marsy + Mm1dist*sin(Mm1angle);
//    Mmoon2x = marsx + Mm2dist*cos(Mm2angle);
  //  Mmoon2y = marsy + Mm2dist*sin(Mm2angle);


    neptunex = sunx + nesdist*cos(neangle);
    neptuney = suny + nesdist*sin(neangle);
    Nmoon1x = neptunex + Nm1dist*cos(Nm1angle);
    Nmoon1y = neptuney + Nm1dist*sin(Nm1angle);
    Nmoon2x = neptunex + Nm2dist*cos(Nm2angle);
    Nmoon2y = neptuney + Nm2dist*sin(Nm2angle);


    saturnx = sunx + sasdist*cos(saangle);
    saturny = suny + sasdist*sin(saangle);
    Smoon1x = saturnx + Sm1dist*cos(Sm1angle);
    Smoon1y = saturny + Sm1dist*sin(Sm1angle);
    Smoon2x = saturnx + Sm2dist*cos(Sm2angle);
    Smoon2y = saturny + Sm2dist*sin(Sm2angle);






   eangle+= einc;
   mangle-= minc;

   msangle+=msinc;

   mvangle+=mvinc;


   maangle+=mainc;
   Mm1angle-=Mm1inc;
   Mm2angle-=Mm2inc;


   neangle+=neinc;
   Nm1angle-=Nm1inc;
   Nm2angle-=Nm2inc;


   saangle+=sainc;
   Sm1angle-=Sm1inc;
   Sm2angle-=Sm2inc;


    glFlush();
    delay(1);



}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Solar System by Daniyal Riaz 201207");
    setup();
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
}
