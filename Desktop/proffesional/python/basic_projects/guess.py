# Update your dictionary with Python-related questions
dictionary = {
    'a': 'Python is an interpreted, high-level, general-purpose programming language.',
    'b': 'Guido van Rossum',
    'c': 'Python 3.x',
    'd': 'Python Software Foundation'
}

# Add questions_and_options related to Python
questions_and_options = [
    ["What is Python?", "a. A type of snake", "b. A programming language", "c. A dessert", "d. A country",
     'a'],
    ["Who is the creator of Python?", "a. Bill Gates", "b. Elon Musk", "c. Guido van Rossum", "d. Mark Zuckerberg",
     'c'],
    ["Which version of Python is the latest stable version?", "a. Python 2.x", "b. Python 3.x", "c. Python 4.x",
     "d. Python 1.x", 'b'],
    ["Who oversees Python's development?", "a. Google", "b. Facebook", "c. Python Software Foundation",
     "d. Microsoft", 'c']
]

def new_game():
    while True:
        guesses = []
        correct_guesses = 0
        question_number = 1
        
        for key, value in dictionary.items():
            print()
            print(key)
            
            # Extracting options and correct answer from the list
            options = questions_and_options[question_number - 1][:4]
            correct_answer = questions_and_options[question_number - 1][4]
            
            for i in options:
                print(i)
            
            # Validate user input
            guess = get_valid_input(options)
            guesses.append(guess)
            
            # Calling the check_answer function
            correct_guesses += check_answer(correct_answer, guess)
            
            question_number += 1

        display_score(correct_guesses, guesses)

        play_again = input("\nDo you want to play again? (yes/no): ").lower()
        if play_again != "yes":
            break

def get_valid_input(options):
    while True:
        guess = input().lower()
        if guess in ['a', 'b', 'c', 'd']:
            return guess
        else:
            print("Invalid input. Choose a, b, c, or d.")

def check_answer(answer, guess):
    if answer == guess:
        print("Correct Answer")
        return 1
    else:
        print("Wrong Answer. The correct answer is:", answer)
        return 0

def display_score(correct_guesses, guesses):
    print("\nResult:")
    print("Questions: ", end=" ")
    for i in guesses:
        print(i, end=" ")
    print("\nAnswers: ", end=" ")
    for i in guesses:
        print(dictionary.get(i), end=" ")
    
    # Displaying all keys in the dictionary and their corresponding values
    print("\n\nAll Keys and Correct Answers:")
    for key, value in dictionary.items():
        print(f"{key} - {value}")

    # Displaying the percentage of correct answers
    score = (correct_guesses / len(dictionary)) * 100
    print(f"\nPercentage of Correct Answers: {score}%")

# Your dictionary and questions_and_options lists remain unchanged

new_game()
