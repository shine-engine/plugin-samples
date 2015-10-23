cmake_minimum_required(VERSION 3.2.1)

project(PluginSamples)

set(SH_ROOT_DIR "../Shine" CACHE PATH "Shine root directory")

# some sample plugins
add_subdirectory(Rotate)
add_subdirectory(Translate)

# Extension (to run plugins in the editor)
add_subdirectory(Extension)