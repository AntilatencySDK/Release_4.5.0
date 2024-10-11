#pragma once

#include <Antilatency.Api.h>

#if defined(__has_include) && __has_include(<QLibrary>)
    #include "Antilatency.InterfaceContract.SharedLibrary.Qt.h"
#elif defined(_WIN32)
    #if !defined(WINAPI_FAMILY) || (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
        #include "Antilatency.InterfaceContract.SharedLibrary.Win32.h"
    #elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
        #include "Antilatency.InterfaceContract.SharedLibrary.Uwp.h"
    #endif
#elif defined(__ANDROID__) || defined(__linux__)
    #include "Antilatency.InterfaceContract.SharedLibrary.Unix.h"
#endif


namespace Antilatency {
    namespace InterfaceContract {

        template<typename LibraryInterface>
        class LibraryLoader : public Antilatency::InterfaceContract::Library<LibraryInterface> {
        public:
            LibraryLoader(const char* libraryName) : _library(libraryName){

            }
            typename Library<LibraryInterface>::LibraryEntryPoint getEntryPoint() override{
                if(_library.isLoaded()){
                    return reinterpret_cast<typename Library<LibraryInterface>::LibraryEntryPoint>(_library.getFunctionPointer("getLibraryInterface"));
                }
                return nullptr;
            }
            bool isLoaded() {
                return _library.isLoaded();
            }
        protected:
            void unloadLibraryImpl() override {
                //_library.unload();
            }
        private:
            SharedLibrary _library;
        };


        template<typename LibraryInterface>
        LibraryInterface getLibraryInterface(const char* libraryName){
            return (new LibraryLoader<LibraryInterface>(libraryName))->getLibraryInterface();
        }
    }
}
