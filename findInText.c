#include <stdio.h>
#include <string.h>
#include "findInText.h"


int get_line(char s[])
{
	int length;
	char c;
	
	for(length = 0; (c = getchar()) != EOF && (c != '\n') && (length < (LINE-1));)
	{
		s[length++] = c;
	}
	s[length] = '\0';

	return length-1;
}


int getword(char w[])
{
	int length = 0;
	char c;
	
	//Skip to the next word beginning:
	do
	{
		c = getchar();
	} while( ((c == ' ') || (c == '\n') || (c == '\t')) && (c != EOF) );
	
	//Catch the next word:
	w[length++] = c;
	while( (c != EOF) && (length < WORD -1) && (c != '\n') && (c != ' ') && (c != '\t') )
	{
		w[length++] = getchar();
	}
	w[length] = '\0';
	
	return length-1;
}


int substring(char* str1, char* str2)
{
	char *subString = str1, *s1, *s2;
	
	if(!*str2) return 1;
	
	while(*subString)
	{
		s1 = subString;
		s2 = str2;
		while(*s1 && *s2 && !(*s1-*s2))
		{
			s1++, s2++;
		}
		
		if(!*s2) return 1;
		
		subString++;
	}
	return 0;
}


int similar (char* s, char* t, int n)
{
	int i;

	while(*t)
	{
		i = 0;
		while(*(s + i) != *t)
		{
			if(!(*(s+i)))
			{
				return 0;
			}
			i++;
		}
		n -= i;
		t = t+1;
		s = s+i+1;
	}
	return (n == strlen(s));
}


void print_lines(char* str)
{
	char line[LINE];

	while( get_line(line) )			//This condition include case in which line length == 0
	{
    		if( (substring(line, str)) )
		{
      			puts(line);
		}
	}
}


void print_similar_words(char* str)
{
	char word[WORD];
	
	while( getword(word) )
	{
		if((similar(word, str, 0) || similar(word, str, 1)))
		{
			puts(word);
		}
	}
}