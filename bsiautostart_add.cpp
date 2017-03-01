#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

void autostart_add(char *vm) {
	char path[200], com[300];

	sprintf(path, "/usr/vm//%s/%s.img", vm, vm);
	ifstream vm_file(path);

	if(vm_file) {
	

	sprintf(com, "echo '#!/bin/sh\n\n. /etc/rc.subr\n\nname=\"%s_bsivm\"\nrcvar=`set_rcvar`\nstart_cmd=\"/usr/local/bin/bsi -s %s\"\n\nload_rc_config $name\n\nrun_rc_command \"$1\"' > /usr/local/etc/rc.d/%s_bsivm; chmod +x /usr/local/etc/rc.d/%s_bsivm && echo '%s_bsivm_enable=\"YES\"' >> /etc/rc.conf", vm, vm, vm, vm, vm);
	system(com);

	cout << "\n";
	cout << vm << " added to autostart.\n\n";

	}

	else cout << "Vm does not exists.\n";
}
