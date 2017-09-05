set(domain_included_dirs "${CMAKE_CURRENT_SOURCE_DIR}/domain/airport"
"${CMAKE_CURRENT_SOURCE_DIR}/domain/report"
"${CMAKE_CURRENT_SOURCE_DIR}/domain/log"
"${CMAKE_CURRENT_SOURCE_DIR}/domain/simulator")

include_directories(${domain_included_dirs})

add_subdirectory(domain)
add_subdirectory(app)
add_subdirectory(util)


