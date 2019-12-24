#ifndef FIND_IN_TEXT_H
#define FIND_IN_TEXT_H

#define LINE 256
#define WORD 30

int get_line(char s[]);
int getword(char w[]);
int substring(char* str1, char* str2);
int similar (char* s, char* t, int n);
void print_lines(char* str);
void print_similar_words(char* str);

#endif