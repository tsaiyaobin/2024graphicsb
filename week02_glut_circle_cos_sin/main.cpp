#include <GL/glut.h>
#include <math.h>
void myCircle(float cx,float cy ,float r)
{
    glBegin(GL_POLYGON);///�}�l�e
    for(float a=0;a<3.1415*2;a+=0.1){///�ܦh���P������
        glVertex2f(r*cos(a)+cx,r*sin(a)+cy);
    }
    glEnd();///����
}
void display()
{
    glColor3f(1,1,1); myCircle(0,0,1);
    glColor3f(0,0,0); myCircle(-0.5,+0.5,0.3);
    glColor3f(0,0,0); myCircle(+0.5,+0.5,0.3);
    glColor3f(0,0,0); myCircle(0,-0.3,0.7);
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
