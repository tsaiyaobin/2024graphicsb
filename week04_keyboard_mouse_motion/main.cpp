#include <GL/glut.h>
#include <stdio.h>
int N = 0;
float teapotX[1000],teapotY[1000];///存座標
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景
    for(int i=0;i<N;i++){
        glPushMatrix();
            glTranslatef(teapotX[i],teapotY[i],0);
            glutSolidTeapot(0.03);///畫一個實心的茶壺,大小是0.3
        glPopMatrix();
    }
    glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
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
{ ///上面是特別的main函式,有很多參數
	glutInit(&argc, argv);///把GLUT開起來 （GLUT初始化）
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        ///上面這行是把顯示的模式設定好
	glutCreateWindow("week04 keyboard mouse motion");///要開視窗
	glutDisplayFunc(display);///要顯示的對應函式
	glutKeyboardFunc(keyboard);///鍵盤事件函式
	glutMouseFunc(mouse);///滑鼠事件的函式
	glutMainLoop();///最後用main迴圈,壓在最後面
}
