install:
	pkg ins -y screen 
	mkdir -p /usr/vm/iso
	cp bsi* /usr/local/bin
	chmod +x /usr/local/bin/bsi*
