
/*** includes ***/
#include "terminal.h"
#include "commons.h"
#include "input.h"

/*** init ***/

int main() {
  funcRawModeEnabled();
  processKeypress();
  return 0;
}
