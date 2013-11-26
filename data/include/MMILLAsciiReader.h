/*
 * nsxtool : Neutron Single Crystal analysis toolkit
    ------------------------------------------------------------------------------------------
    Copyright (C)
    2012- Laurent C. Chapon, Eric C. Pellegrini Institut Laue-Langevin
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
#ifndef NSXTOOL_MMILLASCIIREADER_H_
#define NSXTOOL_MMILLASCIIREADER_H_

#include <string>
#include <boost/interprocess/file_mapping.hpp>

namespace SX {

namespace Data {

//! Forward declaration
class MetaData;

class MMILLAsciiReader {
public:
	MMILLAsciiReader(const std::string& filename);
	//! Read the header of the file made of MetaData.
	MetaData* readMetaDataBlock(int nlines=100);
	//! Return the number of blocks
	std::size_t nBlocks() const {return _nframes;}
	//! Read block number i. First frame starts at index 0
	std::vector<int> readBlock(unsigned int i) const;
	virtual ~MMILLAsciiReader();
private:
	bool _isInitialized;
	std::size_t _nframes;
	std::size_t _datapoints;
	std::size_t _nangles;
	std::size_t _header_size;
	std::size_t _skipchar;
	std::size_t _datalength;
	boost::interprocess::file_mapping _map;

};

} // end namespace Data

} // end namespace SX

#endif NSXTOOL_MMILLASCIIREADER_H_
