#pragma once

#include <Antilatency.Api.h>
#include <QLibrary>

namespace Antilatency {
    namespace InterfaceContract {

        class SharedLibrary {
        public:
            SharedLibrary(const char* libraryName) {
                _library.setFileName(libraryName);
                _library.load();
            }
            bool isLoaded() {
                return _library.isLoaded();
            }
            void unload() {
                _library.unload();
            }
            void* getFunctionPointer(const char* functionName) {
                if(!isLoaded()){
                    return nullptr;
                }
                auto* func = _library.resolve(functionName);
                return reinterpret_cast<void*>(func);
            }
        private:
            QLibrary _library;
        };
    }
}
