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

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcCurveSegment2D.h"
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcCurveSegment2D 
		IfcCurveSegment2D::IfcCurveSegment2D() { m_entity_enum = IFCCURVESEGMENT2D; }
		IfcCurveSegment2D::IfcCurveSegment2D( int id ) { m_id = id; m_entity_enum = IFCCURVESEGMENT2D; }
		IfcCurveSegment2D::~IfcCurveSegment2D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCurveSegment2D::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcCurveSegment2D> other = dynamic_pointer_cast<IfcCurveSegment2D>(other_entity);
			if( !other) { return; }
			m_StartPoint = other->m_StartPoint;
			m_StartDirection = other->m_StartDirection;
			m_SegmentLength = other->m_SegmentLength;
		}
		void IfcCurveSegment2D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCURVESEGMENT2D" << "(";
			if( m_StartPoint ) { stream << "#" << m_StartPoint->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_StartDirection ) { m_StartDirection->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SegmentLength ) { m_SegmentLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCurveSegment2D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCurveSegment2D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCurveSegment2D, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcCurveSegment2D, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_StartPoint, map );
			m_StartDirection = IfcPlaneAngleMeasure::readStepData( args[1] );
			m_SegmentLength = IfcPositiveLengthMeasure::readStepData( args[2] );
		}
		void IfcCurveSegment2D::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcBoundedCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCurveSegment2D::unlinkSelf()
		{
			IfcBoundedCurve::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
