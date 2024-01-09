#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


#define LINELEN (80)

int lencmp(const char *str1, const char *str2);
int lexcmp(const char *str1, const char *str2);
char *mygets(char *buf, int len);

int main(int argc, char *argv[])
{
	char str1[LINELEN + 1];
	char str2[LINELEN + 1];

	if (argc != 2)
		return -1;
	char * start = (char*)malloc(strlen(argv[1])*sizeof(char)+3);

	strcmp(start ,"./");
	strcmp(start ,argv[1]);

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
		}
		else
		{
			int status;
			wait(&status);
			printf("%d\n",WEXITSTATUS(status));

		}
		
		fflush(stdout);
	}
	return 0;
}

int lencmp(const char *str1, const char *str2)
{
	int val;
	val = strlen(str1) - strlen(str2);
	if (val < 0)
		return 1;
	if (val > 0)
		return 2;
	return 0;
}

int lexcmp(const char *str1, const char *str2)
{
	int val;

	val = strcmp(str1, str2);
	if (val < 0)
		return 1;
	if (val > 0)
		return 2;
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