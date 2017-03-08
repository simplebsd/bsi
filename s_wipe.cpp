#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sys/stat.h>
using namespace std;

int main() {
	ofstream s_wipe;
	s_wipe.open("/usr/local/etc/rc.d/s_wipe");
	s_wipe << "#!/bin/sh\n#\n# PROVIDE: utility\n# REQUIRE: DAEMON\n# KEYWORD: shutdown\n\n. /etc/rc.subr\n\nname=\"s_wipe\"\nrcvar=`set_rcvar`\nstart_cmd=\"/usr/local/bin/screen -wipe\"\n\nload_rc_config $name\n\nrun_rc_command \"$1\"\n";
	s_wipe.close();

	system("sed -i '' '/s_wipe_enable=\"YES\"/d' /etc/rc.conf");
	ofstream rcconf;
	rcconf.open("/etc/rc.conf", ios::app);
	rcconf << "s_wipe_enable=\"YES\"\n";
	rcconf.close();

	chmod("/usr/local/etc/rc.d/s_wipe", S_IRWXU|S_IXGRP|S_IXOTH);

	return 0;

}
