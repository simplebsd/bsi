#include <iostream>
#include <cstring>
#include "bsilist.cpp"
#include "bsiactive.cpp"
#include "bsistart.cpp"
using namespace std;

int main(int argc, char *argv[]) {



	if(!strcmp(argv[1], "-l")) list();

	else if(!strcmp(argv[1], "-a")) active();
	
	else if(!strcmp(argv[1], "-s") && !strcmp(argv[2], vm)) start(1, *vm);

	else cout << "No, try again\n"; 

	return 0;
}
