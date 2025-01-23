#ifndef TERMINAL_H
#define TERMINAL_H

/*** includes ***/
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>


void funcRawModeDisabled();

void funcRawModeEnabled();

char editorReadKey();

#endif
