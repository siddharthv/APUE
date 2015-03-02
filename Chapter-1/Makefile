ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS =	basicls copyf_unbuf copyf_std hellopid basic_shell error_func_ex uid_gid basic_shell_with_sig Ex1-1

all:	$(PROGS)

%:	%.c
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

#include $(ROOT)/Make.libapue.inc
