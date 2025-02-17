/*** includes ***/
#include "terminal.h"
#include "commons.h"
#include "input.h"

/*** struct ***/
struct termios original;

/*** terminal ***/

// disabling the raw mode which will reset the settings of terminal
void funcRawModeDisabled(){
  if(tcsetattr(STDIN_FILENO , TCSAFLUSH , &original) == -1){
   perror("tcsetattr");
  }
}


//enabling raw mode
void funcRawModeEnabled(){
   struct termios noecho;
   // saving the settings of the terminal in termios struct original
   if(tcgetattr(STDIN_FILENO , &original) == -1){
      perror("tcgetattr");
   }
   //calling the function in atexit when the program terminates
   atexit(funcRawModeDisabled);                       
   noecho = original;
   // disabling terminal control functions ECHO AND ICANON
   noecho.c_lflag &= ~( ECHO | ICANON | ISIG | IEXTEN );
   noecho.c_iflag &= ~( ICRNL | IXON);
   noecho.c_oflag &= ~(OPOST);
   noecho.c_cc[VMIN] = 0;
   noecho.c_cc[VTIME] = 1;
   if(tcsetattr(STDIN_FILENO , TCSAFLUSH , &noecho) == -1){
      perror("tcsetattr");
   }
   
}


char editorReadKey(){
    char c;
    read(STDIN_FILENO , &c , 1);
    return c;
}
