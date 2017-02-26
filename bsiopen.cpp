#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[]) {
	char *vm;
	char com[50];
	
	if(argc != 2) {
		cout << "Usage: bsiopen <vm>\n";
	}
		
	vm = argv[1];
	sprintf(com, "screen -r %s", vm);
	system(com);

	return 0;
}
	
