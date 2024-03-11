#include <GL/glut.h>
float s = 1;///一開始是原本一倍的大小
void display()
{
    glClearColor(1,1,0.9,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景
    glColor3f(0,1,0);
    glPushMatrix();
        glScalef(s,s,s);///縮放S倍
        glutSolidTeapot(0.3);///畫一個實心的茶壺,大小是0.3
    glPopMatrix();
	glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}
void motion(int x,int y)
{
    s = 1 + (x-150)/150.0;///會變大變小的0 ~ 1 ~ 2
    display();///重畫畫面
}
int main(int argc, char *argv[])
{ ///上面是特別的main函式,有很多參數
 	glutInit(&argc, argv);///把GLUT開起來 （GLUT初始化）

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        ///上面這行是把顯示的模式設定好

	glutCreateWindow("week03 Mouse");///要開視窗

	glutDisplayFunc(display);///要顯示的對應函式

	glutMotionFunc(motion);///拖動motion的時候

	glutMainLoop();///最後用main迴圈,壓在最後面

}
