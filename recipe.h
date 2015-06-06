#ifndef _RECIPE_
#define _RECIPE_


/* 定数 */
#define MAX_RECIPE 256

#define NULL_RECIPE 

/* 構造体 */
typedef struct recipe
{
	int id;
	char *name;
} Recipe;

/* 関数 */
void print_recipes(Recipe *recipes, int num);

#endif 