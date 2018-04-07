// this file is created by Rafi at February 13, 2017
// The reference is Rabinovich et al.
// Thermophysical Propeties of Neon, Argon, Krypton and Xenon// for the purpose of temperature dependent thermal condcutivity for U-10Mo
#ifndef XENONT_H
#define XENONT_H

#include "Material.h"


class XenonT;

template<>
InputParameters validParams<XenonT>();

/**
 * Material objects inherit from Material and override computeQpProperties.
 *
 * Their job is to declare properties for use by other objects in the
 * calculation such as Kernels and BoundaryConditions.
 */
class XenonT : public Material
{
public:
  XenonT(const InputParameters & parameters);

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

#endif //XENONT_H
