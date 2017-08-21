FILE(GLOB DOMAIN "*.cpp" "*.h")

source_group("airport" FILES ${DOMAIN})

add_library(airport ${DOMAIN})

set_property(TARGET airport PROPERTY FOLDER "domain")


