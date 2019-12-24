#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "findInText.h"


int main()
{
	char word[WORD];
	char option;
	getword(word);
	option=getchar();
	getchar();
	getchar();
	if(option!='a' && option !='b')
	{
		printf("Bad selection.\n");
		exit(1);
	}
	if(option=='a')
	{
		printf("Printing lines that contain the word '%s':\n\n",word);
		print_lines(word);
	}
	if(option=='b')
	{
		printf("Printing the similar words for '%s' up to 1 degree of similarity:\n",word);
		print_similar_words(word);
	}
}