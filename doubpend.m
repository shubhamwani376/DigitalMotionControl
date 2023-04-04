% Motor-Pendulum Position Control Modeling, Design, Analysis, Simulation, Verification by Virtual Experiment
% Author: Tsu-Chin Tsao, June 2022

clc;
% bdclose('all')
close all; clear all;

%plant = 'rotor';
plant = 'pendulum';   %Plant model is linearized at specified equlibrium angle

pend = 1; %1: single pendulum for this file 2: double pendulum not implemented


%SSdesign = 'state_observer_feedback';
SSdesign = 'state_observer_feedback_integral';

k_c = 0.074; %torsional spring constant

Ts = 0.001;  %digital control sampling time


%Motor and Pendulum Parameters:
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
V_s = 10.5;    %(V)Supply voltage of the motor drive (H-bridge)

%Motor and Pendulum Parameters:
m2=0.032;       %(kg) Mass of pendulum
l_c2=2.5655*1E-2;     %(m)Distance from pivot joint to the center of pendulum rod
J_rodc2=1.6383*1E-5;  %(kgm^2) Moment of inertia of pendulum about center of rod
J_motor2=1.67*1E-6; %(kgm^2)  Moment of inertia of motor rotor
J_rotor2=J_rodc+J_motor;   %2.33*1E-5;  %(kgm^2)Moment of inertia of inertia mode of system
J_dp2=J_rotor+m*l_c^2 ;     %3.7494e-05 %8.54*1E-5;   %(kgm^2) Moment of inertia of downward pendulum mode of system
J_ip2=J_dp2;          %(kgm^2)Moment of inertia of inverted pendulum mode of system
b2 = 4.425*1e-6;               % Motor-rotor viscous damping
R2 = 6;        % (Ohms)Motor coil resistant
L2 = 0;             %(Henry) Motor coil inductance
K_m2 = 0.025463 ;          %(Nm/A) Motor torque constant
V_s2 = 10.5;    %(V)Supply voltage of the motor drive (H-bridge)

m=3.6e-2;       %(kg) Mass of pendulum
g=9.80665;           %(m/s^2) Gravitational acceleration
l_c=2.54e-2;     %(m)Distance from pivot joint to the center of pendulum rod
J_rotor=1.911e-5;  %(kgm^2) Moment of inertia of pendulum about center of rod
J_dp=4.23e-5;   %(kgm^2) Moment of inertia of pendulum mode of system

b = 0;              % Motor-rotor viscous damping
R=8.985;             % (Ohms)Motor coil resistant
L=0.23e-3;          %(Henry) Motor coil inductance
K_m=3.9e-2;       %(Nm/A) Motor torque constant
V_s=10.72;    %(V)Supply voltage of the motor drive (H-bridge)
F_v = 5e-6; % static friction

m2=3.6e-2;       %(kg) Mass of pendulum
g2=9.80665;           %(m/s^2) Gravitational acceleration
l_c2=2.54e-2;     %(m)Distance from pivot joint to the center of pendulum rod
J_rotor2=1.911e-5;  %(kgm^2) Moment of inertia of pendulum about center of rod
J_dp2=4.23e-5;   %(kgm^2) Moment of inertia of pendulum mode of system

b2 = 0;              % Motor-rotor viscous damping
R2=8.985;             % (Ohms)Motor coil resistant
L2=0.23e-3;          %(Henry) Motor coil inductance
K_m2=3.9e-2;       %(Nm/A) Motor torque constant
V_s2=10.72;    %(V)Supply voltage of the motor drive (H-bridge)
F_v2 = 5e-6; % static friction

% input d = Duty cycle
% output (rad) - Angle of pendulum

%Parameters in the virtual plant simulation:
Tcomp=0.0005*Ts*14;  %controller computation delay (less than one sampling interval)
saturation =1.0;    %PWM duty cycle is between - and 100% and polarity
deadzone = 0.06;    % PWM switcing short circuit protection results in 4% duty cycle deadzone
Tss= 1/20000;       % 20kHz Encoder sampling rate by FPGA
encoder_resolution= 2*pi/400;  % Encoder resolution 400 counts/revolutin

Angle_Pendu = 0/180*pi;   %pendulum equlibrium position, 0 is vertically down, 180 is up
K_g =  m*g*l_c;
K_g2 =  m2*g*l_c2;
K_sin = cos(Angle_Pendu);  %linearization sin(angle)
Friction_static = 4E-4; %Static friction Nm
Friction_static2 = 4E-4; %Static friction Nm


