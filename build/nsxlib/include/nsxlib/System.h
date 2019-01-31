// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      nsxlib/utils/System.h
//! @brief     Implements module/class/test System
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Groups at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

#pragma once

// Define necessary symbols for exporting symbols in dll table.
#ifdef _WIN32
#    ifdef NSXLIB_EXPORT
#        define DLLExport __declspec(dllexport)
#    else
#        define DLLEXport __declspec(dllimport)
#    endif
#else
#    define DLLExport
#endif
