#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
using namespace std;

void del(char *vm) {
	char com[100], path_img[100], folder_vm[50], file_img[50], file_sh[50], path_vm[100], folder_path[100];
	struct stat st;
	sprintf(folder_path, "/usr/vm/%s", vm);

	sprintf(path_img, "/usr/vm/%s/%s.img", vm, vm);
	ifstream vm_img(path_img);

	if(vm_img) {
		sprintf(folder_vm, "/usr/vm/%s", vm);
		sprintf(file_img, "/usr/vm/%s/%s.img", vm, vm);
		sprintf(file_sh, "/usr/vm/%s/%s.sh", vm, vm);
		remove(file_img);
		remove(file_sh);
		rmdir(folder_vm);
		
		sprintf(com, "bhyvectl --destroy --vm=%s", vm);
		system(com);
		
		sprintf(path_vm, "/usr/vm/%s/%s.img", vm, vm);
		ifstream vm_file(path_vm);
		if(!vm_file) {
			cout << "\n";
			cout << vm << " is deleted.\n\n";

			if(stat(folder_path, &st) == 0) {
                        	cout << "\n";
                        	cout << "But folder not deleted.\nYou may remove it manually.\n\n";
			}

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
