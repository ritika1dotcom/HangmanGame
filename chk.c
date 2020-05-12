#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>


const char* input[100]; //secret word by first player

int wrongTry; // wrong strikes

int s; // length of the secret word

int f; // flag in the game

int counter; // counter loop for loop

char word; // guess letter by second player

int winner; // keep tracks of right answer

char category[10]; // category of the word

char output[100]; // for the '_'

void showhangman(int);

void hangmanOutput();

void hangmanOutput()
{
    int counter;
    int i;
    //char output[100];
    for(counter = 0; counter < s; counter++)
    {
        output[counter] = '_';
        output[s] = '\0';
    }
    for(counter = 0; counter< s; counter++)
    {
        printf(" ");
        printf("%c",output[counter]);
    }

}

void replace(char word, int i)
{
    output[i] = word;
   // printf("%s\n",output);
}


void Guessedword(char word, int s,const char* input)
{
    int counter;
     wrongTry = 0;
     winner = 0;
     f = 0;

    for (counter = 0 ; counter < 26; counter++)
    {
        if (winner == s)
        {
            printf("\nCONGRALUTIONS!YOU HAVE SAVED THE MAN!\n\n");
            printf("THE WORD IS: %s\n", input);
            printf("\n\n\t\t\tTHANK YOU FOR PLAYING!\n\n");
            break;
        }
         showhangman(wrongTry);

        if (wrongTry == 5)
        {
            printf("\n THE WORD IS: %s\n",input);
            printf("\nYOU LOST!\n\n");
            printf("\n\n\t\t\tTHANK YOU FOR PLAYING!\n\n");
            break;
        }

        printf("\n%s\n",output);
        printf("\n\nThe given word has %d characters\n\n",s);
        printf("ENTER THE GUESS:");
        scanf("%s",&word);


        int i = 0;
        for( i = 0; i <= s; i++)
        {
            if(input[i] == word)
            {
                replace(word, i);
                f++;
                winner++;
            }
        }

        if (f == 0)
        {
            wrongTry++;
        }
        f=0;


        }
    }



int main()
{
    char word1;
    char category[10];
    int i = 0;
    int counter = 0;
    int wrongTry = 5;
    int f = 0;
    int winner = 0;


    const char* animal[100] = {"tiger","duck","elephant","cat","boar"};
    const char* birds[100] = {"crow","pigeons","chicken","cuckoo","flamingos"};
    const char* food[100] = {"rice","celery","egg","potatoes","tomatoes"};
    const char* fruit[100] = {"apple","banana","cucumber","peaches","strawberry"};
    const char* clothe[100] = {"tshirts","shirts","jeans","skirt","jackets"};
    const char* input;
    int menu;

    printf("\t\t\t\tWELCOME TO HANGMAN GAME!!!\n\n");
    printf("RULES:\n");
    printf("1. Choose the category and guess the word related to the category.\n");
    printf("2. You have 5 chances to guess.\n");
    printf("3. If you guessed the secret word, you win!\n 4. If you don't manage to guess, you lose!\n\n");
    printf("\n\n\t\tCHOOSE CATEGORIES FROM THE GIVEN BELOW CHOICE\n\n");
    printf("MENUS:\n1. ANIMALS\n2. BIRDS\n3. FOODS\n4. FRUITS\n5. CLOTHES\n");
   label:printf("\nCategory: ");
    scanf("%d",&menu);

    getchar();
    srand(time(NULL));
    switch(menu)
    {
        case 1:
         input = animal[rand()% 5];
         break;
        case 2:
         input = birds[rand() % 5];
         break;
        case 3:
              input = food[rand() % 5];
              break;
         case 4:
              input = fruit[rand() % 5];
              break;
        case 5:
              input = clothe[rand() % 5];
              break;
        default:
            printf("\nPlease enter a valid choice!\n");
            goto label;
            break;


    }

   // printf("%s\n",input);
    s = strlen(input);
   // printf("%d",s);
    getchar();
    system("cls");

    printf("Please enjoy the game!\n\nGET...SET...GO!!!\n");
    getchar();
    system("cls");

    hangmanOutput();


    printf("\n\t||===== ");                 /**show the HANGMAN**/
	printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");



    Guessedword(word1, s, input);
    getchar();
                    //Wait for user to hit a key. This is done to keep results on-screen and not close the terminal/cmd window right away.
    return 0;

}


void showhangman(int choice)

{
      switch(choice)
      {
       case 5:
        system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	break;
     case 4:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	break;
     case 3:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 2:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 1:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO ",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 0:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    O ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
    break;
    }//end of switch-case
   return;
}

