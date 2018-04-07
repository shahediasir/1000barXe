// this file created by Rafi, January 24, 2017
#ifndef TEMPDEPK_H
#define TEMPDEPK_H

#include "Diffusion.h"

class Tempdepk;

template<>
InputParameters validParams<Tempdepk>();

/**
 * This kernel will solve a temperature dependent thermal conductivity with diffusion of temperature
 */
class Tempdepk : public Diffusion
{
public:
  Tempdepk(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;
// creating a moose array for material property

 const MaterialProperty<Real> & _thermal_conductivity;


};


#endif 
