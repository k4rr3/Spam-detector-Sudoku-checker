#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 21
#define M 30
void jump_spaces(char &space, bool &last_word);
void read_word(char &letter, int &length, bool &last_word, char search_words[][M]);
void keywords(char &letter, int &length, bool &last_word, char search_words[][M]);
void search_repeated_words(char &letter, char search_words[][M], int &length, char repeated_words[][M], bool &last_word);
bool end(char &letter, bool &last_word);
int main()
{
    int i = 0, length = 0;
    char search_words[N][M];
    char repeated_words[length][M];
    char letter;
    bool last_word = false;
    keywords(letter, length, last_word, search_words);
    printf("-------------------------\n");
    search_repeated_words(letter, search_words, length, repeated_words, last_word);
}

void keywords(char &letter, int &length, bool &last_word, char search_words[][M])
{
    while (last_word == false)
    {
        jump_spaces(letter, last_word);
        read_word(letter, length, last_word, search_words);
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

void read_word(char &letter, int &length, bool &last_word, char search_words[][M])
{
    char searching_words[N + 1];
    int i = 0;
    while (isalpha(letter) && last_word == false)
    {

        letter = tolower(letter);
        searching_words[i] = letter;
        i++;
        scanf("%c", &letter);
    }
    searching_words[i] = '\0';
    strcpy(search_words[length], searching_words);
    printf("%s", search_words[length]);
    length++;
    printf("\n");
}
bool end(char &letter, bool &last_word)
{
    last_word = false;
    if (letter == '.')
    {
        scanf("%c", &letter);
    }
    else if (letter == '.')
    {
        last_word == true;
    }
    return last_word;
}
void search_repeated_words(char &letter, char search_words[][M], int &length, char repeated_words[][M], bool &last_word)
{
    int i = 0, j = 0;
    last_word = false;
    while (last_word == false)
    {
        jump_spaces(letter, last_word);
        scanf("%s", repeated_words[j]);
        printf("%s", repeated_words[j]);
        repeated_words[j][M] = tolower(repeated_words[j][M]);
        for (i = 0; i <= length; i++)
        {
            if (search_words[i] == repeated_words[j])
            {
                printf("repetida");
                last_word = true;
            }
        }
    }
}