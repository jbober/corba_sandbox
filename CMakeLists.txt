cmake_minimum_required (VERSION 2.6)
project (corba_sandbox) 
enable_testing()

add_subdirectory (gmock) 

project("To Do List")


add_executable(toDo main.cc
	                    ToDo.cc)
