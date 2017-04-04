install:
	pkg ins -y screen rsync
	mkdir -p /usr/bsi/vm
	mkdir -p /usr/bsi/iso
	mkdir -p /usr/local/etc/bsi
	touch /usr/local/etc/bsi/tap.conf
	clang++ bsi.cpp -o /usr/local/bin/bsi
	clang++ s_wipe.cpp -o s_wipe
	./s_wipe
	rm s_wipe

deinstall:
	pkg del -y screen rsync
	pkg autoremove -y
	rm /usr/local/bin/bsi
