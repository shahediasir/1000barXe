
#include "HeatFlux.h"

template<>
InputParameters validParams<HeatFlux>()
{
  InputParameters params = validParams<AuxKernel>();

  MooseEnum component("x y z");
  // Declare the options for a MooseEnum.
  // These options will be presented to the user in Peacock
  // and if something other than these options is in the input file
  // an error will be printed
  params.addClassDescription("This is to calculate the heat flux for over all material");
  // Add a "coupling paramater" to get a variable from the input file.
  params.addRequiredCoupledVar("field_temperature", "The temperature field.");
  params.addRequiredParam<MooseEnum>("component", component, "The desired component of temperature");

  return params;
}

HeatFlux::HeatFlux(const InputParameters & parameters) :
    AuxKernel(parameters),

    // Get the gradient of the variable
    _temperature_gradient(coupledGradient("field_temperature")),

    // Snag thermal_coductivity from the Material system.
    // Only AuxKernels operating on Elemental Auxiliary Variables can do this
    _t_thermal_conductivity(getMaterialProperty<Real>("thermal_conductivity")),
	_component(getParam<MooseEnum>("component"))

{
}

Real
HeatFlux::computeValue()
{
  // Access the gradient of the pressure at this quadrature point
  // Then pull out the "component" of it we are looking for (x, y or z)
  // Note that getting a particular component of a gradient is done using the
  // parenthesis operator
  return _t_thermal_conductivity[_qp]*_temperature_gradient[_qp](_component);
}
