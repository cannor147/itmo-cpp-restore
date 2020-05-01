# set_restore_guard

## Условие задания

Необходимо реализовать библиотеку `set_restore_guard`, которая бы содержала реализацию следующего интерфейса:

```c++
template <typnename T>
struct set_restore_guard {
    set_restore_guard();
    set_restore_guard(T& var, T const& new_value);
    
    ~set_restore_guard();
    void set(T& var, T const& new_value);
    void restore();
    
    T const& old_value() const;
    explicit operator bool() const;
};
```

