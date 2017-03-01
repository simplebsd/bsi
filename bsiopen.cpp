#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void open(char *vm) {
	char com[50];
	
	sprintf(com, "/usr/local/bin/screen -r %s", vm);
	system(com);
}
	
