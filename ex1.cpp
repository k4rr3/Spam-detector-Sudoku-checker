#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 500
void jump_spaces(char &space, bool &last_word);
void read_word(char &letter, char searching_words[], int &length, bool &last_word);
void read(char &letter, char searching_words[], int &length, bool &last_word);

int main()
{
    int i = 0, length;
    char letter, searching_words[N + 1];
    bool last_word = false;
    read(letter, searching_words, length, last_word);

    printf("------------------\n");
    //printf("%i", length);
    for (i = 0; i < length; i++)
    {
        printf("%c", searching_words[i]);
    }
}

void read(char &letter, char searching_words[], int &length, bool &last_word)
{
    while (last_word == false)
    {
        jump_spaces(letter, last_word);
        read_word(letter, searching_words, length, last_word);
        if (letter == '.')
        {
            last_word = true;
        }
    }
}
void jump_spaces(char &letter, bool &last_word)
{
    while (!isalpha(letter))
    {
        scanf("%c", &letter);
    }
}

void read_word(char &letter, char searching_words[], int &length, bool &last_word)
{
    int i = 0;
    while (isalpha(letter))
    {
        searching_words[i] = letter;
        printf("%c", searching_words[i]);
        i++;
        scanf("%c", &letter);
    }
    length = i;
    searching_words[i] = '\0';
    printf("\n");
}
