#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

void install() {
	int os, cpu, mem, disk;
	char iso[150], tap[100], name[100], com1[300], com2[300];
	char *filename; 

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
		cout << "Enter number of cores CPU(1-4): ";
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
		
		sprintf(com1, "mkdir /usr/vm/%s; truncate -s %iG /usr/vm/%s/%s.img", name, disk, name, name);
		system(com1);
		sprintf(filename, "/usr/vm/%s/%s.sh", name, name);
		ofstream osconf;
		osconf.open(filename);
		osconf << "#!/bin/sh\n/usr/share/examples/bhyve/vmrun.sh -c " << cpu << " -m " <<  mem << " -t " << tap << " -d " << name << ".img " << name << "\n";
		osconf.close();
		sprintf(com2, "chmod +x /usr/vm/%s/%s.sh; /usr/share/examples/bhyve/vmrun.sh -c %i -m %i -t %s -d /usr/vm/%s/%s.img -i -I %s %s", name, name, cpu, mem, tap, name, name, iso, name);
		system(com2);
		

	}
	
	else if(os == 2) cout << "Sorry we work!\n";
}
