#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LINELEN (80)
char *mygets(char *buf, int len);

int main(int argc, char *argv[])
{
	char w[3] = "./";
	char str1[LINELEN + 1];
	char str2[LINELEN + 1];

	if (argc != 2)
		return -1;
	char * start = (char*)malloc(strlen(argv[1])*sizeof(char)+3);

	strcat(start ,w);
	strcat(start ,argv[1]);

	while (1)
	{
		if (mygets(str1, LINELEN) == NULL)
			break;
		if (mygets(str2, LINELEN) == NULL)
			break;
		int rc = fork();
		if (rc==-1)
			return -1;
		if (rc==0)
		{
			char* myargv[4];
			myargv[0] = strdup(start);
			myargv[1] = strdup(str1);
			myargv[2] = strdup(str2);
			myargv[3] = NULL;
			execvp(myargv[0] , myargv);
			free(myargv[0]);
			free(myargv[1]);
			free(myargv[2]);
			return -2;
		}
		else
		{
			int status;
			wait(&status);
			printf("%d\n",WEXITSTATUS(status));

		}
		fflush(stdout);
	}
	free(start);
	return 0;
}


char *mygets(char *buf, int len)
{
	char *retval;

	retval = fgets(buf, len, stdin);
	buf[len] = '\0';
	if (buf[strlen(buf) - 1] == 10) /* trim \r */
		buf[strlen(buf) - 1] = '\0';
	else if (retval) while (getchar() != '\n'); /* get to eol */

	return retval;
}
