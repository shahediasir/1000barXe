// this file created by Rafi, January 24, 2017
#ifndef TXENON_H
#define TXENON_H

#include "Diffusion.h"

class TXenon;

template<>
InputParameters validParams<TXenon>();

/**
 * This kernel will solve a temperature dependent thermal conductivity with diffusion of temperature
 */
class TXenon : public Diffusion
{
public:
  TXenon(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;
// creating a moose array for material property

 const MaterialProperty<Real> & _thermal_conductivity;


};


#endif 
