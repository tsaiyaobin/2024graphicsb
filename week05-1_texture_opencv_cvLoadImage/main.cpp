#include <GL/glut.h>
#include <opencv/highgui.h>
void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    IplImage * img = cvLoadImage("c:/luffy.jpg");
    ///�b�j�g��Image
    cvShowImage("img",img);
    ///cvWaitKey(0);///�����N��b�~��

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week05-1 texture opencv");

    glutDisplayFunc(display);

    glutMainLoop();

}
