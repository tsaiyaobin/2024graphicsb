#include <GL/glut.h>
#include <stdio.h>///���Fprintf()
void display()
{
    glutSolidTeapot(0.3);///�e�@�ӹ�ߪ�����,�j�p�O0.3
	glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}
void mouse(int button,int state,int x,int y)
{///�w�qmouse�禡
    ///printf("Hello World\n");///�J��mouse�LHello
    /*button:0:�ƹ����� 1:�ƹ����� 2:�ƹ��k��
      state: 0:�ƹ����U 1:�ƹ��u�_           */
    ///printf("%d %d %d %d\n",button,state,x,y);
    if(state==GLUT_DOWN){
        printf("glVertex2f((%d-150)/150.0,-(%d-150)/150);\n",x,y);
    }
}
int main(int argc, char *argv[])
{ ///�W���O�S�O��main�禡,���ܦh�Ѽ�

	glutInit(&argc, argv);///��GLUT�}�_�� �]GLUT��l�ơ^
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        ///�W���o��O����ܪ��Ҧ��]�w�n
	glutCreateWindow("week03 Mouse");///�n�}����

	glutDisplayFunc(display);///�n��ܪ������禡
	glutMouseFunc(mouse);///�o�@��]�wmouse�禡

	glutMainLoop();///�̫��main�j��,���b�̫᭱
}
