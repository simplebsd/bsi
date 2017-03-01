#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
using namespace std;

void stop(char *vm) {
	char com[50], path[100];

	sprintf(com, "bhyvectl --destroy --vm=%s", vm);
	system(com);

	sleep(1);

	sprintf(path, "/dev/vmm/%s", vm);
        ifstream vm_file(path);
        if(!vm_file) {
                cout << "\n";
                cout << vm << " is stoped.\n\n";
        }

        else {
                cout << "\n";
                cout << vm << " was not stoped.\n\n";
        }

}
