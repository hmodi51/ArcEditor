
/*** includes ***/
#include "terminal.h"


/*** defines ***/

#define CTRL(i) ((i) & 0x1F)



// /*** terminal ***/

// // disabling the raw mode which will reset the settings of terminal
// void funcRawModeDisabled(){
//    tcsetattr(STDIN_FILENO , TCSAFLUSH , &original);
// }

// void funcRawModeEnabled(){
//    struct termios noecho;
//    tcgetattr(STDIN_FILENO , &original);
//    //calling the function in atexit when the program terminates
//    atexit(funcRawModeDisabled);                       
//    noecho = original;
//    // disabling terminal control functions ECHO AND ICANON
//    noecho.c_lflag &= ~( ECHO | ICANON | ISIG | IEXTEN );
//    noecho.c_iflag &= ~( ICRNL | IXON);
//    noecho.c_oflag &= ~(OPOST);
//    noecho.c_cc[VMIN] = 0;
//    noecho.c_cc[VTIME] = 1;
//    tcsetattr(STDIN_FILENO , TCSAFLUSH , &noecho);
   
// }


// char editorReadKey(){
//     char c;
//     read(STDIN_FILENO , &c , 1);
//     return c;
// }


/*** input ***/

void processKeypress(){
   while(1){
   char c = editorReadKey();
   switch(c){
      case CTRL('q'):
         return;
         break;
   }
   }
}


/*** init ***/

int main() {
  funcRawModeEnabled();
  processKeypress();
  return 0;
}
