#include <GL/glut.h>
void display()
{
    glBegin(GL_POLYGON);///�}�l�e

        glColor3f(1,0,0);glVertex2f(0,1);

        glColor3f(0,1,0);glVertex2f(1,-0.6);

        glColor3f(0,0,1);glVertex2f(-1,-0.6);
    glEnd();///����
	glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}
int main(int argc, char *argv[])
{ ///�W���O�S�O��main�禡,���ܦh�Ѽ�
	glutInit(&argc, argv);///��GLUT�}�_�� �]GLUT��l�ơ^
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        ///�W���o��O����ܪ��Ҧ��]�w�n
	glutCreateWindow("GLUT Shapes");///�n�}����
	glutDisplayFunc(display);///�n��ܪ������禡
	glutMainLoop();///�̫��main�j��,���b�̫᭱
}
