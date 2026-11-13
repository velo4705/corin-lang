#ifndef CORIN_STDLIB_TESTING_H
#define CORIN_STDLIB_TESTING_H

#include <string>
#include <vector>
#include <functional>
#include <iostream>

namespace corin {
namespace stdlib {

/**
 * Testing - Unit test framework
 * 
 * Provides assertions and test organization.
 */
class Testing {
private:
    static int total_tests;
    static int passed_tests;
    static int failed_tests;
    static std::vector<std::string> failures;
    
public:
    // Test registration
    static void run_test(const std::string& name, std::function<void()> test_func);
    
    // Assertions
    static void assert_true(bool condition, const std::string& message = "");
    static void assert_false(bool condition, const std::string& message = "");
    static void assert_equal(int actual, int expected, const std::string& message = "");
    static void assert_equal(double actual, double expected, const std::string& message = "", double epsilon = 0.0001);
    static void assert_equal(const std::string& actual, const std::string& expected, const std::string& message = "");
    static void assert_not_equal(int actual, int expected, const std::string& message = "");
    static void assert_not_equal(const std::string& actual, const std::string& expected, const std::string& message = "");
    static void assert_null(void* ptr, const std::string& message = "");
    static void assert_not_null(void* ptr, const std::string& message = "");
    
    // Test results
    static void print_summary();
    static int get_total_tests() { return total_tests; }
    static int get_passed_tests() { return passed_tests; }
    static int get_failed_tests() { return failed_tests; }
    static void reset();
};

} // namespace stdlib
} // namespace corin

// C API for use from Corin code
extern "C" {
    void corin_test_assert_true(bool condition, const char* message);
    void corin_test_assert_false(bool condition, const char* message);
    void corin_test_assert_equal_int(int actual, int expected, const char* message);
    void corin_test_assert_equal_str(const char* actual, const char* expected, const char* message);
    void corin_test_print_summary();
}

#endif // CORIN_STDLIB_TESTING_H
