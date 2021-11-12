#include <stdio.h>
#include <string.h>
#include <string.h>


#define TRUE 1
#define FALSE 0

typedef struct
{
    /*talking mute*/
    int bootPrompt; /*开机提示*/
    char sss;
    int *p;
}imLedEventInfo_t;

 imLedEventInfo_t gImLedInfo;

int a= 1;
int b= 1;
int c= 1;

 int imLedGetActionByState()
{

    // printf("gImLedInfo.bootPrompt = %d\n",gImLedInfo.bootPrompt);
    // printf("sss %d\n",gImLedInfo.sss);
    // printf("sss %d\n",gImLedInfo.p);
    //int num =2;
    // gImLedInfo.sss ='a';
    //int *s = &num;
    //gImLedInfo.p=s;
    printf("sss %d\n",*(gImLedInfo.p));
    //     printf("sss %d\n",gImLedInfo.p);
    // if (gImLedInfo.bootPrompt==0)
    // {
    //     printf("bootPrompt进入待机，快闪一次\n");
    // }
}


int  main()
{
   // printf("c = %d\n",c);
    imLedGetActionByState();
    return 0;
}