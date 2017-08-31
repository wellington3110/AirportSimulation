FILE(GLOB DOMAIN "*.cpp" "*.h")

source_group("airport" FILES ${DOMAIN})
include_directories("${PROJECT_SOURCE_DIR}/src/util")

add_library(airport ${DOMAIN})

target_link_libraries(airport util)

set_property(TARGET airport PROPERTY FOLDER "domain")


