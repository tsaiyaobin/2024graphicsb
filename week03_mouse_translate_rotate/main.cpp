#include <GL/glut.h>
#include <stdio.h>///���Fprintf()
float teapotX = 0 , teapotY = 0;///�s�a���{��,�Ψө�������y��
float angle = 0;///���઺����
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��

    glPushMatrix();///�Ƥ��x�}
        glTranslatef(teapotX,teapotY,0);///�y�в���
        glRotatef(angle,0,0,1);///������z
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
    //glutSolidTeapot(0.3);///�e�@�ӹ�ߪ�����,�j�p�O0.3
	glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}
int method=1;///1:���� 2:����
int oldX=0,oldY=0;
void mouse(int button,int state,int x,int y)
{///�ڭ̳o�̭n���������ץ�
    oldX=x;
    oldY=y;
}
void motion(int x,int y)
{
    if(method==1){
        angle = x;
    }else if(method==2){
        teapotX += (x-oldX)/150.0;
        teapotY -= (y-oldY)/150.0;
    }
    oldX=x;
    oldY=y;
    display();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='e') method=1;///Rotate
    if(key=='w') method=2;///Translate
}
int main(int argc, char *argv[])
{ ///�W���O�S�O��main�禡,���ܦh�Ѽ�

	glutInit(&argc, argv);///��GLUT�}�_�� �]GLUT��l�ơ^
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        ///�W���o��O����ܪ��Ҧ��]�w�n
	glutCreateWindow("week03 mouse glTranslatef");///�n�}����

	glutDisplayFunc(display);///�n��ܪ������禡
	glutMouseFunc(mouse);///�o�@��]�wmouse�禡
    glutMotionFunc(motion);///�o��,�]�wmouse��motion�ʧ@
    glutKeyboardFunc(keyboard);
	glutMainLoop();///�̫��main�j��,���b�̫᭱
}
