void conf(char *vm) {
	char path_img[150], os[250], cpu[250], mem[250], disk[250], net[250];

	sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
	ifstream vm_img(path_img);

	if(vm_img) {

		cout << "\n";

		cout << "Name: " << vm << "\n";

		sprintf(os, "/bin/cat /usr/bsi/vm/%s/%s.sh | /usr/bin/grep OS | /usr/bin/cut -c 2-25", vm, vm);
		system(os);


		sprintf(cpu, "/bin/cat /usr/bsi/vm/%s/%s.sh | /usr/bin/grep CPU | /usr/bin/cut -c 2-25", vm, vm);
		system(cpu);

		sprintf(mem, "/bin/cat /usr/bsi/vm/%s/%s.sh | /usr/bin/grep Memory | /usr/bin/cut -c 2-25", vm, vm);
		system(mem);

		sprintf(disk, "/bin/cat /usr/bsi/vm/%s/%s.sh | /usr/bin/grep Disk | /usr/bin/cut -c 2-25", vm, vm);
		system(disk);

		sprintf(net, "/bin/cat /usr/bsi/vm/%s/%s.sh | /usr/bin/grep Network | /usr/bin/cut -c 2-25", vm, vm);
                system(disk);

		cout << "\n";
	}

	else {
		cout << "\n";	
		cout << "VM does not exists.\n\n";
	}
}
