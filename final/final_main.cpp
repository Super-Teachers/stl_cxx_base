#include <gtest/gtest.h>
#include <iostream>

#include "employee.hpp"

TEST(Employee, print_works) {
    Employee e{"Bill", "Gates"};

    std::stringstream ss;
    ss << e;
    EXPECT_EQ(ss.str(), "[Bill][Gates]");
}

TEST(Employee, sorting_by_last_name) {
    Employee shouldBeFirst;
    std::vector<Employee> employees = randomEmployees();

    std::sort(employees.begin(), employees.end(),
              [](auto one, auto two) { return one._lastname < two._lastname; });

    // employees.push_back( Employee {"Bartosz", "Taczała"});
    // sort employees
    EXPECT_EQ(employees.at(0)._lastname , "Clinton");
}

// TEST(Employee, sort_by_salary) {
// std::vector<Employee> employees = randomEmployees();
//}

// TEST(Employee, give_raise) {
//// give raise (1k) everyone who earns below 5000
// std::vector<Employee> employees = randomEmployees();
//}

// TEST(Employee, change_sex_of_every_bill) {}

// TEST(Employee, find_all_mariages) {}
// TEST(Employee, binary_search_salaries) {
//// Super quickly find  those who earn 5000 with std::binary_search
//}
// TEST(Employee, sexism) {
//// compare means for each men/women salaries!
////
// EXPECT_TRUE([> Man should earns the same as women<] false);
//}

// TEST(EmployeeMultithreaded, how_much_all_earn) {
//// in separate thread calculate sum of all salaries
//}

// TEST(EmployeeMultithreaded, sort_by_sex) {}

// TEST(EmployeeMultithreaded, who_earn_the_most) {
//// in separate thread find out who earns the most
//}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
