[Mesh]
    file = 81_bubbles.e
    block_id = '1 2'
    boundary_id = '1 2'
    boundary_name = 'left right'
[]

[Variables]
    [./temperature] # define by Rafi
    [../]
[]

[AuxVariables]
    [./H_flux_x]
        order = CONSTANT
        family = MONOMIAL
    [../]
    [./H_flux_y]
        order = CONSTANT
        family = MONOMIAL
    [../]
    [./H_flux_z]
        order = CONSTANT
        family = MONOMIAL
    [../]
    [./T_Gradient_x]
        order = CONSTANT
        family = MONOMIAL
    [../]
    [./T_Gradient_y]
        order = CONSTANT
        family = MONOMIAL
    [../]
    [./T_Gradient_z]
        order = CONSTANT
        family = MONOMIAL
    [../]
[]

[Kernels]
    [./k_diff]
        type = Tempdepk #HeatConduction with temperature dependent thermal conductivity
        variable = temperature
        block = 1
    [../]
    [./k_Xe]
        type = TXenon
        variable = temperature
        block = 2
    [../]
[]

[AuxKernels]
    [./Heat_flux_x]
        type = HeatFlux
        variable = H_flux_x
        component = x
        field_temperature=temperature
    [../]
    [./Heat_flux_y]
        type = HeatFlux
        variable = H_flux_y
        component = y
        field_temperature = temperature
    [../]
    [./Heat_flux_z]
        type = HeatFlux
        variable = H_flux_z
        component = z
        field_temperature = temperature
    [../]
    [./T_Gradient_x]
        type = TGradient
        variable = T_Gradient_x
        component = x
        field_temperature = temperature
    [../]
    [./T_Gradient_y]
        type = TGradient
        variable = T_Gradient_y
        field_temperature = temperature
        component = y
    [../]
    [./T_Gradient_z]
        type = TGradient
        variable = T_Gradient_z
        component = z
        field_temperature = temperature
    [../]
[]

[BCs]
    [./inlet_temperature]
        type = DirichletBC
        #type = HeatConductionBC
        variable = temperature
        boundary_id = 1
        boundary= left # this "left" may be came from the mesh
        value = 713 # (K)
    [../]
    [./outlet_temperature]
        #type = HeatConductionBC
        type = DirichletBC
        variable = temperature
        boundary = right
        boundary_id = 2
        value = 753
    [../]
[]

[Materials]
    [./U10Mo]       # have to read about this 
        type = Tconductivity # may be need a source and header file
        block = 1
        dep_variable='temperature' # this is to calculate T dependent thermal conductivity of U10Mo
    [../]
    [./Xenon]
        type = XenonT
        block =2
        dep_variable = 'temperature' #this is to calculate the T dependent thermal conductivity of Xenon
    [../]
[]

[Postprocessors]
#    [./outlet_heat_flux]
#        type=SideFluxIntegral
#        variable=temperature
#        boundary = right
#        diffusivity = thermal_conductivity 
#    [../]
    [./average_temp]
        type = ElementAverageValue
        variable = temperature
    [../]
    [./average_flux_x]
        type = ElementAverageValue
        variable = H_flux_x
        component = x
        field_temperature = temperature
    [../]
    [./average_flux_y]
        type = ElementAverageValue
        variable = H_flux_y
        component = y
        field_temperature = temperature
    [../]
    [./average_temperature_gradient_x]
        type = ElementAverageValue
        variable = T_Gradient_x
        component = x
        field_temperature = temperature
    [../]
    [./average_temperature_gradient_y]
        type = ElementAverageValue
        variable = T_Gradient_y
        component = y
        field_temperature = temperature
    [../]
[]

#[Problem]
#    type = FEProblem
#    coord_type = RZ
#    rz_coord_axis = x
#[]
[Executioner]
    type = Steady
    solve_type = PJFNK
    petsc_options_iname = '-pc_type -pc_hypre_type'
    petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
    exodus = true
    #vtk =  true
    csv = true
[]



























