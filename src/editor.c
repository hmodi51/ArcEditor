#include <stdio.h>
#include <ncurses.h>
// #include <string>
// #include <fstream>
// using namespace std;

#define ctrl(x) (x & 0x1F)


// void openFile(string name){
//     // ifstream MyReadFile(name);
//     // string text;
//     // while(getline (MyReadFile, text )){
//     //     printw("%s" , text.c_str());
//     // //    cout << text;
//     //     refresh();
//     // }
// }


// void save(WINDOW *editWindow , string name, int maxy){
// //    scr_dump("test.txt");
// // cout << maxy;
//     int maxx;
//     int tempy;
//     // vector<string> data;
//     data.clear();
//     getmaxyx(editWindow, tempy , maxx);
//     for(int y=0 ; y<=maxy ; y++){
//         string line;
//         for(int x=0;x<maxx;x++){
//          char ch = mvinch( y ,x ) & A_CHARTEXT;
//          line += ch;
//     }
//        data.push_back(line);
//     }
//     ofstream MyFile(name);
//     for(int i=0;i<data.size();i++){
//         //  move(i+1,0);
//         //  printw("%s" , data[i].c_str());
//          MyFile << data[i];
//         //  refresh();
//     }
//     MyFile.close();
// }

int main(int argc , char* argv[])
{	
   // string name;
    // if (argc > 1){
    //     name = argv[1];
    // }
    int ch;
    int oldy;
    int newy;
    int oldx;
	initscr();			
	cbreak();			
    noecho();
   //  openFile(name);
     WINDOW *editWindow = newwin(100, 5, 1,1);
     keypad(editWindow , true);
     scrollok(editWindow , true);
     idlok(editWindow , true);
    while((ch=wgetch(editWindow))!=KEY_F(1))
    {
        getyx(editWindow,newy,oldx);
        // if(newy>oldy){
        //     oldy=newy;
        //     // cout << "testing";
        // }
        // else{
        //     newy=oldy;
        //     // cout << "testing2";
        // }
        //wprintw(editWindow , "Key code: %d", ch);
        switch(ch){
            case KEY_BACKSPACE :
            case 127:
                 int x , y;
                 getyx(editWindow , y , x);
                // wprintw(editWindow , "print0");
                  if(x>0){
                    wmove(editWindow , y,x-1);
                  }
                  else{
                  //  wprintw(editWindow , "print1");
                    wmove(editWindow , y-1,x);
                  //  wprintw(editWindow , "testing");
                  }
                 wdelch(editWindow);
                 break;
            case KEY_UP :
                  getyx(editWindow , y , x);
                  wmove(editWindow , y-1,x);
                  break;
             case KEY_DOWN :
                  getyx(editWindow , y , x);
                  wmove(editWindow , y+1,x);
                  break;
             case KEY_RIGHT :
                  getyx(editWindow , y , x);
                  wmove(editWindow ,  y ,x+1);
                  break;
              case KEY_LEFT :
                  getyx(editWindow , y , x);
                  wmove(editWindow,  y,x-1);
                  break;
              case ctrl('O') :
                //  save(editWindow, name , newy);
                  break;
            default:
                  wprintw(editWindow , "%c" , ch);
        }
        wrefresh(editWindow);
    }
    endwin();
	return 0;
}


