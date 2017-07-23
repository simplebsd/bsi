void active() {
	char path_fol[100];
	
	strcpy(path_fol, "/dev/vmm");
	
	std::ifstream vm_fol(path_fol);
	if(vm_fol) {
		system("ls -1 /dev/vmm");
	}

	else std::cout << "No running vm's\n";

}
