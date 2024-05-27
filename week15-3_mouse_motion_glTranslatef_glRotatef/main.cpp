#include <GL/glut.h>
float angleX[15]={},angleY[15]={};///關節要夠用
void display()
{
    ///glClearColor(1,1,0,1);///黃色背景,可幫你確認模型有沒有黑黑的
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///要寫任何程式來畫圖,一定要包起來
        glTranslatef(angleX[14]/150.0,-angleY[14]/150.0,0);///拿來當成移動的
        glRotatef(angleX[0],1,0,0);
        glRotatef(angleX[0],0,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
	glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}
int angleID=0,oldX=0,oldY=0;
void mouse(int button,int state,int x,int y){
    oldX=x;
    oldY=y;
}
void motion(int x,int y){
    angleX[angleID]+=x-oldX;
    angleY[angleID]+=y-oldY;
    oldX=x;
    oldY=y;
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y){
    if(key=='x') angleID = 14;
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week15-3");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutMainLoop();
}
