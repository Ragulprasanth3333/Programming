import random

def get_computer_choice():
    """Randomly select and return the computer's choice."""
    choices = ["rock", "paper", "scissors"]
    return random.choice(choices)

def get_user_choice():
    """Get the user's choice."""
    user_input = input("Enter your choice (rock, paper, scissors): ").lower()
    while user_input not in ["rock", "paper", "scissors"]:
        print("Invalid choice. Please try again.")
        user_input = input("Enter your choice (rock, paper, scissors): ").lower()
    return user_input

def determine_winner(user_choice, computer_choice):
    """Determine the winner based on user and computer choices."""
    if user_choice == computer_choice:
        return "It's a tie!"
    elif (user_choice == "rock" and computer_choice == "scissors") or \
         (user_choice == "paper" and computer_choice == "rock") or \
         (user_choice == "scissors" and computer_choice == "paper"):
        return "You win!"
    else:
        return "You lose!"

def play_game():
    """Main function to play the game."""
    print("Welcome to Rock-Paper-Scissors!")
    user_choice = get_user_choice()
    computer_choice = get_computer_choice()
    print(f"You chose: {user_choice}")
    print(f"Computer chose: {computer_choice}")
    result = determine_winner(user_choice, computer_choice)
    print(result)





if __name__ == '__main__':
    play_game()
