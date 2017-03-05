#include <iostream>
#include <cstring>
#include "bsiactive.cpp"
#include "bsistart.cpp"
#include "bsipoweroff.cpp"
#include "bsilist.cpp"
#include "bsiinstall.cpp"
#include "bsidelete.cpp"
#include "bsiclon.cpp"
#include "bsiopen.cpp"
#include "bsiautostart_add.cpp"
#include "bsiautostart_del.cpp"
#include "bsiautostart_list.cpp"
using namespace std;

char *vm, *vm2;

int main(int argc, char *argv[]) {
	
	vm = argv[2];
	vm2 = argv[3];

	if(argc < 2)  {
		cout << "Not enough parameters\n";
	}

	else {

		if(!strcmp(argv[1], "-a")) active();
		else if(!strcmp(argv[1], "-l")) list();
		else if(!strcmp(argv[1], "-s") && !strcmp(argv[2], vm)) start(vm);
		else if(!strcmp(argv[1], "-p") && !strcmp(argv[2], vm)) stop(vm);
		else if(!strcmp(argv[1], "-r") && !strcmp(argv[2], vm)) {
			stop(vm); 
			start(vm);
		}
		else if(!strcmp(argv[1], "-i")) install();
		else if(!strcmp(argv[1], "-d") && !strcmp(argv[2], vm)) del(vm);
		else if(!strcmp(argv[1], "-c") && !strcmp(argv[2], vm) && !strcmp(argv[3], vm2)) clon(vm, vm2);
		else if(!strcmp(argv[1], "-o") && !strcmp(argv[2], vm)) open(vm);
		else if(!strcmp(argv[1], "-u")) autostart_list();
		else if(!strcmp(argv[1], "-ua") && !strcmp(argv[2], vm)) autostart_add(vm);
		else if(!strcmp(argv[1], "-ud") && !strcmp(argv[2], vm)) autostart_del(vm);

		else {
			cout << "\n";
			cout << "Not enough parameters.\n\n";
		}


	}

	return 0;
}
