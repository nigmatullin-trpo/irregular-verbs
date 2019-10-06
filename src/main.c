#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERBS_NUMBER 130
#define DICTIONARY_PATH "src/wordbook"

typedef struct 
{
	char time_1st[32];
	char time_2nd[32];
	char time_3rd[32];
} 	wordbook;

int write_word(char fname[], wordbook *array)
{
	FILE *wordfile = fopen(fname, "r");
	int counter = 0;

	while (fscanf(wordfile, "%s%s%s", array[counter].time_1st, array[counter].time_2nd, array[counter].time_3rd) != EOF) 
	{
		counter++;
	}

	fclose(wordfile);
	return 0;
}

int main()
{
	wordbook array[VERBS_NUMBER];
	write_word(DICTIONARY_PATH, array);

	return 0;
}