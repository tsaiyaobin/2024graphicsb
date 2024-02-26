#include <GL/glut.h>
void display()
{
    glBegin(GL_POLYGON);///開始畫

        glColor3f(1,1,1);
        glVertex2f((30-200)/200.0,-(45-200)/200.0);
        glVertex2f((46-200)/200.0,-(102-200)/200.0);
        glVertex2f((84-200)/200.0,-(23-200)/200.0);
    glEnd();///結束
	glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])
{ ///上面是特別的main函式,有很多參數
	glutInit(&argc, argv);///把GLUT開起來 （GLUT初始化）
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        ///上面這行是把顯示的模式設定好
	glutCreateWindow("GLUT Shapes");///要開視窗
	glutDisplayFunc(display);///要顯示的對應函式
	glutMainLoop();///最後用main迴圈,壓在最後面
}

