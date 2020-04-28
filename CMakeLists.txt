cmake_minimum_required(VERSION 3.12)
project(set_restore_guard)

set(CMAKE_CXX_STANDARD 14)

set(SetRestoreGuard
        set_restore_guard.h
        )

add_executable(main main.cpp ${SetRestoreGuard})