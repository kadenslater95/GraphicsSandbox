
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void displayFunc();

void checkerboard(int, int, int);


int viewWidth = 640;
int viewHeight = 480;


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

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(viewWidth, viewHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("OpenGL UT Template");

    glutDisplayFunc(displayFunc);

    init();

    glutMainLoop();

    return 0;
}

void displayFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    checkerboard(25, viewHeight - 25, 50);

    glFlush();
}


void checkerboard(int x, int y, int l) {
    glBegin(GL_QUADS);

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 1) {
                continue;
            }

            glVertex2i(x + l*i, y - l*j);
            glVertex2i(x + l*(i+1), y - l*j);
            glVertex2i(x + l*(i+1), y - l*(j+1));
            glVertex2i(x + l*i, y - l*(j+1));
        } 
    }

    glEnd();
}

