// -*-C++-*-
/*!
 * @file  MobileRobotSVC_impl.cpp
 * @brief Service implementation code of MobileRobot.idl
 *
 */

#include "MobileRobotSVC_impl.h"
#include <iostream>

#include <mrpt/slam/COccupancyGridMap2D.h>
#include <mrpt/slam/CPathPlanningCircularRobot.h>
#include <mrpt/poses/CPose2D.h>


using namespace mrpt;
using namespace mrpt::slam;
using namespace std;


// End of example implementational code

/*
 * Example implementational code for IDL interface RTC::PathPlanner
 */


PathPlannerSVC_impl::PathPlannerSVC_impl()
{
	CPose2D start(0,0,0);
	CPose2D goal(0,0,0);
}


PathPlannerSVC_impl::~PathPlannerSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */

void PathPlannerSVC_impl::OGMapToCOccupancyGridMap(RTC::OGMap ogmap, COccupancyGridMap2D *gridmap) {
	gridmap->setSize(0, ogmap.map.width, 0, ogmap.map.height, ogmap.config.xScale, 0.5f);
	
	//������������
	for(int i=0; i<gridmap->getSizeY(); i++){
		for(int j=0; j < gridmap->getSizeX(); j++){	
			gridmap->setCell( i, j, ogmap.map.cells[i* gridmap->getSizeX() + j]);
		}
	}
}


RTC::RETURN_VALUE PathPlannerSVC_impl::planPath(const RTC::OGMap & map,const RTC::TimedPose2D & currentPose,const RTC::TimedPose2D & targetGoal ,RTC::Path2D_out path)
{
	RTC::RETURN_VALUE result;

	CPathPlanningCircularRobot pathPlanning;
	pathPlanning.robotRadius = 0.3; //robot radius should be able to change by configuration

	COccupancyGridMap2D gridmap;	
	OGMapToCOccupancyGridMap(map, &gridmap);
	

	//TimedPose2d -> CPose2D 
	setStart(currentPose);
	setGoal(targetGoal);

	bool notFound = false;
	std::deque <TPoint2D> tPath;

	pathPlanning.robotRadius = 0.30f;
		
	//plan path
	pathPlanning.computePath(gridmap, getStart(), getGoal(), tPath, notFound, 100.0f);


	//deque <TPoint2D>  -> Path2D_out�ɕϊ�����
	path = new RTC::Path2D(); //������������path = new RTC::Path2D_out.ptr();�����H
	path->waypoints.length(tPath.size());
	for(int i = 0;i < tPath.size(); i++) {
		path->waypoints[i].target.position.x = tPath[i].x;
		path->waypoints[i].target.position.y = tPath[i].y;
	}

	std::cout<< path << endl;

  return result;
}

// End of example implementational code



