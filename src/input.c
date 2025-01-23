/*** includes ***/
#include "terminal.h"
#include "input.h"
#include "commons.h"

/*** defines ***/

#define CTRL(i) ((i) & 0x1F)

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