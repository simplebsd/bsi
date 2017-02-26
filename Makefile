install:
	mkdir -p /usr/vm/iso
	clang++ bsi.cpp -o /usr/local/bin/bsi
	clang++ bsicreate.cpp -o /usr/local/bin/bsicreate
	clang++ bsistart.cpp -o /usr/local/bin/bsistart
	clang++ bsistop.cpp -o /usr/local/bin/bsistop
	clang++ bsilist.cpp -o /usr/local/bin/bsilist
	clang++ bsidelete.cpp -o /usr/local/bin/bsidelete
	clang++ bsiopen.cpp -o /usr/local/bin/bsiopen
	clang++ bsiclon.cpp -o /usr/local/bin/bsiclon
