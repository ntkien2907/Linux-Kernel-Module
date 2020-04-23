KDIR = /lib/modules/`uname -r`/build

all:	user_app.c
	cc -o run user_app.c
	make -C $(KDIR) M=`pwd`

clean:
	make -C $(KDIR) M=`pwd` clean
	rm run
