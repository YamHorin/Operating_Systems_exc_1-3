#include <string.h>

// 
int mystrcmp(const char *str1, const char *str2)
{
	int val , val2;

	val = strlen(str1);
	val2 = strlen(str1);
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