/* include */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recipe.h"


/* 定数 */
#define MAX_CHARLEN 256 //1行あたり読み込める最大文字数
#define EXIT_FAILURE 1

/* 関数定義 */
void usage();
void malloc_free( Recipe *, int );

/* 関数 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char str[MAX_CHARLEN];
	Recipe recipes[MAX_RECIPE], recipe_tmp[ MAX_RECIPE ];
	
	int recipe_id = 0;
	
	if(argc < 2)
	{
		usage();
		exit( EXIT_FAILURE );
	}


	if( (fp = fopen(argv[1], "r")) == NULL)
	{
		printf("File Open Error!!\n");
		exit( EXIT_FAILURE );
	}

	int i;
	memset( recipe_tmp, 0, sizeof( recipe_tmp ) );
	
	while( fgets(str, MAX_CHARLEN, fp) != NULL )
	{	       
		// レシピにidを追加し、名前をコピー、配列に格納
		recipe_tmp[ recipe_id ].id = recipe_id;
		
		//TODO: バグがある
		//例: recipe-data.txtを入れた時に発生
		recipe_tmp[ recipe_id ].name = (char *)malloc( sizeof(char) * strlen( str - 1 ) );
		if( recipe_tmp[ recipe_id ].name == NULL ) {
			printf("malloc FAILURE\n");
			for( i = 0; i < recipe_id; i++ ) {
				free( recipe_tmp[ i ].name );
			}
			exit( EXIT_FAILURE );
		}
				
		strncpy( recipe_tmp[ recipe_id ].name, str, strlen( str ) - 1  );
		recipes[ recipe_id ] = recipe_tmp[ recipe_id ];

		printf("recipes[ recipe_id ].id:%d  recipes[ recipe_id ].name:%s \n", recipes[ recipe_id ].id, recipes[ recipe_id ].name );

		recipe_id++;		
	}
	
	print_recipes(recipes, recipe_id); //ここでrecipe_idは配列の数に相当

	malloc_free( recipe_tmp, recipe_id );
	fclose(fp);

	return 0;
}

void usage()
{
	printf("usage: ./main filename\n");
}



void malloc_free( Recipe recipe_tmp[], int recipe_id ) {
	int i;       
	for( i = 0; i < recipe_id; i++ ) {
		free( recipe_tmp[ i ].name );
	}
}

