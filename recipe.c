#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recipe.h"

void print_recipes(Recipe recipes[], int num)
{
	int i = 0;

	for(i = 0; i < num; i++)
	{
		printf("%d: ", recipes[i].id);
		printf("%s\n", recipes[i].name);
	}
}