#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
using namespace std;

void del(char *vm) {
	char com[100], com2[150], path_img[100], path_vm[100], a_vm[100];
	struct stat st;

	sprintf(a_vm, "/dev/vmm/%s", vm);
	fstream vm_file(a_vm);

	if(!vm_file) {
		sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
		ifstream vm_img(path_img);

		if(vm_img) {
			sprintf(com, "bhyvectl --destroy --vm=%s", vm);
			system(com);

			sprintf(com2, "rm -rf /usr/bsi/vm/%s", vm);
			system(com2);
		
			sprintf(path_vm, "/usr/bsi/vm/%s/%s.img", vm, vm);
			ifstream vm_file(path_vm);

			if(!vm_file) {
				cout << "\n";
				cout << vm << " is deleted.\n\n";
               		}

			else {
				cout << "\n";
				cout << vm << " not deleted.\n\n";
			}
		}

		else {
			cout << "\n";	
			cout << "VM does not exists.\n\n";
		}

	}

	else {
		cout << "\n";
		cout << "First stop VM, and then delete.\n\n";
	}
}
