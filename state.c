#include "state.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snake_utils.h"

/* Helper function definitions */
static void set_board_at(game_state_t* state, unsigned int row, unsigned int col, char ch);
static bool is_tail(char c);
static bool is_head(char c);
static bool is_snake(char c);
static char body_to_tail(char c);
static char head_to_body(char c);
static unsigned int get_next_row(unsigned int cur_row, char c);
static unsigned int get_next_col(unsigned int cur_col, char c);
static void find_head(game_state_t* state, unsigned int snum);
static char next_square(game_state_t* state, unsigned int snum);
static void update_tail(game_state_t* state, unsigned int snum);
static void update_head(game_state_t* state, unsigned int snum);

/* Task 1 */
game_state_t* create_default_state() {
  // TODO: Implement this function.
    game_state_t* def_state = malloc(sizeof(game_state_t));
    def_state->num_rows = 18;
    def_state->num_snakes = 1;
    
    snake_t* def_snake = malloc(sizeof(snake_t));

    def_snake->head_row = 2;
    def_snake->head_col = 4;
    def_snake->tail_row = 2;
    def_snake->tail_col = 2;
    def_snake->live = true;

    snake_t* snake_arr = malloc(sizeof(snake_t) * def_state->num_snakes);
    
    snake_arr[0] = *def_snake;

    def_state->snakes = snake_arr;

    

    char **def_board = malloc(sizeof(char) * def_state->num_rows * 21);
        
    for (int i = 0; i < def_state->num_rows; i++) {
        def_board[i] = malloc(sizeof(char) * 21);
    }



    char *border = "####################\0";
     
    char *walls = "#                  #\0"; 

    char *snek = "# d>D    *         #\0";


    strcpy(def_board[0], border);
    strcpy(def_board[1], walls);
    strcpy(def_board[2], snek);
    
    for (int i = 3; i < (def_state->num_rows) - 1; i ++) {
        strcpy(def_board[i], walls);
    }

    strcpy(def_board[def_state->num_rows - 1], border);


    def_state->board = def_board;
    free(def_snake);
    return def_state;
}



/* Task 2 */
void free_state(game_state_t* state) {
    for (int i = 0; i < state->num_rows; i++) {
        free(state->board[i]);
    }
    free(state->board);
    free(state->snakes);
    free(state);
    return;
}

/* Task 3 */
void print_board(game_state_t* state, FILE* fp) {
    for (int i = 0; i < state->num_rows; i++) {
        fprintf(fp, "%s\n", state->board[i]);
    }

    return;
}

/*
  Saves the current state into filename. Does not modify the state object.
  (already implemented for you).
*/
void save_board(game_state_t* state, char* filename) {
  FILE* f = fopen(filename, "w");
  print_board(state, f);
  fclose(f);
}

/* Task 4.1 */

/*
  Helper function to get a character from the board
  (already implemented for you).
*/
char get_board_at(game_state_t* state, unsigned int row, unsigned int col) {
  return state->board[row][col];
}

/*
  Helper function to set a character on the board
  (already implemented for you).
*/
static void set_board_at(game_state_t* state, unsigned int row, unsigned int col, char ch) {
  state->board[row][col] = ch;
}

/*
  Returns true if c is part of the snake's tail.
  The snake consists of these characters: "wasd"
  Returns false otherwise.
*/
static bool is_tail(char c) {
  switch(c) {
    case 'w': case 'a': case 's': case 'd': return true;
  }
  return false;

}

/*
  Returns true if c is part of the snake's head.
  The snake consists of these characters: "WASDx"
  Returns false otherwise.
*/
static bool is_head(char c) {
  switch(c) {                     
      case 'W': case 'A': case 'S': case 'D': case 'x': return true;
  }
  return false;
}

/*
  Returns true if c is part of the snake.
  The snake consists of these characters: "wasd^<v>WASDx"
*/
static bool is_snake(char c) {
  switch(c) {
    case '^': case '<': case 'v': case '>': return true;
  }
  if (is_head(c) || is_tail(c)) {
    return true;
  }
  return false;
}

/*
  Converts a character in the snake's body ("^<v>")
  to the matching character representing the snake's
  tail ("wasd").
*/
static char body_to_tail(char c) {
  if (is_snake(c) && !is_head(c) && !is_tail(c)) {
    switch(c) {
        case '^':
            return 'w';
        case '<':
            return 'a';
        case 'v':
            return 's';
        case '>':
            return 'd';
        default:
            return '?';
    }
  } else {
      return '?';
  }
}

