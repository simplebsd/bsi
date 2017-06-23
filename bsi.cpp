#include <iostream>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sys/stat.h>
#include "bsiactive.cpp"
#include "bsistart.cpp"
#include "bsistop.cpp"
#include "bsistop_all.cpp"
#include "bsilist.cpp"
#include "bsiinstall.cpp"
#include "bsidelete.cpp"
#include "bsiclon.cpp"
#include "bsiopen.cpp"
#include "bsiautostart_add.cpp"
#include "bsiautostart_del.cpp"
#include "bsiautostart_list.cpp"
#include "bsidownloadiso.cpp"
#include "bsisetup.cpp"
#include "bsiupdate.cpp"
//#include "bsiconf.cpp"
//#include "bsibackup.cpp"
using namespace std;

char *vm, *vm2;

int main(int argc, char *argv[]) {
	
	vm = argv[2];
	vm2 = argv[3];

	if(argc < 2)  {
		cout << "\e[1mNAME\e[0m\n";
		cout << "\tbsi - Bhyve simple installer\n\n";
		cout << "\e[1mSYNOPSYS\e[0m\n";
		cout << "\tbsi [ -alfaiukbdwstup ] [ -sfrdouaud \033[4mVM\033[24m ] [ -c \033[4mVM\033[24m \033[4mNEWVM\033[24m ]\n\n";
		cout << "\e[1mDESCRIPTION\e[0m\n";
		cout << "\tBsi is a simple Bhyve VM manager. It helps to install and manage virtual machines on Bhyve hypervisor.\n\n";
		cout << "\e[1mOPTIONS\e[0m\n";
		cout << "\t-a\t List all active virtual machines.\n\n";
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
//		cout << "\t-k \033[4mVM\033[24m\t Show configuration of virtual machine.\n\n";
//		cout << "\t-b\t Show backup information of virtual machines.\n\n";
		cout << "\t-dw\t Download installation iso.\n\n";
		cout << "\t-st\t Setup bhyve configuration files.\n\n";
		cout << "\t-up\t Setup bhyve configuration files.\n\n";
		
	}

	else {

		if(!strcmp(argv[1], "-a")) active();
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
//		else if(!strcmp(argv[1], "-k") && !strcmp(argv[2], vm)) conf(vm);
//		else if(!strcmp(argv[1], "-b")) backup();
		else if(!strcmp(argv[1], "-dw")) diso();
		else if(!strcmp(argv[1], "-st")) setup();
		else if(!strcmp(argv[1], "-up")) update();

		else {
			cout << "\n";
			cout << "Not enough parameters.\n";
			cout << "Run bsi without parameters to see the manual.\n\n";
		}


	}

	return 0;
}
