// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file MobileRobotSkel.h 
 * @brief MobileRobot server skeleton header wrapper code
 * @date Sat Sep  6 06:23:20 2025 
 *
 */

#ifndef HOME_REL_GIT_PATHPLANNER_MRPT_IDL_MOBILEROBOTSKEL_H
#define HOME_REL_GIT_PATHPLANNER_MRPT_IDL_MOBILEROBOTSKEL_H


#include <rtm/config_rtc.h>
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION

#if   defined ORB_IS_TAO
#  include "MobileRobotC.h"
#  include "MobileRobotS.h"
#elif defined ORB_IS_OMNIORB
#  if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#    ifdef USE_stub_in_nt_dll
#        undef USE_stub_in_nt_dll
#    endif
#    ifdef OpenRTM_IMPORT_SYMBOL
#        define USE_stub_in_nt_dll
#    endif
#  endif
#  include "MobileRobot.hh"
//#  include "MobileRobotUtil.h"
#elif defined ORB_IS_MICO
#  include "MobileRobot.h"
#elif defined ORB_IS_ORBIT2
#  include "/MobileRobot-cpp-stubs.h"
#  include "/MobileRobot-cpp-skels.h"
#elif defined ORB_IS_RTORB
#  include "MobileRobot.h"
#elif defined ORB_IS_ORBEXPRESS
#  include "MobileRobot.h"
#else
#  error "NO ORB defined"
#endif

#endif // HOME_REL_GIT_PATHPLANNER_MRPT_IDL_MOBILEROBOTSKEL_H
