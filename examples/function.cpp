#include <functional>

void free_fun(int a, char c){};

struct Test {
    void mem_fun(int a, char c){};
};

int main(int, char *[]) {
    std::function<void(int, char)> fn{free_fun};
    Test t;
    fn = std::bind(&Test::mem_fun, t, std::placeholders::_1,
                   std::placeholders::_2);
    return 0;
}
