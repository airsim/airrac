#
# AirRAC Tests
#

##
# Specify each test suite configuration

# * AirRAC Test Suite
module_test_add_suite (airrac YieldTestSuite YieldTestSuite.cpp)


##
# Register all the test suites to be built and performed
module_test_build_all ()

