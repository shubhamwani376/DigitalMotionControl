% Motor-Pendulum Experiment: Run this section to initialize before running other sections
% Author: Tsu-Chin Tsao, April 2020

clc;
close all;
clear all;

% Motor-Pendulum plant model
% G_rotorspeed = kapa/(tau*s+1)
% G_rotorposition =kapa/(s*(tau*s+1))

m=0.032;       %(kg) Mass of pendulum
g=9.81;           %(m/s^2) Gravitational acceleration
l_c=2.5655*1E-2;     %(m)Distance from pivot joint to the center of pendulum rod
J_rodc=1.6383*1E-5;  %(kgm^2) Moment of inertia of pendulum about center of rod
J_motor=1.67*1E-6; %(kgm^2)  Moment of inertia of motor rotor
J_rotor=J_rodc+J_motor;   %2.33*1E-5;  %(kgm^2)Moment of inertia of inertia mode of system
J_dp=J_rotor+m*l_c^2 ;     %3.7494e-05 %8.54*1E-5;   %(kgm^2) Moment of inertia of downward pendulum mode of system
J_ip=J_dp;          %(kgm^2)Moment of inertia of inverted pendulum mode of system
b = 4.425*1e-6;               % Motor-rotor viscous damping
R = 6;        % (Ohms)Motor coil resistant
L = 0;             %(Henry) Motor coil inductance
K_m = 0.025463 ;          %(Nm/A) Motor torque constant
V_s = 10.5;          %(V)Supply voltage of the motor drive (H-bridge)
                    % input d = Duty cycle
                    % output (rad) - Angle of pendulum
Angle_Pendu=30/180*pi;   %vpendulum equlibrium position
K_pendu =  m*g*l_c*cos(Angle_Pendu);  %linearrized pendulm spring constant



s=tf('s');   %transfer function variable

%plant model


%Full order motor-rotor model (second order):
P_rotorfull= (K_m*V_s)/((J_rotor*s+b)*(L*s+R)+K_m^2)  ;
P_rotorposfull= P_rotorfull/s; 
F_rotorfull=(L*s+R)/(K_m*V_s);
P_penduposfull= P_rotorposfull/(1+K_pendu*P_rotorposfull*F_rotorfull); 


%Reduced order motor-rotor model for control design (first order, assuming b=0,L=0):
kapa=V_s/K_m;
tau=J_rotor*R/K_m^2;
P_rotorred=kapa/(tau*s+1);
P_rotorposred=P_rotorred/s;
F_rotorred=R/(K_m*V_s);
P_penduposred= P_rotorposred/(1+K_pendu*P_rotorposred*F_rotorred); 

% Discrte-time plant model:

Ts=0.001; %sampling time

z=tf('z',Ts)
G= P_rotorposred;
G_d= c2d(G,Ts,'zoh')  %Exact discrete-time model with sampling ADC  and zero order hold DAC
G_dw=d2c(G_d,'tustin')
pzmap(G,'r',G_dw,'b')

%design = 'z_rootlocus'    %For discrete time controller design
%design = 'rootlocus'      %For continuous time controller design
design = 'transientspecs'  %Used for continuous time PD control design

filterform = 'PD'          %Filter forms for direct digital control design
%filterform = 'lead'
%filterform = 'PID'
%filterform = 'leadlag'


digitalcontrol = 'indirect'   %direct or indirect digital control
digitalcontrol = 'direct'

%analysis ='reducedorderplant_s'   %Closed loop dynamics analysis
%analysis ='higherorderplant_s'    %Continuous-time domain

analysis ='reducedorderplant_DT'   %discrete-time domain
%analysis ='higherorderplant_DT'
%analysis ='reducedorderplant_W'    % W-domain (pseudo continuous)
%analysis ='higherorderplant_W'

%figure(1)  %Open loop dynamics
%step(P_rotorfull,P_rotorred);
%grid
%figure
%bode(P_rotorfull,P_rotorposred);
%grid
%'Hit return to Continue to PI Control Design & Analysis'
%pause;


switch(design)

    case {'z_rootlocus'}
        
        switch(filterform)
            case {'PD'}   %PD: C(z)=Kp+Kd*(1-z^-1)/Ts=Kc(z-C_zero)/z
       C_zero=0.98
       Kc=0.0322*10*5.61*0.757*10*0.7*2.2
       
       C_d=Kc*(z-C_zero)/z
       
            case{'lead'}       %lead compensator: Kc(z-C_zero)/(z-C_pole)
        C_zero=0.9;
        C_pole=0.8;
       Kc=1
       C_d=Kc*(z-C_zero)/(z-C_pole)
       
            case{'PID'} %PID:
       C_zero= 0.75   %0.98  % 0.994;
       C_zero1=  0.25 % 0.95  % 0.98;
       Kc= 0.04          %76   %27
     C_d=Kc*(z-C_zero)*(z-C_zero1)/(z*(z-1))
     
            case{'leadlag'}  %leadlag: Kc(z-C_zero)/(z-C_pole)
       C_zero=0.9;
       C_pole=0.3;
       C_zero1=0.8;
       C_pole1=0.99;
       Kc=1
       C_d=Kc*(z-C_zero)*(z-C_zero1)/((z-C_pole)*(z-Cpole1))
       
        end
        
   case {'rootlocus'}
gain=1
Kd=10000*gain;   %PI control adds a negative real zero and a pole at the origin
zz = 100;
tau_c=1/zz/100;
C = Kd*(s+zz)/(tau_c*s+1);  %Kp=zz/Kd


    case {'transientspecs'}

%Closed loop Transient Specifications:

