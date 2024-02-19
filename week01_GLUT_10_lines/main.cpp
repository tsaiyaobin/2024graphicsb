#include <GL/glut.h>///使用GLUT外掛

void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char *argv[])///main函式
{
    glutInit(&argc, argv);///初始化 GLUT

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");///建立視窗

    glutDisplayFunc(display);///設定要畫圖的display函式

    glutMainLoop();///主要迴圈

    return EXIT_SUCCESS;
}
