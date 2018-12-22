// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/utils/ProgressHandler.h
//! @brief     Implements module/class/test ProgressHandler
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

#include <atomic>
#include <functional>
#include <mutex>
#include <string>
#include <vector>

namespace nsx {

//! thread safe class to handle progress and status messages
class ProgressHandler {
public:
    ProgressHandler();
    ~ProgressHandler();

    void setCallback(std::function<void()> callback);

    void setProgress(int progress);
    int getProgress();

    void setStatus(const char* status);
    const std::string getStatus();

    void log(const char* message);
    void log(const std::string& message);
    std::vector<std::string> getLog();

    void abort();
    bool aborted();

private:
    std::mutex _mutex;
    std::string _status;
    std::vector<std::string> _log;
    int _progress;

    std::atomic_bool _aborted;

    std::function<void(void)> _callback;
};

} // end namespace nsx
