cmake_minimum_required(VERSION 3.2.1)

project(PluginRotate)

include_directories("${SH_ROOT_DIR}/include")

if (WIN32)
	find_package(DirectX9 REQUIRED)
	include_directories("${DirectX9_INCLUDE_DIR}")
endif (WIN32)

set(SOURCES_CSHPLUGINROTATE CShPluginRotate.cpp CShPluginRotate.h)
source_group("Rotate" FILES ${SOURCES_CSHPLUGINROTATE})

# Compile to use it on Runtime
add_library(PluginRotate STATIC ${SOURCES_CSHPLUGINROTATE})
set_property(TARGET PluginRotate PROPERTY FOLDER "Runtime")
set_property(TARGET PluginRotate APPEND PROPERTY COMPILE_DEFINITIONS "SH_DEV=1")
set_property(TARGET PluginRotate APPEND PROPERTY COMPILE_DEFINITIONS "SH_$<UPPER_CASE:$<CONFIG>>=1")

# Compile to use it in the Shine Editor
add_library(PluginRotate_Editor OBJECT ${SOURCES_CSHPLUGINROTATE})
set_property(TARGET PluginRotate_Editor PROPERTY FOLDER "Editor")
set_property(TARGET PluginRotate_Editor APPEND PROPERTY COMPILE_DEFINITIONS "SH_DEV=1")
set_property(TARGET PluginRotate_Editor APPEND PROPERTY COMPILE_DEFINITIONS "SH_$<UPPER_CASE:$<CONFIG>>=1")
set_property(TARGET PluginRotate_Editor APPEND PROPERTY COMPILE_DEFINITIONS "SH_EDITOR=1")
set_property(TARGET PluginRotate_Editor APPEND PROPERTY COMPILE_DEFINITIONS "_INTERNAL_DLL")
