#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sys/stat.h>
using namespace std;

void autostart_add(char *vm) {
	char path[200], filename[300], rc_file[50];

	sprintf(path, "/usr/vm//%s/%s.img", vm, vm);
	ifstream vm_file(path);

	if(vm_file) {
		sprintf(filename, "/usr/local/etc/rc.d/%s_bsivm", vm);
		ofstream upconf;
		upconf.open(filename);
		upconf << "#!/bin/sh\n#\n# PROVIDE: utility\n# REQUIRE: DAEMON\n# KEYWORD: shutdown\n\n. /etc/rc.subr\n\nname=\"" << vm << "_bsivm\"\nrcvar=`set_rcvar`\nstart_cmd=\"/usr/local/bin/bsi -s " << vm << "\"\n\nload_rc_config $name\n\nrun_rc_command \"$1\"\n";
		upconf.close();

		ofstream rcconf;
		rcconf.open("/etc/rc.conf", ios::app);
		rcconf << vm << "_bsivm_enable=\"YES\"\n";
		rcconf.close();

		sprintf(rc_file, "/usr/local/etc/rc.d/%s_bsivm", vm);
		chmod(rc_file, S_IRWXU|S_IXGRP|S_IXOTH);

		cout << "\n";
		cout << vm << " added to autostart.\n\n";
	}

	else {
		cout << "\n";	
		cout << "VM does not exists.\n\n";
	}
}
