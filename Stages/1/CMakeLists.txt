project(stage_1)

add_executable(stage_1 ./main.cpp)
target_include_directories(stage_1 PRIVATE ./problem)
target_link_libraries(stage_1 GTest::gtest_main)

add_executable(stage_1_solution ./main.cpp)
target_include_directories(stage_1_solution PRIVATE ./solution)
target_link_libraries(stage_1_solution GTest::gtest_main)
