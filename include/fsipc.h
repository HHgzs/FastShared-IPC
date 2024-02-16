#ifndef __FAST_SHARED_IPC_H__
#define __FAST_SHARED_IPC_H__
#include <string>

namespace fsipc {
    key_t __gen_hash_shm_key__(const std::string& __str);
}





#endif