
#ifndef HEATFLUX_H
#define HEATFLUX_H

#include "AuxKernel.h"

//Forward Declarations
class HeatFlux;

template<>
InputParameters validParams<HeatFlux>();

/**
 * Constant auxiliary value
 */
class HeatFlux : public AuxKernel
{
public:
  HeatFlux(const InputParameters & parameters);

  virtual ~HeatFlux() {}

protected:
  /**
   * AuxKernels MUST override computeValue.  computeValue() is called on
   * every quadrature point.  For Nodal Auxiliary variables those quadrature
   * points coincide with the nodes.
   */
  virtual Real computeValue() override;


  /// The gradient of a coupled variable
  const VariableGradient & _temperature_gradient;

  /// Holds the permeability and viscosity from the material system
  const MaterialProperty<Real> & _t_thermal_conductivity;
  // const MaterialProperty<Real> & _viscosity;

	int _component;
};

#endif // end of HEATFLUX_H
