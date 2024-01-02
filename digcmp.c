#include <string.h>
#include <stdio.h>  
#include <ctype.h> 
// 
int mystrcmp(const char *str1, const char *str2)
{
	int val =0 , val2=0 ;
    int c = strlen(str1);
    for (int i=0 ; i<c ; i++)
    {
        char w = str1[i];
        if (isdigit(w))
            val++;
    }
    c = strlen(str2);
    for (int i=0 ; i<c ; i++)
    {
        char w = str2[i];
        if (isdigit(w))
            val2++;
    }
	
	if (val < val2)
		return 2;
	if (val > val2)
		return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		return -1;
	}
	return mystrcmp(argv[1], argv[2]);
}