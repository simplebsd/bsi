#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void autostart_del(char *vm) {
	char path[100], com[300];

	sprintf(path, "/usr/vm//%s/%s.img", vm, vm);
	ifstream vm_file(path);

	if(vm_file) {
		sprintf(com, "rm /usr/local/etc/rc.d/%s_bsivm; sed -i '' '/%s_bsivm_enable=\"YES\"/d' /etc/rc.conf", vm, vm);
		system(com);
	
		cout << "\n";
		cout << vm << " deleted from autostart.\n\n";
	}

	else cout << "Vm does not exists.\n";
}