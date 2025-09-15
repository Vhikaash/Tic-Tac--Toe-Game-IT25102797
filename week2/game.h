#ifndef GAME_H
#define GAME_H

// Constants
#define MIN_SIZE 3
#define MAX_SIZE 10

// Game structure
typedef struct {
    char** board;        // 2D array for the game board
    int size;            // Size of the N×N board
    int current_player;  // Current player (0 or 1)
} Game;

/**
 * Initialize the game board with dynamic memory allocation
 * @param size: Size of the N×N board (3-10)
 * @return: Pointer to initialized game structure, NULL if failed
 */
Game* initialize_game_board(int size);

/**
 * Display the current game board
 * @param game: Pointer to the game structure
 */
void display_game_board(Game* game);

/**
 * Get valid board size from user input
 * @return: Valid board size between MIN_SIZE and MAX_SIZE
 */
int get_board_size();

/**
 * Free all dynamically allocated memory
 * @param game: Pointer to game structure to clean up
 */
void cleanup_game(Game* game);

/**
 * Accept user input for move coordinates
 * Coming in Week 3
 */
int accept_user_input(Game* game, int* row, int* col);

/**
 * Validate user input and moves
 * Coming in Week 3  
 */
int validate_user_input(Game* game, int row, int col);

/**
 * Check win conditions (row, column, diagonal)
 * Coming in Week 4
 */
int check_win_conditions(Game* game);

/**
 * Check for draw condition
 * Coming in Week 4
 */
int check_for_draw(Game* game);

#endif

