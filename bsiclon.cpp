#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[]) {
	char *vm1, *vm2;
	char com[300];

	if(argc != 3) {
		cout << "Usage: bsiclon <vm>\n";
	}

	vm1 = argv[1];
	vm2 = argv[2];

	sprintf(com, "rsync -a --info=progress2 /usr/vm/%s/* /usr/vm/%s; mv /usr/vm/%s/%s.img /usr/vm/%s/%s.img; mv /usr/vm/%s/%s.sh /usr/vm/%s/%s.sh; sed -i '' 's/%s/%s/g' /usr/vm/%s/%s.sh", vm1, vm2, vm2, vm1, vm2, vm2, vm2, vm1, vm2, vm2, vm1, vm2, vm2, vm2);  
	system(com);

	return 0;
}
	
