find_package(Threads REQUIRED)

function(add_exercise)
    add_executable(exercise_${ARGV0} ${ARGV0}.cpp)
    target_link_libraries(exercise_${ARGV0} gtest ${CMAKE_THREAD_LIBS_INIT})
    add_test(${ARGV0} exercise_${ARGV0})
endfunction()


add_exercise(pair)
add_exercise(unique_ptr)
add_exercise(tuple)
add_exercise(function)
add_exercise(thread)
add_exercise(threaded_accumulate)
add_exercise(async_accumulate)
add_exercise(threaded_string)
add_exercise(hash_map)
add_exercise(dictionary)
