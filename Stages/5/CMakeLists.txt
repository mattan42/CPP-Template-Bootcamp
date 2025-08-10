project(stage_5)

include_directories(./include)

add_executable(stage_5 ./main.cpp)
target_include_directories(stage_5 PRIVATE ./problem)
target_link_libraries(stage_5 GTest::gtest_main)

add_executable(stage_5_solution ./main.cpp)
target_include_directories(stage_5_solution PRIVATE ./solution)
target_link_libraries(stage_5_solution GTest::gtest_main)
