FILE(GLOB COMMAND "*.cpp" "*.h")

source_group("commands" FILES ${COMMAND})
include_directories("${PROJECT_SOURCE_DIR}/src/app/gui")
include_directories("${PROJECT_SOURCE_DIR}/src/domain")

add_library(command ${COMMAND})

target_link_libraries(command gui)
target_link_libraries(command airport)

set_property(TARGET command PROPERTY FOLDER "app")


