#include <stdio.h>
#include <stdlib.h>
#include "game.h"

 

/**
 * Initialize the game board with dynamic memory allocation
 * This function demonstrates dynamic 2D array allocation as required
 */
Game* initialize_game_board(int size) {
    // Allocate memory for the game structure
    Game* game = (Game*)malloc(sizeof(Game));
    if (game == NULL) {
        printf("Error: Memory allocation failed for game structure!\n");
        return NULL;
    }
    
    // Set basic properties
    game->size = size;
    game->current_player = 0; // Player 1 starts (will use 'X')
    
    // Allocate memory for array of row pointers
    game->board = (char**)malloc(size * sizeof(char*));
    if (game->board == NULL) {
        printf("Error: Memory allocation failed for board rows!\n");
        free(game);
        return NULL;
    }
    
    // Allocate memory for each row
    for (int i = 0; i < size; i++) {
        game->board[i] = (char*)malloc(size * sizeof(char));
        if (game->board[i] == NULL) {
            printf("Error: Memory allocation failed for board row %d!\n", i);
            
            // Clean up previously allocated rows
            for (int j = 0; j < i; j++) {
                free(game->board[j]);
            }
            free(game->board);
            free(game);
            return NULL;
        }
        
        // Initialize all cells to empty (space character)
        for (int j = 0; j < size; j++) {
            game->board[i][j] = ' ';
        }
    }
    
    return game;
}

/**
 * Display the game board with nice formatting
 * Shows row/column numbers and borders for clarity
 */
void display_game_board(Game* game) {
    if (game == NULL) {
        printf("Error: Cannot display NULL game!\n");
        return;
    }
    
    printf("\n");
    
    // Print column headers (1, 2, 3, ...)
    printf("   ");  // Space for row numbers
    for (int j = 0; j < game->size; j++) {
        printf(" %2d ", j + 1);
    }
    printf("\n");
    
    // Print top border
    printf("   ");
    for (int j = 0; j < game->size; j++) {
        printf("+---");
    }
    printf("+\n");
    
    // Print each row with row number and borders
    for (int i = 0; i < game->size; i++) {
        // Row number
        printf("%2d ", i + 1);
        
        // Row contents with borders
        for (int j = 0; j < game->size; j++) {
            printf("| %c ", game->board[i][j]);
        }
        printf("|\n");
        
        // Row separator
        printf("   ");
        for (int j = 0; j < game->size; j++) {
            printf("+---");
        }
        printf("+\n");
    }
    
    printf("\n");
}

/**
 * Get valid board size from user with input validation
 * Ensures size is within required range (3-10)
 */
int get_board_size() {
    int size;
    
    do {
        printf("Enter board size (%d-%d): ", MIN_SIZE, MAX_SIZE);
        
        // Check if input is a valid integer
        if (scanf("%d", &size) != 1) {
            printf("Invalid input! Please enter a number.\n");
            
            // Clear the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        
        // Check if size is in valid range
        if (size < MIN_SIZE || size > MAX_SIZE) {
            printf("Size must be between %d and %d. Please try again.\n", 
                   MIN_SIZE, MAX_SIZE);
        }
        
    } while (size < MIN_SIZE || size > MAX_SIZE);
    
    return size;
}

/**
 * Clean up all dynamically allocated memory
 * Important to prevent memory leaks!
 */
void cleanup_game(Game* game) {
    if (game == NULL) {
        return; // Nothing to clean up
    }
    
    // Free each row
    if (game->board != NULL) {
        for (int i = 0; i < game->size; i++) {
            if (game->board[i] != NULL) {
                free(game->board[i]);
            }
        }
        // Free the array of row pointers
        free(game->board);
    }
    
    // Free the game structure itself
    free(game);
    
    printf("Memory cleaned up successfully.\n");
}

 

int accept_user_input(Game* game, int* row, int* col) {
    printf("accept_user_input() - Coming in Week 3!\n");
    return 0; // Placeholder return
}

int validate_user_input(Game* game, int row, int col) {
    printf("validate_user_input() - Coming in Week 3!\n");
    return 0; // Placeholder return
}

int check_win_conditions(Game* game) {
    printf("check_win_conditions() - Coming in Week 4!\n");
    return 0; // Placeholder return
}

int check_for_draw(Game* game) {
    printf("check_for_draw() - Coming in Week 4!\n");
    return 0; // Placeholder return
}
