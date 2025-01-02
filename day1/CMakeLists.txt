get_filename_component(CURRENT_PROJECT ${CMAKE_CURRENT_LIST_DIR} NAME)

add_executable(${CURRENT_PROJECT}
        ${CMAKE_CURRENT_LIST_DIR}/day1_main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/day1.cpp
        ${CMAKE_CURRENT_LIST_DIR}/day1.h
)

add_executable(${CURRENT_PROJECT}_test
        ${CMAKE_CURRENT_LIST_DIR}/day1_test.cpp
        ${CMAKE_CURRENT_LIST_DIR}/day1.cpp
        ${CMAKE_CURRENT_LIST_DIR}/day1.h
)

target_link_libraries(${CURRENT_PROJECT}_test PRIVATE GTest::gtest_main)

