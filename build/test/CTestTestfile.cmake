# CMake generated Testfile for 
# Source directory: E:/Coding/GameHouse/test
# Build directory: E:/Coding/GameHouse/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[GameHouseTests]=] "E:/Coding/GameHouse/build/test/Debug/GameHouseTests.exe")
  set_tests_properties([=[GameHouseTests]=] PROPERTIES  _BACKTRACE_TRIPLES "E:/Coding/GameHouse/test/CMakeLists.txt;15;add_test;E:/Coding/GameHouse/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[GameHouseTests]=] "E:/Coding/GameHouse/build/test/Release/GameHouseTests.exe")
  set_tests_properties([=[GameHouseTests]=] PROPERTIES  _BACKTRACE_TRIPLES "E:/Coding/GameHouse/test/CMakeLists.txt;15;add_test;E:/Coding/GameHouse/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[GameHouseTests]=] "E:/Coding/GameHouse/build/test/MinSizeRel/GameHouseTests.exe")
  set_tests_properties([=[GameHouseTests]=] PROPERTIES  _BACKTRACE_TRIPLES "E:/Coding/GameHouse/test/CMakeLists.txt;15;add_test;E:/Coding/GameHouse/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[GameHouseTests]=] "E:/Coding/GameHouse/build/test/RelWithDebInfo/GameHouseTests.exe")
  set_tests_properties([=[GameHouseTests]=] PROPERTIES  _BACKTRACE_TRIPLES "E:/Coding/GameHouse/test/CMakeLists.txt;15;add_test;E:/Coding/GameHouse/test/CMakeLists.txt;0;")
else()
  add_test([=[GameHouseTests]=] NOT_AVAILABLE)
endif()
