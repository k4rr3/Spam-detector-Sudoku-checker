#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 21
#define M 30
void jump_keyword_spaces(char &space, bool &last_word);
void read_keyword(char &letter, int &length, bool &last_word, char search_words[][M], char words[N][M]);
void keywords(char &letter, int &length, bool &last_word, char search_words[][M], char words[N][M]);
void search_repeated_words(int coincidences[N], char words[N][M], int &length, char &letter, char search_words[][M], char repeated_words[][M], bool &last_word, bool &exit);
void jump_text_spaces(char &letter, bool &last_word);
void words_text(int coincidences[N], char words[N][M], int &length, char &letter, bool &last_word, char search_words[][M], char repeated_words[][M], bool &exit);
void results(int &length, int coincidences[N], char search_words[N][M]);
void ratio(int coincidences[N], char words[N][M], int &length);
int main()
{
    int length = 0;
    int coincidences[N] = {0};
    char search_words[N][M];
    char repeated_words[N][M];
    char words[N][M];
    char letter;
    bool exit = false;
    bool last_word = false;
    printf("Introdueix les paraules a identificar:\n");
    keywords(letter, length, last_word, search_words, words);
    printf("Introdueix el text acabat en doble punt:\n");
    last_word = false;
    words_text(coincidences, words, length, letter, last_word, search_words, repeated_words, exit);
    printf("Relacio de paraules buscades:\n");
    /*for (i = 0; i < length; i++)
    {
        printf("%s\n", words[i]);
    }*/
    results(length, coincidences, search_words);
    printf("Resultat:\n");
    ratio(coincidences, words, length);
}

void search_repeated_words(int coincidences[N], char words[N][M], int &length, char &letter, char search_words[][M], char repeated_words[][M], bool &last_word, bool &exit)
{
    int i = 0, j = 1;
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

    // printf("%s ", repeated_words[j + 1]);
    for (i = 0; i < length; i++)
    {
        if (strcmp(words[i], repeated_words[j + 1]) == 0)
        {
            coincidences[i]++;
            // printf("%i coincidencias para %s\n", coincidences[i], words[i]);
        }
    }
    j++;
}
void results(int &length, int coincidences[N], char words[N][M])
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        printf("La paraula \"%s\" apareix %i vegada/es.\n", words[i], coincidences[i]);
    }
}
void ratio(int coincidences[N], char words[N][M], int &length)
{
    int i = 0;
    float contador = 0;
    float flength = (float)length;
    for (i = 0; i < length; i++)
    {
        if (coincidences[i] > 1)
        {
            contador++;
        }
    }
    printf("Rati: paraules amb 2 o mes aparicions / total de paraules = %.0f / %i = %.3f\n", contador, length, contador / flength);
    if ((contador / flength) >= 0.5)
    {
        printf("El missatge es SPAM!\n");
    }
    else
    {
        printf("El missatge no es SPAM!\n");
    }
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
void words_text(int coincidences[N], char words[N][M], int &length, char &letter, bool &last_word, char search_words[][M], char repeated_words[][M], bool &exit)
{
    while (last_word == false)
    {
        jump_text_spaces(letter, last_word);
        search_repeated_words(coincidences, words, length, letter, search_words, repeated_words, last_word, exit);
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
void keywords(char &letter, int &length, bool &last_word, char search_words[][M], char words[N][M])
{
    while (last_word == false)
    {
        jump_keyword_spaces(letter, last_word);
        read_keyword(letter, length, last_word, search_words, words);
        if (letter == '.')
        {
            last_word = true;
        }
    }
}
void jump_keyword_spaces(char &letter, bool &last_word)
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

void read_keyword(char &letter, int &length, bool &last_word, char search_words[][M], char words[N][M])
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
    if (searching_words[0] != '\0')
    {
        strcpy(search_words[length], searching_words);
        strcpy(words[length], search_words[length]);
        // printf("%s pos %i", search_words[length]\n, length);
        length++;
    }
    else{
        scanf("%c", &letter);
    }
}
