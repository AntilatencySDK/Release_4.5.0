#pragma once

#include <string>
#include <cstring>
#include <stdexcept>


#if defined(_WIN32)
    #include <filesystem>
    #include <sstream>
    #include <Windows.h>
#elif defined(__linux__)
    #include <dlfcn.h>
#endif

namespace Antilatency {
    namespace InterfaceContract {
        namespace PathResolver {

#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
            inline std::string siblingLibraryPath(const std::string& name) {
                return name;
            }
#elif defined(_WIN32) && (!defined(WINAPI_FAMILY) || (WINAPI_FAMILY != WINAPI_FAMILY_APP))
            inline std::filesystem::path getCurrentModulePath() {
                wchar_t path[512];
                HMODULE hm = NULL;

                if (GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                    GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                    (LPCWSTR)&getCurrentModulePath, &hm) == 0) {
                    int ret = GetLastError();
                    std::stringstream ss;
                    ss << "GetModuleHandleExA failed, error = " << ret;
                    throw std::runtime_error(ss.str());
                }
                if (GetModuleFileNameW(hm, path, sizeof(path)) == 0) {
                    int ret = GetLastError();
                    std::stringstream ss;
                    ss << "GetModuleFileNameA failed, error = " << ret;
                    throw std::runtime_error(ss.str());
                }
                return std::filesystem::path(path);
            }

            inline std::string siblingLibraryPath(const std::string& name) {
                auto path = getCurrentModulePath();
                auto dir = path.parent_path();
                auto result = dir.append((name + ".dll"));
                return result.string().c_str();
            }
#elif defined(__ANDROID__)
            inline std::string siblingLibraryPath(const std::string& name) {
                std::string androidLibraryName = "lib" + name + ".so";
                return androidLibraryName;
            }
#elif defined(__linux__)
            inline std::string getParentPath(const char *inp){
                auto len = strlen(inp);
                if(len == 0) throw std::runtime_error("no parent path: " + std::string(inp));
                int i = len - 1;
                while(i > 0){
                    if(inp[i] == '/'){
                        return std::string(inp, inp + i + 1);
                    }
                    --i;
                }
                throw std::runtime_error("no parent path: " + std::string(inp));
            }

            inline std::string getCurrentModulePath(){
                Dl_info dlinfo;
                auto dladdrRes = dladdr(reinterpret_cast<void*>(getCurrentModulePath), &dlinfo);
                if(dladdrRes == 0){
                    auto err = dlerror();
                    throw std::runtime_error(std::string("dladdr failed") + err);
                }
                auto len = strlen(dlinfo.dli_fname);
                if(len == 0) {
                    throw std::runtime_error("module path == \"\"");
                }
                //crash. https://stackoverflow.com/questions/63902528/program-crashes-when-filesystempath-is-destroyed
                //return std::filesystem::path(dlinfo.dli_fname).parent_path();
                return getParentPath(dlinfo.dli_fname);
            }

            inline std::string siblingLibraryPath(const std::string& name) {
                auto path = getCurrentModulePath();
                auto libPath = path.append(("lib" + name + ".so"));
                return libPath;
            }
#endif
        }
    }
}
