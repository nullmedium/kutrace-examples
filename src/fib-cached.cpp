// Compile with g++ -O2 hello_world_trace.c kutrace_lib.cc -o hello_world_trace

#include <iostream>

#include <unordered_map>

#include "kutrace_lib.h"

namespace
{
    std::unordered_map<int,int> cache;
}

int fib(int x)
{
    kutrace::mark_a("fib");

    if (x == 0 || x == 1)
    {
        kutrace::mark_b("recursion end");
        return 1;
    }

    kutrace::mark_a("lookup");
    auto res = cache.insert(std::make_pair(x, 0));

    if (res.second)
    {
        auto val = fib(x-1) + fib(x-2);

        kutrace::mark_a("write");
        res.first->second = val;
    }

    kutrace::mark_b("/fib");

    return res.first->second;
}

int main (int argc, const char** argv) {
    kutrace::go(argv[0]);

    kutrace::mark_a("main");

    auto res = fib(20);

    kutrace::mark_a("out");
    // std::cout << "fib = " << res << std::endl;
    printf("fib = %i", res);
    kutrace::mark_b("/out");

    kutrace::mark_b("/main");

    kutrace::stop("fib-cached.trace");

    return 0;
}
