#include <GL/glut.h>
float s = 1;///�@�}�l�O�쥻�@�����j�p
void display()
{
    glClearColor(1,1,0.9,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��
    glColor3f(0,1,0);
    glPushMatrix();
        glScalef(s,s,s);///�Y��S��
        glutSolidTeapot(0.3);///�e�@�ӹ�ߪ�����,�j�p�O0.3
    glPopMatrix();
	glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}
void motion(int x,int y)
{
    s = 1 + (x-150)/150.0;///�|�ܤj�ܤp��0 ~ 1 ~ 2
    display();///���e�e��
}
int main(int argc, char *argv[])
{ ///�W���O�S�O��main�禡,���ܦh�Ѽ�
 	glutInit(&argc, argv);///��GLUT�}�_�� �]GLUT��l�ơ^

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        ///�W���o��O����ܪ��Ҧ��]�w�n

	glutCreateWindow("week03 Mouse");///�n�}����

	glutDisplayFunc(display);///�n��ܪ������禡

	glutMotionFunc(motion);///���motion���ɭ�

	glutMainLoop();///�̫��main�j��,���b�̫᭱

}
