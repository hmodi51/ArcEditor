/*** includes ***/
#include "terminal.h"
#include "input.h"
#include "commons.h"

/*** defines ***/

#define CTRL(i) ((i) & 0x1F)
int inputMode = 0;

/*** input ***/

void processKeypress(){
   while(1){
   char c = editorReadKey();
   switch(c){
      case CTRL('Q'):
         return;
         break;
   }
   if(c == ':' ){
      char a = editorReadKey();
      switch(a){
         case 'q':
            return;
            break;
      }
   }
   }
}