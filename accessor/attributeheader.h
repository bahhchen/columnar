// Copyright (c) 2020-2021, Manticore Software LTD (https://manticoresearch.com)
// All rights reserved
//
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _attributeheader_
#define _attributeheader_

#include "columnar.h"

namespace columnar
{

class FileReader_c;

class AttributeHeader_i
{
public:
	virtual						~AttributeHeader_i() = default;

	virtual const std::string &	GetName() const = 0;
	virtual AttrType_e			GetType() const = 0;
	virtual const Settings_t &	GetSettings() const = 0;

	virtual uint32_t			GetNumDocs() const = 0;
	virtual int					GetNumBlocks() const = 0;
	virtual uint32_t			GetNumDocs ( int iBlock ) const = 0;
	virtual uint64_t			GetBlockOffset ( int iBlock ) const = 0;

	virtual int					GetNumMinMaxLevels() const = 0;
	virtual int					GetNumMinMaxBlocks ( int iLevel ) const = 0;
	virtual std::pair<int64_t,int64_t> GetMinMax ( int iLevel, int iBlock ) const = 0;

	virtual bool				HaveStringHashes() const = 0;

	virtual bool				Load ( FileReader_c & tReader, std::string & sError ) = 0;
};


AttributeHeader_i * CreateAttributeHeader ( AttrType_e eType, uint32_t uTotalDocs, std::string & sError );

} // namespace columnar

#endif // _attributeheader_