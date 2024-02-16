#ifndef __FAST_SHARED_IPC_H__
#define __FAST_SHARED_IPC_H__
#include <string>

namespace fsipc {

    key_t __shm_gen_hash_key__(const std::string& __str);
    void* __shm_alloc__(key_t __key__, size_t __size__);
    void __shm_free__(key_t __key__);

}





#endif