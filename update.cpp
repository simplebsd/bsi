void update() {
	system("/usr/local/bin/git clone https://github.com/simplebsd/bsi /usr/local/etc/bsi/update");
	system("cd /usr/local/etc/bsi/update && make update");
	system("rm -rf /usr/local/etc/bsi/update/*");
	system("rm -rf /usr/local/etc/bsi/update/.git");
}
