#include <iostream>
#include <ncurses.h>
using namespace std;

int main()
{	
    int ch;
	initscr();			
	cbreak;			
	keypad(stdscr , true);
    noecho();
    while((ch=getch())!=KEY_F(1))
    {

        switch(ch){
            case KEY_BACKSPACE :
                 printw("%c" , ch);
                 delch();
                 break;
            default:
                  printw("%c" , ch);
        }
        refresh();
    }
    endwin();
	return 0;
	
}