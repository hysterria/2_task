#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(get_digits_number, check_positive) {
	ABelyaeva::LongNumber x("12345");
	ASSERT_EQ(5, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}

TEST(get_digits_number, check_negative) {
	ABelyaeva::LongNumber x("-1");
	ASSERT_EQ(1, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}

class EqualityFixture : public testing::Test {
	public:
		ABelyaeva::LongNumber zero = ABelyaeva::LongNumber("0");
		ABelyaeva::LongNumber one_v1 = ABelyaeva::LongNumber("1");
		ABelyaeva::LongNumber two = ABelyaeva::LongNumber("2");
		ABelyaeva::LongNumber one_v2 = ABelyaeva::LongNumber("1");
		ABelyaeva::LongNumber six = ABelyaeva::LongNumber("6");
		ABelyaeva::LongNumber twelve = ABelyaeva::LongNumber("12");
		ABelyaeva::LongNumber negative_one = ABelyaeva::LongNumber("-1");
};

TEST_F(EqualityFixture, equal) {
	ASSERT_TRUE(one_v1 == one_v2) << "Проверка " << one_v1 << " == " << one_v2;
}

TEST_F(EqualityFixture, not_equal) {
	ASSERT_FALSE(one_v1 == twelve) << "Проверка " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFixture, not_equal_negative_var) {
	ASSERT_FALSE(one_v1 == negative_one) 
		<< "Проверка " << one_v1 << " == " << negative_one;
}

TEST_F(EqualityFixture, equal_operator) {
	ABelyaeva::LongNumber one_v2("1");
	ASSERT_TRUE(one_v1 == one_v2);
	ASSERT_FALSE(one_v1 == negative_one);
	ASSERT_FALSE(one_v1 == two);
}

TEST_F(EqualityFixture, greater_operator) {
	ASSERT_TRUE(two > one_v1);
	ASSERT_TRUE(zero > negative_one);
	ASSERT_FALSE(one_v1 > two);
}

TEST_F(EqualityFixture, less_operator) {
	ASSERT_TRUE(one_v1 < two);
	ASSERT_FALSE(zero < negative_one);
	ASSERT_FALSE(two < one_v1);
}

TEST_F(EqualityFixture, add_operator) {
	ABelyaeva::LongNumber sum = one_v1 + one_v2;
	ASSERT_EQ(two, sum);
	ASSERT_FALSE(sum.is_negative());
}

TEST_F(EqualityFixture, subtr_operator) {
	ABelyaeva::LongNumber difference = one_v1 - two;
	ASSERT_EQ(negative_one, difference);
	ASSERT_TRUE(difference.is_negative());
}

TEST_F(EqualityFixture, multip_operator) {
	ABelyaeva::LongNumber product = one_v1 * two;
	ASSERT_EQ(two, product);
	ASSERT_FALSE(product.is_negative());
}

TEST_F(EqualityFixture, div_operator) {
	ABelyaeva::LongNumber dividend(twelve);
	ABelyaeva::LongNumber divisor(two);
	ABelyaeva::LongNumber quotient = dividend / divisor;
	ASSERT_EQ(six, quotient);
	ASSERT_FALSE(quotient.is_negative());
}

TEST_F(EqualityFixture, mod_operator) {
	ABelyaeva::LongNumber dividend(six);
	ABelyaeva::LongNumber divisor(two);
	ABelyaeva::LongNumber remainder = dividend % divisor;
	ASSERT_EQ(zero, remainder);
	ASSERT_FALSE(remainder.is_negative());
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
