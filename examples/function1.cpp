#include <functional>
struct Test {
    void on_ready(const std::function<void()>& bReadyCb) { _cb = bReadyCb; }
    void run() {
        // LONG OPERATION
        if (_cb) _cb();
    }
   private:
    std::function<void()> _cb;
};

int main(int, char* []) {
    Test t;
    t.on_ready([]() {
        // TODO: Implement me
    });
    t.run();
    return 0;
}
