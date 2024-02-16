#include "fsipc.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string>

key_t fsipc::__gen_hash_shm_key__(const std::string& __str__) {
    unsigned long __hash = 5381;
    const char* __cstr = __str__.c_str();
    int __c;
    while ((__c = *__cstr++))
        __hash = ((__hash << 5) + __hash) + __c;

    return (key_t)__hash;
}

