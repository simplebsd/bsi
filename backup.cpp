void backup() {
	ifstream backup;
	backup.open("/usr/local/etc/bsi/backup.conf");
	
	cout << "\n";
	cout << backup.rdbuf();
	cout << "\n";

	backup.close();
}
