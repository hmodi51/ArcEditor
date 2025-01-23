
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>



struct termios original;

// disabling the raw mode which will reset the settings of terminal
void funcRawModeDisabled(){
   tcsetattr(STDIN_FILENO , TCSAFLUSH , &original);
}

void funcRawModeEnabled(){
   struct termios noecho;
   tcgetattr(STDIN_FILENO , &original);
   //calling the function in atexit when the program terminates
   atexit(funcRawModeDisabled);                       
   noecho = original;
   // disabling terminal control functions ECHO AND ICANON
   noecho.c_lflag &= ~( ECHO | ICANON | ISIG | IEXTEN );
   noecho.c_iflag &= ~( ICRNL | IXON);
   noecho.c_oflag &= ~(OPOST);
   noecho.c_cc[VMIN] = 0;
   noecho.c_cc[VTIME] = 1;
   tcsetattr(STDIN_FILENO , TCSAFLUSH , &noecho);
   

}

int main() {
  funcRawModeEnabled();
  char c;
  while(1){
   c = '\0';
   read(STDIN_FILENO , &c , 1);
   if (c=='q'){
      break;
   }
  }
//   while (read(STDIN_FILENO , &c , 1) == 1 && c!= 'q');
//       printf("%d " , c);
  return 0;
}
