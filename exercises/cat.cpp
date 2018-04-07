#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>

std::pair<int, bool> my_atoi(const std::string& s) {
    auto value = std::atoi(s.c_str());

    if (value != 0)
        return std::make_pair(value, true);
    else if (value == 0 && s == "0")
        return std::make_pair(value, true);
    else
        return std::make_pair(std::numeric_limits<int>::max(), false);
}

void copy(std::istream& is, std::ostream& os) {
    auto old_flags = is.flags();
    std::noskipws(is);
    std::copy(std::istream_iterator<char>(is), std::istream_iterator<char>(),
              std::ostream_iterator<char>(os, ""));
    is.flags(old_flags);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        copy(std::cin, std::cout);
    } else {
        std::fstream file{argv[1]};
        std::fstream file_out{"copy_asd"};
        copy(file, file_out);
    }
    return 0;
}
