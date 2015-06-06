#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256 //1行あたり読み込める最大文字数

void usage();

int main(int argc, char *argv[])
{
	FILE *fp;
	char str[MAX_LEN];


	if(argc < 2)
	{
		usage();
		exit(1);
	}


	if( (fp = fopen(argv[1], "r")) == NULL)
	{
		printf("File Open Error!!\n");
		exit(1);
	}


	while( fgets(str, MAX_LEN, fp) != NULL )
	{
		printf("%s\n", str);
	}

	fclose(fp);

	return 0;
}

void usage()
{
	printf("usage: ./main filename\n");
}