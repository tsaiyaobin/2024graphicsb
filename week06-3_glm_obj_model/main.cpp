#include <GL/glut.h>
#include "glm.h"///使用glm的程式碼
GLMmodel* pmodel = NULL;///加的程式,有顆指標,指到模型檔
void drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/al.obj");
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
    drawmodel();///glutSolidTeapot(0.3);
	glutSwapBuffers();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week06-3");
	glutDisplayFunc(display);
	glutMainLoop();
}
