#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>

///上週有做過, 請用剪貼的
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * arm1 = NULL;
GLMmodel * arm2 = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * hand2 = NULL;
GLMmodel * foot1 = NULL;
GLMmodel * foot2 = NULL;
GLMmodel * shoe1 = NULL;
GLMmodel * shoe2 = NULL;

void drawbody(void) ///身體
{
    glPushMatrix();
        glScalef(0.6, 0.6, 0.6);
        if (!pmodel)
        {
            pmodel = glmReadOBJ("body.obj");
            if (!pmodel)
                exit(0);
            glmUnitize(pmodel);
            glmFacetNormals(pmodel);
            glmVertexNormals(pmodel, 90.0);
        }
        glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}

void drawarm1(void) ///右上手臂
{
    glPushMatrix();
        glScalef(0.6, 0.6, 0.6);
        if (!arm1)
        {
            arm1 = glmReadOBJ("right_arm.obj");
            if (!arm1) exit(0);
            glmUnitize(arm1);
            glmFacetNormals(arm1);
            glmVertexNormals(arm1, 90.0);
        }
        glmDraw(arm1, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}

void drawarm2(void) ///左上手臂
{
    glPushMatrix();
        glScalef(0.6, 0.6, 0.6);
        if (!arm2)
        {
            arm2 = glmReadOBJ("left_arm.obj");
            ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
            ///本週,要換更好的地方
            if (!arm2) exit(0);
            glmUnitize(arm2);
            glmFacetNormals(arm2);
            glmVertexNormals(arm2, 90.0);
        }
        glmDraw(arm2, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}

void drawhand1(void) ///右下手臂
{
    glPushMatrix();
        glScalef(0.6, 0.6, 0.6);
        if (!hand1)
        {
            hand1 = glmReadOBJ("right_hand.obj");
            ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
            ///本週,要換更好的地方
            if (!hand1) exit(0);
            glmUnitize(hand1);
            glmFacetNormals(hand1);
            glmVertexNormals(hand1, 90.0);
        }
        glmDraw(hand1, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}

void drawhand2(void) ///左下手臂
{
    glPushMatrix();
        glScalef(0.6, 0.6, 0.6);
        if (!hand2)
        {
            hand2 = glmReadOBJ("left_hand.obj");
            ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
            ///本週,要換更好的地方
            if (!hand2) exit(0);
            glmUnitize(hand2);
            glmFacetNormals(hand2);
            glmVertexNormals(hand2, 90.0);
        }
        glmDraw(hand2, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}

void drawfoot1(void) ///右大腿
{
    glPushMatrix();
        glScalef(0.6, 0.6, 0.6);
        if (!foot1)
        {
            foot1 = glmReadOBJ("right_foot.obj");
            ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
            ///本週,要換更好的地方
            if (!foot1) exit(0);
            glmUnitize(foot1);
            glmFacetNormals(foot1);
            glmVertexNormals(foot1, 90.0);
        }
        glmDraw(foot1, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}

void drawfoot2(void) ///左大腿
{
    glPushMatrix();
        glScalef(0.6, 0.6, 0.6);
        if (!foot2)
        {
            foot2 = glmReadOBJ("left_foot.obj");
            ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
            ///本週,要換更好的地方
            if (!foot2) exit(0);
            glmUnitize(foot2);
            glmFacetNormals(foot2);
            glmVertexNormals(foot2, 90.0);
        }
        glmDraw(foot2, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}

void drawshoe1(void) ///右小腿
{
    glPushMatrix();
        glScalef(0.6, 0.6, 0.6);
        if (!shoe1)
        {
            shoe1 = glmReadOBJ("right_shoe.obj");
            ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
            ///本週,要換更好的地方
            if (!shoe1) exit(0);
            glmUnitize(shoe1);
            glmFacetNormals(shoe1);
            glmVertexNormals(shoe1, 90.0);
        }
        glmDraw(shoe1, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}

void drawshoe2(void) ///左小腿
{
    glPushMatrix();
        glScalef(0.6, 0.6, 0.6);
        if (!shoe2)
        {
            shoe2 = glmReadOBJ("left_shoe.obj");
            ///上週的模型檔,放在奇怪的目錄裡 桌面\freeglut\bin
            ///本週,要換更好的地方
            if (!shoe2) exit(0);
            glmUnitize(shoe2);
            glmFacetNormals(shoe2);
            glmVertexNormals(shoe2, 90.0);
        }
        glmDraw(shoe2, GLM_SMOOTH | GLM_MATERIAL);
    glPopMatrix();
}

float bodyX = 0 , bodyY = 0;
int angleID=0;
float angleX[20]={ };
float angleY[20]={ };
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

     glPushMatrix();
        glScalef(0.3, 0.3, 0.3);
        glutSolidSphere(0.1,30,30);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(bodyX,bodyY,0);
        glRotatef(180, 0, 1, 0);
        glRotatef(angleX[0],1,0,0);
        glRotatef(angleY[0],0,-1,0);
        drawbody();///身體

        glPushMatrix();
            glTranslatef(0.4,0.02,-0.05);
            glRotatef(angleX[1],1,0,0);
            glRotatef(angleY[1],0,-1,0);
            ///glRotatef(angle[2],0,0,1);
            glTranslatef(0.15,0.1,0);
            drawarm1();///左上手臂
            glPushMatrix();
                glScalef(0.35, 0.35, 0.35);
                glTranslatef(0.35,0.2,-0.01);
                glutSolidSphere(0.1,30,30);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.13,0.075,0);
                glRotatef(angleX[2],1,0,0);
                glRotatef(angleY[2],0,-1,0);
                ///glRotatef(angle[5],0,0,1);
                glTranslatef(0.18,0.09,0);
                drawhand1(); ///左下手臂
            glPopMatrix();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(-0.27,0,0);
            glRotatef(angleX[3],1,0,0);
            glRotatef(angleY[3],0,-1,0);
            ///glRotatef(angle[8],0,0,1);
            glTranslatef(-0.15,0.1,0);
            drawarm2();///右上
            glPushMatrix();
                glScalef(0.35, 0.35, 0.35);
                glTranslatef(-0.35,0.18,-0.01);
                glutSolidSphere(0.1,30,30);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.14,0.08,0);
                glRotatef(angleX[4],1,0,0);
                glRotatef(angleY[4],0,-1,0);
                ///glRotatef(angle[11],0,0,1);
                glTranslatef(-0.18,0.085,0);
                drawhand2();///右下
            glPopMatrix();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(0.3,-0.43,-0.05);
            glRotatef(angleX[5],1,0,0);
            glRotatef(angleY[5],0,-1,0);
            ///glRotatef(angle[14],0,0,1);
            glTranslatef(0,-0.15,0);
            drawfoot1();///右上
            glPushMatrix();
                glScalef(0.35, 0.35, 0.35);
                glTranslatef(0.02,-0.4,0.03);
                glutSolidSphere(0.1,30,30);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.007,-0.15,0.01);
                glRotatef(angleX[6],1,0,0);
                glRotatef(angleY[6],0,-1,0);
                ///glRotatef(angle[17],0,0,1);
                glTranslatef(0.049,-0.159,-0.01);
                drawshoe1();///右上
            glPopMatrix();

        glPopMatrix();


        glPushMatrix();
            glTranslatef(0,-0.47,-0.05);
            glRotatef(angleX[7],1,0,0);
            glRotatef(angleY[7],0,-1,0);
            ///glRotatef(angle[20],0,0,1);
            glTranslatef(0,-0.15,-0.004);
            drawfoot1();///右上
            glPushMatrix();
                glScalef(0.35, 0.35, 0.35);
                glTranslatef(0.01,-0.45,0.03);
                glutSolidSphere(0.1,30,30);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.003,-0.138,0);
                glRotatef(angleX[8],1,0,0);
                glRotatef(angleY[8],0,-1,0);
                ///glRotatef(angle[23],0,0,1);
                glTranslatef(0.017,-0.2,0);
            drawshoe2();///右上
        glPopMatrix();
        glPopMatrix();

    glPopMatrix();


    glutSwapBuffers();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
#include <stdio.h>
FILE * fout=NULL;
FILE * fin=NULL;
bool isDragging = false;
void timer(int t);
int oldX=0, oldY=0;
void mouse(int button,int state,int x,int y){
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            oldX = x;
            oldY = y;
            isDragging = true;
        } else if (state == GLUT_UP) {
            isDragging = false;
        }
    }
    oldX=x;
    oldY=y;

}
void motion(int x,int y){
    if (isDragging) {
        bodyX += (x - oldX) / 150.0;
        bodyY -= (y - oldY) / 150.0;
        oldX = x;
        oldY = y;
        glutPostRedisplay();
    }
    angleX[angleID]+=y-oldY;
    angleY[angleID]+=x-oldX;
    oldX=x;
    oldY=y;
    glutPostRedisplay();
}
#include "CMP3_MCI.h"
CMP3_MCI myMP3;
void keyboard(unsigned char key,int x,int y){
    if(key=='p'){
        glutTimerFunc(0,timer,0);
    }
    if(key=='c'){
        myMP3.Load("Fate.mp3");
        myMP3.Play();
    }
    if(key=='r'){
        if(fin==NULL) fin=fopen("angle.txt","r");
        for(int i=0;i<10;i++){
            fscanf(fin,"%f",&angleX[i]);
            fscanf(fin,"%f",&angleY[i]);
        }
        glutPostRedisplay;
    }
    if(key=='s'){
        if(fout==NULL) fout=fopen("angle.txt","w+");
        for(int i=0;i<10;i++){
            printf("%.1f ",angleX[i]);
            fprintf(fout,"%.1f ",angleX[i]);
            printf("%.1f ",angleY[i]);
            fprintf(fout,"%.1f ",angleY[i]);
        }
        printf("\n");
        fprintf(fout,"\n");
    }
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
    if(key=='5') angleID=5;
    if(key=='6') angleID=6;
    if(key=='7') angleID=7;
    if(key=='8') angleID=8;
}

float oldAngleX[10]={};
float oldAngleY[10]={};
float newAngleX[10]={};
float newAngleY[10]={};
void timer(int t){
    glutTimerFunc(20,timer,t+1);
    if(fin==NULL) fin=fopen("angle.txt","r");
    if(t%25==0){
        for(int i=0;i<10;i++){
            oldAngleX[i]=newAngleX[i];
            oldAngleY[i]=newAngleY[i];
            fscanf(fin,"%f",&newAngleX[i]);
            fscanf(fin,"%f",&newAngleY[i]);
        }
    }
    float alpha=(t%25)/25.0;
    for(int i=0;i<10;i++){
        angleX[i]=alpha*newAngleX[i]+(1-alpha)*oldAngleX[i];
        angleY[i]=alpha*newAngleY[i]+(1-alpha)*oldAngleY[i];
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{

    printf("程式開啟成功\n");///week14-2
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week07-2 obj gundam opencv texture");
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glutKeyboardFunc(keyboard);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    ///glutTimerFunc(0,timer,0);///week14-2
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutIdleFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
