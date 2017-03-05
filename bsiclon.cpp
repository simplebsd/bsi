#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void clon(char *vm, char *vm2) {
	char com[300], path_img[100];

	sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
	ifstream vm_img(path_img);

	if(vm_img) {
		cout << "\n";

		sprintf(com, "/usr/local/bin/rsync -a --info=progress2 /usr/bsi/vm/%s/* /usr/bsi/vm/%s; mv /usr/bsi/vm/%s/%s.img /usr/bsi/vm/%s/%s.img; mv /usr/bsi/vm/%s/%s.sh /usr/bsi/vm/%s/%s.sh; sed -i '' 's/%s/%s/g' /usr/bsi/vm/%s/%s.sh", vm, vm2, vm2, vm, vm2, vm2, vm2, vm, vm2, vm2, vm, vm2, vm2, vm2);  
		system(com);

		cout << "\n";
		cout << "VM is cloned.\n";
		cout << "Don't forget to change hostname, ip address and tap device.\n\n";
	}

	else {
		cout << "\n";	
		cout << "VM does not exists.\n\n";
	}

}
	
