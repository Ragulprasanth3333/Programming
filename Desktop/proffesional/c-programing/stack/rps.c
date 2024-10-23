#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* choices[] = {"rock", "paper", "scissors"};

int get_computer_choice() {
    return rand() % 3;  // Random number between 0 and 2
}

int get_user_choice() {
    int choice;
    printf("Enter your choice (0 for rock, 1 for paper, 2 for scissors): ");
    scanf("%d", &choice);
    
    // Validate user input
    while (choice < 0 || choice > 2) {
        printf("Invalid choice. Please enter 0, 1, or 2: ");
        scanf("%d", &choice);
    }
    return choice;
}

void determine_winner(int user_choice, int computer_choice) {
    printf("You chose: %s\n", choices[user_choice]);
    printf("Computer chose: %s\n", choices[computer_choice]);
    
    if (user_choice == computer_choice) {
        printf("It's a tie!\n");
    } else if ((user_choice == 0 && computer_choice == 2) ||
               (user_choice == 1 && computer_choice == 0) ||
               (user_choice == 2 && computer_choice == 1)) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    printf("Welcome to Rock-Paper-Scissors!\n");
    
    int user_choice = get_user_choice();
    int computer_choice = get_computer_choice();
    
    determine_winner(user_choice, computer_choice);
    
    return 0;
}