/*
  Converts a character in the snake's head ("WASD")
  to the matching character representing the snake's
  body ("^<v>").
*/
static char head_to_body(char c) {
  if (is_head(c)) {
    switch(c) {
        case 'W':
            return '^';
        case 'A':
            return '<';                            
        case 'S':                                   
            return 'v';                             
        case 'D':                                   
            return '>';
        default:
            return '?';
    }                                               
  } else {                                          
      return '?';                                   
  }          
}

/*
  Returns cur_row + 1 if c is 'v' or 's' or 'S'.
  Returns cur_row - 1 if c is '^' or 'w' or 'W'.
  Returns cur_row otherwise.
*/
static unsigned int get_next_row(unsigned int cur_row, char c) {
  switch(c) {
    case 'v': case 's': case 'S': return cur_row + 1;
        break;
    case '^': case 'w': case 'W': return cur_row - 1;
        break;
    default:
        return cur_row;
  }
}

/*
  Returns cur_col + 1 if c is '>' or 'd' or 'D'.
  Returns cur_col - 1 if c is '<' or 'a' or 'A'.
  Returns cur_col otherwise.
*/
static unsigned int get_next_col(unsigned int cur_col, char c) {
  switch(c) {                      
    case '>': case 'd': case 'D': return cur_col + 1;
        break;              
    case '<': case 'a': case 'A': return cur_col - 1;
        break;
    default:
        return cur_col;
  }              
}

/*
  Task 4.2

  Helper function for update_state. Return the character in the cell the snake is moving into.

  This function should not modify anything.
*/
static char next_square(game_state_t* state, unsigned int snum) {
  char snake_head = get_board_at(state, state->snakes[snum].head_row, state->snakes[snum].head_col);
  switch(snake_head) {
    case 'W':
        return get_board_at(state, get_next_row(state->snakes[snum].head_row, 'W'), state->snakes[snum].head_col);
        break;
    case 'S':
        return get_board_at(state, get_next_row(state->snakes[snum].head_row, 'S'), state->snakes[snum].head_col);
        break;

    case 'A':
        return get_board_at(state, state->snakes[snum].head_row, get_next_col(state->snakes[snum].head_col, 'A'));
        break;
    case 'D':
        return get_board_at(state, state->snakes[snum].head_row, get_next_col(state->snakes[snum].head_col, 'D'));
        break;
    default:
        return '?';
  }
}

/*
  Task 4.3

  Helper function for update_state. Update the head...

  ...on the board: add a character where the snake is moving

  ...in the snake struct: update the row and col of the head

  Note that this function ignores food, walls, and snake bodies when moving the head.
*/
static void update_head(game_state_t* state, unsigned int snum) {
  snake_t curr_snake = state->snakes[snum];
  unsigned int head_row = curr_snake.head_row;
  unsigned int head_col = curr_snake.head_col;
  char sn_head = get_board_at(state, head_row, head_col);
  unsigned int new_row = get_next_row(head_row, sn_head);
  unsigned int new_col = get_next_col(head_col, sn_head);
  
        
  set_board_at(state, new_row, new_col, sn_head);
  set_board_at(state, head_row, head_col, head_to_body(sn_head));
  state->snakes[snum].head_row = new_row;
  state->snakes[snum].head_col = new_col;
  
  return;
}

/*
  Task 4.4

  Helper function for update_state. Update the tail...

  ...on the board: blank out the current tail, and change the new
  tail from a body character (^<v>) into a tail character (wasd)

  ...in the snake struct: update the row and col of the tail
*/
static void update_tail(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  snake_t curr_snake = state->snakes[snum];
  unsigned int tail_row = curr_snake.tail_row;
  unsigned int tail_col = curr_snake.tail_col;
  char sn_tail = get_board_at(state, tail_row, tail_col);
  unsigned int new_row = get_next_row(tail_row, sn_tail);
  unsigned int new_col = get_next_col(tail_col, sn_tail);


  set_board_at(state, new_row, new_col, body_to_tail(get_board_at(state, new_row, new_col)));
  set_board_at(state, tail_row, tail_col, ' ');
  state->snakes[snum].tail_row = new_row;
  state->snakes[snum].tail_col = new_col;

  return;
}

