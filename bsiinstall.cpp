#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sys/stat.h>
using namespace std;

void install() {
	int os, cpu, mem, disk;
	char iso[150], tap[100], name[100], com1[300], com2[300], folder[150], filename[150], uifilename[150], ifile[100], ufilename[150], sh_file[150], ush_file[300];

	cout << "OS:\n";
	cout << "1. FreeBSD.\n";
	cout << "2. Ubuntu.\n\n";
	cout << "1 or 2: ";
	cin >> os;
	cout << "\n";

	if(os == 1) {
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
		cout << "Enter tap device: ";
		cin >> tap;
		cout << "\n";
		cout << "Enter name: ";
		cin >> name;
		
		sprintf(folder, "/usr/bsi/vm/%s", name);
		mkdir(folder, 0777);
		sprintf(com1, "truncate -s %iG /usr/bsi/vm/%s/%s.img", disk, name, name);
		system(com1);
		sprintf(filename, "/usr/bsi/vm/%s/%s.sh", name, name);
		ofstream osconf;
		osconf.open(filename);
		osconf << "#!/bin/sh\n\n#OS: FreeBSD\n\n/usr/share/examples/bhyve/vmrun.sh -c " << cpu << " -m " <<  mem << " -t " << tap << " -d " << name << ".img " << name << "\n";
		osconf.close();
		sprintf(sh_file, "/usr/bsi/vm/%s/%s.sh", name, name);
		chmod(sh_file, S_IRWXU|S_IXGRP|S_IXOTH);
		sprintf(com2, "/usr/share/examples/bhyve/vmrun.sh -c %i -m %i -t %s -d /usr/bsi/vm/%s/%s.img -i -I %s %s", cpu, mem, tap, name, name, iso, name);
		system(com2);	

	}
	
	else if(os == 2) {
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
                cout << "Enter tap device: ";
                cin >> tap;
                cout << "\n";
                cout << "Enter name: ";
                cin >> name;

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
	}
}
