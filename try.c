#include <string.h>

#include <stdio.h>
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY_CHECK_VALUE_PATH       "/home/edu/share/i6x/I10V/tools/IntercomI64/userdata/default/keymap/keycheck.txt"
#define KEY_CHECK_EVENT            "event" 
typedef enum
{
    IMCALL_EVENT_KEY = 0,         /*收到按键*/
    IMCALL_NUMBER_UPDATE,         /*收到需要更新号码*/
    IMCALL_EVENT_CALL_CHANGED,    /*call info changed*/
    IMCALL_EVENT_CALL_NOTIFY,     /*收到call notify*/
    IMCALL_EVENT_CURRENT_CHANGED, /*当前通话变了*/
    IMCALL_EVENT_DTMF_RECEIVED,   /*收到DTMF事件*/
    IMCALL_EVENT_CONFIG_CHANGED,  /*imCallConfig changed*/

    IMAPP_EVENT_SYSTEM_STARTED,   /*收到系统启动完成的消息*/
    IMAPP_EVENT_ATE_START,        /*start ATE*/
    IMAPP_EVENT_ATE_EXIT,         /*exit ATE*/
    IMAPP_EVENT_IP_OBTAIN_SUCCESS,/*收到系统上报的获取IP成功事件*/
    IMAPP_EVENT_COMEBACK_IDLE,    /*状态机回到IDLE状态*/
    IMCMD_EVENT_TIMEOUT,          /*所有定时器超时处理*/
    IMLED_EVENT_DSSKEY,           /*收到dsskey的led变化事件*/
    IMLED_EVENT_STATE_UPDATE,     /*LED更新事件*/
    IMLCD_EVENT_WAKEUP,           /*唤醒屏幕，重置熄屏计时器*/
}imCoreEventType_e;

char *imCoreEventToString(imCoreEventType_e event)
{
    switch(event)
    {
        case IMCALL_EVENT_KEY:
        {
            return "key event ";
        }
        case IMCALL_EVENT_CALL_CHANGED:
        {
            return "call info changed ";
        }
        case IMCALL_EVENT_CALL_NOTIFY:
        {
            return "call notify";
        }
        case IMCALL_EVENT_CURRENT_CHANGED:
        {
            return "current changed ";
        }
        case IMCALL_NUMBER_UPDATE:
        {
            return "number update";
        }
        case IMCALL_EVENT_DTMF_RECEIVED:
        {
            return "dtmf received";
        }
        case IMCALL_EVENT_CONFIG_CHANGED:
        {
            return "line in config changed";
        }
        case IMAPP_EVENT_SYSTEM_STARTED:
        {
            return "system started";
        }
        case IMCMD_EVENT_TIMEOUT:
        {
            return "cmd time out";
        } 
    }

    return "";
}
void test()
{
	char buf[32];
	char dst[32];
	char src[32]= "event1";										
	FILE *fp_event = NULL;char *msg[16]={NULL};
	int i=0;char *temp = NULL;int keyCode=0;
	fp_event = fopen(KEY_CHECK_VALUE_PATH, "r");

	memset(buf, 0, sizeof(buf));
	memset(dst, 0, sizeof(dst));
	while(fgets(buf,sizeof(buf),fp_event) != NULL){
		i++;
		if(i==2)
		{printf("buf1  = %s   \n",buf);
			int i=0;
			msg[i] = strtok(buf,",");
			
			while(msg[i] != NULL)
			{
				i++;
				msg[i] = strtok(NULL, ",");
			}
		printf("msg[1] = %s\n",msg[1]);
				if(strcmp( msg[1],"21") == 0)
				{
					printf("msg[1] = %s\n",msg[1]);
				}
		}
		printf("buf  = %s  i = %d\n ",buf,i);
	}
			
				fclose(fp_event);
	if(strncmp(buf,KEY_CHECK_EVENT,5) == 0)
	{
		sprintf(dst,"/dev/input/%s",buf); 
		printf(" 不等于event1 %s\n",dst);
		//dst[strlen(dst)-1]=0;
		printf(" 不等于event1 %s  \n",dst);
	}
	else
	{
		printf(" 等于event1 \n");
	}
}
void test1()
{
	char temp[124]="";
	memset(temp,0,sizeof(temp));
	if(temp == NULL)
	{
	printf("temp = is NULL \n");
	}
	strcpy(temp,imCoreEventToString(155));
	printf("size = %d len = %d\n",sizeof(temp), strlen(temp));
	printf("temp = %s \n",temp);
}

void test2()
{
    int inputIndex = 0;

	for(inputIndex = 0; inputIndex < 3; inputIndex++)
	{
		if(inputIndex == 1 )
		{
			printf( "1111111111\n");
		}
		else if(inputIndex == 2 )
		{
			break;
		}
		else
		{
			printf( "no such input type name is sensor\n");
		}
	}

	if(inputIndex == 0)
	{
		printf(" 不等于event0   \n");
	}
	else if(inputIndex == 1)
	{
		printf(" 不等于event1   \n");
	}
	else if(inputIndex == 2)
	{
	printf(" 不等于event2  \n");
	}
}
int flag=0;
extern void printfFalg();

void printfFalg()
{
	printf("哈哈 Fp open =%d  \n",flag);

}
void test3()
{
    int xxfp = open("./test.txt",O_WRONLY);
	flag=xxfp;
}
int main(void)
{	
	test2();
}
