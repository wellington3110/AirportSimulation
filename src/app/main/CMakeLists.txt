file(GLOB MAIN "*.cpp" "*.h")

source_group("main" FILES ${MAIN})

include_directories("${PROJECT_SOURCE_DIR}/src/app/gui")
include_directories("${PROJECT_SOURCE_DIR}/src/domain")
include_directories("${PROJECT_SOURCE_DIR}/src/app/commands")

add_executable(main ${MAIN})

target_link_libraries(main command)
target_link_libraries(main gui)
target_link_libraries(main airport)

set_property(TARGET main PROPERTY FOLDER "app")
