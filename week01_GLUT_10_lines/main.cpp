#include <GL/glut.h>///�ϥ�GLUT�~��

void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char *argv[])///main�禡
{
    glutInit(&argc, argv);///��l�� GLUT

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");///�إߵ���

    glutDisplayFunc(display);///�]�w�n�e�Ϫ�display�禡

    glutMainLoop();///�D�n�j��

    return EXIT_SUCCESS;
}