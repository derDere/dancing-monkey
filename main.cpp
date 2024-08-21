#include <iostream>
#include <locale.h>
#include <ncursesw/ncurses.h>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define APP "Dancing-Monkey"

using namespace std;

/* A long int buffer containing the ascii animation of a dancing monkey for the mvaddstr function to get */
const char* monkey = "  , - ~ ~ ~ - ,\n" \
                     "  , '      ' , \n" \
                     " ,           , \n" \
                     " ,           , \n" \
                     " ,           , \n";

void quit();

/**
 * Project: Dancing-Monkey
 * Creator: derDere
 * Creation Date: Wen Aug 21 18:07:57 CEST 2024
 */
int main(int argc, char* argv[]) {
  bool isDebug = false;

  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      if (string(argv[i]) == "-d" || string(argv[i]) == "--debug" || string(argv[i]) == "debug") {
        isDebug = true;
      }
    }
  }

  // Init Curses ----------
  setlocale(LC_ALL, "");
  WINDOW* win = initscr();
  atexit(quit);
  curs_set(0);
  start_color();
  clear();
  noecho();
  cbreak();
  keypad(stdscr, true);
  //mousemask(BUTTON1_CLICKED, NULL); //ALL_MOUSE_EVENTS, NULL);

  nodelay(win, true);

  mvaddstr( 3, 5, monkey);

  while (true) {
    int input = getch();
    if (isDebug) {
      if (input == 'q' || input == 'Q' || input == 27) {
        break;
      }
    }
  }

  return 0;
}

void quit() {
  endwin();
}
