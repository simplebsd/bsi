install:
	pkg ins -y screen rsync
	mkdir -p /usr/vm/iso
	clang++ bsi.cpp -o /usr/local/bin/bsi
	clang++ bsicreate.cpp -o /usr/local/bin/bsicreate
	clang++ bsistart.cpp -o /usr/local/bin/bsistart
	clang++ bsistop.cpp -o /usr/local/bin/bsistop
	clang++ bsilist.cpp -o /usr/local/bin/bsilist
	clang++ bsidelete.cpp -o /usr/local/bin/bsidelete
	clang++ bsiopen.cpp -o /usr/local/bin/bsiopen
	clang++ bsiclon.cpp -o /usr/local/bin/bsiclon

deinstall:
	pkg del -y screen rsync
	pkg autoremove -y
	rm /usr/local/bin/bsi
	rm /usr/local/bin/bsicreate
	rm /usr/local/bin/bsistart
	rm /usr/local/bin/bsistop
	rm /usr/local/bin/bsilist
	rm /usr/local/bin/bsidelete
	rm /usr/local/bin/bsiopen
	rm /usr/local/bin/bsiclon
