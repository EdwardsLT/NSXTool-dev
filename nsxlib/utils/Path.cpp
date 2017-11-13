#include <cstdlib>
#include <fstream>
#include <mutex>
#include <numeric>
#include <stdexcept>

#include "NSXConfig.h"
#include "Path.h"
#include "StringIO.h"

namespace nsx {

static int g_argc = 0;

static char** g_argv = nullptr;

std::mutex g_argc_mutex;
std::mutex g_argv_mutex;

std::string fileSeparator()
{
    #ifdef _WIN32
        return "\\";
    #else
        return "/";
    #endif
}

std::string fileBasename(const std::string& input_path)
{
    auto pos_sep = input_path.find_last_of(fileSeparator());
    return input_path.substr(pos_sep+1);
}

std::string removeFileExtension(const std::string& input_path)
{
    auto pos_sep = input_path.find_last_of(fileSeparator());
    auto pos_dot = input_path.substr(pos_sep+1).find_last_of(".");

    return input_path.substr(0,pos_sep + pos_dot + 1);
}

std::string fileDirname(const std::string& input_path)
{

    std::string output_path = trimmed(input_path);

    output_path.erase(output_path.find_last_of(fileSeparator()),output_path.size()-1);

    return output_path;
}

void setArgc(int argc)
{
    std::lock_guard<std::mutex> guard(g_argc_mutex);
    g_argc = argc;
}

void setArgv(char **argv)
{
    std::lock_guard<std::mutex> guard(g_argv_mutex);
    g_argv = argv;
}

std::string homeDirectory()
{
    const char* home_envvar = getenv("HOME");

    // Build the home directory from HOME environment variable
    if (home_envvar) {
        return std::string(home_envvar);
    }
    // If HOME is not defined (on Windows it may happen) define the home
    // directory from USERPROFILE environment variable
    else {
        home_envvar = getenv("USERPROFILE");
        if (home_envvar)
            return std::string(home_envvar);
        // If the USERPROFILE environment variable is not defined try to build
        // a home directory from the HOMEDRIVE and HOMEPATH environment variable
        else {
            char const *hdrive = getenv("HOMEDRIVE");
            char const *hpath = getenv("HOMEPATH");
            if (hdrive && hpath) {
                std::string home(hdrive);
                home += fileSeparator();
                home += hpath;
                return home;
            }
        }
    }
    // Otherwise throw and error
    throw std::runtime_error("The home directory could not be defined");
}

std::string buildPath(const std::string& root, const std::vector<std::string>& paths)
{
    auto append_path = [](std::string base, std::string p){return base+fileSeparator()+p;};

    std::string path = std::accumulate(paths.begin(),paths.end(),root,append_path);

    return path;
}

std::string applicationDataPath()
{
    std::vector<std::string> possible_paths = {
        "",
        ".",
        "nsxtool",
        homeDirectory(),
        homeDirectory() + fileSeparator() + "nsxtool",
        g_application_data_path
    };

    // check for environment variable NSX_ROOT_DIR
    const char* nsx_root_dir = getenv("NSX_ROOT_DIR");

    // if defined, it takes highest precedence
    if (nsx_root_dir) {
        possible_paths.insert(possible_paths.begin(), nsx_root_dir);
    }

    // add location of executable if possible
    if (g_argc > 0 && g_argv && g_argv[0]) {
        std::string path = fileDirname(g_argv[0]);
        possible_paths.insert(possible_paths.begin(), path);
    }

    std::vector<std::string> d19_relative_path = {"instruments","D19.yml"};

    for (auto&& path : possible_paths) {
        std::string d19_file = buildPath(path,d19_relative_path);

        std::ifstream file(d19_file, std::ios_base::in);
        if (file.good()) {
            file.close();
            return path;
        }
    }

    throw std::runtime_error("The application data directory could not be defined");
}

std::string diffractometersPath()
{
    std::string path = applicationDataPath() + fileSeparator() + "instruments";
    return path;
}

bool fileExists(const std::string& filename)
{
    std::ifstream fs(filename);
    return fs.good();
}

} // end namespace nsx

