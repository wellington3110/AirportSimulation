set(CMAKE_AUTOMOC ON)
file(GLOB_RECURSE main "${CMAKE_CURRENT_SOURCE_DIR}/main/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/main/*.cpp")
file(GLOB_RECURSE gui "${CMAKE_CURRENT_SOURCE_DIR}/gui/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/gui/*.cpp")
file(GLOB_RECURSE commands "${CMAKE_CURRENT_SOURCE_DIR}/commands/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/commands/*.cpp")

source_group("main" FILES ${main})
source_group("gui" FILES ${gui})
source_group("commands" FILES ${commands})

include_directories("${PROJECT_SOURCE_DIR}/src/util")

add_executable(app ${main} ${gui} ${commands})

set_property(TARGET app PROPERTY FOLDER "app")

set(CMAKE_PREFIX_PATH "C:/Qt/5.0.2/msvc2010/lib/cmake/")
find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})

target_link_libraries(app util ${Qt5Widgets_LIBRARIES} domain)