Tr=0.05  % Rise time
Mp=15/100   % Maximum percent overshoot
%Tp =       % Peak time
%Ts =       % Settling time (2%)
%Wb=        % Closed loop bandwidth
%PM=        % Phase Margin (degrees)

% Calculate closed loop damping ratio and natural frequency:
Wn=1.8/Tr %rad/sec
tmp=(log(Mp)/pi)^2;
Zeta=sqrt(tmp/(1+tmp))
%Wd=sqrt(1-Zeta^2)*Wn = pi/Tp;
%Sig=Zeta*Wn=4/Ts;
%Wn=Wb % rad/sec;
%Zeta= PM/100;

%Rotor Velocity Closed loop pole:  tau s^2 + (1+kapa*Kp)*s+kapa*Ki=0
%Rotor Position Closed loop pole:  tau s^2 + (1+kapa*Kd)*s+kapa*Kp=0
%Pendulum Position Closed loop pole:
%Wn^2=kapa*Ki/tau;
%2*Zeta*Wn=(1+kapa*Kp)/tau);
%Ki= Wn^2*tau/kapa;
%Kp= (2*Zeta*Wn*tau-1)/kapa;
%C = Kp+Ki/s;

Kp= Wn^2*tau/kapa;
Kd= (2*Zeta*Wn*tau-1)/kapa;
tau_c= 1/(100*Wn);  % to make the controller causal, place a faster pole than closed loop bandwidth 
C =(Kd*s+Kp)/(tau_c*s+1);
C= 2*200*0.01*C;  % iterative gain adjustment to satisfy the spec.
    end



switch (analysis)
    case{'reducedorderplant_s'}
G=P_rotorposred;  %Used the reduced order plant model for control design
F=F_rotorred;      
    
    case{'higherorderplant_s'}
G=P_rotorposfull;  %Used the reduced order plant model for c
F=F_rotorfull;    

    
case{'reducedorderplant_DT'}

G=P_rotorposred;  %Used the reduced order plant model for control design
F=F_rotorred;   
G_d= c2d(G,Ts,'zoh');  %Exact discrete-time model with sampling ADC  and zero order hold DAC
 switch (digitalcontrol)   
    case {'indirect'}
C_d= c2d(C,Ts,'tustin');
    case{'direct'}
       
end

GF=G*F;
GF_d=c2d(GF,Ts,'zoh');
F_d=GF_d/G_d;
 
 G=G_d;  %reassign to G as plant for analysis
 C=C_d;
 F=F_d;
    
    
case {'higherorderplant_DT'}


G=P_rotorposfull;  %Used the reduced order plant model for control design
F=F_rotorfull;   
G_d= c2d(G,Ts,'zoh');  %Exact discrete-time model with sampling ADC  and zero order hold DAC
switch (digitalcontrol)   
    case {'indirect'}
C_d= c2d(C,Ts,'tustin');
    case{'direct'}
end

GF=G*F;
GF_d=c2d(GF,Ts,'zoh');
F_d=GF_d/G_d;
 
 G=G_d;  %reassign to G as plant for analysis
 C=C_d;
 F=F_d;


    case{'reducedorderplant_W'}
    
    G=P_rotorposred;  %Used the reduced order plant model for control design
F=F_rotorred;   
G_d= c2d(G,Ts,'zoh');  %Exact discrete-time model with sampling ADC  and zero order hold DAC
G_dw=d2c(G_d,'tustin');
 switch (digitalcontrol)   
    case {'indirect'}
C_d= c2d(C,Ts,'tustin');
C_dw= d2c(C_d,'tustin');  %C_ddw=C if no-prewarping
    case{'direct'}
C_dw= d2c(C_d,'tustin'); 
    end

GF=G*F;
GF_d=c2d(GF,Ts,'zoh');
F_d=GF_d/G_d;
F_dw=d2c(F_d,'tustin'); 
 
 G=G_dw;  %reassign to G as plant for analysis
 C=C_dw;
 F=F_dw;
 
    case {'higherorderplant_W'}
        
  


end
 


%Analysis:
%Connect the feedback system for Closed loop Analysis for the cases:

 C.InputName = 'e';  C.OutputName = 'u';
 G.InputName = 'u';  G.OutputName = 'y';
 Sum = sumblk('e','r','y','+-');
 T = connect(G,C,Sum,'r','y') ;
 S = connect(G,C,Sum,'r','e');
 SC= connect(G,C,Sum,'r','u') ;
 
 C.InputName = 'y';  C.OutputName = 'u';
 G.InputName = 'm';  G.OutputName = 'y';
 Sum = sumblk('m','d','u','+-');
 SG= connect(G,C,Sum,'d','y') ;

 Loop=G*C;
 SGF=SG*F;
 TF=T*F;
 
 figure
 step(T,S,SG,0.5*SC,0.05*TF,0.05*SGF);
 legend('T','S','SG','0.5*SC','0.05*TF','0.05*SGF');
 grid;
 figure 
 bode(T,S,SG,SC,TF,SGF);
 legend('T','S','SG','SC','TF','SGF');
 grid
 figure
 nyquist(Loop)
 grid
 % Check the transient response specs.
 stepinfo(T)
 [Gm,Pm,Wcg,Wcp] = margin(Loop)
 figure
 rlocus(Loop)
 
% Virtual Plant Model Simulation:
%digital controller is C_d:
%sampling time is Ts
C_d_num= cell2mat(C_d.num);
C_d_den= cell2mat(C_d.den);
open('RotorVirtualPlantModel_DigitalControl')
sim('RotorVirtualPlantModel_DigitalControl')


 
 