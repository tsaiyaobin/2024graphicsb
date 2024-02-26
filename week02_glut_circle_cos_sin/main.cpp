#include <GL/glut.h>
#include <math.h>
void myCircle(float cx,float cy ,float r)
{
    glBegin(GL_POLYGON);///開始畫
    for(float a=0;a<3.1415*2;a+=0.1){///很多不同的角度
        glVertex2f(r*cos(a)+cx,r*sin(a)+cy);
    }
    glEnd();///結束
}
void display()
{
    glColor3f(1,1,1); myCircle(0,0,1);
    glColor3f(0,0,0); myCircle(-0.5,+0.5,0.3);
    glColor3f(0,0,0); myCircle(+0.5,+0.5,0.3);
    glColor3f(0,0,0); myCircle(0,-0.3,0.7);
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
