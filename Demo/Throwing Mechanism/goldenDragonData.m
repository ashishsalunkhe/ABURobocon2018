% World parameters
jointDamping = 1e-3; % Rotational joint damping
prisDamping = 1e-3; % Prismatic damping for 6DOF joint
k = 5000; % Locked joint stiffness
b = 10000; % Locked joint damping

% Shuttlecock parameters
tailMass = 1;  % shuttlecock tail mass, grams
headMass = 150; % shuttlecock head mass, grams

% Inputs
finalSpeed = 30; % Max spinning speed, rad/s
maxRate = 10; % Max acceleration, rad/s^2
inputTs = 0.1; % Input sample time (needed for rate limiter), s
inputFiltConstant = 0.1; % Input filter time constant
releaseTime = 2.625; % Grip release time, s

% Other parameters (used by old model)
Tf = 1e-6; % Low-pass filter time constant for torque feedback