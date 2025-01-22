
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>



struct termios original;


void funcRawModeDisabled(){
   tcsetattr(STDIN_FILENO , TCSAFLUSH , &original);   // set the terminal attribute back to as it was before starting the program
}

void funcRawModeEnabled(){
   struct termios noecho;
   tcgetattr(STDIN_FILENO , &original);
   atexit(funcRawModeDisabled);                       // at exit is called when the program terminated and calls the function argument
   noecho = original;
   noecho.c_lflag = noecho.c_lflag ^ ( ECHO | ICANON );  //disables the terminal functions like ECHO and ICANON
   tcsetattr(STDIN_FILENO , TCSAFLUSH , &noecho);  
   

}

int main() {
  funcRawModeEnabled();
  char c;
  while (read(STDIN_FILENO , &c , 1) == 1 && c!= 'q');
  printf("%d " , c);
  return 0;
}
