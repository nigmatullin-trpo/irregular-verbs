#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "verbs.h"

int main()
{
	wordbook array[VERBS_NUMBER];

	write_word(DICTIONARY_PATH, array);
	print_menu(array);

	return 0;
}