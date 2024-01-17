#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asserts.h"
// Necessary due to static functions in state.c
#include "state.c"

/* Look at asserts.c for some helpful assert functions */

int greater_than_forty_two(int x) {
  return x > 42;
}

bool is_vowel(char c) {
  char* vowels = "aeiouAEIOU";
  for (int i = 0; i < strlen(vowels); i++) {
    if (c == vowels[i]) {
      return true;
    }
  }
  return false;
}

/*
  Example 1: Returns true if all test cases pass. False otherwise.
    The function greater_than_forty_two(int x) will return true if x > 42. False otherwise.
    Note: This test is NOT comprehensive
*/
bool test_greater_than_forty_two() {
  int testcase_1 = 42;
  bool output_1 = greater_than_forty_two(testcase_1);
  if (!assert_false("output_1", output_1)) {
    return false;
  }

  int testcase_2 = -42;
  bool output_2 = greater_than_forty_two(testcase_2);
  if (!assert_false("output_2", output_2)) {
    return false;
  }

  int testcase_3 = 4242;
  bool output_3 = greater_than_forty_two(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  return true;
}

/*
  Example 2: Returns true if all test cases pass. False otherwise.
    The function is_vowel(char c) will return true if c is a vowel (i.e. c is a,e,i,o,u)
    and returns false otherwise
    Note: This test is NOT comprehensive
*/
bool test_is_vowel() {
  char testcase_1 = 'a';
  bool output_1 = is_vowel(testcase_1);
  if (!assert_true("output_1", output_1)) {
    return false;
  }

  char testcase_2 = 'e';
  bool output_2 = is_vowel(testcase_2);
  if (!assert_true("output_2", output_2)) {
    return false;
  }

  char testcase_3 = 'i';
  bool output_3 = is_vowel(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  char testcase_4 = 'o';
  bool output_4 = is_vowel(testcase_4);
  if (!assert_true("output_4", output_4)) {
    return false;
  }

  char testcase_5 = 'u';
  bool output_5 = is_vowel(testcase_5);
  if (!assert_true("output_5", output_5)) {
    return false;
  }

  char testcase_6 = 'k';
  bool output_6 = is_vowel(testcase_6);
  if (!assert_false("output_6", output_6)) {
    return false;
  }

  return true;
}

/* Task 4.1 */

bool test_is_tail() {
  char testcase_1 = 'w';
  bool output_1 = is_tail(testcase_1);
  if (!assert_true("output_1", output_1)) {
    return false;
  }
    
  char testcase_2 = 'a';
  bool output_2 = is_tail(testcase_2);
  if (!assert_true("output_2", output_2)) {
    return false;
  }    

  char testcase_3 = 's';
  bool output_3 = is_tail(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }    

  char testcase_4 = 'd';
  bool output_4 = is_tail(testcase_4);
  if (!assert_true("output_4", output_4)) {
    return false;
  }    
    
  char testcase_5 = 'W';
  bool output_5 = is_tail(testcase_5);
  if (!assert_false("output_5", output_5)) {
    return false;
  }    

  char testcase_6 = 'A';
  bool output_6 = is_tail(testcase_6);
  if (!assert_false("output_6", output_6)) {
    return false;
  }    

  char testcase_7 = 'S';
  bool output_7 = is_tail(testcase_7);
  if (!assert_false("output_7", output_7)) {
    return false;
  }

  char testcase_8 = 'D';
  bool output_8 = is_tail(testcase_8);
  if (!assert_false("output_8", output_8)) {
    return false;
  }

  char testcase_9 = '^';
  bool output_9 = is_tail(testcase_9);
  if (!assert_false("output_9", output_9)) {
    return false;
  }

  char testcase_10 = '<';
  bool output_10 = is_tail(testcase_10);
  if (!assert_false("output_10", output_10)) {
    return false;
  }

  char testcase_11 = 'v';
  bool output_11 = is_tail(testcase_11);
  if (!assert_false("output_11", output_11)) {
    return false;
  }

  char testcase_12 = '>';
  bool output_12 = is_tail(testcase_12);
  if (!assert_false("output_12", output_12)) {
    return false;
  }

  char testcase_13 = '#';
  bool output_13 = is_tail(testcase_13);
  if (!assert_false("output_13", output_13)) {
    return false;
  }   


  char testcase_14 = 'x';              
bool output_14 = is_tail(testcase_14);     
if (!assert_false("output_14", output_14)) {
      return false; 
  }     

char testcase_15 = '*';
bool output_15 = is_tail(testcase_15);
if (!assert_false("output_15", output_15)) {
	return false;
}

char testcase_16 = ' ';
bool output_16 = is_snake(testcase_16);
if (!assert_false("output_16", output_16)) {
	return false;
}

  return true;
}

bool test_is_head() {
  
  char testcase_1 = 'W';
  bool output_1 = is_head(testcase_1);
  if (!assert_true("output_1", output_1)) {
        return false;
    }

  char testcase_2 = 'A';              
  bool output_2 = is_head(testcase_2);     
  if (!assert_true("output_2", output_2)) {
        return false; 
    }     

  char testcase_3 = 'S';              
bool output_3 = is_head(testcase_3);     
if (!assert_true("output_3", output_3)) {
      return false; 
  }

  char testcase_4 = 'D';              
bool output_4 = is_head(testcase_4);     
if (!assert_true("output_4", output_4)) {
      return false; 
  }     

  char testcase_5 = 'w';              
bool output_5 = is_head(testcase_5);     
if (!assert_false("output_5", output_5)) {
      return false; 
  }     

  char testcase_6 = 'a';              
bool output_6 = is_head(testcase_6);     
if (!assert_false("output_6", output_6)) {
      return false; 
  }     

  char testcase_7 = 's';              
bool output_7 = is_head(testcase_7);     
if (!assert_false("output_7", output_7)) {
      return false; 
  }     

  char testcase_8 = 'd';              
bool output_8 = is_head(testcase_8);     
if (!assert_false("output_8", output_8)) {
      return false; 
  }     

  char testcase_9 = '^';              
bool output_9 = is_head(testcase_9);     
if (!assert_false("output_9", output_9)) {
      return false; 
  }     

  char testcase_10 = '<';              
bool output_10 = is_head(testcase_10);     
if (!assert_false("output_10", output_10)) {
      return false; 
  }     

  char testcase_11 = 'v';              
bool output_11 = is_head(testcase_11);     
if (!assert_false("output_11", output_11)) {
      return false; 
  }     

  char testcase_12 = '>';              
bool output_12 = is_head(testcase_12);     
if (!assert_false("output_12", output_12)) {
      return false; 
  }     

  char testcase_13 = 'x';              
bool output_13 = is_head(testcase_13);     
if (!assert_true("output_13", output_13)) {
      return false; 
  }     
    printf("this one");
  char testcase_14 = '#';              
bool output_14 = is_head(testcase_14);     
if (!assert_false("output_14", output_14)) {
      return false; 
  }     

char testcase_15 = '*';
bool output_15 = is_head(testcase_15);
if (!assert_false("output_15", output_15)) {
	return false;
}

char testcase_16 = ' ';
bool output_16 = is_head(testcase_16);
if (!assert_false("output_16", output_16)) {
	return false;
}


  return true;
}

bool test_is_snake() {
  // TODO: 
  char testcase_1 = 'w';
bool output_1 = is_snake(testcase_1);
if (!assert_true("output_1", output_1)) {
	return false;
}

char testcase_2 = 'a';
bool output_2 = is_snake(testcase_2);
if (!assert_true("output_2", output_2)) {
	return false;
}

char testcase_3 = 's';
bool output_3 = is_snake(testcase_3);
if (!assert_true("output_3", output_3)) {
	return false;
}

char testcase_4 = 'd';
bool output_4 = is_snake(testcase_4);
if (!assert_true("output_4", output_4)) {
	return false;
}

char testcase_5 = '^';
bool output_5 = is_snake(testcase_5);
if (!assert_true("output_5", output_5)) {
	return false;
}

char testcase_6 = '<';
bool output_6 = is_snake(testcase_6);
if (!assert_true("output_6", output_6)) {
	return false;
}

char testcase_7 = 'v';
bool output_7 = is_snake(testcase_7);
if (!assert_true("output_7", output_7)) {
	return false;
}

char testcase_8 = '>';
bool output_8 = is_snake(testcase_8);
if (!assert_true("output_8", output_8)) {
	return false;
}

char testcase_9 = 'w';
bool output_9 = is_snake(testcase_9);
if (!assert_true("output_9", output_9)) {
	return false;
}

char testcase_10 = 'A';
bool output_10 = is_snake(testcase_10);
if (!assert_true("output_10", output_10)) {
	return false;
}

char testcase_11 = 'S';
bool output_11 = is_snake(testcase_11);
if (!assert_true("output_11", output_11)) {
	return false;
}

char testcase_12 = 'D';
bool output_12 = is_snake(testcase_12);
if (!assert_true("output_12", output_12)) {
	return false;
}

char testcase_13 = 'x';
bool output_13 = is_snake(testcase_13);
if (!assert_true("output_13", output_13)) {
	return false;
}

char testcase_14 = '#';
bool output_14 = is_snake(testcase_14);
if (!assert_false("output_14", output_14)) {
	return false;
}

char testcase_15 = '*';
bool output_15 = is_snake(testcase_15);
if (!assert_false("output_15", output_15)) {
	return false;
}

char testcase_16 = ' ';
bool output_16 = is_snake(testcase_16);
if (!assert_false("output_16", output_16)) {
	return false;
}

  return true;
}

bool test_body_to_tail() {
  // TODO: Implement this function.
  
    char testcase_1 = '^';
    char correct_1 = 'w';
char output_1 = body_to_tail(testcase_1);
if (!assert_equals_char("output_1", correct_1, output_1)) {
    return false;              
}                    

char testcase_2 = '<';
char correct_2 = 'a';
char output_2 = body_to_tail(testcase_2);
if (!assert_equals_char("output_2", correct_2, output_2)) {
    return false;              
}                    

char testcase_3 = 'v';
char correct_3 = 's';
char output_3 = body_to_tail(testcase_3);
if (!assert_equals_char("output_3", correct_3, output_3)) {
    return false;              
}                    

char testcase_4 = '>';
char correct_4 = 'd';
char output_4 = body_to_tail(testcase_4);
if (!assert_equals_char("output_4", correct_4, output_4)) {
    return false;                               


    return true;
}

bool test_head_to_body() {
  // TODO: Implement this function.
  
  char testcase_1 = 'W';
char correct_1 = '^';
char output_1 = head_to_body(testcase_1);
if (!assert_equals_char("output_1", correct_1, output_1)) {
    return false;                  
}

char testcase_2 = 'A';
char correct_2 = '<';
char output_2 = head_to_body(testcase_2);
if (!assert_equals_char("output_2", correct_2, output_2)) {
    return false;                  
}

char testcase_3 = 'S';
char correct_3 = 'v';
char output_3 = head_to_body(testcase_3);
if (!assert_equals_char("output_3", correct_3, output_3)) {
    return false;                  
}

char testcase_4 = 'D';
char correct_4 = '>';
char output_4 = head_to_body(testcase_4);
if (!assert_equals_char("output_4", correct_4, output_4)) {
    return false;                  
}
  

  return true;
}

bool test_get_next_row() {
  // TODO: Implement this function.
  
  unsigned int test_num = 3;


char testcase_1 = 'v';
unsigned int new_row_1 = 4;
unsigned int output_1 = get_next_row(test_num, testcase_1);
if (!assert_equals_int("output_1", new_row_1, output_1)) {
    return false;
}

char testcase_2 = 's';
unsigned int new_row_2 = 4;
unsigned int output_2 = get_next_row(test_num, testcase_2);
if (!assert_equals_int("output_2", new_row_2, output_2)) {
    return false;
}

char testcase_3 = 'S';
unsigned int new_row_3 = 4;
unsigned int output_3 = get_next_row(test_num, testcase_3);
if (!assert_equals_int("output_3", new_row_3, output_3)) {
    return false;
}

char testcase_4 = '^';
unsigned int new_row_4 = 2;
unsigned int output_4 = get_next_row(test_num, testcase_4);
if (!assert_equals_int("output_4", new_row_4, output_4)) {
    return false;
}

char testcase_5 = 'w';
unsigned int new_row_5 = 2;
unsigned int output_5 = get_next_row(test_num, testcase_5);
if (!assert_equals_int("output_5", new_row_5, output_5)) {
    return false;
}

char testcase_6 = 'W';
unsigned int new_row_6 = 2;
unsigned int output_6 = get_next_row(test_num, testcase_6);
if (!assert_equals_int("output_6", new_row_6, output_6)) {
    return false;
}

char testcase_7 = '<';
unsigned int new_row_7 = 3;
unsigned int output_7 = get_next_row(test_num, testcase_7);
if (!assert_equals_int("output_7", new_row_7, output_7)) {
    return false;
}

char testcase_8 = '>';
unsigned int new_row_8 = 3;
unsigned int output_8 = get_next_row(test_num, testcase_8);
if (!assert_equals_int("output_8", new_row_8, output_8)) {
    return false;
}

char testcase_9 = 'a';
unsigned int new_row_9 = 3;
unsigned int output_9 = get_next_row(test_num, testcase_9);
if (!assert_equals_int("output_9", new_row_9, output_9)) {
    return false;
}

char testcase_10 = 'A';
unsigned int new_row_10 = 3;
unsigned int output_10 = get_next_row(test_num, testcase_10);
if (!assert_equals_int("output_10", new_row_10, output_10)) {
    return false;
}

char testcase_11 = 'd';
unsigned int new_row_11 = 3;
unsigned int output_11 = get_next_row(test_num, testcase_11);
if (!assert_equals_int("output_11", new_row_11, output_11)) {
    return false;
}

char testcase_12 = 'D';
unsigned int new_row_12 = 3;
unsigned int output_12 = get_next_row(test_num, testcase_12);
if (!assert_equals_int("output_12", new_row_12, output_12)) {
    return false;
}

char testcase_13 = '#';
unsigned int new_row_13 = 3;
unsigned int output_13 = get_next_row(test_num, testcase_13);
if (!assert_equals_int("output_13", new_row_13, output_13)) {
    return false;
}

char testcase_14 = '*';
unsigned int new_row_14 = 3;
unsigned int output_14 = get_next_row(test_num, testcase_14);
if (!assert_equals_int("output_14", new_row_14, output_14)) {
    return false;
}

char testcase_15 = ' ';
unsigned int new_row_15 = 3;
unsigned int output_15 = get_next_row(test_num, testcase_15);
if (!assert_equals_int("output_15", new_row_15, output_15)) {
    return false;
}

char testcase_16 = 'x';
unsigned int new_row_16 = 3;
unsigned int output_16 = get_next_row(test_num, testcase_16);
if (!assert_equals_int("output_16", new_row_16, output_16)) {
    return false;
}


  return true;
}



bool test_get_next_col() {
  // TODO: Implement this function.
  
  unsigned int test_num = 3;

char testcase_1 = '>';
unsigned int new_col_1 = 4;
unsigned int output_1 = get_next_col(test_num, testcase_1);
if (!assert_equals_int("output_1", new_col_1, output_1)) {
    return false;
}

char testcase_2 = 'd';
unsigned int new_col_2 = 4;
unsigned int output_2 = get_next_col(test_num, testcase_2);
if (!assert_equals_int("output_2", new_col_2, output_2)) {
    return false;
}

char testcase_3 = 'D';
unsigned int new_col_3 = 4;
unsigned int output_3 = get_next_col(test_num, testcase_3);
if (!assert_equals_int("output_3", new_col_3, output_3)) {
    return false;
}

char testcase_4 = '<';
unsigned int new_col_4 = 2;
unsigned int output_4 = get_next_col(test_num, testcase_4);
if (!assert_equals_int("output_4", new_col_4, output_4)) {
    return false;
}

char testcase_5 = 'a';
unsigned int new_col_5 = 2;
unsigned int output_5 = get_next_col(test_num, testcase_5);
if (!assert_equals_int("output_5", new_col_5, output_5)) {
    return false;
}

char testcase_6 = 'A';
unsigned int new_col_6 = 2;
unsigned int output_6 = get_next_col(test_num, testcase_6);
if (!assert_equals_int("output_6", new_col_6, output_6)) {
    return false;
}

char testcase_7 = '^';
unsigned int new_col_7 = 3;
unsigned int output_7 = get_next_col(test_num, testcase_7);
if (!assert_equals_int("output_7", new_col_7, output_7)) {
    return false;
}

char testcase_8 = 'v';
unsigned int new_col_8 = 3;
unsigned int output_8 = get_next_col(test_num, testcase_8);
if (!assert_equals_int("output_8", new_col_8, output_8)) {
    return false;
}

char testcase_9 = 'w';
unsigned int new_col_9 = 3;
unsigned int output_9 = get_next_col(test_num, testcase_9);
if (!assert_equals_int("output_9", new_col_9, output_9)) {
    return false;
}

char testcase_10 = 'W';
unsigned int new_col_10 = 3;
unsigned int output_10 = get_next_col(test_num, testcase_10);
if (!assert_equals_int("output_10", new_col_10, output_10)) {
    return false;
}

char testcase_11 = 's';
unsigned int new_col_11 = 3;
unsigned int output_11 = get_next_col(test_num, testcase_11);
if (!assert_equals_int("output_11", new_col_11, output_11)) {
    return false;
}

char testcase_12 = 'S';
unsigned int new_col_12 = 3;
unsigned int output_12 = get_next_col(test_num, testcase_12);
if (!assert_equals_int("output_12", new_col_12, output_12)) {
    return false;
}

char testcase_13 = 'x';
unsigned int new_col_13 = 3;
unsigned int output_13 = get_next_col(test_num, testcase_13);
if (!assert_equals_int("output_13", new_col_13, output_13)) {
    return false;
}

char testcase_14 = '#';
unsigned int new_col_14 = 3;
unsigned int output_14 = get_next_col(test_num, testcase_14);
if (!assert_equals_int("output_14", new_col_14, output_14)) {
    return false;
}

char testcase_15 = '*';
unsigned int new_col_15 = 3;
unsigned int output_15 = get_next_col(test_num, testcase_15);
if (!assert_equals_int("output_15", new_col_15, output_15)) {
    return false;
}

char testcase_16 = ' ';
unsigned int new_col_16 = 3;
unsigned int output_16 = get_next_col(test_num, testcase_16);
if (!assert_equals_int("output_16", new_col_16, output_16)) {
    return false;
}



  return true;
}




bool test_customs() {
  if (!test_greater_than_forty_two()) {
    printf("%s\n", "test_greater_than_forty_two failed.");
    return false;
  }
  if (!test_is_vowel()) {
    printf("%s\n", "test_is_vowel failed.");
    return false;
  }
  if (!test_is_tail()) {
    printf("%s\n", "test_is_tail failed");
    return false;
  }
  if (!test_is_head()) {
    printf("%s\n", "test_is_head failed");
    return false;
  }
  if (!test_is_snake()) {
    printf("%s\n", "test_is_snake failed");
    return false;
  }
  if (!test_body_to_tail()) {
    printf("%s\n", "test_body_to_tail failed");
    return false;
  }
  if (!test_head_to_body()) {
    printf("%s\n", "test_head_to_body failed");
    return false;
  }
  if (!test_get_next_row()) {
    printf("%s\n", "test_get_next_row failed");
    return false;
  }
  if (!test_get_next_col()) {
    printf("%s\n", "test_get_next_col failed");
    return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  init_colors();

  if (!test_and_print("custom", test_customs)) {
    return 0;
  }

  return 0;
}
