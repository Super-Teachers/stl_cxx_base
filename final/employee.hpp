#ifndef EMPLOYEE_HPP_TBCTFQ4S
#define EMPLOYEE_HPP_TBCTFQ4S

#include <cstdint>
#include <iostream>

struct Employee {
    enum Sex : std::int8_t { Male = 0, Female };
    enum SalaryType : std::int8_t { Contractor = 0, Regular };

    std::string _name;
    std::string _lastname;
    std::uint8_t _height;
    std::pair<float, SalaryType> _salary;
    Sex _sex;
};

std::ostream& operator<<(std::ostream& os, const Employee& e) {
    os << "[" << e._name << "][" << e._lastname << "]";
    return os;
}


std::vector<Employee> randomEmployees() {
    std::vector<Employee> emps;
    emps.push_back(Employee {"Bill", "Murray", 170,
               std::make_pair(0, Employee::Contractor), Employee::Male});
    emps.push_back(Employee {"Bill", "Gates", 180,
               std::make_pair(rand() % 10000, Employee::Contractor), Employee::Female});
    emps.push_back(Employee {"Adam", "Sandler", 140,
               std::make_pair(20000, Employee::Contractor), Employee::Male});
    emps.push_back(Employee {"Bill", "Cosby", 160,
               std::make_pair(rand() % 10000, Employee::Regular), Employee::Male});
    emps.push_back(Employee {"Bill", "Clinton", 110,
               std::make_pair(rand() % 10000, Employee::Contractor), Employee::Male});
    emps.push_back(Employee {"Bill", "Whatever", 120,
               std::make_pair(rand() % 10000, Employee::Regular), Employee::Female});
    emps.push_back(Employee {"Melinda", "Gates", 185,
               std::make_pair(rand() % 10000, Employee::Contractor), Employee::Male});
    return emps;
}
#endif /* end of include guard: EMPLOYEE_HPP_TBCTFQ4S */
