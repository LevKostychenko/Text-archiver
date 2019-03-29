#include "Filereader.h"

void filRead()
{
	FILE *fileptr;
	fileptr = fopen("basictext.txt", "r");
	readByWord(fileptr);
	getText(fileptr);
	fclose(fileptr);
}

char* getText(FILE* fileptr) 
{
	char* Text = (char *)malloc(filesize(fileptr));

}


Node* listOfWordsCreate() 
{

}

long int filesize(FILE*  fileptr)
{
	long int save_pos, size_of_file;
	save_pos = ftell(fileptr);
	fseek(fileptr, 0L, SEEK_END);
	size_of_file = ftell(fileptr);
	fseek(fileptr, save_pos, SEEK_SET);
	return size_of_file;
}


void readByWord(FILE* fileptr) 
{
	char symbol = fgetc(fileptr);
	char* word = (char *)malloc(20);
	int counterOfWordSymbols = 0;
	while ( symbol != EOF)
	{
		
		if (symbol == ' ')
		{
			if (counterOfWordSymbols >= 3)
			{

				nodeIntermediary(word);
				//add word to list 
			}
			else
			{
				while (symbol == ' ')
				{
					symbol = fgetc(fileptr);
				}
			}
			counterOfWordSymbols = 0;

		}
		else
		{
			*(word + counterOfWordSymbols) = symbol;
			counterOfWordSymbols++;
		}
		
		symbol = fgetc(fileptr);
	}
}

void nodeIntermediary(char* word)
{
	char* id = (char *)malloc(10);
	id = createId();
	Node* node = NULL;
	add(node, word, id);
}