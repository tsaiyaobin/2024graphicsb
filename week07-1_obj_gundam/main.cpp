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
    ///glutSolidTeapot(0.3);///畫一個實心的茶壺,大小是0.3
	glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])
{ ///上面是特別的main函式,有很多參數
	glutInit(&argc, argv);///把GLUT開起來 （GLUT初始化）
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    ///上面這行是把顯示的模式設定好
	glutCreateWindow("week07-1 obj gundam");///要開視窗
	glutDisplayFunc(display);///要顯示的對應函式
	glutMainLoop();///最後用main迴圈,壓在最後面
}
