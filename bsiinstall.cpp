#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;

void install() {
	int os, cpu, mem, disk;
	char iso[100], tap[100], name[100], com1[300], com2[300], com3[300];
	char *cmd1, *cmd2;
	ofstream osconf;

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
		
		osconf.open
		
		sprintf(com1, "cd /usr/vm/ && mkdir %s; cd %s && truncate -s %iG %s.img", name, name, disk, name);
		sprintf(com2, " && echo '#!/bin/sh' > %s.sh; echo '/usr/share/examples/bhyve/vmrun.sh -c %i -m %i -t %s -d %s.img %s' >> %s.sh && chmod +x %s.sh", name, cpu, mem, tap, name, name, name, name);
		sprintf(com3, " && /usr/share/examples/bhyve/vmrun.sh -c %i -m %i -t %s -d %s.img -i -I %s %s", cpu, mem, tap, name, iso, name);
		cmd1 = strcat(com1, com2);
		cmd2 = strcat(cmd1, com3);
		system(cmd2);
		

	}
	
	else if(os ==2) cout << "Sorry we work!\n";
}
