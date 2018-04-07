#include <iostream>
#include <vector>

#include <algorithm>
#include <cstdint>
#include <numeric>
#include <sstream>

using ByteArray = std::vector<std::uint8_t>;

void print(const ByteArray& arr, std::ostream& os) {
    const auto old = os.flags();
    std::for_each(arr.begin(), arr.end(), [&os](auto t) {
        // for (typename ByteArray::value_type t : arr) {
        os << std::hex << "0x";
        os.width(8);
        os.fill('_');
        os << std::left << static_cast<int>(t) << " ";
    });

    os.flags(old);
}

int main(int argc, char* argv[]) {
    ByteArray arr;

    arr.resize(std::numeric_limits<ByteArray::value_type>::max());

    std::iota(arr.begin(), arr.end(), 0);

    std::stringstream ss;
    // print(arr, ss);

    ss << 100;
    std::string asd = ss.str();
    // std::cout << ss.str() << std::endl;

    return 0;
}
