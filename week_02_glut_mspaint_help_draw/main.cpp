#include <GL/glut.h>
void display()
{
    glBegin(GL_POLYGON);///�}�l�e

        glColor3f(1,1,1);
        glVertex2f((30-200)/200.0,-(45-200)/200.0);
        glVertex2f((46-200)/200.0,-(102-200)/200.0);
        glVertex2f((84-200)/200.0,-(23-200)/200.0);
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

