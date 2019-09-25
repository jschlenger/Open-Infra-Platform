/*
    Copyright (c) 2018 Technical University of Munich
    Chair of Computational Modeling and Simulation.

    TUM Open Infra Platform is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License Version 3
    as published by the Free Software Foundation.

    TUM Open Infra Platform is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "IfcPeekStepReader.h"

#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>

using OpenInfraPlatform::Core::IfcGeometryConverter::IfcPeekStepReader;

using MapType = std::pair< std::string, IfcPeekStepReader::IfcSchema>;

std::map<std::string, IfcPeekStepReader::IfcSchema> schemata = {
	MapType("ifc2x3", IfcPeekStepReader::IfcSchema::IFC2X3),
	MapType("ifc4", IfcPeekStepReader::IfcSchema::IFC4),
	MapType("ifc4x1", IfcPeekStepReader::IfcSchema::IFC4X1),
	MapType("ifc4x2-bim4road", IfcPeekStepReader::IfcSchema::IFC4X2_BIM4ROAD),
	MapType("ifc4x2-draft-1", IfcPeekStepReader::IfcSchema::IFC4X2_DRAFT_1)
};

IfcPeekStepReader::IfcPeekStepReader()
{

}

IfcPeekStepReader::~IfcPeekStepReader()
{

}

IfcPeekStepReader::IfcSchema IfcPeekStepReader::parseIfcHeader(const std::string& filename)
{
	std::ifstream ifcFile(filename);

	if (!ifcFile.is_open())
	{
		throw std::exception("Could not open IFC file in ifc peek step reader.");
		return IfcSchema::UNKNOWN;
	}

	std::string line;
	// search file line by line
	while (std::getline(ifcFile, line))
	{
		// find the header entry section
		if (line.find("HEADER") != std::string::npos)
		{
			// look for the FILE_SCHEMA keyword
			while (std::getline(ifcFile, line))
			{
				if (line.find("FILE_SCHEMA") != std::string::npos)
				{
					// get the entry position of the string
					const size_t schema_beg = line.find_last_of('(') + 1;

					if (schema_beg != std::string::npos)
					{
						// get the last entry of the string
						const size_t schema_end = line.find_first_of(')') - 1;

						if (schema_end != std::string::npos)
						{
							// compute string length
							const size_t schema_len = schema_end - schema_beg + 1;
							// extract schema string from the line
							std::string schema = line.substr(schema_beg, schema_len);
							// remove single quotation marks
							schema.erase(std::remove(schema.begin(), schema.end(), '\''), schema.end());
							// remove all whitespaces
							schema.erase(std::remove_if(schema.begin(), schema.end(), std::isspace), schema.end());
							//DEBUG
							//std::cout << "SCHEMA = " << schema << std::endl;
							ifcFile.close();
							
							std::transform(schema.begin(), schema.end(), schema.begin(), ::tolower);
							
							if(schemata.count(schema) > 0) {
								return schemata[schema];
							}
							else {
								throw std::exception("IFC schema is not specified or could not be determined.");
								return IfcSchema::UNKNOWN;
							}							
						}
					}
				}
			}
		}
		else if (line.find("DATA") != std::string::npos)
		{
			ifcFile.close();
			throw std::exception("IFC schema is not specified or could not be determined.");
			//return IfcSchema::UNKNOWN;
		}
	}

	ifcFile.close();
	throw std::exception("IFC schema is not specified or could not be determined.");
}
