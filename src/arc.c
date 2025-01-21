
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>


struct termios original;


void funcRawModeDisabled(){
   tcsetattr(STDIN_FILENO , TCSAFLUSH , &original);
}

void funcRawModeEnabled(){
   struct termios noecho;
   tcgetattr(STDIN_FILENO , &original);
   atexit(funcRawModeDisabled);
   noecho = original;
   noecho.c_lflag = noecho.c_lflag ^ ( ECHO | ICANON );
   tcsetattr(STDIN_FILENO , TCSAFLUSH , &noecho);
   

}

int main() {
  funcRawModeEnabled();
  char c;
  while (read(STDIN_FILENO , &c , 1) == 1 && c!= 'q');
  return 0;
}