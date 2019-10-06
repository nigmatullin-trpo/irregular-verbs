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

void print_word(wordbook *array)
{	
	int counter = 0;

	printf("|====================+====================+====================|\n");
	printf("|     Infinitive     |     Past Simple    |   Past Participle  |\n");
	printf("|====================+====================+====================|\n");
	for (counter = 0; counter < VERBS_NUMBER; counter++) 
	printf("| %18s | %18s | %18s |\n", array[counter].time_1st, array[counter].time_2nd, array[counter].time_3rd);
	printf("|====================+====================+====================|\n");
}

int write_mark(int amount, int correct)
{
	double rating = (double)correct / (double)amount;

	if (rating > 0.00 && rating <= 0.35) return 2;
	if (rating > 0.35 && rating <= 0.60) return 3;
	if (rating > 0.60 && rating <= 0.85) return 4;
	if (rating > 0.85 && rating <= 1.00) return 5;

	return 0;
}

int main()
{
	wordbook array[VERBS_NUMBER];
	write_word(DICTIONARY_PATH, array);

	return 0;
}