#ifndef _ENCLAVE_H_
#define _ENCLAVE_H_

#include <assert.h>
#include <stdlib.h>

#if defined(__cplusplus)
 {
#endif
void printf1();
void ecall_compile();
int __lxstat(int vers, const char *name, struct stat *buf);
#if defined(__cplusplus)
}
#endif

#endif
