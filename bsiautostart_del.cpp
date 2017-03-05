#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void autostart_del(char *vm) {
	char path[100], com[300], file[100];;

	sprintf(path, "/usr/bsi/vm/%s/%s.img", vm, vm);
	ifstream vm_file(path);

	if(vm_file) {
		sprintf(file, "/usr/local/etc/rc.d/%s_bsivm", vm);
		remove(file);
		sprintf(com, "sed -i '' '/%s_bsivm_enable=\"YES\"/d' /etc/rc.conf", vm);
		system(com);
	
		cout << "\n";
		cout << vm << " deleted from autostart.\n\n";
	}

	else {
		cout << "\n";
		cout << "Vm does not exists.\n\n";
	}
}
