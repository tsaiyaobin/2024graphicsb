#include <opencv/highgui.h>
int main()
{///�j�gI�p�gpl(Intel performance library)
    IplImage * img = cvLoadImage("c:/luffy.jpg");
    ///�b�j�g��Image
    cvShowImage("img",img);
    cvWaitKey(0);///�����N��b�~��
}
