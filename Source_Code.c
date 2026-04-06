//Author - Mehul Kumar
//Date   - 05/04/2026

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int play_again;

    do{
        srand(time(0));
        int RandomNumber = (rand() % 100) + 1;
        int x;
        int count = 0;

        do
        {
            printf("Guess The Number:");
            scanf("%d", &x);
            if (x < RandomNumber){
                printf("Higher Number Please\n");
            }
            else if (x > RandomNumber){
                printf("Lower Number Please\n+");
            }
            else{
                printf("Congrats");
            }
            count++;
        } while (x != RandomNumber);
    printf("Great You Guessed It Right\n The Number Was %d", RandomNumber);
    printf("\nYou Figured it in attempt %d", count + 1);
    printf("\nWould you like to try again, submit 1 for yess and 0 to quite:");
    scanf("%d",&play_again);
    }while(play_again == 1) ;

    return 0;
}