switch(plant)
    case {'pendulum'}
        K_pend = 1;
        Stepsize = pi;  %Stepsize= Angle_Pendu;
        J_pend = J_dp;
        J_pend2 = J_dp2;
    case {'rotor'}
        K_pend =0;  %K_pend=0 for the rotor mode
        Stepsize= 1;
        J_pend =J_rotor;  % If this is for the rotor, treat as a special case of pendulum
end
K_tot = K_g*K_sin*K_pend;
K_tot2 = K_g2*K_sin*K_pend;

s=tf('s');   %transfer function variable

% Continuous-time plant model

%Full order motor-rotor model (third order):
% P_rotorfull= (K_m*V_s)/((J_pend*s+b)*(L*s+R)+K_m^2)  ;
% P_rotorposfull= P_rotorfull/s;
% F_rotorfull=(L*s+R)/(K_m*V_s);
% P_penduposfull= P_rotorposfull/(1+K_tot*P_rotorposfull*F_rotorfull);

%Reduced order motor-rotor model for control design (second order, assuming b=0,L=0):
kapa=V_s/K_m;
tau=J_pend*R/K_m^2;
P_rotorred=kapa/(tau*s+1);
P_rotorposred=P_rotorred/s;
F_rotorred=R/(K_m*V_s);
P_penduposred= P_rotorposred/(1+K_tot*P_rotorposred*F_rotorred);

kapa2=V_s2/K_m2;
tau2=J_pend*R/K_m2^2;
P_rotorred2=kapa2/(tau2*s+1);
P_rotorposred2=P_rotorred2/s;
F_rotorred2=R2/(K_m2*V_s2);
P_penduposred2= P_rotorposred2/(1+K_tot2*P_rotorposred2*F_rotorred2);

% Discrte-time plant model:

z=tf('z',Ts);
%G= P_penduposred;  %Use the reduced order plant for control design

switch(pend)
    case{1}
        % Single pendulum
        %G_tf = balred(P_penduposred,2);
%         A = [0 1; -K_tot/J_pend -1/tau];
%         B = [0; kapa/tau];
%         C = [1 0];
        A_sub = [0 1; -K_tot/J_pend, -1/tau];
        B_sub = [0; kapa/tau];
        Bd_sub = [0;1/J_pend];
        A_sub2 = [0 1; -K_tot2/J_pend2, -1/tau2];
        B_sub2 = [0; kapa2/tau2];
        Bd_sub2 = [0;1/J_pend2];
        C_sub = [1 0];

        A = [A_sub-k_c.*Bd_sub*C_sub, k_c.*Bd_sub*C_sub; k_c.*Bd_sub2*C_sub, A_sub2-k_c.*Bd_sub2*C_sub];
        B = [0;0;B_sub2];
        C = [C_sub,0,0];
        G = ss(A, B, C, 0);
        zpk(G);
    case{2}
        % Double pendulum
              
        % To be filled for double pendulum 
end

G_d= c2d(G,Ts,'zoh'); %Exact discrete-time model with sampling ADC  and zero order hold DAC
zpk(G_d)

        
        % State Observer Feedback Control based on 2 states reduced order model
        
        Plant=tf(G);
        Plant_d = tf(G_d);
   
        [A_d,B_d,C_d,D_d] = ssdata(G_d);
        switch(pend)
            case{1}
                %Bw = F_rotorred*B_d;                     % Single pendulum
                Bw = F_rotorred2*B_d;                     % Single pendulum
            case{2}
               % To be filled for double pendulum  
        end
        
        % Set up the Above State Space Model for Control Design Below

        %Observer Poles:
        %Tr  % Rise time
        %Mp  % Maximum percent overshoot %
        %Tp       % Peak time
        %Ts     % Settling time (2%)
        %Wb     % Closed loop bandwidth
        %PM       % Phase Margin (degrees)
        
        % Calculate Observer damping ratio and natural frequency:
        
%         Zeta=7.5;
%         Wn = 20*2*pi;        % 100*2*pi
%         s_pole= [(-Zeta+sqrt(Zeta^2-1))*Wn,  (-Zeta-sqrt(Zeta^2-1))*Wn];
%         Pole_Pred=exp(s_pole*Ts);
%         if pend ~= 1; 
%             
%         % To be filled for double pendulum 
%         end       
        %Pole_Pred = [0,0]; [0.8+1j*0.1 0.8-1j*0.1];
        %L_Pred = place(A_d',C_d',Pole_Pred); %for MIMO, but no identical poles
%         L_Pred = acker(A_d',C_d',Pole_Pred);  %for SISO only
%         
        
        %%% DO NOT CHANGE - NO DISTURBANCE
