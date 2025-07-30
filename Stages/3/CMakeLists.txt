project(stage_3)

add_executable(stage_3 ./main.cpp)
target_include_directories(stage_3 PRIVATE ./problem)
target_link_libraries(stage_3 GTest::gtest_main)

add_executable(stage_3_solution ./main.cpp)
target_include_directories(stage_3_solution PRIVATE ./solution)
target_link_libraries(stage_3_solution GTest::gtest_main)
