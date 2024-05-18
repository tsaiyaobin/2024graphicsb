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


int angleID=0;
float angle[40];
float i=0, di=1;
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    glPushMatrix();
        glScalef(0.6, 0.6, 0.6);
        glutSolidSphere(0.1,30,30);
    glPopMatrix();

    glPushMatrix();
        glRotatef(180, 0, 1, 0);
        drawbody();///身體

        glPushMatrix();
            glTranslatef(0.35,0.02,-0.6);
            glRotatef(angle[0],1,0,0);
            glRotatef(angle[1],0,1,0);
            glRotatef(angle[2],0,0,1);
            glTranslatef(0.2,0.1,0.03);
            drawarm1();///左上手臂
            glPushMatrix();
                glTranslatef(0.10,0.07,0);
                glRotatef(angle[3],1,0,0);
                glRotatef(angle[4],0,1,0);
                glRotatef(angle[5],0,0,1);
                glTranslatef(0.2,0.1,0);
                drawhand1(); ///左下手臂
            glPopMatrix();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(-0.27,0,0);
            glRotatef(angle[6],1,0,0);
            glRotatef(angle[7],0,1,0);
            glRotatef(angle[8],0,0,1);
            glTranslatef(-0.15,0.1,0);
            drawarm2();///右上
            glPushMatrix();
                glTranslatef(-0.11,0.078,0);
                glRotatef(angle[9],1,0,0);
                glRotatef(angle[10],0,1,0);
                glRotatef(angle[11],0,0,1);
                glTranslatef(-0.2,0.1,0);
                drawhand2();///右下
            glPopMatrix();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(0.3,-0.4,-0.1);
            glRotatef(angle[12],1,0,0);
            glRotatef(angle[13],0,1,0);
            glRotatef(angle[14],0,0,1);
            glTranslatef(0,-0.1,0);
            drawfoot1();///右上
            glPushMatrix();
                glTranslatef(0.007,-0.15,0);
                glRotatef(angle[15],1,0,0);
                glRotatef(angle[16],0,1,0);
                glRotatef(angle[17],0,0,1);
                glTranslatef(0.049,-0.15,0);
            drawshoe1();///右上
            glPopMatrix();
        glPopMatrix();



        glPushMatrix();
            glTranslatef(0,-0.47,-0.1);
            glRotatef(angle[18],1,0,0);
            glRotatef(angle[19],0,1,0);
            glRotatef(angle[20],0,0,1);
            glTranslatef(0,-0.1,0);
            drawfoot1();///右上
            glPushMatrix();
                glTranslatef(0.003,-0.18,0);
                glRotatef(angle[21],1,0,0);
                glRotatef(angle[22],0,1,0);
                glRotatef(angle[23],0,0,1);
                glTranslatef(0.017,-0.15,0);
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



void keyboard(unsigned char key,int x,int y){
    if(key=='r'){ ///讀angle.txt近來
        if(fin==NULL) fin=fopen("angle.txt","r");
        for(int i=0;i<20;i++){
            fscanf(fin,"%f",&angle[i]);
        }
        glutPostRedisplay;
    }
     if(key=='w'){///把角度寫進angle.txt
        if(fout==NULL) fout=fopen("angle.txt","w+");
        for(int i=0;i<20;i++){
            printf("%.1f",angle[i]);
            fprintf(fout,"%.1f ",angle[i]);
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
    if(key=='9') angleID=9;
    if(key=='z') angleID=10;
    if(key=='x') angleID=11;
    if(key=='a') angleID=12;
    if(key=='s') angleID=13;
    if(key=='d') angleID=14;
    if(key=='f') angleID=15;
    if(key=='g') angleID=16;
    if(key=='h') angleID=17;
    if(key=='i') angleID=18;
    if(key=='o') angleID=19;
    if(key=='p') angleID=20;
    if(key=='j') angleID=21;
    if(key=='k') angleID=22;
    if(key=='l') angleID=23;
}
int oldX=0, oldY=0;
void mouse(int button,int state,int x,int y){
    oldX=x;
    oldY=y;
}
void motion(int x,int y){
    angle[angleID]+=y-oldY;
    oldX=x;
    oldY=y;
    glutPostRedisplay();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Homework");
    glutDisplayFunc(display);
    ///myTexture("Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glutKeyboardFunc(keyboard);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

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
}
