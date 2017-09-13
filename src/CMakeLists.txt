set(domain_included_dirs "${CMAKE_CURRENT_SOURCE_DIR}/domain/airport"
"${CMAKE_CURRENT_SOURCE_DIR}/domain/report"
"${CMAKE_CURRENT_SOURCE_DIR}/domain/log"
"${CMAKE_CURRENT_SOURCE_DIR}/domain/simulator")

set(app_included_dirs "${CMAKE_CURRENT_SOURCE_DIR}/app/gui"
"${CMAKE_CURRENT_SOURCE_DIR}/app/main"
"${CMAKE_CURRENT_SOURCE_DIR}/app/commands")

include_directories(${domain_included_dirs})
include_directories(${app_included_dirs})

add_subdirectory(domain)
add_subdirectory(app)
add_subdirectory(util)


