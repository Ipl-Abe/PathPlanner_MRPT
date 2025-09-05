// -*-C++-*-
/*!
 * @file  MobileRobotSVC_impl.h
 * @brief Service implementation header of MobileRobot.idl
 *
 */

#include "BasicDataTypeSkel.h"
#include "ExtendedDataTypesSkel.h"
#include "InterfaceDataTypesSkel.h"

#include "MobileRobotSkel.h"

#ifndef MOBILEROBOTSVC_IMPL_H
#define MOBILEROBOTSVC_IMPL_H
 
#include <iostream>

/*
#include <mrpt/maps/COccupancyGridMap2D.h>
#ifdef WIN32
#include <mrpt/nav/planners/CPathPlanningCircularRobot.h>
#else
#include <mrpt/nav/planners/PlannerSimple2D.h>
#endif
#include <mrpt/poses/CPose2D.h>
*/

// MRPT 2.x includes
#include <mrpt/gui/CDisplayWindow.h>     // もしGUIを使う場合
#include <mrpt/bayes/CParticleFilter.h>

#include <mrpt/poses/CPose2D.h>
#include <mrpt/poses/CPosePDFGaussian.h>
#include <mrpt/system/CTicTac.h>         // utils → system に移動

#include <mrpt/slam/CMonteCarloLocalization2D.h>  // ここ重要!!

#include <mrpt/maps/COccupancyGridMap2D.h>
#include <mrpt/maps/CMultiMetricMap.h>

#include <mrpt/obs/CActionRobotMovement2D.h>
#include <mrpt/obs/CObservation2DRangeScan.h>
#include <mrpt/obs/CSensoryFrame.h>
#include <mrpt/obs/CObservationOdometry.h>
#include <mrpt/obs/CActionCollection.h>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <mrpt/config/CConfigFile.h>


using namespace mrpt;
//using namespace mrpt::slam;
using namespace std;

class PathPlanner_MRPT;
/*!
 * @class PathPlannerSVC_impl
 * Example class implementing IDL interface RTC::PathPlanner
 */
class PathPlannerSVC_impl
 : public virtual POA_RTC::PathPlanner,
   public virtual PortableServer::RefCountServantBase
{
 private:

	 PathPlanner_MRPT *m_pRTC;

	mrpt::poses::CPose2D start;
	mrpt::poses::CPose2D goal;
	float RADIUS;
	float PATH_LENGTH;

public:
	void setRTC(PathPlanner_MRPT* pRTC) { m_pRTC = pRTC; }
 public:
	 
	 
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  /*!
   * @brief standard constructor
   */
   PathPlannerSVC_impl();

  /*!
   * @brief destructor
   */
   virtual ~PathPlannerSVC_impl();

   // attributes and operations
   RTC::RETURN_VALUE planPath(const RTC::PathPlanParameter & param ,RTC::Path2D_out path);
   
   	mrpt::poses::CPose2D getStart(){return start;}
	mrpt::poses::CPose2D getGoal(){return goal;}

	void setConfig(float radius, float pathLength){
		RADIUS = radius;
		PATH_LENGTH = pathLength;
	}
	float getRadius(){return RADIUS;}
	float getPathLength(){return PATH_LENGTH;}

	void setStart(const RTC::Pose2D & tp, const RTC::OGMap & map);
	void setGoal(const RTC::Pose2D & tp, const RTC::OGMap & map);
void OGMapToCOccupancyGridMap(RTC::OGMap ogmap, mrpt::maps::COccupancyGridMap2D *gridmap);
};

#endif // MOBILEROBOTSVC_IMPL_H


