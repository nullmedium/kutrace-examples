// Compile with g++ -O2 hello_world_trace.c kutrace_lib.cc -o hello_world_trace

#include <iostream>

#include <thread>
#include <future>

#include <memory>

#include "kutrace_lib.h"

int fib(int x)
{
    kutrace::mark_a("fib");

    if (x == 0 || x == 1)
    {
        kutrace::mark_b("recursion end");
        return 1;
    }

    kutrace::mark_b("/fib");

    return fib(x-1) + fib(x-2);
}

int main (int argc, const char** argv) {
    kutrace::go(argv[0]);

    kutrace::mark_a("main");

    auto fut = std::async(&fib, 20);
    fut.wait();

    auto res = fut.get();

    std::cout << "fib = " << res << std::endl;

    kutrace::mark_b("/main");

    kutrace::stop("fib-thread.trace");

    return 0;
}
