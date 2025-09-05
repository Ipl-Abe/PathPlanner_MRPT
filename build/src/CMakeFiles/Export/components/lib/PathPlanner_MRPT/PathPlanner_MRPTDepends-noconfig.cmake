#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "PathPlanner_MRPT" for configuration ""
set_property(TARGET PathPlanner_MRPT APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(PathPlanner_MRPT PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "pthread;RTC2;omniDynamic4;omniORB4;omnithread;rtmCamera2;rtmManipulator2;mrpt::obs;mrpt::maps;mrpt::gui;mrpt::slam;mrpt::hwdrivers;mrpt::io;mrpt::nav"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/lib/PathPlanner_MRPT.so"
  IMPORTED_SONAME_NOCONFIG "PathPlanner_MRPT.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS PathPlanner_MRPT )
list(APPEND _IMPORT_CHECK_FILES_FOR_PathPlanner_MRPT "${_IMPORT_PREFIX}/components/lib/PathPlanner_MRPT.so" )

# Import target "PathPlanner_MRPTComp" for configuration ""
set_property(TARGET PathPlanner_MRPTComp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(PathPlanner_MRPTComp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/bin/PathPlanner_MRPTComp"
  )

list(APPEND _IMPORT_CHECK_TARGETS PathPlanner_MRPTComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_PathPlanner_MRPTComp "${_IMPORT_PREFIX}/components/bin/PathPlanner_MRPTComp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
