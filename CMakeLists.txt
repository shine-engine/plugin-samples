cmake_minimum_required(VERSION 3.2.1)

project(PluginSamples)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(SH_ROOT_DIR "../Shine" CACHE PATH "Shine root directory")

if (MSVC)
	# The editor is compiled with /MD !
	# In debug mode the default is /MDd
	# To prevent false heap error detection we must compile the extension with the same flag
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD")
endif (MSVC)

# some sample plugins
add_subdirectory(Rotate)
add_subdirectory(Translate)

# Extension (to run plugins in the editor)
add_subdirectory(Extension)