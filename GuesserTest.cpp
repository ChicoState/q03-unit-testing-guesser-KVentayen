/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Test the input ASCII string
TEST(GuesserTest, test_standard_char) {
	Guesser my_guess("Standard_Text");
	ASSERT_TRUE(my_guess.match("Standard_Text"));
}

// Test the input ASCII string
TEST(GuesserTest, test_nonprintable_char) {
	Guesser my_guess("Standard_Text\0");
	ASSERT_TRUE(my_guess.match("Standard_Text\0"));
}

// Test multi ASCII Character String
TEST(GuesserTest, test_multicharacter) {
	Guesser my_guess("Hola Niño");
	ASSERT_TRUE(my_guess.match("Hola Niño"));
}

// Test Unicode Character String
TEST(GuesserTest, test_unicode_character) {
	Guesser my_guess("This is Hello: 你好");
	ASSERT_TRUE(my_guess.match("This is Hello: 你好"));
}

// Test Less than 32 Character Input
TEST(GuesserTest, test_less_than_32_character) {
	Guesser my_guess("Less than 32 Characters");
	ASSERT_TRUE(my_guess.match("Less than 32 Characters"));
}

// Test Equal to 32 Character Input
TEST(GuesserTest, test_equal_to_32_character) {
	Guesser my_guess("-012345678901234567890123456789-");
	ASSERT_TRUE(my_guess.match("-012345678901234567890123456789-"));
}

// Test Greater Than 32 Character Input
TEST(GuesserTest, test_greater_than_32_character) {
	Guesser my_guess("This input is greater than 32 characters long");
	ASSERT_TRUE(my_guess.match("This input is greater than 32 ch"));
}

// Test Empty String
TEST(GuesserTest, test_empty_string) {
	Guesser my_guess("");
	ASSERT_TRUE(my_guess.match(""));
}

// Test Initial m_remaining value
TEST(GuesserTest, test_initial_value) {
	Guesser my_guess("Standard_Text");
	ASSERT_EQ(my_guess.remaining(), 3);
}

// Test 1 Failing Attempt
TEST(GuesserTest, test_1_fail_value) {
	Guesser my_guess("Standard_Text");
	my_guess.match("Standard");
	ASSERT_EQ(my_guess.remaining(), 2);
}

// Test 2 Failing Attempt
TEST(GuesserTest, test_2_fail_value) {
	Guesser my_guess("Standard_Text");
	my_guess.match("Standard");
	my_guess.match("Standard");
	ASSERT_EQ(my_guess.remaining(), 1);
}

// Test 3 Failing Attempt
TEST(GuesserTest, test_3_fail_value) {
	Guesser my_guess("Standard_Text");
	my_guess.match("Standard");
	my_guess.match("Standard");
	my_guess.match("Standard");
	ASSERT_EQ(my_guess.remaining(), 0);
}

// Test 4 Failing Attempt
TEST(GuesserTest, test_4_fail_value) {
	Guesser my_guess("Standard_Text");
	my_guess.match("Standard");
	my_guess.match("Standard");
	my_guess.match("Standard");
	my_guess.match("Standard");
	ASSERT_EQ(my_guess.remaining(), 0);
}

// Test 1 Passing Attempt
TEST(GuesserTest, test_1_pass_value) {
	Guesser my_guess("Standard_Text");
	my_guess.match("Standard_Text");
	ASSERT_EQ(my_guess.remaining(), 3);
}

// Test 2 Passing Attempt
TEST(GuesserTest, test_2_pass_value) {
	Guesser my_guess("Standard_Text");
	my_guess.match("Standard_Text");
	my_guess.match("Standard_Text");
	ASSERT_EQ(my_guess.remaining(), 3);
}

// Test 2 Failing Attempts, 1 Passing Attempt
TEST(GuesserTest, test_2_fail_1_pass_value) {
	Guesser my_guess("Standard_Text");
	my_guess.match("Standard");
	my_guess.match("Standard");
	my_guess.match("Standard_Text");
	ASSERT_EQ(my_guess.remaining(), 3);
}

// Test Input Distance of 0
TEST(GuesserTest, test_distance_0_string) {
	Guesser my_guess("Standard_Text");
	my_guess.match("Standard_Text");
	ASSERT_EQ(my_guess.remaining(), 3);
}

// Test Input Distance of 1
TEST(GuesserTest, test_distance_1_string) {
	Guesser my_guess("Standard_Text");
	my_guess.match("Standard_Text1");
	ASSERT_EQ(my_guess.remaining(), 3);
}

// Test Input Distance of 2
TEST(GuesserTest, test_distance_2_string) {
	Guesser my_guess("Standard_Text");
	my_guess.match("Standard_Text12");
	ASSERT_EQ(my_guess.remaining(), 3);
}

// Test Input Distance of 3
TEST(GuesserTest, test_distance_3_string) {
	Guesser my_guess("Standard_Text");
	my_guess.match("Standard_Text123");
	ASSERT_EQ(my_guess.remaining(), 2);
}

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/
