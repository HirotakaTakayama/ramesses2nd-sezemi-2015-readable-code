/* include */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recipe.h"


/* 定数 */
#define MAX_CHARLEN 256 //1行あたり読み込める最大文字数

/* 関数定義 */
void usage();


/* 関数 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char str[MAX_CHARLEN];
	Recipe recipes[MAX_RECIPE], recipe_tmp;
	
	int recipe_id = 0;

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


	while( fgets(str, MAX_CHARLEN, fp) != NULL )
	{
		// レシピにidを追加し、名前をコピー、配列に格納
		recipe_tmp.id = recipe_id;
		recipe_tmp.name = (char *)malloc(sizeof(char) * strlen(str-1));
		strncpy(recipe_tmp.name, str, strlen(str)-1);
		recipes[recipe_id] = recipe_tmp;
		
		recipe_id++;
	}
	
	print_recipes(recipes, recipe_id); //ここでrecipe_idは配列の数に相当

	fclose(fp);

	return 0;
}

void usage()
{
	printf("usage: ./main filename\n");
}