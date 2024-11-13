#include <exception>
#include <iostream>

template <typename T> class deque {
public:
  deque() : _map(nullptr), _sz(0), _cap(0) {}

private:
  T *resrve_chunk() {
    T *temp_chunk;
    try {
      temp_chunk =
          reinterpret_cast<T *>(new char[sizeof(T) * _deque_chank_size]);
    } catch (const std ::exception &ex) {
      std ::cout << ex.what() << std ::endl;
    }
  }
  T **_map;
  size_t _sz;
  size_t _cap;
  static constexpr size_t _deque_chank_size = 32;
};

int main() {}
