#include "tetris.h"

#include <iostream>

#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

#include <curses.h>

using namespace std;

Tetris::Tetris (int w, int h) {
  width = w;
  height = h;
  step = 0;

  // [start of] Curses Initialisations
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  // [end of] Curses Initialisations
  
}

int Tetris::get_width () {
  return width;
}

int Tetris::get_height () {
  return height;
}

int Tetris::get_user_input (int timeout){
  
  //configure timeout to stop to wait for user in getch()
  timeout(timeout);

  //get a character from user
  struct timeval start, end;
  gettimeofday(&start, NULL);
  int pressed_key = getch();
  gettimeofday(&end, NULL);

  //computes how much time was used in getch()
  long diff_in_millis, seconds, millis;    
  seconds  = end.tv_sec  - start.tv_sec;
  millis = end.tv_usec - start.tv_usec;
  diff_in_millis = ((seconds) * 1000 + millis/1000.0) + 0.5;

  //decides if we have to wait a little more for the same cycle
  if (timeout > diff_in_millis){
    move_block(pressed_key);
    get_user_input(timeout - diff_in_millis);
  } else {
    step_forward();
    get_user_input(1000);
  }

  return 0;

}

int Tetris::step_forward () {
  step = step + 1;
  show_board(step);
  return 0;
}

int Tetris::move_block (int pressed_key) {

  switch(pressed_key) {
    
    case KEY_LEFT:  
      step = step - 1;
      show_board(step);
      break;

    case KEY_RIGHT:  
      step = step + 1;
      show_board(step);
      break;

  }

  
  return 0;
}

int Tetris::start_game () {


  

  

  get_user_input(1000);


  // tm* millis_before_getch = current_time_in_milliseconds();
  // int pressed_key = getch();
  // tm* millis_after_getch = current_time_in_milliseconds();

  // printf("%s\n", millis_after_getch);

  // while(pressed_key != 'q') {


  //   switch(pressed_key) {
  //     case KEY_LEFT:  printw("\nLeft Arrow");
  //     break;

  //     case KEY_RIGHT: printw("\nRight Arrow");
  //     break;
  //   }
  // }

  printw("\n\nTchau ;-)\n");

  refresh();
  getch();
  endwin();
  
  return 0;
}

int Tetris::show_board (int x) {

  clear();
  printw("TETRIS - aperte 'q' para sair\n");

  for (int i=0; i<height; ++i) {
    printw("\n");
    for (int j=0; j<width; ++j) {
      if (j==x){
        printw("#");
      } else {
        printw(".");
      }
    }
  }
  printw("\n");

  return 0;
}