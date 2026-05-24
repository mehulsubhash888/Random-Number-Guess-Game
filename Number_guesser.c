// Author          -  Mehul Kumar
// Creation Date   -  05-04-02026
// Updated On      -  22-05-2026

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct to track overall player statistics across all rounds
typedef struct {    
    int total_games;    
    int games_won;    
    int best_score;    // Lowest number of attempts to win a game
    int total_attempts; // Cumulative attempts across all games played
} GameStats;

// Helper function for Robust Input Validation
// This safely reads integers and shields the game from infinite loop crashes if text is typed
int get_valid_int() {
    int value;
    while (scanf("%d", &value) != 1) {
        // If scanf fails, clear out the text buffer line completely
        int c;
        while ((c = getchar()) != '\n' && c != EOF); 
        printf("Invalid input! Please enter a valid number: ");
    }
    return value;
}

// Helper function to draw visual hearts for remaining lives
void print_lives(int remaining, int max) {
    printf("Lives: [ ");
    for (int i = 0; i < max; i++) {
        if (i < remaining) {
            printf("<3 "); // Safe ASCII representation of a heart
        } else {
            printf("X  "); // Used life
        }
    }
    printf("]\n");
}

int main()
{
    // Seed the random number generator ONCE at startup
    srand(time(0)); 

    // Initialize the game statistics
    GameStats stats = {0, 0, 999, 0}; // Set best_score to 999 initially as a placeholder high score
    
    printf("==================================================\n");
    printf("     WELCOME TO THE ARCADE NUMBER GUESSER!       \n");
    printf("==================================================\n");
    printf("-- Guess the number while balancing your finite lives.\n");
    printf("-- Listen closely to the computer's hints to survive!\n\n");
    
    int play_again;

    // Outer loop: Manages whole matches and rematches
    do
    {
        int difficulty;
        int max_range = 100;
        int max_lives = 7;
        
        // 1. Difficulty Level Prompt
        printf("Choose your difficulty level:\n");
        printf("1. Easy   (Range: 1-50,   10 Lives)\n");
        printf("2. Medium (Range: 1-100,  7 Lives)\n");
        printf("3. Hard   (Range: 1-200,  5 Lives)\n");
        printf("Enter choice (1, 2, or 3): ");
        difficulty = get_valid_int(); // Robustly grab choice

        // 2. Set Rules Dynamically based on Difficulty choice
        switch (difficulty) 
        {
            case 1:
                max_range = 50;
                max_lives = 10;
                printf("\n[Easy Mode Enabled] Range 1-50. Find the target!\n\n");
                break;
            case 2:
                max_range = 100;
                max_lives = 7;
                printf("\n[Medium Mode Enabled] Range 1-100. Stay focused.\n\n");
                break;
            case 3:
                max_range = 200;
                max_lives = 5;
                printf("\n[Hard Mode Enabled] Range 1-200. High stakes!\n\n");
                break;
            default:
                max_range = 100;
                max_lives = 7;
                printf("\nInvalid choice! Defaulting to Medium Mode.\n\n");
                break;
        }

        // Setup the specific round parameters
        int RandomNumber = (rand() % max_range) + 1;
        int x = -1;
        int current_round_attempts = 0;
        int lives_left = max_lives;
        
        stats.total_games++; // Increment total games started

        // Inner loop: The tactical guessing game
        while (x != RandomNumber && lives_left > 0)
        {
            print_lives(lives_left, max_lives); // Display visual gauge of health
            printf("Guess The Number: ");
            x = get_valid_int(); // Robust input validation protecting your buffer
            
            current_round_attempts++;
            stats.total_attempts++; // Add to lifetime counters

            // 3. Directional System and Life Deductions
            if (x < RandomNumber) {
                printf("Hint: Higher Number Please\n");
                lives_left--;
            } else if (x > RandomNumber) {
                printf("Hint: Lower Number Please\n");
                lives_left--;
            }
            printf("----------------------------------------\n");
        }

        // 4. Post-Match Logic & Updating Stats Struct
        if (x == RandomNumber) {
            printf("\n🎉 CONGRATS! You beat the system!\n");
            printf("The number was indeed %d.\n", RandomNumber);
            printf("You guessed it in %d attempts.\n", current_round_attempts);
            
            stats.games_won++;
            
            // Logically check if this is a personal record for best_score
            if (current_round_attempts < stats.best_score) {
                stats.best_score = current_round_attempts;
                printf("🏆 NEW PERSONAL RECORD! Your best game score updated!\n");
            }
        } else {
            printf("\n💀 GAME OVER! You ran out of lives.\n");
            printf("The correct secret number was: %d\n", RandomNumber);
        }

        // 5. Print Dynamic Profile Stats Panel
        printf("\n==================================================\n");
        printf("               YOUR CURRENT PERFORMANCE            \n");
        printf("==================================================\n");
        printf(" Total Games Handled : %d\n", stats.total_games);
        printf(" Games Successfully Won: %d\n", stats.games_won);
        printf(" Lifetime Guesses Fired: %d\n", stats.total_attempts);
        if (stats.best_score != 999) {
            printf(" Best Winning Score    : %d attempts\n", stats.best_score);
        } else {
            printf(" Best Winning Score    : No wins recorded yet\n");
        }
        printf("==================================================\n");
        
        // 6. Loop check for Rematch
        printf("\nWould you like to try another sector? (1 for Yes, 0 to Quit): ");
        play_again = get_valid_int();
        printf("\n\n");

    } while (play_again == 1); 

    printf("Shutting down core engine. Thanks for playing, Commander!\n");
    return 0;
}
