#include <exception>
#include <cmath>
#include <iostream>

template <typename T>
class deque
{
public:
  deque() : _map(nullptr), _sz(0), _cap(0) {}
  deque(size_t _sz) : _map(nullptr), _sz(_sz), _cap(sizeof(T) * _sz)
  {
    if (_sz < _deque_chank_size)
    {
      reseve_map();
    }
    else
    {
      size_t _chunk_amount = ceil(_sz / _deque_chank_size);
      reseve_map(_chunk_amount);
    }
    for (size_t _index = 0; _index < _chunk_amount; ++_index) {
      new(_map+_index)T*();
      _map[_index] = reserve_chunk();
    }
  }

  size_t capacity() const
  {
    return _cap;
  }

  size_t size() const
  {
    return _sz;
  }

  ~deque()
  {
    for (size_t _index = 0; _index < _chunk_amount; ++_index)
    {
      try
      {
        for (size_t __index = 0; __index < _chunk_amount; ++__index)
        {
          (_map[_index] + __index)->~T();
        }
      }
      catch (std ::exception &ex)
      {
        std ::cout << ex.what() << std ::endl;
        std ::abort();
      }
      delete[] reinterpret_cast<char *>(_map[_index]);
    }
    delete[] reinterpret_cast<char *>(_map);
  }

private:
  void reseve_map(size_t sz = 1)
  {
    try
    {
      _map = reinterpret_cast<T **>(new char[sizeof(T*) * sz]);
    }
    catch (const std ::bad_alloc& ex)
    {
      std ::cout << ex.what() << std ::endl;
    }
  }

  T *reserve_chunk()
  {
    T *temp_chunk;
    try
    {
      temp_chunk = reinterpret_cast<T *>(new char[sizeof(T) * _deque_chank_size]);
    }
    catch (const std ::exception &ex)
    {
      std ::cout << ex.what() << std ::endl;
    }
    return temp_chunk;
  }

private:
  T **_map;
  size_t _sz;
  size_t _chunk_amount;
  size_t _cap;
  static constexpr size_t _deque_chank_size = 32;
};

int main()
{
  deque<int> _deque(3);
  std ::cout << _deque.size() << " " << _deque.capacity() << std ::endl;
}
