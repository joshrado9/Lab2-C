\
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mymemdump(FILE * fd, char * p , int len) {
	// Add your code here.
	// You may see p as an array.
	// p[0] will return the element 0 
	// p[1] will return the element 1 and so on
    	int c;
	int count = 0;
	int section = 16;
	while (count < len)
	{
		fprintf(fd, "0x%016lX: ", (unsigned long) p + count);
		// Print first byte as hexadecimal
		for (int i = count; i < len && i < count + 16; i ++)
		{
			c = p[i]&0xFF;
			fprintf(fd, "%02X ", c);
		}
		int s = len;
		while (s < count + 16)
		{
			s ++;
			fprintf(fd, "%s ", "  ");
		}
		fprintf(fd, "%s", " ");
		// Print first byte as character
		for (int i = count; i < len && i < count + 16; i ++)
		{
			c = p[i]&0xFF;
			fprintf(fd, "%c", (c>=32 && c <= 127)?c:'.');
		}
		count += 16;
		fprintf(fd,"\n");
	} 
}

