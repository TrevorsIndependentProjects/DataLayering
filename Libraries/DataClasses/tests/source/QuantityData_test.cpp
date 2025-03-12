#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "QuantityData.h"
#include "Datum.h"

#include <string>
#include <ostream>
#include <limits>

namespace QuantityDataTests {
	using ::testing::Eq;

	TEST(QuantityData_Tests, DefaultConstructor) {
		DataClasses::QuantityData testData{};

		EXPECT_THAT(testData.getStringValue(), Eq(""));
		ASSERT_TRUE(testData.isEmpty());
	}

	TEST(QuantityData_Tests, CopyConstructor) {
		DataClasses::QuantityData expectedData{};
		expectedData.setHighest(520);
		expectedData.setLowest(3);
		expectedData.setQuantity(7);
		
		DataClasses::QuantityData actualData{ expectedData };

		EXPECT_THAT(actualData.getStringValue(), Eq(expectedData.getStringValue()));
		EXPECT_THAT(actualData.getQuantity(), Eq(expectedData.getQuantity()));
		EXPECT_THAT(actualData.getHighest(), Eq(expectedData.getHighest()));
		EXPECT_THAT(actualData.getLowest(), Eq(expectedData.getLowest()));
		EXPECT_THAT(actualData.getName(), Eq(expectedData.getName()));
		ASSERT_THAT(actualData.isEmpty(), Eq(false));
	}

	TEST(QuantityData_Tests, CountDatumConstructor) {
		DataClasses::CountDatum datum{ "count", 4 };

		DataClasses::QuantityData testData{datum};

		ASSERT_THAT(testData.getQuantity(), Eq(4));
	}

	TEST(QuantityData_Tests, MetaDataGetHighest) {
		DataClasses::QuantityData testData{};

		ASSERT_THAT(testData.getHighest(), Eq(std::numeric_limits<size_t>::max()));
	}

	TEST(QuantityData_Tests, MetaDataGetLowest) {
		DataClasses::QuantityData testData{};

		ASSERT_THAT(testData.getLowest(), Eq(0));
	}

	TEST(QuantityData_Tests, Size_tConstructor) {
		DataClasses::QuantityData testData{ 5 };

		EXPECT_THAT(testData.isEmpty(), Eq(false));
		ASSERT_THAT(testData.getStringValue(), Eq("5"));
	}

	TEST(QuantityData_Tests, SetQuantityWithinLimits) {
		DataClasses::QuantityData testData{};

		testData.setQuantity(9099);

		ASSERT_THAT(testData.getStringValue(), Eq("9099"));
	}

	TEST(QuantityData_Tests, SetHighest) {
		DataClasses::QuantityData testData{};

		testData.setHighest(5000);

		ASSERT_THAT(testData.getHighest(), Eq(5000));
	}

	TEST(QuantityData_Tests, SetQuantityTooLowSetsToLowest) {
		DataClasses::QuantityData testData{};

		testData.setQuantity(-4);

		ASSERT_THAT(testData.getStringValue(), Eq("0"));
	}

	TEST(QuantityData_Tests, SetQuantityTooHighSetsToHighest) {
		DataClasses::QuantityData testData{};
		testData.setHighest(500);

		testData.setQuantity(720);

		ASSERT_THAT(testData.getStringValue(), Eq("500"));
	}

	TEST(QuantityData_Tests, SetHighestTooLowSetsToLowest) {
		DataClasses::QuantityData testData{};
		testData.setLowest(5);

		testData.setHighest(4);
		ASSERT_THAT(testData.getHighest(), Eq(5));
	}

	TEST(QuantityData_Tests, SetLowestTooHighSetsToHighest) {
		DataClasses::QuantityData testData{};
		testData.setHighest(50000);

		testData.setLowest(60000);
		ASSERT_THAT(testData.getLowest(), Eq(50000));
	}

}