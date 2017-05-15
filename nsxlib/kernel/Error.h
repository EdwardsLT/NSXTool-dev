/*
 * nsxtool : Neutron Single Crystal analysis toolkit
 ------------------------------------------------------------------------------------------
 Copyright (C)
 2012- Laurent C. Chapon, Eric Pellegrini
 Institut Laue-Langevin
 BP 156
 6, rue Jules Horowitz
 38042 Grenoble Cedex 9
 France
 chapon[at]ill.fr
 pellegrini[at]ill.fr

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef NSXTOOL_ERROR_H_
#define NSXTOOL_ERROR_H_

#include <exception>
#include <string>

namespace nsx
{

namespace Kernel
{

template<typename T>
class Error : public std::exception
{
public:
    Error(std::string message);
    Error(const Error& other) noexcept;
    virtual ~Error();

    const char* what() const noexcept;

private:
    std::string _message;
};

template<typename T>
Error<T>::Error(std::string message): std::exception(), _message(std::move(message))
{
}

template<typename T>
Error<T>::Error(const Error& other) noexcept: std::exception(other), _message()
{
    try {
        // since string copying requries memory allocation, this could
        // throw bad_alloc
        _message = other._message;
    }
    catch(...) {
        // nothing we can do if we are out of memory!
    }
}

template<typename T>
Error<T>::~Error()
{
}

template<typename T>
const char* Error<T>::what() const noexcept
{
    return _message.c_str();
}

} // end namespace Kernel

} // end namespace nsx

#endif /* NSXTOOL_ERROR_H_ */
