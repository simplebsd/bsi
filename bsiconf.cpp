#include <iostream>
using namespace std;

void bsiconf(char *vm) {
	sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
	ifstream vm_img(path_img);

	if(vm_img) {

		system("/bin/cat /usr/bsi/vm/f2z/f2z.sh | /usr/bin/grep vmrun | /usr/bin/cut -c27-31");
		
		cout << "OS: " << os;

	}

	else {
		cout << "\n";	
		cout << "VM does not exists.\n\n";
	}
}
