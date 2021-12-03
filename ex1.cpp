#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 500
void jump_spaces(char &space);
void read_words(char &letter, char searching_words[]);
void read(char &letter, char searching_words[]);
void read_first_word(char &letter, char searching_words[]);

int main()
{
    char letter;
    char searching_words[N + 1];
    jump_spaces(letter);
    read_first_word(letter, searching_words);
    read_words(letter, searching_words);
}

void read_words(char &letter, char searching_words[])
{
    jump_spaces(letter);
    read(letter, searching_words);
}
void read(char &letter, char searching_words[])
{
    int i = 0;
    scanf("%c", &letter);
    while (letter != ' ' && letter != '.' && i < N)
    {
        // printf("%c",letter);
        searching_words[i] = letter;
        printf("%c", searching_words[i]);
        i++;
        scanf("%c", &letter);
    }
    searching_words[i] = '\0';
    printf("\n");
}
void jump_spaces(char &letter)
{
    while (!isalpha(letter))
    // while (letter == ' ')
    {
        scanf("%c", &letter);
    }
}

void read_first_word(char &letter, char searching_words[])
{
    scanf("%c", &letter);
    read(letter, searching_words);
}