/* this is a main app file created for the purpose of simulating heat conduction
 * 		This is file is created by Rafi, Sepetember 27, 2016
 * 		*****************************************************	*/

#include "HeatCondRafiApp.h"

//Moose Includes
#include "MooseInit.h"
#include "Moose.h"
#include "MooseApp.h"
#include "AppFactory.h"

// Creat a performance log
PerfLog Moose::perf_log("HeatCondRafi");

//Begin the main problem.
int main(int argc, char *argv[])
{
	// Initialize MPI, solvers and MOOSE
	MooseInit init(argc, argv);

	// Register this application's MooseApp and any it depends on
	HeatCondRafiApp::registerApps();

	// This creates dynamic memory that we're responsible for deleting
	// this line worked on the previous verson
	//MooseApp * app =  AppFactory::createApp("HeatCondRafiApp", argc, argv);
	std::shared_ptr<MooseApp> app = AppFactory::createAppShared("HeatCondRafiApp", argc, argv);

	//Execute the application
	app->run();
	
	// Free up the memory we created earlier
	//delete app;

	return 0;	




}
