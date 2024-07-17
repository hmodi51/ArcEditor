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
                 int x , y;
                 getyx(stdscr , y , x);
                 move(y,x-1);
                 delch();
                 break;
            case KEY_UP :
                  getyx(stdscr , y , x);
                  move(y-1,x);
                  break;
             case KEY_DOWN :
                  getyx(stdscr , y , x);
                  move(y+1,x);
                  break;
             case KEY_RIGHT :
                  getyx(stdscr , y , x);
                  move(y,x+1);
                  break;
              case KEY_LEFT :
                  getyx(stdscr , y , x);
                  move(y,x-1);
                  break;
            default:
                  printw("%c" , ch);
        }
        refresh();
    }
    endwin();
	return 0;
	
}