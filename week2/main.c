#include <stdio.h>
#include "game.h"

int main() {
    
    printf("Welcome to Tic-Tac-Toe!\n");    
    
    // Get board size from user
    int size = get_board_size();
    
    // Initialize the game board
    Game* game = initialize_game_board(size);
    if (game == NULL) {
        printf("Error: Failed to create game board!\n");
        return 1;
    }
    
    printf("Successfully created %dx%d game board!\n", size, size);
    
    // Display the empty board
    printf("Here's your empty board:\n");
    display_game_board(game);
    
    // Test with some sample moves to show it works
    printf("Testing with some sample moves...\n");
    game->board[0][0] = 'X';
    game->board[1][1] = 'O';
    if (size > 2) {
        game->board[2][0] = 'X';
    }
    
    printf("Board after sample moves:\n");
    display_game_board(game);
    
    // Clean up memory
    cleanup_game(game);
    
    printf("Week 2 complete! Next week: Add user input and validation.\n");
    
    return 0;
}
