#pragma once

#include <Antilatency.InterfaceContract.h>
#include <dlfcn.h>

namespace Antilatency {
    namespace InterfaceContract {

        class SharedLibrary {
        public:
            SharedLibrary(const char* libraryName) {
                _library = dlopen(libraryName, RTLD_LAZY);
            }
            bool isLoaded() {
                return _library != nullptr;
            }
            void unload() {
                if(isLoaded()){
                    dlclose(_library);
                    _library = nullptr;
                }
            }
            void* getFunctionPointer(const char* functionName) {
                if(isLoaded()){
                    return dlsym(_library, functionName);
                }
                return nullptr;
            }
        private:
            void* _library = nullptr;
        };
    }
}
