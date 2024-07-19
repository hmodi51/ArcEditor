#include <iostream>
#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#define ctrl(x) (x & 0x1F)


void openFile(string name){
    ifstream MyReadFile(name);
    string text;
    while(getline (MyReadFile, text )){
        printw("%s" , text.c_str());
    //    cout << text;
        refresh();
    }
}


void save(WINDOW *stdscr , string name, int maxy){
//    scr_dump("test.txt");
cout << maxy;
    int maxx;
    int tempy;
    vector<string> data;
    data.clear();
    getmaxyx(stdscr, tempy , maxx);
    for(int y=0 ; y<=maxy ; y++){
        string line;
        for(int x=0;x<maxx;x++){
         char ch = mvinch(y ,x ) & A_CHARTEXT;
         line += ch;
    }
       data.push_back(line);
    }
    ofstream MyFile(name);
    for(int i=0;i<data.size();i++){
        //  move(i+1,0);
        //  printw("%s" , data[i].c_str());
         MyFile << data[i];
        //  refresh();
    }
    MyFile.close();
}

int main(int argc , char* argv[])
{	
    string name;
    if (argc > 1){
        name = argv[1];
    }
    int ch;
    int oldy;
    int newy;
    int oldx;
	initscr();			
	cbreak;			
	keypad(stdscr , true);
    noecho();
     openFile(name);
    while((ch=getch())!=KEY_F(1))
    {
        getyx(stdscr,newy,oldx);
        if(newy>oldy){
            oldy=newy;
            cout << "testing";
        }
        else{
            newy=oldy;
            cout << "testing2";
        }
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
                  save(stdscr , name , newy);
                  break;
            default:
                  printw("%c" , ch);
        }
        refresh();
    }
    endwin();
	return 0;
}