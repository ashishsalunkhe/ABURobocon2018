# README
### Introduction to Contact Modeling
### Copyright 2017 The MathWorks, Inc.

## SETUP
Run initialize.m, and then go to the Examples folder.

## EXAMPLES
### SIMULINK
Contains Simulink examples of impulse-based and penalty force-based contact.

### SIMSCAPE
Contains Simscape examples of 1-D rotational and translational forces.
These use the built-in hard stop and friction Simscape blocks.

### MULTIBODY
#### 1D
Contains 1D examples that connect Simscape hard stop and friction blocks to
individual Simscape Multibody joint primitives.
#### 3D
Contains 3D examples that use the Simscape Multibody Contact Forces Library, 
as well as the "from scratch" approach with Transform Sensor and External 
Force and Torque blocks, to calculate 3D contact forces.
#### NOTE
The Simscape Multibody Contact Forces Library already ships with 2D and 3D examples
of the library blocks. These blocks use the 3D approach described in the previous section.
https://www.mathworks.com/matlabcentral/fileexchange/47417-simscape-multibody-contact-forces-library

## MULTIPHYSICS AND CONTACT LIBRARIES
For convenience, local copies of the Simscape Multibody Multiphysics Library and
Simscape Multibody Contact Forces Library have been included with this submission. 
If you would like to install the latest version of these libraries, you can find
them from the Add-On Explorer, or on the File Exchange
* Simscape Multibody Multiphysics Library: https://www.mathworks.com/matlabcentral/fileexchange/37636-simscape-multibody-multiphysics-library
* Simscape Multibody Contact Forces Library: https://www.mathworks.com/matlabcentral/fileexchange/47417-simscape-multibody-contact-forces-library
