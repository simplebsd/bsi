void confed(char *vm) {
	char path_img[150], os[250], cpu[250], mem[250], disk[250], net[250];

        sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
        ifstream vm_img(path_img);

        if(vm_img) {	
		cout << "Name[" << old_name << "]: ";
		cin >> new_name;
		cout << "CPU, cores[" << old_core << "]: ";
		cin >> new_core;
		cout << "Memory, MB[" << old_mem << "]: ";
		cin >> new_mem;
