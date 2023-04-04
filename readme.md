## Inverted double-pendulum state observer feedback control (SOFC) simulation and verification
### Author:
[Shubham Wani](https://www.linkedin.com/in/shubhamwani/) , Aruul Mozhi Varman Senthilkumar, Pruthak Joshi

## Implementation
This project implements the following features:
1. System identification of 2 motor-pendulum systems and torsional spring
2. Dynamics equation of combined system and their state-space representation
3. Simulink simulation of control of virtual plant for step and oscillatory input.
4. Simulink hardware implementation using TI C2000 microcontroller and motor rotor plant for step and oscillatory input.
5. Controller design using LQR for estimator and controller using SOFC with integral terms and error analysis.
6. Pendulum 1 is observed but not controlled, whereas Pendulum 2 is unobserved but controlled.

## Images
![Schematic](https://github.com/shubhamwani376/MPC_Quadcopter/blob/main/Quadrotor.gif)
![Hardware](https://github.com/shubhamwani376/MPC_Quadcopter/blob/main/Quadrotor.gif)

## Dependencies
```
Hardware: TI C2000, 2 DC motor with encoder and rotor, motor driver, torsional clamp
Software: Follow Reference folder. Eg. TI CCS, MATLAB embedded toolbox, C++ compiler, etc.
MATLAB, Simulink.
```
## Reference
Class notes MAE277 @ UCLA, Winter 2023
Relevant files added to folder [Reference](https://github.com/shubhamwani376/MPC_Quadcopter/tree/main/Reference)
