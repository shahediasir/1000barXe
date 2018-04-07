#ifndef HEAT_COND_RAFIAPP_H
#define HEAT_COND_RAFIAPP_H

#include "MooseApp.h"

class HeatCondRafiApp;

template<>
InputParameters validParams<HeatCondRafiApp>();

class HeatCondRafiApp : public MooseApp
{
public:
	HeatCondRafiApp(InputParameters parameters);
	virtual ~HeatCondRafiApp();

	static void registerApps();
	static void registerObjects(Factory & factory);
	static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif	/* HeatCondRafiApp */
