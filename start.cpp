using namespace std;

void start(char *vm) {
	char com[100], path_img[100], path_vm[100], dt[100];

	time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        sprintf(dt, "%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
	ifstream vm_img(path_img);

	if(vm_img) {
		sprintf(com, "/usr/local/bin/screen -d -m -S %s sh -c 'cd /usr/bsi/vm/%s && ./%s.sh';", vm, vm, vm); 
		system(com);
	
		sleep(1);

		sprintf(path_vm, "/dev/vmm/%s", vm);
		ifstream vm_file(path_vm);
		if(vm_file) {
			ofstream logfile;
			logfile.open("/var/log/bsi.log", ios::app);
			logfile << dt << "\t" << vm << " is started\n";
			logfile.close();

			cout << "\n";
			cout << vm << " is started.\n\n";
		}

		else {
			cout << "\n";
			cout << vm << " not started.\n\n";
		}
	}

	else {
		cout << "\n";	
		cout << "VM does not exists.\n\n";
	}

}
