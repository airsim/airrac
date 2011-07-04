#
# Tests for AirRAC
#

# Subdirs
add_subdirectory (${PROJECT_NAME})

if (Boost_FOUND)

  add_custom_target (check
    DEPENDS checkAirracTest checkAirracTest)

endif()
