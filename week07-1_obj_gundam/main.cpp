#include <GL/glut.h>
#include "glm.h"
GLMmodel* pmodel = NULL;
void drawmodel(void)
{
    if (!pmodel) {
        pmodel = glmReadOBJ("gundam.obj");
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    drawmodel();
    ///glutSolidTeapot(0.3);///�e�@�ӹ�ߪ�����,�j�p�O0.3
	glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}
int main(int argc, char *argv[])
{ ///�W���O�S�O��main�禡,���ܦh�Ѽ�
	glutInit(&argc, argv);///��GLUT�}�_�� �]GLUT��l�ơ^
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    ///�W���o��O����ܪ��Ҧ��]�w�n
	glutCreateWindow("week07-1 obj gundam");///�n�}����
	glutDisplayFunc(display);///�n��ܪ������禡
	glutMainLoop();///�̫��main�j��,���b�̫᭱
}
