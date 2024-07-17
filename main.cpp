#include <iostream>
#include <ncurses.h>
#include <vector>
#include <string>
using namespace std;

#define ctrl(x) (x & 0x1F)


void save(WINDOW *stdscr ){
//    scr_dump("test.txt");
    int maxx , maxy;
    vector<string> data;
    data.clear();
    string line;
    getmaxyx(stdscr, maxy , maxx);
    for(int i=0 ; i<maxx ; i++){
         
    }
}

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
                  if(x<1){
                    y=y-1;
                    move(y,x);
                  }
                  else{
                    move(y,x-1);
                  }
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
              case ctrl('O') :
                  save(stdscr);
                  break;
            default:
                  printw("%c" , ch);
        }
        refresh();
    }
    endwin();
	return 0;
	
}