void install() {
	int os, cpu, mem, disk, t, nt;
	char iso[150], tap[100], name[100], com1[300], com2[300], folder[150], filename[150], uifilename[150], ifile[100], ufilename[150], sh_file[150], ush_file[300], br1[150], br2[150], atp[300];

	cout << "OS:\n";
	cout << "1. FreeBSD.\n";
	cout << "2. Ubuntu.\n\n";
	cout << "1 or 2: ";
	cin >> os;
	cout << "\n";

	if(os == 1) {

		ifstream tapr("/usr/local/etc/bsi/tap.conf");
                tapr >> t;
                tapr.close();

                nt = t +1;

                sprintf(tap, "tap%i", nt);

		cout << "Enter full path for install iso: ";
		cin >> iso;
		cout << "\n";
		cout << "Enter number of cores CPU(1-16): ";
		cin >> cpu;
		cout << "\n";
		cout << "Enter size of memory(MB): ";
		cin >> mem;
		cout << "\n";
		cout << "Enter size of disk(GB): ";
		cin >> disk;
		cout << "\n";
		cout << "\n";
		cout << "Enter name: ";
		cin >> name;

		ofstream tapw("/usr/local/etc/bsi/tap.conf");
                tapw << nt;
                tapw.close();
		
		sprintf(br1, "/sbin/ifconfig %s create", tap);
		sprintf(br2, "/sbin/ifconfig bridge0 addm %s up", tap);
		system(br1);
		system(br2);
		system("sed -i '' '/^cloned_interfaces/s/.$//' /etc/rc.conf");
		system("sed -i '' '/^ifconfig_bridge0/s/...$//' /etc/rc.conf");
		sprintf(atp, "sed -i '' '/^cloned_interfaces/s/$/ %s\"/' /etc/rc.conf && sed -i '' '/^ifconfig_bridge0/s/$/addm %s up\"/' /etc/rc.conf", tap, tap); 
system(atp);
		
		sprintf(folder, "/usr/bsi/vm/%s", name);
		mkdir(folder, 0777);
		sprintf(com1, "truncate -s %iG /usr/bsi/vm/%s/%s.img", disk, name, name);
		system(com1);
		sprintf(filename, "/usr/bsi/vm/%s/%s.sh", name, name);
		ofstream osconf;
		osconf.open(filename);
		osconf << "#!/bin/sh\n\n#OS: FreeBSD\n#CPU(cores): " << cpu << "\n#Memory(MB): " << mem << "\n#Disk(GB): " << disk << "\n#Network : " << tap << "\n\n/usr/share/examples/bhyve/vmrun.sh -c " << cpu << " -m " <<  mem << " -t " << tap << " -d " << name << ".img " << name << "\n";
		osconf.close();
		sprintf(sh_file, "/usr/bsi/vm/%s/%s.sh", name, name);
		chmod(sh_file, S_IRWXU|S_IXGRP|S_IXOTH);
		sprintf(com2, "/usr/share/examples/bhyve/vmrun.sh -c %i -m %i -t %s -d /usr/bsi/vm/%s/%s.img -i -I %s %s", cpu, mem, tap, name, name, iso, name);
		system(com2);	
	}
	
	else if(os == 2) {
		ifstream tapr("/usr/local/etc/bsi/tap.conf");
                tapr >> t;
                tapr.close();

                nt = t +1;

                sprintf(tap, "tap%i", nt);

		cout << "Enter full path for install iso: ";
                cin >> iso;
                cout << "\n";
                cout << "Enter number of cores CPU(1-16): ";
                cin >> cpu;
                cout << "\n";
                cout << "Enter size of memory(MB): ";
                cin >> mem;
                cout << "\n";
                cout << "Enter size of disk(GB): ";
                cin >> disk;
                cout << "\n";
                cout << "\n";
                cout << "Enter name: ";
                cin >> name;

		ofstream tapwu("/usr/local/etc/bsi/tap.conf");
                tapwu << nt;
                tapwu.close();

                sprintf(br1, "/sbin/ifconfig %s create", tap);
                sprintf(br2, "/sbin/ifconfig bridge0 addm %s up", tap);
                system(br1);
                system(br2);
                system("sed -i '' '/^cloned_interfaces/s/.$//' /etc/rc.conf");
                system("sed -i '' '/^ifconfig_bridge0/s/...$//' /etc/rc.conf");
		sprintf(atp, "sed -i '' '/^cloned_interfaces/s/$/ %s\"/' /etc/rc.conf && sed -i '' '/^ifconfig_bridge0/s/$/addm %s up\"/' /etc/rc.conf", tap, tap); 
		system(atp);

		sprintf(folder, "/usr/bsi/vm/%s", name);
                mkdir(folder, 0777);
                sprintf(com1, "truncate -s %iG /usr/bsi/vm/%s/%s.img", disk, name, name);
                system(com1);
		sprintf(filename, "/usr/bsi/vm/%s/device.map", name);
		ofstream osconf;
                osconf.open(filename);
		osconf << "(hd0) /usr/bsi/vm/" << name << "/" << name << ".img\n(cd0) " << iso << "\n";
		osconf.close();
		sprintf(uifilename, "/usr/bsi/vm/%s/%s-install.sh", name, name);
		ofstream ui_file;
		ui_file.open(uifilename);
		ui_file << "#!/bin/sh\nbhyvectl --destroy --vm=" << name << "\ngrub-bhyve -r cd0 -m /usr/bsi/vm/" << name << "/device.map -M " << mem << " " << name << "\n\nbhyve -c " << cpu << " -m " << mem << " -H -P -A \\\n-l com1,stdio \\\n-s 0:0,hostbridge \\\n-s 1:0,lpc \\\n-s 2:0,virtio-net," << tap << " \\\n-s 3,ahci-cd," << iso << " \\\n-s 4,virtio-blk,/usr/bsi/vm/" << name << "/" << name << ".img " << name << "\nbhyvectl --destroy --vm=" << name << "\n";
		ui_file.close();
		chmod(uifilename, S_IRWXU|S_IXGRP|S_IXOTH);
		sprintf(ifile, "/usr/bsi/vm/%s/./%s-install.sh", name, name);
		system(ifile);
		remove(uifilename);
		sprintf(ufilename, "/usr/bsi/vm/%s/%s.sh", name, name);
		ofstream ush_file;
		ush_file.open(ufilename);
		ush_file << "#!/bin/sh\nwhile [ 1 ]; do\nbhyvectl --destroy --vm=" << name << "\ngrub-bhyve -r hd0,msdos1 -m /usr/bsi/vm/" << name << "/device.map -M " << mem << " " << name << "\n\nbhyve -c " << cpu << " -m " << mem << " -H -P -A \\\n-l com1,stdio \\\n-s 0:0,hostbridge \\\n-s 1:0,lpc \\\n-s 2:0,virtio-net," << tap << " \\\n-s 4,virtio-blk,/usr/bsi/vm/" << name << "/" << name << ".img " << name << " \nbhyve_exit=$?\nif [$bhyve_exit -ne 0]; then\nbreak\nfi\ndone\nbhyvectl --destroy --vm=" << name << "\n";
		ush_file.close();
		chmod(ufilename, S_IRWXU|S_IXGRP|S_IXOTH);

		ofstream tapw("/usr/local/etc/bsi/tap.conf");
                tapw << nt;
                tapw.close();
	}
}
