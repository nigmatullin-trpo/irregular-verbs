#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "verbs.h"

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

void print_mark(int amount, int correct, int rating)
{
	printf("|==============================================================|\n");
	printf("|             Correct: %1d/%1d      Rating: %1d                |\n", correct, amount, rating);
	printf("|==============================================================|\n");
}

void clean_buff(void)
{
    int temp;

    do 
    {
        temp = getchar();
    } 
    while (temp != '\n' && temp != EOF);
}

void print_task(wordbook *array)
{
	char answer[32];

	int time	= 0;
	int word	= 0;
	int amount  = TASK_NUMBER;
	int rating  = 0;
	int counter = 0;
	int correct = 0;

	printf("|==============================================================|\n");
	printf("|          Fill in the blanks with the correct form            |\n");
	printf("|  If it has several forms, list them via '/' without spaces   |\n");
	printf("|             For example 'example 1 / example 2'              |\n");
	printf("|     Infinitive     |     Past Simple    |   Past Participle  |\n");
	printf("|==============================================================|\n");

	for (counter = 0; counter < amount; counter++) 
	{
		time = (rand() % VERBS_NUMBER) % 2;
		word = (rand() % VERBS_NUMBER);

		switch (time) 
		{
			case 0:
				printf("| %18s | %18s |                    | \n", array[word].time_1st, array[word].time_2nd);
				scanf("%32s", answer);
				clean_buff();
				if (strcmp(array[word].time_3rd, answer) == 0) 
				{
					printf("This is the correct answer! \n");
					correct++;
				}
				else 
				{
					printf("This is not the correct answer! Correct form is: %-14s| \n", array[word].time_3rd);
				}
				break;

			case 1:
				printf("| %18s |                    | %18s | \n", array[word].time_1st, array[word].time_3rd);
				scanf("%32s", answer);
				clean_buff();
				if (strcmp(array[word].time_2nd, answer) == 0) 
				{
					printf("This is the correct answer! \n");
					correct++;
				}
				else 
				{
					printf("This is not the correct answer! Correct form is: %-14s| \n", array[word].time_2nd);
				}
				break;

			default:
				break;
		}
	}

	rating = write_mark(amount, correct);
	print_mark(amount, correct, rating);
}

void print_menu(wordbook *array)
{
	char command;

	while (1) 
	{
		printf("|==============================================================|\n");
		printf("| Enter '1' to print list of irregular verbs                   |\n");
		printf("| Enter '2' to test your knowledge of irregular verbs          |\n");
		printf("| Enter '3' to exit                                            |\n");
		printf("|==============================================================|\n");

		command = getchar();
		clean_buff();

		switch (command) 
		{
			case '1':
				print_word(array);
				break;

			case '2':
				print_task(array);
				break;

			case '3':
				return;

			default :
				break;
		}
	}
}