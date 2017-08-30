file(GLOB INTERFACE "*.h")
source_group("interface" FILES ${INTERFACE})

add_library(interface ${INTERFACE})

#set_property(TARGET interface PROPERTY FOLDER "interfaces")

			

