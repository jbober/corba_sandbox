cmake_minimum_required (VERSION 2.8)
project (corba_sandbox)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
enable_testing()

#add_subdirectory (gmock-1.7.0)
SET(CMAKE_CXX_FLAGS "-lACE")
SET(CMAKE_CXX_FLAGS "-lTAO")
SET(CMAKE_CXX_FLAGS "lTAO_PortableServer")
#SET(CMAKE_CXX_FLAGS "-lTAO_DynamicAny")
SET(CMAKE_CXX_FLAGS "-lpthread")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
	"${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()

if (NOT CONFIGURED_ONCE)
	set(CMAKE_CXX_FLAGS "${warnings}"
	CACHE STRING "Flags used by the compiler during all build types." FORCE)
	set(CMAKE_C_FLAGS   "${warnings}"
	CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#include_directories(ToDoCore)

#add_subdirectory(ToDoCore)

#add_executable(server server.cpp)
find_package(TAO REQUIRED)
find_package(ACE REQUIRED)
if (TAO_FOUND)
	if (ACE_FOUND)
include_directories(${TAO_INCLUDE_DIRS})
include_directories(${ACE_INCLUDE_DIRS})
#find_package(ACE REQUIRED)
#add_executable(toDo main.cc )
#target_link_libraries(server ${TAO_LIBRARIES} ${ACE_LIBRARIES})

#target_link_libraries(ToDoCore ${TAO_LIBRARIES} )
endif (ACE_FOUND)
endif (TAO_FOUND)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ToDoCore/idl)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ToDoCore/idl/build/)

add_executable(server main.cpp)
target_link_libraries(server idl)# ${TAO_LIBRARIES} ${ACE_LIBRARIES})

#target_link_libraries(toDo toDoCore)
#add_test(toDoTest toDo)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
"A flag showing that CMake has configured at least once.")
