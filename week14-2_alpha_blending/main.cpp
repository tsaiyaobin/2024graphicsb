#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
///�W�g�����L, �ХΰŶK��
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * arml = NULL;
GLMmodel * arm2 = NULL;
GLMmodel * upper = NULL;
GLMmodel * lower = NULL;
GLMmodel * body = NULL;
void drawbody(void)
{
        if (!body)
        {
            body = glmReadOBJ("body.obj");
            ///�W�g���ҫ���,��b�_�Ǫ��ؿ��� �ୱ\freeglut\bin
            ///���g,�n����n���a��
            if (!body)
                exit(0);
            glmUnitize(body);
            glmFacetNormals(body);
            glmVertexNormals(body, 90.0);
        }
        glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
}
void drawUpper(void)
{
    glPushMatrix();
        glScalef(0.3, 0.3, 0.3);///MAYA��i�Ӧ��I�j,�Q��Scalef�⥦�ܤp
        if (!upper)
        {
            upper = glmReadOBJ("upper.obj");
            ///�W�g���ҫ���,��b�_�Ǫ��ؿ��� �ୱ\freeglut\bin
            ///���g,�n����n���a��
            if (!upper)
                exit(0);
            glmUnitize(upper);
            glmFacetNormals(upper);
            glmVertexNormals(upper, 90.0);
        }
        glmDraw(upper, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
}
void drawLower(void)
{
    glPushMatrix();///MAYA��i�Ӧ��I�j,�Q��Scalef�⥦�ܤp
        glScalef(0.3, 0.3, 0.3);
        if (!lower)
        {
            lower = glmReadOBJ("lower.obj");
            ///�W�g���ҫ���,��b�_�Ǫ��ؿ��� �ୱ\freeglut\bin
            ///���g,�n����n���a��
            if (!lower)
                exit(0);
            glmUnitize(lower);
            glmFacetNormals(lower);
            glmVertexNormals(lower, 90.0);
        }
        glmDraw(lower, GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();
}
/*void drawmodel(void)
{
    if (!pmodel)
    {
        pmodel = glmReadOBJ("arm1.obj");
        ///�W�g���ҫ���,��b�_�Ǫ��ؿ��� �ୱ\freeglut\bin
        ///���g,�n����n���a��
        if (!pmodel)
            exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
}*/
void drawarml(void)
{
    if (!arml)
    {
        arml = glmReadOBJ("arm1.obj");
        ///�W�g���ҫ���,��b�_�Ǫ��ؿ��� �ୱ\freeglut\bin
        ///���g,�n����n���a��
        if (!arml) exit(0);
        glmUnitize(arml);
        glmFacetNormals(arml);
        glmVertexNormals(arml, 90.0);
    }
    glmDraw(arml, GLM_SMOOTH | GLM_TEXTURE);
}
void drawarm2(void)
{
    if (!arm2)
    {
        arm2 = glmReadOBJ("arm2.obj");
        ///�W�g���ҫ���,��b�_�Ǫ��ؿ��� �ୱ\freeglut\bin
        ///���g,�n����n���a��
        if (!arm2) exit(0);
        glmUnitize(arm2);
        glmFacetNormals(arm2);
        glmVertexNormals(arm2, 90.0);
    }
    glmDraw(arm2, GLM_SMOOTH | GLM_TEXTURE);
}
int angleID=0;
float angleX[10]={ };
float angleY[10]={ };///mouse motion��,�i�P�ɧ��1�����`��2���
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidSphere(0.1,30,30);
    glPushMatrix();
        glRotatef(180, 0, 1, 0);
        glRotatef(angleX[0],1,0,0);
        glRotatef(angleY[0],0,-1,0);
        drawbody();
        glPushMatrix();
            glTranslatef(-0.2,0.1,0);
            glRotatef(angleX[1],1,0,0);
            glRotatef(angleY[1],0,1,0);
            glTranslatef(0,-0.05,0);
            drawUpper();
            glPushMatrix();
                glTranslatef(0,-0.1,0);
                glRotatef(angleX[2],1,0,0);///�����u�b0-90�פ����Ӧ^�u��
                glRotatef(angleY[2],0,1,0);
                glTranslatef(0,-0.2,0);
                drawLower(); ///glutSolidTeapot( 0.3 );
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


void timer(int t);///�禡�Ϊ��ŧi
void keyboard(unsigned char key,int x,int y){
    if(key=='p'){///Play����
        glutTimerFunc(0,timer,0);
    }
    if(key=='r'){///ReadŪ���
        if(fin==NULL) fin=fopen("angle.txt","r");
        for(int i=0;i<10;i++){
            fscanf(fin,"%f",&angleX[i]);
            fscanf(fin,"%f",&angleY[i]);
        }
        glutPostRedisplay;
    }
    if(key=='s'){///Save�s���
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
}
int oldX=0, oldY=0;
void mouse(int button,int state,int x,int y){
    oldX=x;
    oldY=y;
}
void motion(int x,int y){
    angleX[angleID]+=y-oldY;
    angleY[angleID]+=x-oldX;
    oldX=x;
    oldY=y;
    glutPostRedisplay();
}
float oldAngleX[10]={};
float oldAngleY[10]={};
float newAngleX[10]={};
float newAngleY[10]={};
void timer(int t){
    glutTimerFunc(50,timer,t+1);
    if(fin==NULL) fin=fopen("angle.txt","r");
    if(t%20==0){
        for(int i=0;i<10;i++){
            oldAngleX[i]=newAngleX[i];
            oldAngleY[i]=newAngleY[i];
            fscanf(fin,"%f",&newAngleX[i]);
            fscanf(fin,"%f",&newAngleY[i]);
        }
    }
    float alpha=(t%20)/20.0;
    for(int i=0;i<10;i++){
        angleX[i]=alpha*newAngleX[i]+(1-alpha)*oldAngleX[i];
        angleY[i]=alpha*newAngleY[i]+(1-alpha)*oldAngleY[i];
    }
    glutPostRedisplay();
}
int main(int argc, char* argv[])
{
    printf("�{���}�l����\n");///week14-2
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week07-2 obj gundam opencv texture");
    glutDisplayFunc(display);
    myTexture("Diffuse.jpg");
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
}
