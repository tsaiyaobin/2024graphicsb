#include <GL/glut.h>
void display()
{
    glColor3f(247/255.0,180/255.0,171/255.0);///�w�g���Y�v�C��
    glutSolidTeapot(0.3);///�e�@�ӹ�ߪ�����,�j�p�O0.3
    glColor3f(251/255.0,233/255.0,219/255.0);///�w�g���y���C��
    glutSolidTeapot(0.2);
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
