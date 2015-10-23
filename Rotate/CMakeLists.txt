cmake_minimum_required(VERSION 3.2.1)

project(PluginRotate)

include_directories("${SH_ROOT_DIR}/include")

if (WIN32)
	include_directories("C:\\Program Files (x86)\\Microsoft DirectX SDK (June 2010)\\Include") # TODO : find_package
endif (WIN32)

set(SOURCES_CSHPLUGINROTATE CShPluginRotate.cpp CShPluginRotate.h)
source_group("Rotate" FILES ${SOURCES_CSHPLUGINROTATE})

# Compile to use it on Runtime
add_library(PluginRotate_Runtime STATIC ${SOURCES_CSHPLUGINROTATE})
set_property(TARGET PluginRotate_Runtime APPEND PROPERTY COMPILE_DEFINITIONS "SH_DEV=1")
set_property(TARGET PluginRotate_Runtime APPEND PROPERTY COMPILE_DEFINITIONS "SH_$<UPPER_CASE:$<CONFIG>>=1")

# Compile to use it in the Shine Editor
add_library(PluginRotate OBJECT ${SOURCES_CSHPLUGINROTATE})
set_property(TARGET PluginRotate APPEND PROPERTY COMPILE_DEFINITIONS "SH_DEV=1")
set_property(TARGET PluginRotate APPEND PROPERTY COMPILE_DEFINITIONS "SH_$<UPPER_CASE:$<CONFIG>>=1")
set_property(TARGET PluginRotate APPEND PROPERTY COMPILE_DEFINITIONS "SH_EDITOR=1")
set_property(TARGET PluginRotate APPEND PROPERTY COMPILE_DEFINITIONS "_INTERNAL_DLL")
