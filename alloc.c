/* alloc.c
 * 17 Apr 2000
 * memory allocation with error output if fails
 */

#include <stdio.h>
        /* fprintf, stderr      */
#include <stdlib.h>
        /* calloc, free          */
#include "alloc.h"

void * xcalloc(size_t n, size_t s, int l, char* f)
{
void *tmp;
tmp = calloc(n, s);
if (tmp==NULL)
    {
    fprintf(stderr, "Failure to allocate %lu objects of %lu bytes ", 
	    (unsigned long) n, (unsigned long) s); 
    fprintf(stderr, "on line %d of %s\n", l, f);
    fprintf(stderr, "Emergency stop.\n");
    exit(1);
    }
return tmp;
}

