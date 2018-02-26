#include <vector>
#include <cmath>
#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>

void drawPixel(int x, int y)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawPixel(int x, int y, std::vector<GLfloat> color)
{
    glBegin(GL_POINTS);
    glColor3f(color[0], color[1], color[2]);
    glVertex2i(x, y);
    glEnd();
}

void drawPixel(int x, int y, GLfloat size, std::vector<GLfloat> color)
{
    if(size != -1)
        glPointSize(size);
    glBegin(GL_POINTS);
    glColor3f(color[0], color[1], color[2]);
    glVertex2i(x, y);
    glEnd();
}

void drawSym8Pixel(int x, int x_c, int y, int y_c)
{
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_POINTS);
        glVertex2i(x + x_c, y + y_c);
        glVertex2i(y + x_c, x + y_c);
        glVertex2i(y + x_c, -x + y_c);
        glVertex2i(x + x_c, -y + y_c);
        glVertex2i(-x + x_c, y + y_c);
        glVertex2i(-y + x_c, x + y_c);
        glVertex2i(-y + x_c, -x + y_c);
        glVertex2i(-x + x_c, -y + y_c);
    glEnd();
}

void drawSym8Pixel(int x, int x_c, int y, int y_c, std::vector<GLfloat> color)
{
    glColor3f(color[0], color[1], color[2]);

    glBegin(GL_POINTS);
        glVertex2i(x + x_c, y + y_c);
        glVertex2i(y + x_c, x + y_c);
        glVertex2i(y + x_c, -x + y_c);
        glVertex2i(x + x_c, -y + y_c);
        glVertex2i(-x + x_c, y + y_c);
        glVertex2i(-y + x_c, x + y_c);
        glVertex2i(-y + x_c, -x + y_c);
        glVertex2i(-x + x_c, -y + y_c);
    glEnd();
}

void drawSym4Pixel(int x, int x_c, int y, int y_c)
{
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_POINTS);
        glVertex2i(x + x_c, y + y_c);
        glVertex2i(x + x_c, -y + y_c);
        glVertex2i(-x + x_c, y + y_c);
        glVertex2i(-x + x_c, -y + y_c);
    glEnd();
}

void drawCircle(int x_c, int y_c, int r)
{
    float p_k = (5.0 / 4.0) - r;
    int x = 0, y = r;

    drawSym8Pixel(x, x_c, y, y_c);

    while(x < y)
    {
        if(p_k < 0)
        {
            x++;
            drawSym8Pixel(x, x_c, y, y_c);
            p_k =  p_k + (2 * x) + 1;
        }
        else
        {
            x++; y--;
            drawSym8Pixel(x, x_c, y, y_c);
            p_k =  p_k + (2 * x) + 1 - (2 * y);
        }
    }
}

void drawCircle(int x_c, int y_c, int r, std::vector<GLfloat> color)
{
    float p_k = (5.0 / 4.0) - r;
    int x = 0, y = r;

    drawSym8Pixel(x, x_c, y, y_c, color);

    while(x < y)
    {
        if(p_k < 0)
        {
            x++;
            drawSym8Pixel(x, x_c, y, y_c, color);
            p_k =  p_k + (2 * x) + 1;
        }
        else
        {
            x++; y--;
            drawSym8Pixel(x, x_c, y, y_c, color);
            p_k =  p_k + (2 * x) + 1 - (2 * y);
        }
    }
}


void drawEllipse(int x_c, int y_c, int r_x, int r_y)
{
    //Region 1
    float p1_k = pow(r_y, 2) - (pow(r_x, 2) * r_y) + (pow(r_x, 2) / 4);
    int x = 0, y = r_y;

    drawSym4Pixel(x, x_c, y, y_c);
    while((2 * pow(r_y, 2) * x) < (2 * pow(r_x, 2) * y))
    {
        if(p1_k < 0)
        {
            x++;
            drawSym4Pixel(x, x_c, y, y_c);
            p1_k = p1_k + (2 * pow(r_y, 2) * x) + pow(r_y, 2);
        }
        else
        {
            x++; y--;
            drawSym4Pixel(x, x_c, y, y_c);
            p1_k = p1_k + (2 * pow(r_y, 2) * x) + pow(r_y, 2) - (2 * pow(r_x, 2) * y);
        }
    }

    //Region 2
    float p2_k = pow(r_y, 2) * pow((x + (1 / 2)), 2);
    p2_k += (pow(r_x, 2) * pow((y - 1), 2)) - (pow(r_x, 2) * pow(r_y, 2));

    while(y != 0)
    {
        if(p2_k > 0)
        {
            y--;
            drawSym4Pixel(x, x_c, y, y_c);
            p2_k = p2_k - (2 * pow(r_x, 2) * y) + pow(r_x, 2);
        }
        else
        {
            y--; x++;
            drawSym4Pixel(x, x_c, y, y_c);
            p2_k = p2_k + (2 * pow(r_y, 2) * x) - (2 * pow(r_x, 2) * y) + pow(r_x, 2);
        }
    }
}
