#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Datum.h"
#include "Datum.h"

#include <limits>
#include <string>
#include <ostream>

namespace DatumTests {
	using ::testing::Eq;

	TEST(Datum_Tests, StringDefaultConstructor) {
		DataClasses::StringDatum testDatum{};

		EXPECT_THAT(testDatum.getName(), Eq(""));
		EXPECT_THAT(testDatum.valueToString(), Eq(""));
		EXPECT_THAT(testDatum.getType(), Eq(DataClasses::DataType::kString));
		ASSERT_TRUE(testDatum.isEmpty());
	}

	TEST(Datum_Tests, DoubleNameConstructor) {
		const std::string kExpectedName{ "name" };
		DataClasses::DecimalDatum testDatum{kExpectedName};

		EXPECT_THAT(testDatum.getName(), Eq(kExpectedName));
		EXPECT_THAT(testDatum.valueToString(), Eq(""));
		EXPECT_THAT(testDatum.getType(), Eq(DataClasses::DataType::kDecimal));
		ASSERT_TRUE(testDatum.isEmpty());
	}

	TEST(Datum_Tests, CountFullConstructor) {
		const std::string kExpectedName{ "count" };
		const size_t count = 7;
		DataClasses::CountDatum testDatum{ kExpectedName, count};
		
		EXPECT_THAT(testDatum.getName(), Eq(kExpectedName));
		EXPECT_THAT(testDatum.valueToString(), Eq("7"));
		EXPECT_THAT(testDatum.getType(), Eq(DataClasses::DataType::kCount));
		ASSERT_FALSE(testDatum.isEmpty());
	}

	TEST(Datum_Tests, FlagCopyConstructor) {
		const std::string kExpectedName{ "flag" };
		const bool flag{ false };
		const DataClasses::FlagDatum expectedDatum{ kExpectedName, flag };

		DataClasses::FlagDatum actualDatum{ expectedDatum };

		ASSERT_TRUE(expectedDatum == actualDatum);
	}

	TEST(Datum_Tests, ValueToInteger) {
		const int kValue = 23;
		DataClasses::IntegerDatum testDatum{"number"};

		testDatum.setValue(kValue);

		ASSERT_THAT(testDatum.valueToInt(), Eq(kValue));
	}

	TEST(Datum_Tests, ValueToDouble) {
		const double kValue = 6.6;
		DataClasses::DecimalDatum testDatum{ "number" };

		testDatum.setValue(kValue);

		ASSERT_THAT(testDatum.valueToDouble(), Eq(kValue));
	}

	TEST(Datum_Tests, ValueToCount) {
		const size_t kValue = 23;
		DataClasses::CountDatum testDatum{ "number" };

		testDatum.setValue(kValue);

		ASSERT_THAT(testDatum.valueToCount(), Eq(kValue));
	}

	TEST(Datum_Tests, ValueAtUnsignedIntLimit) {
		const size_t kValue = std::numeric_limits<size_t>::max();
		DataClasses::CountDatum testDatum{ "number" };

		testDatum.setValue(kValue);

		ASSERT_THAT(testDatum.valueToCount(), Eq(kValue));
	}

	TEST(Datum_Tests, ValueToBool) {
		const bool kValue = false;
		DataClasses::FlagDatum testDatum{ "number" };

		testDatum.setValue(kValue);

		ASSERT_THAT(testDatum.valueToBool(), Eq(kValue));
	}

}