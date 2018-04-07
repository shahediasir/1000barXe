// this file is edited by Rafi January 24, 2017
// 
#include "Tconductivity.h"

template<>
InputParameters validParams<Tconductivity>()
{
  InputParameters params = validParams<Material>();
// we do not need to add any data from the input file
  params.addClassDescription("This is to calculate the temperature dependent thermal conductivity of U-10Mo");
// the "temperature" variable has to be defined in the input files
  params.addCoupledVar("dep_variable", "The thermal conductivity is calculated from temperature");
  return params;
}


Tconductivity::Tconductivity(const InputParameters & parameters) :
    Material(parameters),

    // Declare  material properties.  This returns references that we
    // hold onto as member variables
    //_permeability(declareProperty<Real>("permeability")),
	_thermal_conductivity(declareProperty<Real>("thermal_conductivity")),
	//_dep_variable(isCoupled("dep_varible"))
	_dep_variable(coupledValue("dep_variable"))
{
}

void
Tconductivity::computeQpProperties()
{

  // Sample the LinearInterpolation object to get the permeability for the ball size
  //_permeability[_qp] = _permeability_interpolation.sample(_ball_radius);
  _thermal_conductivity[_qp]=0.606+0.0351*_dep_variable[_qp];
}
