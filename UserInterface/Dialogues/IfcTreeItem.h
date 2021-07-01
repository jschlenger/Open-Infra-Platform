/*
	Copyright (c) 2021 Technical University of Munich
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

#ifndef IFCTREEITEM_H
#define IFCTREEITEM_H

#include "EXPRESS/EXPRESSReference.h"
#include <QVariant>
#include <QList>


namespace OpenInfraPlatform {
	namespace UserInterface {

		class IfcTreeItem
		{
		public:
			explicit IfcTreeItem(OpenInfraPlatform::EarlyBinding::EXPRESSEntity *data, IfcTreeItem *parentItem);
			explicit IfcTreeItem(const QList<QVariant> &data, IfcTreeItem *parentItem = 0);
			~IfcTreeItem();

			void appendChild(IfcTreeItem *child);

			IfcTreeItem *child(int row);
			int childCount() const;
			int columnCount() const;
			QVariant data(int column) const;
			int row() const;
			IfcTreeItem *parentItem();
			QString getIfcClassName() const;

		private:
			QList<IfcTreeItem*> childItems_;
			OpenInfraPlatform::EarlyBinding::EXPRESSEntity *data_;
			QList<QVariant> itemData_;
			IfcTreeItem *parentItem_;

			//struct getAttributeDescription;
		};
	}
}


#endif //IFCTREEITEM_H

namespace oip
{
	using OpenInfraPlatform::UserInterface::IfcTreeItem;
}