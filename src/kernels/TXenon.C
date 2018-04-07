// this file is edited by rafi for temperature dependent thermal conductivity
#include "TXenon.h"


template<>
InputParameters validParams<TXenon>()
{
  InputParameters params = validParams<Diffusion>();
  params.addClassDescription("This will solve heat diffusion with temperature dependent thermal conductivity");
  return params;
}

TXenon::TXenon(const InputParameters & parameters) :
    Diffusion(parameters),
	_thermal_conductivity(getMaterialProperty<Real>("thermal_conductivity"))  /*be sure u use the "thermal_conductivity, otherwise it will
not read the thermal_conductivity from the input*/
{
}

Real
TXenon::computeQpResidual()
{
  //return _grad_u[_qp] * _grad_test[_i][_qp];
  //Real _k=0.606+0.0351*_u[_qp]; // from D.E. Burkes et al./ Journal of Nuc Material 2010

/* return _thermal_conductivity[_qp]*Diffusion::computeQpResidual() + 380E3*_test[_i][_qp]; */

// the above one for a constant forcing function

  return _thermal_conductivity[_qp]*Diffusion::computeQpResidual();
}

Real
TXenon::computeQpJacobian()
{
  //Real _k=0.606+0.0351*_u[_qp];
  //return _grad_phi[_j][_qp] * _grad_test[_i][_qp];

  /*return _thermal_conductivity[_qp]*Diffusion::computeQpJacobian() + 
	(-4.33814E-09*_u[_i]*2.+1.9686E-05)*_grad_u[_qp]*_grad_test[_i][_qp]; */

	return _thermal_conductivity[_qp]*Diffusion::computeQpJacobian()+ (7.*(-1.32977E-21)*std::pow(_u[_qp],6)+
	5.21308E-18*6*std::pow(_u[_qp],5)-5*8.09748E-15*std::pow(_u[_qp],4) + 4*6.44801E-12*std::pow(_u[_qp],3)-
	3*3.10489E-09*std::pow(_u[_qp],2)+ 2*1.30628E-06*_u[_qp]-0.00057456)*_grad_test[_i][_qp]*_grad_u[_qp]; 

	/*return _thermal_conductivity[_qp]*Diffusion::computeQpJacobian() + (4*1.63419E-13*std::pow(_u[_qp],3) - 3*6.0966E-10*std::pow(_u[_qp],2)+ 2*8.68151E-07*_u[_qp] - 0.000565237 )*_grad_test[_i][_qp]*_grad_u[_qp];
*/
}
