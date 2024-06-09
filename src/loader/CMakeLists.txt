add_library(RED3ext.Loader SHARED)

set_target_properties(
  RED3ext.Loader
    PROPERTIES
      OUTPUT_NAME winmm
)

red3ext_configure_resource_rc(
  RED3ext.Loader
  "The loader for ${PROJECT_NAME}."
)

geecore_set_target_as_loader(RED3ext.Loader)

set(
  RED3EXT_LOADER_HEADER_FILES
    stdafx.hpp
    Resource.hpp

    AppMetadata.hpp
)

set(
  RED3EXT_LOADER_SRC_FILES
    Main.cpp
    AppMetadata.cpp
)

source_group(CMake REGULAR_EXPRESSION cmake_pch.*)

source_group(
  TREE
    "${CMAKE_CURRENT_SOURCE_DIR}"
  FILES
    ${RED3EXT_LOADER_HEADER_FILES}
    ${RED3EXT_LOADER_SRC_FILES}
    ${RED3EXT_LOADER_DEF_FILES}
)

source_group(
  TREE
    "${CMAKE_CURRENT_BINARY_DIR}"
  FILES
    "${RED3EXT_RC_FILE}"
    "${CMAKE_CURRENT_BINARY_DIR}/GEEcore.def"
)

target_include_directories(
  RED3ext.Loader
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_sources(
  RED3ext.Loader
    PRIVATE
      ${RED3EXT_LOADER_HEADER_FILES}
      ${RED3EXT_LOADER_SRC_FILES}
      ${RED3EXT_LOADER_DEF_FILES}
      ${RED3EXT_RC_FILE}
)

target_precompile_headers(RED3ext.Loader PRIVATE stdafx.hpp)

target_link_libraries(
  RED3ext.Loader
    PRIVATE
      wopss::GEEcore
      WIL::WIL
)
