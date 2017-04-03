#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

void conf(char *vm) {
	char path_img[150], com[250], os[100];

	sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
	ifstream vm_img(path_img);

	if(vm_img) {

		sprintf(com, "/bin/cat /usr/bsi/vm/%s/%s.sh | /usr/bin/grep OS | /usr/bin/cut -c 6-15", vm, vm);
		system(com);

		

	}

	else {
		cout << "\n";	
		cout << "VM does not exists.\n\n";
	}
}
