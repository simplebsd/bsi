void snap() {
	ifstream snap;
	snap.open("/usr/local/etc/bsi/snap.conf");
	
	cout << "\n";
	cout << snap.rdbuf();
	cout << "\n";

	snap.close();
}
