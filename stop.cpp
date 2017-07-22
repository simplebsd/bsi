using namespace std;

void stop(char *vm) {
	char com[50], path_img[100], path_vm[100];

	sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
	ifstream vm_img(path_img);

	if(vm_img) {

		sprintf(com, "bhyvectl --destroy --vm=%s", vm);
		system(com);

		sleep(1);

		sprintf(path_vm, "/dev/vmm/%s", vm);
        	ifstream vm_file(path_vm);
        	if(!vm_file) {
           		cout << "\n";
                	cout << vm << " is stoped.\n\n";
        	}

        	else {
                	cout << "\n";
                	cout << vm << " was not stoped.\n\n";
        	}
	}

	else {
		cout << "\n";	
		cout << "VM does not exists.\n\n";
	}
}