%         L_Pred = dlqr(A_d', C_d', [0.01, 0, 0, 0; 0, 10000, 0, 0; 0, 0, 0.0001, 0; 0, 0, 0, 10], [0.001]);
%         L_Pred = L_Pred';
%%        
        %%% DO NOT CHANGE
        L_Pred = dlqr(A_d', C_d', [1000, 0, 0, 0; 0, 2000, 0, 0; 0, 0, 1000, 0; 0, 0, 0, 1000], 100);
        L_Pred = L_Pred';

        L_Pred = dlqr(A_d', C_d', [1, 0, 0, 0; 0, 100, 0, 0; 0, 0, 0, 0; 0, 0, 0, 0], [0.001]);
        L_Pred = L_Pred';
%%
        switch (SSdesign)
            
            case{'state_observer_feedback'}
                
                
                K_SF=place(A_d,B_d,Pole_SF);  %for MIMO, but no identical poles
                %K_SF=acker(A_d,B_d,Pole_SF);  %for SISO only
                K_int=0;
                %K_SF = [0.516894678422227	0.0126791236940116];
                TF_yrf=ss(A_d-B_d*K_SF,B_d,C_d,[0],Ts);
                N=1/freqresp(TF_yrf,[0]);   %Scale the feedforward gain N to make dc gain y/r=1
                
                %Closed Loop Transfer Functions
                % input: r,d,w,  state: x, x~, output: y, u, e (e=r-y)
                
                
                AA= [A_d-B_d*K_SF, B_d*K_SF; zeros(size(A_d)), A_d-L_Pred*C_d];
                BB= [B_d*N, B_d, Bw; zeros(size(B_d)), B_d, Bw];
                CC= [C_d, zeros(size(C_d)); -K_SF, K_SF; -C_d, zeros(size(C_d))];
                DD= [0 0 0; N 0 0;1, 0 0];
                
                Loop_SF =ss(A_d,B_d,K_SF,0,Ts) %Loop T.F. for state feedback. To compare this with the Observer FB
                
           
            case{'state_observer_feedback_integral'}
                %State Observer Feedback control with integral action
                
                Aaug=[A_d zeros(size(B_d)); C_d 1];
                Baug=[B_d;0];

               
%                 gamma = 0.9;    %0<gamma<1 to select integrator pole faster than SF pole
%                 Pole_int = gamma*max(abs(Pole_SF));
                %gamma = 1   %0<gamma<1 to select integrator pole between SF pole and 1
                %Pole_int = (1-gamma)+gamma*max(abs(Pole_SF));

%                 Pole_SF_int= [Pole_SF, Pole_int];
%                 K_aug=acker(Aaug,Baug,Pole_SF_int);
%                 K_SF=K_aug(1:size(A_d,1));
%                 K_int = K_aug(size(A_d,1)+1:size(K_aug,2));
                
                Q_temp = [0;0;1;0;1]*[0,0,1,0,1];
                Q_temp = [0, 0, 0, 0, 0;
                            0, 0, 0, 0, 0;
                            0, 0, 15, 0, 0;
                            0, 0, 0, 0, 0;
                            0, 0, 0, 0, 0.008];
                K_aug = dlqr(Aaug, Baug, Q_temp, 0.1);
                
                K_SF = K_aug(1:size(A_d,1));
                K_int = K_aug(size(A_d,1)+1:size(K_aug,2));

                TF_yrf=ss(A_d-B_d*K_SF,B_d,C_d,[0],Ts);
                N=1/freqresp(TF_yrf,[0]);  % With integra action, N does not affect steady state, but on transient response
                
                

                AA= [A_d-B_d*K_SF, -B_d*K_int,  B_d*K_SF; C_d, 1, zeros(size(C_d)); zeros(size(A_d)), zeros(size(B_d)), A_d-L_Pred*C_d];
                BB= [B_d*N, B_d, Bw;-1., 0, 0; zeros(size(B_d)), B_d, Bw];
                CC= [C_d, 0, zeros(size(C_d)); -K_SF, -K_int, K_SF; -C_d, 0, zeros(size(C_d))];
                DD= [0 0 0; N 0 0;1, 0 0];
                
                Loop_SF =ss(Aaug,Baug,K_aug,0,Ts)
                
        end  %for statespace design
        
        %SOFC Closed Loop Analysis:
        % input: r,d,w,  state: x, x~, output: y, u, e (e=r-y)
        
        
        SS_closed = ss(AA,BB,CC,DD);
        [NUM,DEN] = tfdata(SS_closed,'v');
        TF=tf(NUM,DEN,Ts);
        
        % input: r,d,w,  state: x, x~, output: y, u, e (e=r-y)
        
        TF_yr=TF(1,1)  ;
        TF_ur=TF(2,1)  ;
        TF_er=TF(3,1) ;
        
        TF_yd=TF(1,2)  ;
        TF_ud=TF(2,2)  ;
        TF_ed=TF(3,2)  ;
        
        TF_yw=TF(1,3)  ;
        TF_uw=TF(2,3)  ;
        TF_ew=TF(3,3) ;
