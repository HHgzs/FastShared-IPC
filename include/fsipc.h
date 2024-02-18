#ifndef __FAST_SHARED_IPC_H__
#define __FAST_SHARED_IPC_H__
#include <string>

namespace fsipc {
    struct __ipc_info_node__ {
        size_t shm_size__ __attribute__((packed));
        key_t shm_key__ __attribute__((packed));
        key_t sem_key__ __attribute__((packed));
    };
    void __node_list_init__();
    void __node_list_extend__();
    void __node_list_destroy__();
    bool __find_or_create_node__(key_t __shm_key__);




    key_t __gen_hash_key__(const std::string& __str);
    void* __shm_alloc__(key_t __key__, size_t __size__);
    void __shm_free__(key_t __key__);

    template <class T>
    T* SharedMemory(std::string __name__, size_t __num__ = 1UL) {
        __ipc_info_node__ __node;
        __node.shm_size__ = __num__ * sizeof(T);
        __node.shm_key__ = __gen_hash_key__(__name__ + "_shm");
        __node.sem_key__ = __gen_hash_key__(__name__ + "_sem");
        T* __ptr = (T*)__shm_alloc__(__node.shm_key__, __num__ * sizeof(T));
        return __ptr;
    }
}





#endif