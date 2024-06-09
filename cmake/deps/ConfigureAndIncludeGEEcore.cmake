option(GEECORE_INSTALL "" OFF)

add_subdirectory(deps/geecore)

set_target_properties(fmt PROPERTIES FOLDER "Dependencies")
set_target_properties(GEEcore PROPERTIES FOLDER "Dependencies")

mark_as_advanced(
  GEECORE_INSTALL
)
