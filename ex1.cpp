#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 21
#define M 30
void jump_spaces(char &space, bool &last_word);
void read_word(char &letter, int &length, bool &last_word, char search_words[][M]);
void keywords(char &letter, int &length, bool &last_word, char search_words[][M]);
void search_repeated_words(char &letter, char search_words[][M], char repeated_words[][M], bool &last_word, bool &exit);
void jump_text_spaces(char &letter, bool &last_word);
void words_text(char &letter, bool &last_word, char search_words[][M], char repeated_words[][M], bool &exit);
int main()
{
    int i = 0, length = 0;
    char search_words[N][M];
    char repeated_words[length][M];
    char letter;
    bool exit = false;
    bool last_word = false;
    printf("Introdueix les paraules a identificar:\n");
    keywords(letter, length, last_word, search_words);
    printf("-------------------------\n");
    printf("Introdueix el text acabat en doble punt:\n");
    last_word = false;
    words_text(letter, last_word, search_words, repeated_words, exit);
}
void search_repeated_words(char &letter, char search_words[][M], char repeated_words[][M], bool &last_word, bool &exit)
{
    int i = 0, j = 1;
    int coincidences = 0;
    char temp[M];
    i = 0;
    while (isalpha(letter) && last_word == false)
    {

        letter = tolower(letter);
        temp[i] = letter;
        i++;
        scanf("%c", &letter);
    }
    temp[i] = '\0';
    strcpy(repeated_words[j + 1], temp);

    printf("%s ", repeated_words[j + 1]);
    j++;
}
void jump_text_spaces(char &letter, bool &last_word)
{
    while (!isalpha(letter) && last_word == false)
    {
        scanf("%c", &letter);
        if (letter == '.')
        {
            scanf("%c", &letter);
            if (letter == '.')
            {

                last_word = true;
            }
        }
        else
        {
            last_word = false;
        }
    }
}
void words_text(char &letter, bool &last_word, char search_words[][M], char repeated_words[][M], bool &exit)
{
    while (last_word == false)
    {
        jump_text_spaces(letter, last_word);
        search_repeated_words(letter, search_words, repeated_words, last_word, exit);
        if (letter == '.')
        {
            scanf("%c", &letter);
            // printf("%c", letter);
            if (letter == '.')
            {
                last_word = true;
            }
        }
    }
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
