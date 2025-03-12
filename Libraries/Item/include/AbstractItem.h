// Trevor Holland
// Created: September 10, 2024

#ifndef ITEM_ABSTRACTITEM_H
#define ITEM_ABSTRACTITEM_H

#include <string>
#include "Datum.h"

namespace Item {
	class AbstractItem {
	public:
		virtual std::string getItemName() = 0;
		virtual void setItemName(const std::string&) = 0;

	protected:
		DataClasses::StringDatum m_name;
	};

}
#endif // !ITEM_ABSTRACTITEM_H