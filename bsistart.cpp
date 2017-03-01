#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
using namespace std;

void start(char *vm) {
	char com[100], path[100];

	sprintf(com, "/usr/local/bin/screen -d -m -S %s sh -c 'cd /usr/vm/%s && ./%s.sh';", vm, vm, vm); 
	system(com);
	
	sleep(1);

	sprintf(path, "/dev/vmm/%s", vm);
	ifstream vm_file(path);
	if(vm_file) {
		cout << "\n";
		cout << vm << " is started.\n\n";
	}

	else {
		cout << "\n";
		cout << vm << " not started.\n\n";
	}

}
