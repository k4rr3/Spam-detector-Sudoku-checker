#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 21
#define M 30
void jump_spaces(char &space, bool &last_word);
void read_word(char &letter, char searching_words[], int &length, bool &last_word);
void read(char &letter, char searching_words[], int &length, bool &last_word);

int main()
{
    int i = 0, length;
    char letter, searching_words[N + 1];
    bool last_word = false;
    read(letter, searching_words, length, last_word);
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
    while (!isalpha(letter) && last_word == false)
    {
        scanf("%c", &letter);
        if (letter == '.')
        {
            last_word = true;
        }
    }
}

void read_word(char &letter, char searching_words[], int &length, bool &last_word)
{
    char search_words[N][M];
    int i = 0, x = 0;
    while (isalpha(letter) && last_word == false)
    {
        searching_words[i] = letter;

        i++;
        scanf("%c", &letter);
    }
    searching_words[i] = '\0';
    strcpy(search_words[x], searching_words);
    printf("%s", search_words[x]);
    x++;
    length = i;
    printf("\n");
}