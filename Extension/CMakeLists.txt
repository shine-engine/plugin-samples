cmake_minimum_required(VERSION 3.2.1)

project(SampleExtension)

set(SH_ROOT_DIR "../Shine" CACHE PATH "Shine root directory")

include_directories("${SH_ROOT_DIR}/include")

find_library(SH_SDK_EDITOR_LIB_DEBUG "ShSDK_Editor_Debug" PATHS "${SH_ROOT_DIR}" PATH_SUFFIXES Lib lib NO_DEFAULT_PATH)
find_library(SH_SDK_EDITOR_LIB_RELEASE "ShSDK_Editor_Release" PATHS "${SH_ROOT_DIR}" PATH_SUFFIXES Lib lib NO_DEFAULT_PATH)

if (WIN32)
	include_directories("C:\\Program Files (x86)\\Microsoft DirectX SDK (June 2010)\\Include") # TODO : find_package
endif (WIN32)

set(SOURCES_EXTENSION Extension.cpp Extension.h)
source_group("Extension" FILES ${SOURCES_EXTENSION})

if(WIN32)
	set(SOURCES_DLLMAIN dllmain.cpp)
else(WIN32)
	set(SOURCES_DLLMAIN)
endif(WIN32)
source_group("dll" FILES ${SOURCES_DLLMAIN})

add_library(SampleExtension SHARED ${SOURCES_DLLMAIN} ${SOURCES_EXTENSION} $<TARGET_OBJECTS:PluginRotate> $<TARGET_OBJECTS:PluginTranslate>)
target_link_libraries(SampleExtension debug ${SH_SDK_EDITOR_LIB_DEBUG} optimized ${SH_SDK_EDITOR_LIB_RELEASE})
set_property(TARGET SampleExtension APPEND PROPERTY COMPILE_DEFINITIONS "SH_DEV=1")
set_property(TARGET SampleExtension APPEND PROPERTY COMPILE_DEFINITIONS "SH_$<UPPER_CASE:$<CONFIG>>=1")
set_property(TARGET SampleExtension APPEND PROPERTY COMPILE_DEFINITIONS "SH_EDITOR=1")
set_property(TARGET SampleExtension APPEND PROPERTY COMPILE_DEFINITIONS "_INTERNAL_DLL")