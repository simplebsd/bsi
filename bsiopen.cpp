#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
using namespace std;

void open(char *vm) {
	char com[50], path_img[100];
	
	sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
	ifstream vm_img(path_img);

	if(vm_img) {

		sprintf(com, "/usr/local/bin/screen -r %s", vm);
		system(com);

	}

	else {
		cout << "\n";	
		cout << "VM does not exists.\n\n";
	}
}
	
