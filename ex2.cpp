#include <stdio.h>

//variables globals on es guarda el sudoku i les regions
int sudoku[9][9];
int regio[3][3];

//variables globals on es guarda en quins espais hi ha hagut l'error
int fila = 0;
int columna = 0;
int RegioColumn = 0;
int RegioRow = 0;

int coincidencies[9] = {0,0,0,0,0,0,0,0,0}; //num de coincidencies per cada numero
int ExpectedCoincidences[9] = {1,1,1,1,1,1,1,1,1}; //La array esperada resultant

//identificador de quin ha estat l'error per donar un print diferent en cada cas
int TypeOfError = 0; // 1 = fila; 2 = columna; 3 = regió

void GetSudoku();
void PrintSudoku();
void GetRegio(int RegioCol, int RegioFila);
void ResetCoincidencesTable();
bool CompareArrays(int arr1[], int arr2[]);
bool CheckIndividualRegion();
bool CheckRegions();
bool CheckFiles(int row);
bool CheckColumnes(int col);

int main()
{
    bool correcte = true;

    GetSudoku();
    PrintSudoku();

    int i = 0;

    while (i < 9 && correcte)
    {
        if (!CheckFiles(i) || !CheckColumnes(i) || !CheckRegions()) //si qualsevol d'aquests checks es fals el sudoku ja està malament
        {
            correcte = false;
        }

        i++;
    }

    if (correcte)
    {
        printf("La solucio al Sudoku es CORRECTA!\n");
    }
    else
    {
        if (TypeOfError == 1)
        {
            printf("El sudoku te un error a la fila %i\n", fila + 1);
        }
        if (TypeOfError == 2)
        {
            printf("El sudoku te un error a la columna %i\n", columna + 1);
        }
        if (TypeOfError == 3)
        {
            printf("El sudoku te un error a la regió %i,%i\n", RegioRow + 1, RegioColumn + 1);
        }
        printf("La solucio al Sudoku es INCORRECTA!\n");
    }
}

//Guarda el sudoku en memoria
void GetSudoku()
{
    printf("Llegint sudoku...\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%i", &sudoku[i][j]);
        }
    }
    printf("Sudoku llegit.\n");
}

//Imprimeix el sudoku llegit
void PrintSudoku()
{
    for (int i = 0; i < 9; i++)
    {
        printf("|---|---|---|---|---|---|---|---|---|\n|");
        for (int j = 0; j < 9; j++)
        {
            printf(" %i |", sudoku[i][j]);
        }
        printf("\n");
    }
    printf("|---|---|---|---|---|---|---|---|---|\n");
}

//Funció per obtenir les diferents regions
void GetRegio(int RegioCol, int RegioFila)
{
    //Les variables RegioCol i RegioFila marquen la casella inicial desde la que es començara a llegir un quadrat de 3x3 del sudoku,
    //es a dir desde quina casella comencem a llegir la regió
    int p = 0 + RegioCol;
    int q = 0 + RegioFila;

    for (int i = 0 + p; i < 3 + p; i++)
    {
        for (int j = 0 + q; j < 3 + q; j++)
        {
            regio[i][j] = sudoku[i][j];
        }
    }
}

void ResetCoincidencesTable(){
    for (int i = 0; i < 9; i++)
    {
        coincidencies[i] = 0;
    }
    
}

bool CompareArrays(int arr1[], int arr2[]){
    bool result = true;
    for (int i = 0; i < 9; i++)
    {
        if(arr1[i] != arr2[i]){
            result = false;
        }
    }
    return result;
    
}

//comprova cada regió individualment
bool CheckIndividualRegion()
{
    ResetCoincidencesTable();
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            num = regio[i][j];
            coincidencies[num-1] += 1;
        }
    }

    if(CompareArrays(coincidencies,ExpectedCoincidences)){
        return true;
    }
    
    else
    {
        TypeOfError = 3;
        return false;
    }
}

//Funcio per mirar totes les regions, s'encarrega de marcar on comença cada regió
//i trucar cada cop la funció que s'encarrega de verificar que la regió es correcta
bool CheckRegions()
{
    int i = 0;
    int j = 0;

    //Marca l'inici des d'on començarem a llegir la regió seleccionada
    //tindrà un offset de 3 ja que les caselles que marquen l'inici de les regions estan separades de 3 en 3
    int RegioCol = 0;
    int RegioFila = 0;

    bool correcte = true;

    while (i < 3 && correcte)
    {
        RegioColumn = i; //Guardem quina regió estem llegint ara mateix per poder-ho imprimir en cas de error (COLUMNA)

        while (j < 3 && correcte)
        {
            RegioRow = j; //Guardem quina regió estem llegint ara mateix per poder-ho imprimir en cas de error (FILA)

            GetRegio(RegioCol, RegioFila);
            correcte = CheckIndividualRegion();
            RegioCol += 3;
            j++;
        }
        RegioFila += 3;
        i++;
    }

    return correcte;
}

//comprova que la columna X sigui correcta
bool CheckFiles(int row)
{
    ResetCoincidencesTable();
    int num = 0;
    for (int i = 0; i < 9; i++)
    {
        num = sudoku[row][i];
        coincidencies[num-1] += 1;
        fila = row;

    }

    if (CompareArrays(coincidencies,ExpectedCoincidences))
    {
        return true;
    }

    else
    {
        TypeOfError = 1;
        return false;
    }
}
//comprova que la fila X sigui correcta
bool CheckColumnes(int col)
{
    ResetCoincidencesTable();
    int num = 0;
    for (int i = 0; i < 9; i++)
    {
        num = sudoku[i][col];
        coincidencies[num-1] += 1;
        columna = col;
    }

    if (CompareArrays(coincidencies,ExpectedCoincidences))
    {
        return true;
    }

    else
    {
        TypeOfError = 2;
        return false;
    }
}


