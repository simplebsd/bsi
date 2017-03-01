#include <iostream>
#include <cstring>
#include "bsilist.cpp"
#include "bsiactive.cpp"
#include "bsistart.cpp"
#include "bsipoweroff.cpp"
using namespace std;

char *vm;

int main(int argc, char *argv[]) {
	
	vm = argv[2];

	if(argc < 2)  {
		cout << "Not enough parameters\n";
	}

	else {

		if(!strcmp(argv[1], "-l")) list();
		else if(!strcmp(argv[1], "-a")) active();
		else if(!strcmp(argv[1], "-s") && !strcmp(argv[2], vm)) start(vm);
		else if(!strcmp(argv[1], "-p") && !strcmp(argv[2], vm)) stop(vm);

		else cout << "Not parameters\n";


	}

	return 0;
}