%         figure
%         step(TF_yr,TF_ur)
%         legend('TFyr','TFur');
%         grid
%         figure
%         step(TF_yd,TF_ud)
%         legend('TFyd','TFud');
%          grid
%         figure
%         bode(TF_yr,TF_ur,TF_yd,TF_ud)
%          legend('TFyr','Tur','TFyd','TFud');
%          grid
%         figure
%         bode(TF_yr,TF_ur)
%         legend('TFyr','Tur');
%        grid
%          figure
%          bode(TF_yd,TF_ud)
%         legend('TFyd','TFud');
%         grid
        zpk(TF_yr)
        zpk(TF_ur)
        zpk(TF_yd)
        zpk(TF_ud)
        %Loop Transfer Function Calculation:
        Controller_SF =ss(A_d-B_d*K_SF-L_Pred*C_d,L_Pred,K_SF,0,Ts);
        Controller_int =K_int/(z-1)*(1-ss(A_d-B_d*K_SF-L_Pred*C_d,B_d,K_SF,0,Ts));
        Controller = Controller_SF+Controller_int;
        Loop=Controller*Plant_d;
        
        
        switch (SSdesign)
            case{'state_observer_feedback'}
                state_order= size(A_d,1)+size(A_d,1);
            case{'state_observer_feedback_integral'}
                state_order = size(A_d,1)+size(A_d,1)+1;
        end
        Loop=balred(Loop,state_order);
        zpk(Loop)
        
%          figure
%         nyquist(Loop, Loop_SF);
%          legend('Loop', 'Loop_{SF}');
%         figure
%         bode(Loop, Loop_SF);
%          legend('Loop', 'Loop_{SF}');
%         grid on
%         [Gm,Pm,Wcp,Wcg] = margin(Loop)
%         [Gm_SF,Pm_SF,Wcp_SF,Wcg_SF] = margin(Loop_SF)
        Sensitivity= 1/(1+Loop);
         Sensitivity_SF= 1/(1+Loop_SF);
        zpk(Sensitivity)
        figure;
         bodemag(Sensitivity);
         hold on
         bodemag(Sensitivity_SF);
         hold off
       grid on;
         legend;
        % Find the Sensitivity_peak and frequency Wpeak
        % S_peak = 10^(dB/20)
        % VGM = S_peak/(S_peak - 1)
        
        % Simulation:
        switch (SSdesign)
           case{'state_observer_feedback'}
                switch(pend)
                   case{1}
                  
%                      open('Pendulum_SOFC')
%                      sim('Pendulum_SOFC')
                   case{2}
                     % open('DoublePendulum_SOFC')
                      % sim('DoublePendulum_SOFC')
               end
            case{'state_observer_feedback_integral'}
                switch(pend)
                    case{1}
               
%                        open('project_sim')
                       sim('project_sim')
                    case{2}
                       % open('DoublePendulum_SOFC_integral')
                       % sim('DoublePendulum_SOFC_integral')
                end
        end %for SSdesign simulation
        
        %save('invertedpendulum_simulation_sine_1000.mat', "u_L", "u_NL", "y_L", "y_NL", "w_L", "w_NL");

        %%
        figure
        subplot(2,2,1)
        plot(xhat(:,1) - y_NL)
        title('Y uncontrolled')
        subplot(2,2,2)
        plot(xhat(:,3) - y_C_NL)
        title('Y controlled')
        subplot(2,2,3)
        plot(xhat(:,2) - w_NL)
        title('W uncontrolled')
        subplot(2,2,4)
        plot(xhat(:,4) - w_C_NL)
        title('W controlled')
        %%
        mean_Y_uncontrolled = mean(xhat(:,1) - y_NL)
        mean_Y_controlled = mean(xhat(:,3) - y_C_NL)
        mean_W_uncontrolled = mean(xhat(:,2) - w_NL)
        mean_W_controlled = mean(xhat(:,4) - w_C_NL)
        
        %%
        figure
        subplot(2,1,1)
        plot(r1 - y_NL)
        title('Tracking uncontrolled')
        subplot(2,1,2)
        plot(r1 - y_C_NL)
        title('Tracking controlled')
        
        %%
        mean_tracking_uncontrolled = mean(r1(8000:end) - y_NL(8000:end))
        mean_tracking_controlled = mean(r1(8000:end) - y_C_NL(8000:end))
        
        