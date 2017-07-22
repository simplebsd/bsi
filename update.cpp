void update() {
	system("/usr/local/bin/git clone https://github.com/simplebsd/bsi /usr/bsi/update");
	system("cd /usr/bsi/update && make update");
	system("rm -rf /usr/bsi/update/*");
	system("rm -rf /usr/bsi/update/.git");
}
