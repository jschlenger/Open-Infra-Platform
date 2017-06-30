// Copied and modified code from "IfcPlusPlus" library.
// This library is available under the OpenSceneGraph Public License. Original copyright notice:

/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and / or modified under
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or
* (at your option) any later version.The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
* OpenSceneGraph Public License for more details.
*/

/* This file has been automatically generated using the TUM Open Infra Platform
Early Binding EXPRESS Generator. Any changes to this file my be lost in the future. */

#include "IfcTendonTypeEnum.h"
#include "OpenInfraPlatform/IfcAlignment1x1/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment1x1/writer/WriterUtil.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment1x1
	{
		IfcTendonTypeEnum::IfcTendonTypeEnum() {}
		IfcTendonTypeEnum::IfcTendonTypeEnum(IfcTendonTypeEnum::IfcTendonTypeEnumEnum value) { m_enum = value; }
		IfcTendonTypeEnum::~IfcTendonTypeEnum() {}
		void IfcTendonTypeEnum::getStepParameter(std::stringstream& stream, bool is_select_type) const
			{
				if ( m_enum == IfcTendonTypeEnumEnum::ENUM_BAR)
				{
					stream << ".BAR.";
				}
				else if ( m_enum == IfcTendonTypeEnumEnum::ENUM_COATED)
				{
					stream << ".COATED.";
				}
				else if ( m_enum == IfcTendonTypeEnumEnum::ENUM_STRAND)
				{
					stream << ".STRAND.";
				}
				else if ( m_enum == IfcTendonTypeEnumEnum::ENUM_WIRE)
				{
					stream << ".WIRE.";
				}
				else if ( m_enum == IfcTendonTypeEnumEnum::ENUM_USERDEFINED)
				{
					stream << ".USERDEFINED.";
				}
				else if ( m_enum == IfcTendonTypeEnumEnum::ENUM_NOTDEFINED)
				{
					stream << ".NOTDEFINED.";
				}
				if (is_select_type) { stream << ")"; }
			}
			std::shared_ptr<IfcTendonTypeEnum> IfcTendonTypeEnum::readStepData(const std::string& arg)
			{
				if( arg.compare( "$" ) == 0 ) { return std::shared_ptr<IfcTendonTypeEnum>(); }
				std::shared_ptr<IfcTendonTypeEnum> type_object(new IfcTendonTypeEnum() );
				if ( _stricmp( arg.c_str(), ".BAR.") == 0)
				{
					type_object->m_enum = IfcTendonTypeEnum::IfcTendonTypeEnumEnum::ENUM_BAR;
				}
				else if ( _stricmp( arg.c_str(), ".COATED.") == 0)
				{
					type_object->m_enum = IfcTendonTypeEnum::IfcTendonTypeEnumEnum::ENUM_COATED;
				}
				else if ( _stricmp( arg.c_str(), ".STRAND.") == 0)
				{
					type_object->m_enum = IfcTendonTypeEnum::IfcTendonTypeEnumEnum::ENUM_STRAND;
				}
				else if ( _stricmp( arg.c_str(), ".WIRE.") == 0)
				{
					type_object->m_enum = IfcTendonTypeEnum::IfcTendonTypeEnumEnum::ENUM_WIRE;
				}
				else if ( _stricmp( arg.c_str(), ".USERDEFINED.") == 0)
				{
					type_object->m_enum = IfcTendonTypeEnum::IfcTendonTypeEnumEnum::ENUM_USERDEFINED;
				}
				else if ( _stricmp( arg.c_str(), ".NOTDEFINED.") == 0)
				{
					type_object->m_enum = IfcTendonTypeEnum::IfcTendonTypeEnumEnum::ENUM_NOTDEFINED;
				}
				return type_object;
			}
	} // end namespace IfcAlignment1x1
} // end namespace OpenInfraPlatform
