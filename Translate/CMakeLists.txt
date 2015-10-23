cmake_minimum_required(VERSION 3.2.1)

project(PluginTranslate)

include_directories("${SH_ROOT_DIR}/include")

if (WIN32)
	find_package(DirectX9 REQUIRED)
	include_directories("${DirectX9_INCLUDE_DIR}")
endif (WIN32)

set(SOURCES_CSHPLUGINTRANSLATE CShPluginTranslate.cpp CShPluginTranslate.h)
source_group("Translate" FILES ${SOURCES_CSHPLUGINTRANSLATE})

# Compile to use it on Runtime
add_library(PluginTranslate STATIC ${SOURCES_CSHPLUGINTRANSLATE})
set_property(TARGET PluginTranslate PROPERTY FOLDER "Runtime")
set_property(TARGET PluginTranslate APPEND PROPERTY COMPILE_DEFINITIONS "SH_DEV=1")
set_property(TARGET PluginTranslate APPEND PROPERTY COMPILE_DEFINITIONS "SH_$<UPPER_CASE:$<CONFIG>>=1")

# Compile to use it in the Shine Editor
add_library(PluginTranslate_Editor OBJECT ${SOURCES_CSHPLUGINTRANSLATE})
set_property(TARGET PluginTranslate_Editor PROPERTY FOLDER "Editor")
set_property(TARGET PluginTranslate_Editor APPEND PROPERTY COMPILE_DEFINITIONS "SH_DEV=1")
set_property(TARGET PluginTranslate_Editor APPEND PROPERTY COMPILE_DEFINITIONS "SH_$<UPPER_CASE:$<CONFIG>>=1")
set_property(TARGET PluginTranslate_Editor APPEND PROPERTY COMPILE_DEFINITIONS "SH_EDITOR=1")
set_property(TARGET PluginTranslate_Editor APPEND PROPERTY COMPILE_DEFINITIONS "_INTERNAL_DLL")
