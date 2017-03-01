#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void autostart_del(char *vm) {
	char com[300];

	sprintf(com, "rm /usr/local/etc/rc.d/%s; sed -i '' '/%s_enable=\"YES\"/d' /etc/rc.conf", vm, vm);
	system(com);

	cout << vm << " deleted from autostart.\n";
}
