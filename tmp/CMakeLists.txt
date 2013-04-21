project(tmp)

add_executable(tmp tmp.cpp)
target_link_libraries(tmp ${GMP_LIBRARIES})