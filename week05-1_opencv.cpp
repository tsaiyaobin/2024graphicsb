#include <opencv/highgui.h>
int main()
{///大寫I小寫pl(Intel performance library)
    IplImage * img = cvLoadImage("c:/luffy.jpg");
    ///在大寫的Image
    cvShowImage("img",img);
    cvWaitKey(0);///等任意鍵在繼續
}
