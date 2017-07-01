void del(char *vm) {
	char com[100], com2[150], path_img[100], path_vm[100], a_vm[100], check_tap[250], tapd[100], delete_tapc[250], delete_tapi[250], delete_tapif[250];
	struct stat st;

	sprintf(a_vm, "/dev/vmm/%s", vm);
	fstream vm_file(a_vm);

	if(!vm_file) {
		sprintf(path_img, "/usr/bsi/vm/%s/%s.img", vm, vm);
		ifstream vm_img(path_img);

		if(vm_img) {
			sprintf(com, "bhyvectl --destroy --vm=%s", vm);
			system(com);

			sprintf(check_tap, "/usr/local/bin/bsi -k %s | /usr/bin/grep tap | /usr/bin/awk '{print $3}' > /usr/local/etc/bsi/tap_change.txt", vm);
			system(check_tap);

			sprintf(com2, "rm -rf /usr/bsi/vm/%s", vm);
			system(com2);


			ifstream tapr("/usr/local/etc/bsi/tap_change.txt");
                	tapr >> tapd;
                	tapr.close();

			sprintf(delete_tapc, "sed -i '' '/^cloned_interfaces/s/ %s//g' /etc/rc.conf", tapd);
                	system(delete_tapc);

			sprintf(delete_tapi, "sed -i '' '/^ifconfig_bridge0/s/ addm %s//g' /etc/rc.conf", tapd);
                	system(delete_tapi);

			sprintf(delete_tapif, "ifconfig %s destroy", tapd);
			system(delete_tapif);
		
			sprintf(path_vm, "/usr/bsi/vm/%s/%s.img", vm, vm);
			ifstream vm_file(path_vm);

			if(!vm_file) {
				cout << "\n";
				cout << vm << " is deleted.\n\n";
               		}

			else {
				cout << "\n";
				cout << vm << " not deleted.\n\n";
			}
		}

		else {
			cout << "\n";	
			cout << "VM does not exists.\n\n";
		}

	}

	else {
		cout << "\n";
		cout << "First stop VM, and then delete.\n\n";
	}
}
