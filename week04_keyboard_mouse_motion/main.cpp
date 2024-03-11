#include <GL/glut.h>
#include <stdio.h>
int N = 0;
float teapotX[1000],teapotY[1000];///�s�y��
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��
    for(int i=0;i<N;i++){
        glPushMatrix();
            glTranslatef(teapotX[i],teapotY[i],0);
            glutSolidTeapot(0.03);///�e�@�ӹ�ߪ�����,�j�p�O0.3
        glPopMatrix();
    }
    glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}
void keyboard(unsigned char key ,int x,int y)
{
    printf("key:%c x:%d y:%d\n",key,x,y);
}
void mouse(int button,int state,int x,int y)
{
    teapotX[N] = (x-150)/150.0;
    teapotY[N] = -(y-150)/150.0;
    N++;
}
int main(int argc, char *argv[])
{ ///�W���O�S�O��main�禡,���ܦh�Ѽ�
	glutInit(&argc, argv);///��GLUT�}�_�� �]GLUT��l�ơ^
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        ///�W���o��O����ܪ��Ҧ��]�w�n
	glutCreateWindow("week04 keyboard mouse motion");///�n�}����
	glutDisplayFunc(display);///�n��ܪ������禡
	glutKeyboardFunc(keyboard);///��L�ƥ�禡
	glutMouseFunc(mouse);///�ƹ��ƥ󪺨禡
	glutMainLoop();///�̫��main�j��,���b�̫᭱
}
