#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[]) {
	char *vm;
	char com[100];

	if(argc != 2) {
		cout << "Usage: bsistart <vm>\n";
	}

	vm = argv[1];
	sprintf(com, "screen -d -m -S %s sh -c 'cd /usr/vm/%s && ./%s.sh'", vm, vm, vm); 
	system(com);

	return 0;
}
