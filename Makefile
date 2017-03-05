install:
	pkg ins -y screen rsync
	mkdir -p /usr/bsi/vm
	mkdir /usr/bsi/iso
	clang++ bsi.cpp -o /usr/local/bin/bsi

deinstall:
	pkg del -y screen rsync
	pkg autoremove -y
	rm /usr/local/bin/bsi
