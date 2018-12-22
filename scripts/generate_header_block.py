import os

if __name__ == "__main__":

    target_dirs = ["app","nsxlib","tests"]

    header = """// ************************************************************************** //
//
//  NSXTool: Neutron Single Xtal analysis Toolkit
//
//! @file      %s
//! @brief     Implements module/class/test %s
//!
//! @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Institut Laue Langevin 2013-now
//! @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
//
// ************************************************************************** //

"""

    python_header = """# **************************************************************************
#
# NSXTool: Neutron Single Xtal analysis Toolkit
#
# @file      %s
# @brief     Implements class %s
#
# @homepage  http://www.code.ill.fr/scientific-software/nsxtool.git
# @license   GNU General Public License v3 or higher (see COPYING)
# @copyright Institut Laue Langevin 2013-now
# @authors   Scientific Computing Group at ILL and MLZ (see AUTHORS)
#
# **************************************************************************

"""

    nsxtool_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

    for target_dir in target_dirs:
        for subdir,_,filenames in os.walk(os.path.join(nsxtool_root,target_dir)):
            for filename in filenames:
                basename,file_ext = os.path.splitext(filename)
                if file_ext not in [".h",".cpp",".c",".py",".h.in",".cpp.in"]:
                    continue

                current_header = python_header if file_ext == ".py" else header

                full_path = os.path.join(subdir,filename)

                with open(full_path,"r") as fin:
                    contents = current_header % (os.path.relpath(full_path,nsxtool_root),basename) + fin.read()

                with open(full_path,"w") as fout:
                    fout.write(contents)
    


