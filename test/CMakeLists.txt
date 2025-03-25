cmake_minimum_required(VERSION 3.31)

set(This GameHouseTests)

set(Sources 
   GameHouseTests.cpp 
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC 
    gtest_main
    GameHouseProject
)

add_test(
   NAME ${This}
   COMMAND ${This}
)
