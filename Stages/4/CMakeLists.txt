project(stage_4)

include_directories(./include)

add_executable(stage_4 ./main.cpp)
target_include_directories(stage_4 PRIVATE ./problem)
target_link_libraries(stage_4 GTest::gtest_main)

add_executable(stage_4_solution ./main.cpp)
target_include_directories(stage_4_solution PRIVATE ./solution)
target_link_libraries(stage_4_solution GTest::gtest_main)
