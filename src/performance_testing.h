/************************************************************************/
/*                                                                      */
/* This file is part of VDrift.                                         */
/*                                                                      */
/* VDrift is free software: you can redistribute it and/or modify       */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or    */
/* (at your option) any later version.                                  */
/*                                                                      */
/* VDrift is distributed in the hope that it will be useful,            */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of       */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        */
/* GNU General Public License for more details.                         */
/*                                                                      */
/* You should have received a copy of the GNU General Public License    */
/* along with VDrift.  If not, see <http://www.gnu.org/licenses/>.      */
/*                                                                      */
/************************************************************************/

#ifndef _PERFORMANCE_TESTING_H
#define _PERFORMANCE_TESTING_H

#include "physics/vehicle.h"
#include "physics/surface.h"

class ContentManager;

class PERFORMANCE_TESTING
{
public:
	PERFORMANCE_TESTING(sim::World & world);

	void Test(
		const std::string & cardir,
		const std::string & carname,
		ContentManager & content,
		std::ostream & info_output,
		std::ostream & error_output);

private:
	sim::World & world;
	sim::Surface surface;
	sim::Vehicle car;
	std::string carstate;

	void SimulateFlatRoad();

	void ResetCar();

	void TestMaxSpeed(std::ostream & info_output, std::ostream & error_output);

	void TestStoppingDistance(bool abs, std::ostream & info_output, std::ostream & error_output);
};

#endif
