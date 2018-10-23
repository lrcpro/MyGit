/*
It's minishell in Linux
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	while(1)
	{
		printf("minishell:");
		fflush(stdout);
		char cmd[1024]={0};
		if(scanf("%[^\n]%*c",cmd)!=1)
		{
			getchar();
		}
		char *ptr = cmd;
		char *argv[32]= {NULL};
		int argc = 0;
		argv[argc++]= ptr;
		while(*ptr != '\0')
		{
			if(isspace(*ptr))
			{
				while(isspace(*ptr)&&*ptr!= '\0')
				{
					*ptr++ = '\0';
				}
				argv[argc++]= ptr;
			}
			ptr++;
		}
		if(fork()==0)
		{
		execvp(argv[0],argv);
		}
		wait(NULL);
	}
	return 0;
}

