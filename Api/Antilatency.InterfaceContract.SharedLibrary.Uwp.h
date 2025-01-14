#pragma once

#include <string>
#include <Antilatency.InterfaceContract.h>

#ifndef _WINDOWS_
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif

    #include <windows.h>
#endif

namespace Antilatency {
    namespace InterfaceContract {

        class SharedLibrary {
        public:
            SharedLibrary(const char* libraryName) {
                std::string s(libraryName);
                std::wstring ws(s.begin(), s.end());
                _library = LoadPackagedLibrary(ws.c_str(), 0);
            }
            bool isLoaded() {
                return _library != nullptr;
            }
            void unload() {
                if(isLoaded()){
                    FreeLibrary(_library);
                    _library = nullptr;
                }
            }
            void* getFunctionPointer(const char* functionName) {
                if(isLoaded()){
                    auto* func = GetProcAddress(_library, functionName);
                    return reinterpret_cast<void*>(func);
                }
                return nullptr;
            }
        private:
            HMODULE _library = nullptr;
        };
    }
}
