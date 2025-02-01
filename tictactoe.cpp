#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

    // Initialize the board with numbers 1-9
    void initializeBoard() {
        char number = '1';
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                board[i][j] = number++;
            }
        }
    }

    // Display the game board
    void showBoard() {
        cout << "\n\n";
        cout << "     |     |     \n";
        cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
        cout << "     |     |     \n\n";
    }

    // Check if the move is valid
    bool isValidMove(int move) {
        if (move < 1 || move > 9)
            return false;

        // Convert move to array indices
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O')
            return false;

        return true;
    }

    // Make a move
    void makeMove(int move) {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        board[row][col] = currentPlayer;
    }

    // Check for a win
    bool checkWin() {
        // Check rows
        for(int i = 0; i < 3; i++)
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;

        // Check columns
        for(int i = 0; i < 3; i++)
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;

        // Check diagonals
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;

        return false;
    }

    // Check for a draw
    bool checkDraw() {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    }

public:
    TicTacToe() {
        currentPlayer = 'X';
        initializeBoard();
    }

    void play() {
        cout << "\nTIC TAC TOE GAME\n";
        cout << "Player 1 (X)  -  Player 2 (O)\n\n";
        cout << "Each number (1-9) represents a position on the board\n";

        while(true) {
            showBoard();
            
            // Get player move
            int move;
            cout << "Player " << currentPlayer << ", enter a number (1-9): ";
            cin >> move;

            // Validate move
            if(!isValidMove(move)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            // Make move
            makeMove(move);

            // Check for win
            if(checkWin()) {
                showBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            // Check for draw
            if(checkDraw()) {
                showBoard();
                cout << "Game is a draw!\n";
                break;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // Ask to play again
        char playAgain;
        cout << "\nWant to play again? (y/n): ";
        cin >> playAgain;
        if(playAgain == 'y' || playAgain == 'Y') {
            initializeBoard();
            currentPlayer = 'X';
            play();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}