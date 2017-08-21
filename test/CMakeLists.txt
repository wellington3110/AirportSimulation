file(GLOB TEST "*.cpp" "*.h")

source_group("test" FILES ${TEST})

add_executable(runUnitTests ${TEST})

include_directories("${PROJECT_SOURCE_DIR}/src/domain")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/googletest/include")

target_link_libraries(runUnitTests google-test)
target_link_libraries(runUnitTests airport)
