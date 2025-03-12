// Trevor Holland
// Created: September 10, 2024

#ifndef DATACLASSES_DATAINTERFACE_H
#define DATACLASSES_DATAINTERFACE_H

#include <string>

namespace DataClasses {
	class DataInterface {
	public:
		virtual std::string getStringValue() = 0;
		virtual std::string getName() = 0;
		[[nodiscard]] virtual bool isEmpty() = 0;
		
		virtual void setName(const std::string& name) = 0;
	};

}
#endif // !DATACLASSES_DATAINTERFACE_H
