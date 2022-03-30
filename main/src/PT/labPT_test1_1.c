#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
typedef struct
{
	char chars[100];
	unsigned freq[26];
}line;
 
void readlines(line *text, unsigned no)
{
	for (unsigned i=0; i<no; i++)
	{
		fgets(text[i].chars, 100, stdin);
		for (unsigned j=0; j<26; j++)
		{
			text[i].freq[j]=0;
		}
	}
}
 
void linefreq(line *text, unsigned no)
{
	for (unsigned i=0; i<no; i++)
	{
		unsigned j=0;
		while (text[i].chars[j])
		{
			if (isalpha(text[i].chars[j]))
			{
				text[i].freq[tolower(text[i].chars[j])-'a']++;
			}
			j++;
		}
	}
}
 
void orderlines(line *text, unsigned no, char key)
{
	for (unsigned i=0; i<no-1; i++)
	{
		for (unsigned j=i+1; j<no; j++)
		{
			if (text[i].freq[key-'a']>text[j].freq[key-'a'])
			{
				line auxline=text[i];
				text[i]=text[j];
				text[j]=auxline;
			}
		}
	}
}
 
void displaylines(line *text, unsigned no)
{
	for (unsigned i=0; i<no; i++)
	{
		printf("%s", text[i].chars);
		for (unsigned j=0; j<26; j++)
		{
			if (text[i].freq[j]>0)
			{
				printf("%c=%d\n", 'a'+j, text[i].freq[j]);
			}
		}
		putchar('\n');
	}
}
 
int main(int argc, char *argv[])
{
	if (argc<3)
	{
		return -1;
	}
	unsigned lineno;
	char key;
	lineno=atoi(argv[1]);
	key=argv[2][0];
	line text[100];
	readlines(text,lineno);
	putchar('\n');
	linefreq(text,lineno);
	orderlines(text,lineno,key);
	displaylines(text,lineno);
	return 0;
}