project(stage_2)

add_executable(stage_2 ./main.cpp)
target_include_directories(stage_2 PRIVATE ./problem)
target_link_libraries(stage_2 GTest::gtest_main)

add_executable(stage_2_solution ./main.cpp)
target_include_directories(stage_2_solution PRIVATE ./solution)
target_link_libraries(stage_2_solution GTest::gtest_main)
