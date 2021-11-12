/* ************************************************************************
 *       Filename:  ss.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2021年08月03日 16时01分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/



#include <stdio.h>

#include <string.h>

int main(void)

{


		
				char buf[32];
							char dst[32];
			char src[32]= "event1";										
				FILE *fp_event = NULL;
			fp_event = fopen("test.txt", "r");
		if(fp_event == NULL)
		{
		printf("fopen fopenfopen\n");
			 perror("fopen");
								  }

			printf("aaaaaa\n");
		memset(buf, 0, sizeof(buf));
				memset(dst, 0, sizeof(dst));
				while(fgets(buf,1024,fp_event) != NULL)
																			
if((strncmp(buf,src,5) == 0)

}
}
