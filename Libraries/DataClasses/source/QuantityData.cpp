#include "QuantityData.h"

#include <limits>

namespace DataClasses {
	QuantityData::QuantityData()
		: quantity("Quantity")
		, meta_highestQuantity("Highest", std::numeric_limits<size_t>::max())
		, meta_lowestQuantity("Lowest", 0)
	{}

	QuantityData::QuantityData(size_t quantity)
		: quantity("Quantity", quantity)
		, meta_highestQuantity("Highest", std::numeric_limits<size_t>::max())
		, meta_lowestQuantity("Lowest", 0)
	{}

	QuantityData::QuantityData(const CountDatum& quantityDatum)
		: QuantityData(quantityDatum.valueToCount())
	{}

	QuantityData::QuantityData(const QuantityData& qData) {
		*this = qData;
	}

	QuantityData& QuantityData::operator=(const QuantityData& q) {
		quantity = q.quantity;
		meta_highestQuantity = q.meta_highestQuantity;
		meta_lowestQuantity = q.meta_lowestQuantity;
		return *this;
	}

	QuantityData& QuantityData::operator=(size_t q) {
		quantity.setValue(q);
		return *this;
	}
	
	std::string QuantityData::getStringValue() {
		return quantity.valueToString();
	}
	
	std::string QuantityData::getName() {
		return quantity.getName();
	}
	bool QuantityData::isEmpty() {
		return quantity.isEmpty();
	}

	size_t QuantityData::getHighest() const {
		return meta_highestQuantity.valueToCount();
	}

	size_t QuantityData::getLowest() const {
		return meta_lowestQuantity.valueToCount();
	}
	
	void QuantityData::setQuantity(size_t q) {
		if (q >= meta_lowestQuantity.valueToCount() && q <= meta_highestQuantity.valueToCount())
			quantity.setValue(q);
		else if (q < meta_lowestQuantity.valueToCount())
			quantity.setValue(meta_lowestQuantity.valueToCount());
		else if (q > meta_highestQuantity.valueToCount())
			quantity.setValue(meta_highestQuantity.valueToCount());
	}

	void QuantityData::setQuantity(int q) {
		if (q < 0)
			quantity.setValue(0);
		else
			setQuantity(static_cast<size_t>(q));
	}

	void QuantityData::setHighest(int q) {
		if (q < 0)
			meta_highestQuantity.setValue(0);
		else
			setHighest(static_cast<size_t>(q));
	}

	void QuantityData::setLowest(int q) {
		if (q < 0)
			meta_lowestQuantity.setValue(0);
		else
			setLowest(static_cast<size_t>(q));
	}

	size_t QuantityData::getQuantity() const {
		return quantity.valueToCount();
	}

	void QuantityData::setHighest(size_t h) {
		if (h < meta_lowestQuantity.valueToCount())
			meta_highestQuantity.setValue(meta_lowestQuantity.valueToCount());
		else
			meta_highestQuantity.setValue(h);
	}

	void QuantityData::setLowest(size_t l) {
		if (l > meta_highestQuantity.valueToCount())
			meta_lowestQuantity.setValue(meta_highestQuantity.valueToCount());
		else
			meta_lowestQuantity.setValue(l);
	}

	void QuantityData::setName(const std::string& name) {
		quantity.setName(name);
	}

}