// Copyright 2025 Kaden Slater

#include <stdio.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void displayFunc();
void timerFunc(int);
void specialFunc(int, int, int);

void checkerboard(int, int, int);


int viewWidth = 640;
int viewHeight = 480;

int checkerboardX = 0;
int checkerboardY = 0;
int checkerLength = 50;


void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) viewWidth, 0.0, (GLdouble) viewHeight);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(viewWidth, viewHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("OpenGL UT Template");

    glutDisplayFunc(displayFunc);
    glutTimerFunc(27, timerFunc, 0);
    glutSpecialFunc(specialFunc);

    init();

    glutMainLoop();

    return 0;
}


void displayFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    checkerboard(checkerboardX, checkerboardY, checkerLength);

    glutSwapBuffers();

    timerFunc(0);
}


void timerFunc(int value) {
    glutPostRedisplay();
}


void specialFunc(int key, int x, int y) {
    int delta = checkerLength * 15/100;

    switch (key) {
        case GLUT_KEY_RIGHT:
            checkerboardX -= delta;
            break;
        case GLUT_KEY_DOWN:
            checkerboardY += delta;
            break;
        case GLUT_KEY_LEFT:
            checkerboardX += delta;
            break;
        case GLUT_KEY_UP:
            checkerboardY -= delta;
            break;
        default:
            break;
    }
}


void checkerboard(int x, int y, int l) {
    glBegin(GL_QUADS);

    // Note 2 additional rows/columns to handle the edges.
    int numColumns = viewWidth / l + 2;
    int numRows = viewHeight / l + 2;

    int viewX = x % l;
    int viewY = y % l;

    for (int i = 0; i < numColumns; i++) {
        for (int j = 0; j < numRows; j++) {
            if ((i + j) % 2 == 1) {
                continue;
            }

            glVertex2i(viewX + l*i, viewY + l*j);
            glVertex2i(viewX + l*i, viewY + l*(j+1));
            glVertex2i(viewX + l*(i+1), viewY + l*(j+1));
            glVertex2i(viewX + l*(i+1), viewY + l*j);
        }
    }

    glEnd();
}

