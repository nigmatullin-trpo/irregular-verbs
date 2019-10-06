#ifndef VERBS
#define VERBS
#define VERBS_NUMBER 130
#define TASK_NUMBER 5
#define DICTIONARY_PATH "src/wordbook"

typedef struct 
{
	char time_1st[32];
	char time_2nd[32];
	char time_3rd[32];
} 	wordbook;

int write_word(char fname[], wordbook *array);
void print_word(wordbook *array);
int write_mark(int amount, int correct);
void print_mark(int amount, int correct, int rating);
void clean_buff(void);
void print_task(wordbook *array);
void print_menu(wordbook *array);


#endif