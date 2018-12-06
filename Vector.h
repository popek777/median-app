#pragma once

#include <cassert>
#include <cstring>

namespace details {
template <typename T>
struct ScopedArrayPtr {
  ScopedArrayPtr(T* ptr) : ptr_(ptr) {}
  ~ScopedArrayPtr() { delete[] ptr_; }

  T* get() { return ptr_; }

 private:
  T* ptr_;
};
}  // namespace details

template <typename T>
class Vector final {
 public:
  using const_iterator = const T*;

  const_iterator begin() const { return buff_; }
  const_iterator end() const { return buff_ + size_; }

  Vector(unsigned capacity = 100) : capacity_(capacity) {
    buff_ = new T[capacity_];
  }
  Vector(const Vector<T>& other)
      : capacity_(other.capacity_), size_(other.size_) {
    buff_ = new T[capacity_];
    std::memcpy(other.buff_, buff_, size_);
  }
  Vector(Vector<T>&& other)
      : capacity_(other.capacity_), size_(other.size_), buff_(other.buff_) {
    other.buff_ = nullptr;
  }

  ~Vector() { delete[] buff_; }

  const T& operator[](unsigned index) const {
    assert(index < size_);
    return buff_[index];
  }

  unsigned size() const { return size_; }

  unsigned capacity() const { return capacity_; }

  void insertAt(unsigned index, T value) {
    assert(index <= size_);

    if (size_ == capacity_)
    {
      details::ScopedArrayPtr<T> prevBuff(buff_);

      capacity_ *= 1.3;
      buff_ = new T[capacity_];

      std::memcpy(buff_ + index + 1, prevBuff.get() + index,
                  (size_ - index) * sizeof(T));
      std::memcpy(buff_, prevBuff.get(), index * sizeof(T));
    }
    else
    {
      for (auto i = size_; i > index; --i) buff_[i] = buff_[i - 1];
    }

    ++size_;
    buff_[index] = value;
  }

 private:
  unsigned capacity_{0};

  unsigned size_{0};
  T* buff_{nullptr};
};
