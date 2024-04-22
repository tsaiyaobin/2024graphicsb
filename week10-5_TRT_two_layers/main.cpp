#include <GL/glut.h>
void myBody()
{
    glColor3f(1,0,0);
    glutWireCube(0.6);///變空心
}
void myArm()
{
    glPushMatrix();///要加保護機制!!
        glColor3f(0,1,0);
        glScalef(1.5,0.5,0.5);
        glutWireCube(0.3);///變空心
    glPopMatrix();
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    ///glTranslatef(-0.6,+0.3,0);
        myBody();
    glPopMatrix();

    glPushMatrix();///右手上手臂
        glTranslatef(+0.3,+0.3,0);///移動整個手臂
        glRotatef(angle++,0,0,1);
        glTranslatef(0.225,0,0);///把移度中心做移動
        myArm();
        glPushMatrix();///右手下手臂
            glTranslatef(+0.225,0,0);///移動整個下手臂
            glRotatef(angle++,0,0,1);
            glTranslatef(0.225,0,0);///把移度中心做移動
            myArm();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();

}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09-2 glutSolid¨t¦C");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();

}


