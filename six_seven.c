/*========================================
 *    sl.c: SL version 5.03
 *        Modified to use six_seven.h macros
 *========================================
 */
#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "six_seven.h"

#define CUSTOMHEIGHT 32
#define CUSTOMLENGTH 60  // Adjust based on your image width

int add_custom(int x);
int my_mvaddstr(int y, int x, char *str);

int my_mvaddstr(int y, int x, char *str)
{
    for ( ; x < 0; ++x, ++str)
        if (*str == '\0')  return ERR;
    for ( ; *str != '\0'; ++str, ++x)
        if (mvaddch(y, x, *str) == ERR)  return ERR;
    return OK;
}

int main(int argc, char *argv[])
{
    int x;
    initscr();
    signal(SIGINT, SIG_IGN);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);

    for (x = COLS - 1; ; --x) {
        if (add_custom(x) == ERR) break;
        getch();
        refresh();
        usleep(40000);
    }
    mvcur(0, COLS - 1, LINES - 1, 0);
    endwin();

    return 0;
}

int add_custom(int x)
{
    static char *custom[CUSTOMHEIGHT]
        = {STR01, STR02, STR03, STR04, STR05, STR06, STR07, STR08,
           STR09, STR10, STR11, STR12, STR13, STR14, STR15, STR16,
           STR17, STR18, STR19, STR20, STR21, STR22, STR23, STR24,
           STR25, STR26, STR27, STR28, STR29, STR30, STR31, STR32};

    int y, i;

    if (x < -CUSTOMLENGTH) return ERR;

    y = LINES / 2 - CUSTOMHEIGHT / 2;

    for (i = 0; i < CUSTOMHEIGHT; ++i) {
        my_mvaddstr(y + i, x, custom[i]);
    }
    
    return OK;
}