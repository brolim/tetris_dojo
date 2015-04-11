#include "tetris.h"

#include <iostream>

#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

#include <curses.h>

using namespace std;


int Tetris::start_game () {
  
  // [start of] Curses Initialisations
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  // [end of] Curses Initialisations

  show_board();
  get_user_input(1000);
  return 0;
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


int Tetris::end_game () {
  
  // [start of] Curses Finalizations
  refresh();
  endwin();
  // [end of] Curses Finalizations

  exit(0);
  return 0;
}


Tetris::Tetris () {
}

int Tetris::step_forward () {
  show_board();
  return 0;
}

int Tetris::move_block (int pressed_key) {

  switch(pressed_key) {
    
    case KEY_LEFT:  
      printw("left");
      break;

    case KEY_RIGHT:  
      printw("right");
      break;

    case 'q':  
      end_game();
      

  }

  
  return 0;
}



int Tetris::show_board () {

  clear();
  printw("TETRIS - aperte 'q' para sair\n");

  for (int i=0; i<20; ++i) {
    printw("\n");
    for (int j=0; j<20; ++j) {
      printw(".");
    }
  }

  printw("\n");

  return 0;
}