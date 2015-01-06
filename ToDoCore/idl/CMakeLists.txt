cmake_minimum_required (VERSION 2.8)
project(IDL)
#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
#set(TAO_IDL /usr/bin/tao_idl)
#FOREACH ( SUFFIX ${IDL_SUFFIXES} )
#       STRING( REGEX REPLACE "\\.idl" ${SUFFIX} OUTPUT "${IDL_SOURCE}" )
#       ADD_CUSTOM_COMMAND(
#         OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT}
#         COMMAND tao_idl #${TAO_IDL}
#         ARGS ${CMAKE_CURRENT_SOURCE_DIR}/${IDL_SOURCE} ${TAO_IDL_ARGS}
#         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${IDL_SOURCE}
#         )
# ENDFOREACH ( SUFFIX ${IDL_SUFFIXES} )
# ADD_CUSTOM_COMMAND(
#	 OUTPUT ${CMAKE_BINARY_DIR}/gen
#	 COMMAND tao_idl
#	 ARGS  time.idl
#         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${IDL_SOURCE}
#	 )
#SET_SOURCE_FILES_PROPERTIES(${IDL_SOURCE} PROPERTIES GENERATED true)

#add_library(idl ${IDL_SOURCE})

#include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#set(TAO_FOUND FALSE)
#set(TAO_FIND_LIBS "PortableServer" "CosNaming" "CosEvent" "CosEvent_Skel" "AnyTypeCode" "DynamicAny" "ACE" "TAO")
#find_path(TAO_INCLUDE_DIR tao/corba.h PATHS ${ACE_INCLUDE_DIR} /usr/include /usr/local/include)
#find_library(TAO_LIBRARY NAMES TAO TAOd ${ACE_INCLUDE_DIR}/lib $ENV{TAO_ROOT}/lib /usr/lib /usr/local/lib)
#find_program(TAO_IDL_COMPILER "tao_idl" ${ACE_INCLUDE_DIR}/bin /usr/bin /usr/local/bin ${TAO_INCLUDE_DIR}/bin)
#message(STATUS "tao_idl at: ${TAO_IDL_COMPILER}")
#if(TAO_INCLUDE_DIR AND TAO_LIBRARY AND TAO_IDL_COMPILER)
#	SET(TAO_FOUND TRUE)
#endif(TAO_INCLUDE_DIR AND TAO_LIBRARY AND TAO_IDL_COMPILER)
##now let's search for parts of tao we need.
#if(TAO_FOUND)
#	foreach(LIBRARY ${TAO_FIND_LIBS})
#		find_library(TAO_${LIBRARY}_LIB NAMES "TAO_${LIBRARY}" "TAO_${LIBRARY}d" ${TAO_LIBRARY} ${ACE_ROOT}/lib /usr/lib /usr/local/lib)
#		if(TAO_${LIBRARY}_LIB)
#			message(STATUS "${LIBRARY} found at: ${TAO_${LIBRARY}_LIB}")
#			#list(APPEND ${TAO_LIBRARY} TAO_${LIBRARY}_LIB)
#		else(TAO_${LIBRARY}_LIB)
#			SET(TAO_FOUND FALSE)
#		endif(TAO_${LIBRARY}_LIB)
#	endforeach()
#endif(TAO_FOUND)
#find_library("TAO")
#FIND_PACKAGE(TAO REQUIRED)
#FIND_PACKAGE(ACE REQUIRED)
set(${IDL}_INCLUDE_DIRS ${IDL_BINARY_DIR}
	CACHE INTERNAL "${IDL}: Include Directories" FORCE)
include_directories(${CMAKE_CURRENT_BINARY_DIR}
	#${ACE_INCLUDE_DIR}
	#${TAO_INCLUDE_DIR}
)

ADD_CUSTOM_COMMAND(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/timeC.cpp
	${CMAKE_CURRENT_BINARY_DIR}/timeC.h
	${CMAKE_CURRENT_BINARY_DIR}/timeS.cpp
	${CMAKE_CURRENT_BINARY_DIR}/timeS.h
	COMMAND tao_idl 
	ARGS ${CMAKE_CURRENT_SOURCE_DIR}/time.idl
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/time.idl
	)
ADD_LIBRARY(idl timeC.cpp timeS.cpp)
#target_include_directories (IDL PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
	#${TAO_LIBRARARIES}
	#${ACE_LIBRARIES}
	#${TAO_PortableServer_LIB}
	#${TAO_CosEvent_Skel_LIB}
	#${TAO_CosNaming_LIB}
	#)
