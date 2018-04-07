
#ifndef TGRADIENT_H
#define TGRADIENT_H

#include "AuxKernel.h"

//Forward Declarations
class TGradient;

template<>
InputParameters validParams<TGradient>();

/**
 * Constant auxiliary value
 */
class TGradient : public AuxKernel
{
public:
  TGradient(const InputParameters & parameters);

  virtual ~TGradient() {}

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
  //const MaterialProperty<Real> & _t_thermal_conductivity;
  int _component;
  // const MaterialProperty<Real> & _viscosity;
};

#endif // end of TGRADIENT_H
