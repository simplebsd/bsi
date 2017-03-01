#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;

void del(char *vm) {
	char com[100];

	sprintf(com, "bhyvectl --destroy --vm=%s; rm -rf /usr/vm/%s", vm, vm);
	system(com);

	cout << "\n";
	cout << vm << " is deleted.\n\n";
}
