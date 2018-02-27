#include <GL/freeglut.h>
#include <GL/gl.h>
#include "LibDraw.cxx"

void myInit (void){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 360, 0, 536);
}

void myDisplay (void)
{
    std::vector<GLfloat> color = {0.54, 0.17, 0.89};
    glClear(GL_COLOR_BUFFER_BIT);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glColor3f(0.54, 0.17, 0.89);

    //left leg
    //foot
    glBegin(GL_TRIANGLES);
        glVertex2f(40, 40);
        glVertex2f(100, 40);
        glVertex2f(100, 60);
        glVertex2f(100, 40);
        glVertex2f(100, 60);
        glVertex2f(112, 50);
    glEnd();

    drawCircle(122, 50, 10, color);

    //shin
    glBegin(GL_TRIANGLES);
        glVertex2f(122, 60);
        glVertex2f(104, 160);
        glVertex2f(144, 160);
        glVertex2f(104, 160);
        glVertex2f(144, 160);
        glVertex2f(122, 180);
    glEnd();

    drawCircle(122, 190, 10, color);

    //thigh
    glBegin(GL_TRIANGLES);
        glVertex2f(122, 200);
        glVertex2f(148, 272);
        glVertex2f(168, 252);
        glVertex2f(148, 272);
        glVertex2f(168, 252);
        glVertex2f(172, 272);
    glEnd();

    //end left leg
    drawCircle(180, 276, 8, color);

    //right leg
    //foot
    glBegin(GL_TRIANGLES);
        glVertex2f(320, 40);
        glVertex2f(260, 40);
        glVertex2f(260, 60);
        glVertex2f(260, 40);
        glVertex2f(260, 60);
        glVertex2f(248, 50);
    glEnd();

    drawCircle(238, 50, 10, color);

    //shin
    glBegin(GL_TRIANGLES);
        glVertex2f(238, 60);
        glVertex2f(256, 160);
        glVertex2f(216, 160);
        glVertex2f(256, 160);
        glVertex2f(216, 160);
        glVertex2f(238, 180);
    glEnd();

    drawCircle(238, 190, 10, color);

    //thigh
    glBegin(GL_TRIANGLES);
        glVertex2f(238, 200);
        glVertex2f(212, 272);
        glVertex2f(192, 252);
        glVertex2f(212, 272);
        glVertex2f(192, 252);
        glVertex2f(188, 272);
    glEnd();
    //end right leg

    //body
    glBegin(GL_TRIANGLES);
        glVertex2f(180, 284);
        glVertex2f(160, 400);
        glVertex2f(200, 400);
        glVertex2f(160, 400);
        glVertex2f(200, 400);
        glVertex2f(180, 420);
    glEnd();
    //endbody

    drawCircle(180, 430, 10, color);

    //head
    glBegin(GL_TRIANGLES);
        glVertex2f(180, 440);
        glVertex2f(172, 488);
        glVertex2f(188, 488);
        glVertex2f(172, 488);
        glVertex2f(188, 488);
        glVertex2f(180, 496);
    glEnd();
    //endhead

    //right arm
    glBegin(GL_TRIANGLES);
        glVertex2f(170, 430);
        glVertex2f(144, 432);
        glVertex2f(152, 408);
        glVertex2f(144, 432);
        glVertex2f(152, 408);
        glVertex2f(72, 344);
    glEnd();

    drawCircle(70, 334, 10, color);

    glBegin(GL_TRIANGLES);
        glVertex2f(70, 324);
        glVertex2f(60, 312);
        glVertex2f(80, 312);
        glVertex2f(60, 312);
        glVertex2f(80, 312);
        glVertex2f(70, 274);
    glEnd();
    //end right arm

    //left arm
    glBegin(GL_TRIANGLES);
        glVertex2f(190, 430);
        glVertex2f(216, 432);
        glVertex2f(208, 408);
        glVertex2f(216, 432);
        glVertex2f(208, 408);
        glVertex2f(288, 344);
    glEnd();

    drawCircle(290, 334, 10, color);

    glBegin(GL_TRIANGLES);
        glVertex2f(290, 324);
        glVertex2f(300, 312);
        glVertex2f(280, 312);
        glVertex2f(300, 312);
        glVertex2f(280, 312);
        glVertex2f(290, 274);
    glEnd();
    //end left arm

    glFlush();
}

void myResize (int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
}

int main (int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(360, 536);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GVentana1.0");
    myInit();
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myResize);
    glutMainLoop();

    return 0;

}
