function(add_example)
    add_executable(${ARGV0} ${ARGV0}.cpp)
    target_link_libraries(${ARGV0} gtest)
endfunction()

add_example(pair)
add_example(tuple)
add_example(tuple1)
add_example(unique)
