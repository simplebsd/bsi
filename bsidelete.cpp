#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	char *vm;
	char com[100];

	if(argc != 2) {
		cout << "Usage: bsidelete <vm>\n";
	}

	vm = argv[1];
	sprintf(com, "bhyvectl --destroy --vm=%s; rm -rf /usr/vm/%s", vm, vm);
	system(com);

	return 0;
}
