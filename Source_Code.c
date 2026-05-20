// Author          - Mehul Kumar
// Creation Date   - 05/04/2026
// Updated On      - 20-05-2026

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator ONCE at the very beginning
    srand(time(0)); 

    printf("Welcome to the Random Number Guessing Game!\n");
    printf("-- The computer will think of a number based on your chosen difficulty.\n");
    printf("-- You have to guess it, and you'll get hints if you are too high or too low.\n\n");
    
    int play_again;

    // Outer loop: This runs the entire game. 
    // If the user chooses a rematch, it loops back HERE and asks for the difficulty again.
    do
    {
        int difficulty;
        int max_range = 100; // Default fallback range
        
        // 1. Difficulty Selection Menu (Runs at the start of EVERY rematch)
        printf("Choose your difficulty level:\n");
        printf("1. Easy   (Range: 1 to 50)\n");
        printf("2. Medium (Range: 1 to 100)\n");
        printf("3. Hard   (Range: 1 to 200)\n");
        printf("Enter your choice (1, 2, or 3): ");
        scanf("%d", &difficulty);

        // 2. Dynamically set the range based on the user's choice
        switch (difficulty) 
        {
            case 1:
                max_range = 50;
                printf("\n[Easy Mode Selected] Guess a number between 1 and 50.\n\n");
                break;
            case 2:
                max_range = 100;
                printf("\n[Medium Mode Selected] Guess a number between 1 and 100.\n\n");
                break;
            case 3:
                max_range = 200;
                printf("\n[Hard Mode Selected] Guess a number between 1 and 200.\n\n");
                break;
            default:
                max_range = 100; // Safe fallback if they type an invalid number
                printf("\nInvalid choice! Defaulting to Medium Mode (1 to 100).\n\n");
                break;
        }

        // 3. Generate the random number based on the chosen difficulty range
        int RandomNumber = (rand() % max_range) + 1;
        int x;
        int count = 0;

        // Inner loop: The actual guessing game
        do
        {
            printf("Guess The Number: ");
            scanf("%d", &x);
            count++;

            if (x < RandomNumber)
            {
                printf("Higher Number Please\n\n");
            }
            else if (x > RandomNumber)
            {
                printf("Lower Number Please\n\n");
            }
            else
            {
                printf("Congrats! ");
            }
        } while (x != RandomNumber);

        // 4. Round Summary
        printf("Great! You Guessed It Right.\n");
        printf("The Number Was %d.\n", RandomNumber);
        printf("You figured it out in %d attempts!\n", count); 
        
        // 5. Rematch prompt
        printf("\nWould you like to try again? (1 for Yes, 0 to Quit): ");
        scanf("%d", &play_again);
        printf("\n--------------------------------------------------\n\n");

    } while (play_again == 1); // If 1, execution goes back to the top of the 'do' block

    printf("Thanks for playing! Goodbye.\n");
    return 0;
}
