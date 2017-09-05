
file(GLOB_RECURSE airport "${CMAKE_CURRENT_SOURCE_DIR}/airport/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/airport/*.cpp")
file(GLOB_RECURSE report "${CMAKE_CURRENT_SOURCE_DIR}/report/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/report/*.cpp")
file(GLOB_RECURSE log "${CMAKE_CURRENT_SOURCE_DIR}/log/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/log/*.cpp")
file(GLOB_RECURSE simulator "${CMAKE_CURRENT_SOURCE_DIR}/simulator/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/simulator/*.cpp")

source_group("airport" FILES ${airport})
source_group("report" FILES ${report})
source_group("log" FILES ${log})
source_group("simulator" FILES ${simulator})

include_directories("${PROJECT_SOURCE_DIR}/src/util")

add_library(domain ${airport} ${report} ${log} ${simulator})
target_link_libraries(domain util)

set_property(TARGET domain PROPERTY FOLDER "domain")






