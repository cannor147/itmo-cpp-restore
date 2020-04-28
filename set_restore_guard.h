#ifndef SET_RESTORE_GUARD_SET_RESTORE_GUARD_H
#define SET_RESTORE_GUARD_SET_RESTORE_GUARD_H
#include <cassert>
#include <iostream>
#include <type_traits>

template <typename T>
class set_restore_guard {

private:
    static const size_t size = sizeof(T);
    char m_old_value[size];
    T *m_var;

public:
    // constructors ans destructors
    set_restore_guard() = default;
    set_restore_guard(T &var, T const &new_value) {
        m_var = &var;
        new (m_old_value) T(var);
        *m_var = new_value;
    }
    ~set_restore_guard() {
        if (*this) {
            *m_var = old_value();
            m_var = nullptr;
        }
    }

    // deleted move and copy operators ans constructors
    set_restore_guard(set_restore_guard const &original) = delete;
    set_restore_guard(set_restore_guard &&original) = delete;
    set_restore_guard operator=(set_restore_guard const &original) = delete;
    set_restore_guard operator=(set_restore_guard &&original) = delete;

    // general methods
    void set(T &var, T const &new_value) {
        if (*this) restore();
        m_var = &var;
        new (m_old_value) T(*m_var);
        *m_var = new_value;
    }
    void restore() {
        *m_var = old_value();
        m_var = nullptr;
    }

    // some useful methods
    T const& old_value() const {
        assert(m_var != nullptr);
        return reinterpret_cast<const T&>(m_old_value);
    }
    explicit operator bool() const {
        return m_var != nullptr;
    }
};

#endif //SET_RESTORE_GUARD_SET_RESTORE_GUARD_H
