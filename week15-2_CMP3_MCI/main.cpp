#include "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI myMP3;
int main()
{
    myMP3.Load("2.mp3");
    myMP3.Play();
    int a;
    scanf("%d",&a);
}
