function(configure_resource_rc TARGET DESCRIPTION)
  get_target_property(RED3EXT_RESOURCE_PRODUCT_NAME "${TARGET}" OUTPUT_NAME)

  set(RED3EXT_RESOURCE_FILE_DESCRIPTION "${DESCRIPTION}")
  set(RED3EXT_RESOURCE_INTERNAL_NAME "${RED3EXT_RESOURCE_PRODUCT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX}")
  set(RED3EXT_RESOURCE_ORIGINAL_NAME "${RED3EXT_RESOURCE_PRODUCT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX}")

  set(OUTPUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/Resource.rc")

  configure_file(
    "${RED3EXT_CMAKE_TEMPLATES_DIR}/Resource.rc.in"
    "${OUTPUT_FILE}"
    @ONLY
  )

  set(RED3EXT_RC_FILE "${OUTPUT_FILE}" PARENT_SCOPE)
endfunction()
