#include <GL/glut.h>
#include <stdio.h>///為了printf()
float teapotX = 0 , teapotY = 0;///新家的程式,用來放茶壺的座標
float angle = 0;///旋轉的角度
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景

    glPushMatrix();///備分矩陣
        glTranslatef(teapotX,teapotY,0);///座標移動
        glRotatef(angle,0,0,1);///最難的z
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    //glutSolidTeapot(0.3);///畫一個實心的茶壺,大小是0.3
	glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}
int method=1;///1:旋轉 2:移動
int oldX=0,oldY=0;
void mouse(int button,int state,int x,int y)
{///我們這裡要做巧妙的修正
    oldX=x;
    oldY=y;
}
void motion(int x,int y)
{
    if(method==1){
        angle = x;
    }else if(method==2){
        teapotX += (x-oldX)/150.0;
        teapotY -= (y-oldY)/150.0;
    }
    oldX=x;
    oldY=y;
    display();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='e') method=1;///Rotate
    if(key=='w') method=2;///Translate
}
int main(int argc, char *argv[])
{ ///上面是特別的main函式,有很多參數

	glutInit(&argc, argv);///把GLUT開起來 （GLUT初始化）
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
        ///上面這行是把顯示的模式設定好
	glutCreateWindow("week03 mouse glTranslatef");///要開視窗

	glutDisplayFunc(display);///要顯示的對應函式
	glutMouseFunc(mouse);///這一行設定mouse函式
    glutMotionFunc(motion);///這行,設定mouse的motion動作
    glutKeyboardFunc(keyboard);
	glutMainLoop();///最後用main迴圈,壓在最後面
}
