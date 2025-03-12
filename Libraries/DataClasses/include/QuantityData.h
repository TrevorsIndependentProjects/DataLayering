// Trevor Holland
// Created: September 26, 2024

#ifndef DATACLASSES_QUANTITYDATA_H
#define DATACLASSES_QUANTITYDATA_H

#include "Datum.h"
#include "DataInterface.h"
#include <string>

namespace DataClasses {
	class QuantityData : public DataInterface {
	public:
		QuantityData();
		QuantityData(size_t);
		QuantityData(const CountDatum&);
		QuantityData(const QuantityData&);
		QuantityData(QuantityData&&) = default;
		virtual ~QuantityData() = default;
		QuantityData& operator=(const QuantityData&);
		QuantityData& operator=(size_t);

		virtual std::string getStringValue() override;
		virtual std::string getName() override;
		[[nodiscard]] virtual bool isEmpty() override;
		void setQuantity(size_t);
		void setQuantity(int);
		size_t getQuantity() const;
		void setHighest(size_t);
		void setHighest(int);
		size_t getHighest() const;
		void setLowest(size_t);
		void setLowest(int);
		size_t getLowest() const;

	private:
		virtual void setName(const std::string& name) override;
		CountDatum quantity;
		CountDatum meta_highestQuantity;
		CountDatum meta_lowestQuantity;
	};

}
#endif // !DATACLASSES_QUANTITYDATA_H
