#include <GL/glut.h>
#include <stdio.h>///為了printf()
void display()
{
    glutSolidTeapot(0.3);///畫一個實心的茶壺,大小是0.3
	glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}
void mouse(int button,int state,int x,int y)
{///定義mouse函式
    ///printf("Hello World\n");///遇到mouse印Hello
    /*button:0:滑鼠左鍵 1:滑鼠中鍵 2:滑鼠右鍵
      state: 0:滑鼠按下 1:滑鼠彈起           */
    ///printf("%d %d %d %d\n",button,state,x,y);
    if(state==GLUT_DOWN){
        printf("glVertex2f((%d-150)/150.0,-(%d-150)/150);\n",x,y);
    }
}
int main(int argc, char *argv[])
{ ///上面是特別的main函式,有很多參數

	glutInit(&argc, argv);///把GLUT開起來 （GLUT初始化）
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        ///上面這行是把顯示的模式設定好
	glutCreateWindow("week03 Mouse");///要開視窗

	glutDisplayFunc(display);///要顯示的對應函式
	glutMouseFunc(mouse);///這一行設定mouse函式

	glutMainLoop();///最後用main迴圈,壓在最後面
}
