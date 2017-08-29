file(GLOB TEST "*.cpp" "*.h")

source_group("main" FILES ${TEST})

add_executable(main ${TEST})

include_directories("${PROJECT_SOURCE_DIR}/src/domain")

target_link_libraries(main airport)
