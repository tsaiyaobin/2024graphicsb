#include <GL/glut.h>
void display()
{
    glColor3f(247/255.0,180/255.0,171/255.0);///安妮雅頭髮顏色
    glutSolidTeapot(0.3);///畫一個實心的茶壺,大小是0.3
    glColor3f(251/255.0,233/255.0,219/255.0);///安妮雅臉的顏色
    glutSolidTeapot(0.2);
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
