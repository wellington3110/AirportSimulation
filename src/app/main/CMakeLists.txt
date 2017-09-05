file(GLOB MAIN "*.cpp" "*.h")

source_group("main" FILES ${MAIN})

include_directories("${PROJECT_SOURCE_DIR}/src/app/gui")
include_directories(${domain_included_dirs})
include_directories("${PROJECT_SOURCE_DIR}/src/app/commands")

add_executable(main ${MAIN})

target_link_libraries(main command)
target_link_libraries(main gui)
target_link_libraries(main domain)

set_property(TARGET main PROPERTY FOLDER "app")
