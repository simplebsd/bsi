#include <iostream>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "active.cpp"
#include "start.cpp"
#include "stop.cpp"
#include "stop_all.cpp"
#include "list.cpp"
#include "install.cpp"
#include "delete.cpp"
#include "clon.cpp"
#include "open.cpp"
#include "autostart_add.cpp"
#include "autostart_del.cpp"
#include "autostart_list.cpp"
#include "downloadiso.cpp"
#include "setup.cpp"
#include "update.cpp"
#include "conf.cpp"
#include "confed.cpp"
//#include "build.cpp"
//#include "snap.cpp"
using namespace std;

char *vm, *vm2;

int main(int argc, char *argv[]) {
	
	vm = argv[2];
	vm2 = argv[3];

	if(argc < 2)  {
		cout << "\e[1mNAME\e[0m\n";
		cout << "\tbsi - Bhyve simple installer\n\n";
		cout << "\e[1mDESCRIPTION\e[0m\n";
		cout << "\tBsi is a simple Bhyve VM manager. It helps to install and manage virtual machines on Bhyve hypervisor.\n\n";
		cout << "\e[1mOPTIONS\e[0m\n";
		cout << "\t-a\t List all active virtual machines.\n\n";
//		cout << "\t-b\Build VM.\n\n";
		cout << "\t-l\t List all virtual machines.\n\n";
		cout << "\t-s \033[4mVM\033[24m\t Start a virtual machine.\n\n";
		cout << "\t-f \033[4mVM\033[24m\t Force stop a virtual machine.\n\n";
		cout << "\t-r \033[4mVM\033[24m\t Restart a virtual machine.\n\n";
		cout << "\t-fa\t Force stop all virtual machines.\n\n";
		cout << "\t-i\t Install a virtual machine.\n\n";
		cout << "\t-d \033[4mVM\033[24m\t Delete a virtual machine.\n\n";
		cout << "\t-c \033[4mVM\033[24m \033[4mNEWVM\033[24m\t Clone a virtual machine.\n\n";
		cout << "\t-o \033[4mVM\033[24m\t Open a session with virtual machine.\n\n";
		cout << "\t-u\t List all autostart virtual machines.\n\n";
		cout << "\t-ua \033[4mVM\033[24m\t Add a virtual machine to autostart.\n\n";
		cout << "\t-ud \033[4mVM\033[24m\t Delete a virtual machine from autostart.\n\n";
		cout << "\t-k \033[4mVM\033[24m\t Show configuration of virtual machine.\n\n";
		cout << "\t-ke \033[4mVM\033[24m\t Edit configuration of virtual machine.\n\n";
//		cout << "\t-b\t List snapshots of virtual machine.\n\n";
		cout << "\t-dw\t Download installation iso.\n\n";
		cout << "\tsetup\t Setup bhyve configuration files.\n\n";
		cout << "\tupdate\t Update bsi.\n\n";
		
	}

	else {

		if(!strcmp(argv[1], "-a")) active();
//		else if(!strcmp(argv[1], "-b")) build();
		else if(!strcmp(argv[1], "-l")) list();
		else if(!strcmp(argv[1], "-s") && !strcmp(argv[2], vm)) start(vm);
		else if(!strcmp(argv[1], "-f") && !strcmp(argv[2], vm)) stop(vm);
		else if(!strcmp(argv[1], "-r") && !strcmp(argv[2], vm)) {
			stop(vm); 
			start(vm);
		}
		else if(!strcmp(argv[1], "-fa")) stop_all();
		else if(!strcmp(argv[1], "-i")) install();
		else if(!strcmp(argv[1], "-d") && !strcmp(argv[2], vm)) del(vm);
		else if(!strcmp(argv[1], "-c") && !strcmp(argv[2], vm) && !strcmp(argv[3], vm2)) clon(vm, vm2);
		else if(!strcmp(argv[1], "-o") && !strcmp(argv[2], vm)) open(vm);
		else if(!strcmp(argv[1], "-u")) autostart_list();
		else if(!strcmp(argv[1], "-ua") && !strcmp(argv[2], vm)) autostart_add(vm);
		else if(!strcmp(argv[1], "-ud") && !strcmp(argv[2], vm)) autostart_del(vm);
		else if(!strcmp(argv[1], "-k") && !strcmp(argv[2], vm)) conf(vm);
		else if(!strcmp(argv[1], "-ke") && !strcmp(argv[2], vm)) confed(vm);
//		else if(!strcmp(argv[1], "-b")) snap();
		else if(!strcmp(argv[1], "-dw")) diso();
		else if(!strcmp(argv[1], "setup")) setup();
		else if(!strcmp(argv[1], "update")) update();

		else {
			cout << "\n";
			cout << "Not enough parameters.\n";
			cout << "Run bsi without parameters to see the manual.\n\n";
		}


	}

	return 0;
}
