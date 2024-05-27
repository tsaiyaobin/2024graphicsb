#include <windows.h>
#include <GL/glut.h>
int main()
{
    PlaySound("mykbeat.wav",NULL,SND_SYNC);
    PlaySound("my_video.wav",NULL,SND_SYNC);
}
