# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\TestControl_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TestControl_autogen.dir\\ParseCache.txt"
  "TestControl_autogen"
  )
endif()
