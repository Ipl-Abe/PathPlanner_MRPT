# PathPlanner_MRPT CMake config file
#
# This file sets the following variables:
# PathPlanner_MRPT_FOUND - Always TRUE.
# PathPlanner_MRPT_INCLUDE_DIRS - Directories containing the PathPlanner_MRPT include files.
# PathPlanner_MRPT_IDL_DIRS - Directories containing the PathPlanner_MRPT IDL files.
# PathPlanner_MRPT_LIBRARIES - Libraries needed to use PathPlanner_MRPT.
# PathPlanner_MRPT_DEFINITIONS - Compiler flags for PathPlanner_MRPT.
# PathPlanner_MRPT_VERSION - The version of PathPlanner_MRPT found.
# PathPlanner_MRPT_VERSION_MAJOR - The major version of PathPlanner_MRPT found.
# PathPlanner_MRPT_VERSION_MINOR - The minor version of PathPlanner_MRPT found.
# PathPlanner_MRPT_VERSION_REVISION - The revision version of PathPlanner_MRPT found.
# PathPlanner_MRPT_VERSION_CANDIDATE - The candidate version of PathPlanner_MRPT found.

message(STATUS "Found PathPlanner_MRPT-1.0.0")
set(PathPlanner_MRPT_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(PathPlanner_MRPT_INCLUDE_DIRS
#    "/usr/local/include/pathplanner_mrpt-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(PathPlanner_MRPT_IDL_DIRS
#    "/usr/local/include/pathplanner_mrpt-1/idl")
set(PathPlanner_MRPT_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(PathPlanner_MRPT_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(PathPlanner_MRPT_LIBRARIES
        "/usr/local/components/lib/libpathplanner_mrpt.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(PathPlanner_MRPT_LIBRARIES
        "/usr/local/components/lib/libpathplanner_mrpt.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(PathPlanner_MRPT_DEFINITIONS ${<dependency>_DEFINITIONS})

set(PathPlanner_MRPT_VERSION 1.0.0)
set(PathPlanner_MRPT_VERSION_MAJOR 1)
set(PathPlanner_MRPT_VERSION_MINOR 0)
set(PathPlanner_MRPT_VERSION_REVISION 0)
set(PathPlanner_MRPT_VERSION_CANDIDATE )

