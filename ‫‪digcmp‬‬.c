#include <string.h>
#include <stdio.h>  
#include <ctype.h> 
// 
int mystrcmp(const char *str1, const char *str2)
{
	int val =0 , val2=0 ;
    char * c = str1;
    while (*c)
    {
        if (isdigit(*c))
            val++;
    }
    c = str2;
    while (*c)
    {
        if (isdigit(*c))
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