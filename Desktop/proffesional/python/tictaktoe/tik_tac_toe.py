import random

def print_board(board):
    for row in board:
        print("|".join(row))
        print("-" * 5)

def check_winner(board, player):
    # Check rows, columns, and diagonals for a win
    for row in board:
        if all(cell == player for cell in row):
            return True
    for col in range(3):
        if all(row[col] == player for row in board):
            return True
    if all(board[i][i] == player for i in range(3)) or all(board[i][2-i] == player for i in range(3)):
        return True
    return False

def is_draw(board):
    return all(cell != " " for row in board for cell in row)

def get_empty_positions(board):
    return [(i, j) for i in range(3) for j in range(3) if board[i][j] == " "]

def player_move(board, player):
    while True:
        try:
            pos = int(input(f"Player {player}, enter your move (1-9): ")) - 1
            row, col = divmod(pos, 3)
            if board[row][col] == " ":
                board[row][col] = player
                break
            else:
                print("Position already taken. Try again.")
        except (ValueError, IndexError):
            print("Invalid input. Enter a number between 1 and 9.")

def ai_move(board):
    empty_positions = get_empty_positions(board)
    row, col = random.choice(empty_positions)
    board[row][col] = "O"

def tic_tac_toe():
    print("Welcome to Tic-Tac-Toe!")
    board = [[" " for _ in range(3)] for _ in range(3)]
    print_board(board)

    while True:
        # Player X's turn
        player_move(board, "X")
        print_board(board)
        if check_winner(board, "X"):
            print("Player X wins!")
            break
        if is_draw(board):
            print("It's a draw!")
            break

        # Player O's turn (AI)
        print("AI's turn...")
        ai_move(board)
        print_board(board)
        if check_winner(board, "O"):
            print("Player O (AI) wins!")
            break
        if is_draw(board):
            print("It's a draw!")
            break

if __name__ == "__main__":
    tic_tac_toe()
