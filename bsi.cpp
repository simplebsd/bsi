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

		else cout << "Not parameters\n";


	}

	return 0;
}
