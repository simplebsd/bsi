#include <fstream>
#include <unistd.h>
using namespace std;

char *vm;

void start(int argc, char *argv[]) {
	//char *vm;
	char com[100], path[100];

	if(argc != 3) {
		cout << "Usage: bsistart <vm>\n";
	}

	vm = argv[1];
	sprintf(com, "screen -d -m -S %s sh -c 'cd /usr/vm/%s && ./%s.sh';", vm, vm, vm); 
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
