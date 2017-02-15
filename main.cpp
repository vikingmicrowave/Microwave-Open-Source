#include "main.hpp"

int __attribute__((constructor)) Init() {
    /* do shiz her. */
    
    InitializeInterfaces();
    
    InitializeVMTs();
    
    InitializeHooks();
    
    NetVarManager::dumpNetvars();
    
    Offsets::getOffsets();
    
    return 0;
}

void __attribute__((constructor)) DeInit() {
}
