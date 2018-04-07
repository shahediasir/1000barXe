// this file is created by Rafi at February 13, 2017

#ifndef TCONDUCTIVITY_H
#define TCONDUCTIVITY_H

#include "Material.h"


class Tconductivity;

template<>
InputParameters validParams<Tconductivity>();

/**
 * Material objects inherit from Material and override computeQpProperties.
 *
 * Their job is to declare properties for use by other objects in the
 * calculation such as Kernels and BoundaryConditions.
 */
class Tconductivity : public Material
{
public:
  Tconductivity(const InputParameters & parameters);

protected:
  /**
   * Necessary override.  This is where the values of the properties
   * are computed.
   */
  virtual void computeQpProperties() override;

private:


	// The thermal conductivity 
  MaterialProperty<Real> & _thermal_conductivity; // for u-10 Mo

  // const VariableGradient & _dep_variable; // this will get the temperature 
  //std::vector<const VariableValue> & _dep_variable;
  //VariableValue<Real> & _dep_variable;
   const VariableValue & _dep_variable;
};

#endif //Tconductivity
