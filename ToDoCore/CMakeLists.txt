cmake_minimum_required(VERSION 2.8)
add_library(toDoCore ToDo.cc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(idl)
add_subdirectory(unit_tests)
add_subdirectory(server)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/idl/build/)
add_executable(server_executable server.cpp)
target_link_libraries(server_executable idl -lACE -lTAO  -lTAO_PortableServer  -lTAO_AnyTypeCode ${TAO_LIBRARIES} ${ACE_LIBRARIES})
#target_link_libraries (server LINK_PUBLIC IDL)
#-L$(ACE_ROOT)/ace -lACE -lTAO -lTAO_PortableServer -lTAO_AnyTypeCode
SET(CMAKE_CXX_FLAGS -L/usr/lib/ace)
SET(CMAKE_CXX_FLAGS -lACE)
SET(CMAKE_CXX_FLAGS -lTAO)
SET(CMAKE_CXX_FLAGS -lTAO_PortableServer)
SET(CMAKE_CXX_FLAGS -lTAO_AnyTypeCode)
