
#include <iostream>
#include <sstream>

struct Employee {
    friend std::ostream& operator<<(std::ostream& os, const Employee& emp);

    Employee(const std::string& name) : _name(name) {}

   private:
    const std::string _name;
};

std::ostream& operator<<(std::ostream& os, const Employee& emp) {
    os << "{" << emp._name << "}";
    return os;
}

std::string serialize(const Employee& emp) {
    std::stringstream ss;
    ss << emp;
    return ss.str();
}

int main(int argc, char* argv[]) {
    Employee e{"Donald Trump"};
    std::stringstream ss;

    std::cout << serialize(e) << " " << serialize(e) << std::endl;
    // std::cout << serialize(e, ss) << std::endl;
    return 0;
}
