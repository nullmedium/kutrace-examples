cmake_minimum_required(VERSION 3.16.3)

project(kutrace_examples)

add_library(kutrace STATIC ../KUtrace/linux/control/kutrace_lib.cc)
target_include_directories(kutrace INTERFACE ../KUtrace/linux/control)

add_executable(checktrace ../KUtrace/postproc/checktrace.cc)
add_executable(eventtospan3 ../KUtrace/postproc/eventtospan3.cc)
add_executable(kuod ../KUtrace/postproc/kuod.cc)
add_executable(makeself ../KUtrace/postproc/makeself.cc)
add_executable(rawtoevent ../KUtrace/postproc/rawtoevent.cc ../KUtrace/postproc/from_base40.cc)
add_executable(samptoname_k ../KUtrace/postproc/samptoname_k.cc)
add_executable(samptoname_u ../KUtrace/postproc/samptoname_u.cc)
add_executable(spantoprof ../KUtrace/postproc/spantoprof.cc)
add_executable(spantospan ../KUtrace/postproc/spantospan.cc)
add_executable(spantotrim ../KUtrace/postproc/spantotrim.cc ../KUtrace/postproc/from_base40.cc)

add_executable(time_getpid ../KUtrace/postproc/time_getpid.cc)
target_link_libraries(time_getpid kutrace)

add_executable(unmakeself ../KUtrace/postproc/unmakeself.cc)

add_executable(kutrace-control ../KUtrace/linux/control/kutrace_control.cc)
target_link_libraries(kutrace-control kutrace)

add_executable(fib fib.cpp)
target_link_libraries(fib kutrace)

add_executable(fib-thread fib-thread.cpp)
target_link_libraries(fib-thread kutrace)

add_executable(fib-cached fib-cached.cpp)
target_link_libraries(fib-cached kutrace)
