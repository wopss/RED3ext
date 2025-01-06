add_library(RED3ext.Dll SHARED)

set_target_properties(
  RED3ext.Dll
    PROPERTIES
      OUTPUT_NAME ${PROJECT_NAME}
)

configure_resource_rc(
  RED3ext.Dll
  "A script extender for REDengine 3."
)

set(
  RED3EXT_DLL_HEADER_FILES
    stdafx.hpp
    Resource.hpp
)

set(
  RED3EXT_DLL_SRC_FILES
    Main.cpp
)

source_group(CMake REGULAR_EXPRESSION cmake_pch.*)

source_group(
  TREE
    "${CMAKE_CURRENT_SOURCE_DIR}"
  FILES
    ${RED3EXT_DLL_HEADER_FILES}
    ${RED3EXT_DLL_SRC_FILES}
)

source_group(
  TREE
    "${CMAKE_CURRENT_BINARY_DIR}"
  FILES
    ${RED3EXT_RC_FILE}
)

target_include_directories(
  RED3ext.Dll
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(
  RED3ext.Dll
    PRIVATE
      ${RED3EXT_DLL_HEADER_FILES}
      ${RED3EXT_DLL_SRC_FILES}
      ${RED3EXT_RC_FILE}
)

target_precompile_headers(RED3ext.Dll PRIVATE stdafx.hpp)
