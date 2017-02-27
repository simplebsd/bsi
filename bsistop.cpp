#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {
	char *vm;
	char com[50], path[100];

	if(argc != 2) {
		cout << "Usage: bsistop <vm>\n";
	}

	vm = argv[1];
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

	return 0;
}
