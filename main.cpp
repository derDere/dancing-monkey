#include <iostream>
#include <locale.h>
#include <ncursesw/ncurses.h>
#include <string>
#include <sys/stat.h>

#include "monkey.hpp"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define APP "Dancing-Monkey"

using namespace std;

const string FILE_NAME = "kill.me";

void quit();
void calcCenter(int, int, int&, int&);
bool exists(string name);

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

  int width, height;
  getmaxyx(stdscr, height, width);

  int frame = 0;
  int frameMilliSeconds = 1000000 / MONKEY_FPS;
  int x, y;
  calcCenter(width, height, x, y);

  while (true) {
    // int input = getch(); depricated! add timeout!
    int input = wgetch(win);

    for(int line = 0; line < MONKEY_HEIGHT - 1; line++) {
      for(int col = 0; col < MONKEY_WIDTH; col++) {
        const wchar_t c[3] = { MONKEY_FRAMES[((MONKEY_WIDTH * MONKEY_HEIGHT) * frame) + (line * MONKEY_WIDTH) + col], L' ', 0 };
        mvaddwstr(line + y, col + x, c);
      }
    }
    frame++;
    if (frame >= MONKEY_FRAME_COUNT) {
      frame = 0;
    }

    // Print the Wellcome message
    mvaddstr(y + MONKEY_HEIGHT + 1, x, "      Welcome");
    mvaddstr(y + MONKEY_HEIGHT + 3, x, "Take a look at this");
    mvaddstr(y + MONKEY_HEIGHT + 4, x, "  dancing monkey!");

    if (isDebug) {
      if (input == 'q' || input == 'Q' || input == 27) {
        break;
      }

      // if size of the terminal has changed
      if (input == KEY_RESIZE) {
        clear();
        getmaxyx(stdscr, height, width);
        calcCenter(width, height, x, y);
      }
    }

    // Check if the file exists
    if (exists(FILE_NAME)) {
      if (remove(FILE_NAME.c_str()) == 0) {
        break;
      }
    }

    // Sleep for a while
    usleep(frameMilliSeconds);
  }

  return 0;
}

bool exists(string name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

void calcCenter(int width, int height, int& x, int& y) {
  x = (width - MONKEY_WIDTH) / 2;
  y = (height - MONKEY_HEIGHT - 4) / 2;
}

void quit() {
  endwin();
}
