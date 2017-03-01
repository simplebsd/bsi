#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void clon(char *vm, char *vm2) {
	char com[300];

	cout << "\n";

	sprintf(com, "/usr/local/bin/rsync -a --info=progress2 /usr/vm/%s/* /usr/vm/%s; mv /usr/vm/%s/%s.img /usr/vm/%s/%s.img; mv /usr/vm/%s/%s.sh /usr/vm/%s/%s.sh; sed -i '' 's/%s/%s/g' /usr/vm/%s/%s.sh", vm, vm2, vm2, vm, vm2, vm2, vm2, vm, vm2, vm2, vm, vm2, vm2, vm2);  
	system(com);

	cout << "\n";
	cout << "VM is cloned.\n\n";

}
	
