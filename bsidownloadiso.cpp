void diso() {
	int i;
	
	cout << "\n";
	cout << "Choose iso file:\n\n";
	cout << "1. FreeBSD 11.0 i386.\n";
	cout << "2. FreeBSD 11.0 x64.\n";
	cout << "3. Ubuntu 16.04 x64.\n";
	cin >> i;

	if(i == 1) system("fetch http://ftp.freebsd.org/pub/FreeBSD/releases/ISO-IMAGES/11.0/FreeBSD-11.0-RELEASE-i386-disc1.iso -o /usr/bsi/iso");
	else if(i == 2) system("fetch http://ftp.freebsd.org/pub/FreeBSD/releases/ISO-IMAGES/11.0/FreeBSD-11.0-RELEASE-amd64-disc1.iso -o /usr/bsi/iso");
	else if(i == 3) system("fetch http://releases.ubuntu.com/16.04/ubuntu-16.04.2-server-amd64.iso -o /usr/bsi/iso");
	else cout << "Choose correct answer.\n";
}
