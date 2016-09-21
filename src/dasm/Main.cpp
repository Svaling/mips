//
// File Name : Main.cpp
// File Date : 19 March 2012
// Author(s) : Valendian
//

#include <stdio.h>
#include <string.h>
#include "Main.h"
#include "Command.h"

static char Buffer[0x1000];

int main(int argc, char *argv[])
{
	// accept user input from the command line...
	if (argc > 1) {
		for (int i = 1; i < argc; i++) strcat_s(Buffer, sizeof(Buffer), argv[i]);
		if (!Command("CommandLine", Buffer)) return 0;
	}

	// accept user input from the console...
	while (*gets_s(Buffer, sizeof(Buffer))) if (!Command("Console", Buffer)) return 0;
	return 0;
}
