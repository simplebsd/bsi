#include <iostream>
#include <stdlib.h>
using namespace std;

void autostart_list() {
	system("ls /usr/local/etc/rc.d/ | grep bsivm | awk -F '_bsivm' '{print $1}'");
}
