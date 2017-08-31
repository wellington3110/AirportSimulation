FILE(GLOB GUI "*.cpp" "*.h")

source_group("gui" FILES ${GUI})

include_directories("${PROJECT_SOURCE_DIR}/src/util")

add_library(gui ${GUI})

target_link_libraries(gui util)

set_property(TARGET gui PROPERTY FOLDER "app")


