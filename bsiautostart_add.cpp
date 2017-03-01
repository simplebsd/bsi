#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void autostart_add(char *vm) {
	char com[300];

	sprintf(com, "echo '#!/bin/sh\n\n. /etc/rc.subr\n\nname=\"%s\"\nrcvar=`set_rcvar`\nstart_cmd=\"/usr/local/bin/bsi -s %s\"\n\nload_rc_config $name\n\nrun_rc_command \"$1\"' > /usr/local/etc/rc.d/%s; chmod +x /usr/local/etc/rc.d/%s && echo '%s_enable=\"YES\"' >> /etc/rc.conf", vm, vm, vm, vm, vm);
	system(com);

	cout << vm << " added to autostart.\n";
}