/* Task 4.5 */
void update_state(game_state_t* state, int (*add_food)(game_state_t* state)) {
  // TODO: Implement this function.
  for (unsigned int i = 0; i < state->num_snakes; i++) {
    
    if (state->snakes[i].live) {
      switch(next_square(state, i)) {
        case ' ':
            update_head(state, i);
            update_tail(state, i);
            break;

        case '#': case '^': case 'v': case '<': case '>': case 'w': case 'a': case 's': case 'd': case 'W': case 'A': case 'S': case 'D': 
            set_board_at(state, state->snakes[i].head_row, state->snakes[i].head_col, 'x');
            state->snakes[i].live = false;
            break;

        case '*':
            update_head(state, i);
            add_food(state);
            break;
      }
    }
  }
  return;
}

/* Task 5 */
game_state_t* load_board(char* filename) {
  // TODO: Implement this function.
  game_state_t* state = malloc(sizeof(game_state_t));
  state->num_snakes = 0;
  state->snakes = NULL;



  char **board = malloc(sizeof(char) * 2000000);
  char *line = malloc(sizeof(char) * 500000);
  FILE* ptr = fopen(filename, "r");
  int i = 0;
  char *temp = malloc(sizeof(char) * 500000);
  int total = 0;
  
  if (ptr == NULL) {
    perror("Could not open file");
    return NULL;
  }

  while (fgets(line, 500000, ptr)) {

    // fgets(line, 100, ptr);
    int j = 0;
    while (true) {
        if (line[j] == '\n') {
            j++;
            break;
        }
        j++;
    }
    temp = realloc(temp, sizeof(char) * j+1);
    strcpy(temp, line);
    temp[j-1] = '\0';
    printf("%c", temp[j]);
    board[i] = temp;
    temp = calloc(500000, sizeof(char));
    total += j;
    i ++;

  }

    
  fclose(ptr);
  board = realloc(board, sizeof(char) * 2 * total + i);
  free(line);
  free(temp);
  state->num_rows = i;
  state->board = board;
  return state;
}

/*
  Task 6.1

  Helper function for initialize_snakes.
  Given a snake struct with the tail row and col filled in,
  trace through the board to find the head row and col, and
  fill in the head row and col in the struct.
*/
static void find_head(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  int tail_row = state->snakes[snum].tail_row;
  int tail_col = state->snakes[snum].tail_col;

  char tail = get_board_at(state, tail_row, tail_col);

  switch (tail) {
    case 'w':
        tail = get_board_at(state, tail_row-1, tail_col);
        tail_row -= 1;
        break;
    case 'a':
        tail = get_board_at(state, tail_row, tail_col-1);
        tail_col -= 1;
        break;
    case 's':
        tail = get_board_at(state, tail_row+1, tail_col);
        tail_row +=1;
        break;
    case 'd':
        tail = get_board_at(state, tail_row, tail_col+1);
        tail_col += 1;
        break;
    default:
        break;
  }

  while (!is_head(get_board_at(state, tail_row, tail_col))) {
    tail_row = get_next_row(tail_row, tail);
    tail_col = get_next_col(tail_col, tail);
    tail = get_board_at(state, tail_row, tail_col);
  }

  state->snakes[snum].head_row = tail_row;
  state->snakes[snum].head_col = tail_col;
  return;
}

/* Task 6.2 */
game_state_t* initialize_snakes(game_state_t* state) {
  // TODO: Implement this function.
  snake_t *snakes = malloc(sizeof(snake_t));
  int num_snakes = 1;
  state->snakes = snakes;
  //snake_t *snake = malloc(sizeof(snake_t)); 

  for (int i = 0; i < state->num_rows; i ++) {
    for (int j = 0; state->board[i][j] != '\0'; j++) {
      if (is_tail(get_board_at(state, i, j))) {
        snake_t *snake = malloc(sizeof(snake_t));
        snake->tail_row = i;
        snake->tail_col = j;
        snake->live = true;
        state->snakes[num_snakes - 1] = *snake;
        find_head(state, num_snakes - 1);
        num_snakes += 1;
        state->snakes = realloc(state->snakes, sizeof(snake_t) * num_snakes);    
        free(snake);

          //snake_t *snake = malloc(sizeof(snake_t)); 
        //state->snakes[num_snakes - 1] = *snake;
        //state->snakes[num_snakes - 1].tail_row = i;
        //state->snakes[num_snakes - 1].tail_col = j;
        //state->snakes[num_snakes - 1].live = true;
        //find_head(state, num_snakes - 1);
        //num_snakes += 1;
        //snake = realloc(snake, sizeof(snake_t));
        //snakes = realloc(snakes, sizeof(snake_t) * num_snakes);
      }
    }
  }
  
  state->num_snakes = num_snakes - 1;
  //free(snake);
  return state;
}
