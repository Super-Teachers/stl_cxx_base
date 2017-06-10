#include <gtest/gtest.h>
#include <future>
#include <iostream>
#include <numeric>

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

    EXPECT_EQ(employees.at(0)._lastname, "Clinton");
}

TEST(Employee, sort_by_salary) {
    std::vector<Employee> employees = randomEmployees();
    std::sort(employees.begin(), employees.end(), [](auto one, auto two) {
        return one._salary.first > two._salary.first;
    });
    //
    EXPECT_EQ(employees.at(employees.size() - 1)._lastname, "Murray");
}

TEST(Employee, give_raise) {
    // give raise (1k) everyone who earns below 5000
    std::vector<Employee> employees = randomEmployees();

    for (auto &v : employees) {
        if (v._salary.first < 5000) v._salary.first += 1000;
    }

    EXPECT_EQ(employees.at(0)._salary.first, 1000);
}

TEST(Employee, change_sex_of_every_bill) {
    std::vector<Employee> employees = randomEmployees();

    std::vector<Employee>::iterator it = employees.begin();
    while (it != employees.end()) {
        it = std::find_if(it, employees.end(),
                          [](auto empl) { return empl._name == "Bill"; });
        if (it == employees.end()) break;
        it->_sex = Employee::Sex::Female;
        ++it;
    }

    auto adamIt = std::find_if(employees.begin(), employees.end(),
                               [](auto e) { return e._name == "Adam"; });

    EXPECT_EQ(adamIt->_sex, Employee::Sex::Male);
}

// TEST(Employee, find_all_mariages) {}
// TEST(Employee, binary_search_salaries) {
//// Super quickly find  those who earn 5000 with std::binary_search
//}
// TEST(Employee, sexism) {
//// compare means for each men/women salaries!
////
// EXPECT_TRUE([> Man should earns the same as women<] false);
//}

TEST(EmployeeMultithreaded, how_much_all_earn) {
    std::vector<Employee> employees = randomEmployees();
    auto fn = [](const std::vector<Employee> &emps) -> int {
        return std::accumulate(
            emps.begin(), emps.end(), 0,
            [](int prev, auto emp) { return prev + emp._salary.first; });
    };

    auto fut = std::async(std::launch::async, fn, employees);

    EXPECT_EQ(fut.get(), 45357);
}

// TEST(EmployeeMultithreaded, sort_by_sex) {}

TEST(EmployeeMultithreaded, who_earn_the_most) {
    std::vector<Employee> employees = randomEmployees();

    auto fn = [](std::vector<Employee> &emps) -> Employee {
        std::sort(emps.begin(), emps.end(), [](auto one, auto two) {
            return one._salary.first > two._salary.first;
        });

        return emps.at(0);
    };

    auto fut = std::async(std::launch::async, fn, std::ref(employees));

    EXPECT_EQ(fut.get()._name, "Adam");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
