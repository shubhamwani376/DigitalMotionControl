% clc; clear all; 
% matfiles = dir('*.mat') ; 
% N = length(matfiles) ; 
% iwant = cell(N,1) ;  % to save output 
% for i = 1:N
%     clc;clear;
%     load(matfiles(i).name)
%     % do what you want, let out put be out
%     matfiles(i).nameiwant{i} = out
% end
clf;clc; clear;

load("L_encp_10Hz.mat")
temp = data.extractTimetable;
t1 = temp.Time;
t2 = temp.Gain;

timeL10Hz = t1(3054:13054)-duration(0,0,13.51);
L_encp_10Hz = t2(3054:13054);

load("L_encv_10Hz.mat")
temp = data.extractTimetable;
t2 = temp.("Discrete Derivative");
L_encv_10Hz = t2(3054:13054);

load("L_input_10Hz.mat")
temp = data.extractTimetable;
t1 = temp.Time;
t2 = temp.Mux3(:,2);
L_input_10Hz = t2(31:131);

%%% 

load("L_encp_100Hz.mat")
temp = data.extractTimetable;
t1 = temp.Time;
t2 = temp.Gain;

timeL100Hz = t1(16729:end)-duration(0,0,31.937);
L_encp_100Hz = t2(16729:end);

load("L_encv_100Hz.mat")
temp = data.extractTimetable;
t2 = temp.("Discrete Derivative");
L_encv_100Hz = t2(16729:end);

load("L_input_100Hz.mat")
temp = data.extractTimetable;
t1 = temp.Time;
t2 = temp.Mux3(:,2);
L_input_100Hz = t2(1:end);

%%%

load("L_encp_1000Hz.mat")
temp = data.extractTimetable;
t1 = temp.Time;
t2 = temp.Gain;

timeL1000Hz = t1(27548:37548)-duration(0,0,39.588);
L_encp_1000Hz = t2(27548:37548);

% load("L_encv_1000Hz.mat")
% temp = data.extractTimetable;
% t2 = temp.("Discrete Derivative");
% L_encv_1000Hz = t2(27548:37548);

load("L_input_1000Hz.mat")
temp = data.extractTimetable;
t1 = temp.Time;
t2 = temp.Mux3(27548:37548,2);
L_input_1000Hz = t2;


figure(1)
hold on
% red 10, green 100, blue 1000, L normal, NL dashed
plot(timeL10Hz,smooth(L_encp_10Hz),'r',timeL100Hz,smooth(L_encp_100Hz),'g',timeL1000Hz,smooth(L_encp_1000Hz),'b')
% plot(time10,smooth(NL_u_10Hz),'r--',time100,smooth(NL_u_100Hz),'g--',time1000,smooth(NL_u_1000Hz),'b--')
legend("Linear 10 Hz","Linear 100 Hz","Linear 1000 Hz")
title("Position u")
%%%

figure(2)
hold on
% red 10, green 100, blue 1000, L normal, NL dashed
plot(timeL10Hz,smooth(L_encv_10Hz),'r',timeL100Hz,smooth(L_encv_100Hz),'g')
% plot(time10,smooth(NL_u_10Hz),'r--',time100,smooth(NL_u_100Hz),'g--',time1000,smooth(NL_u_1000Hz),'b--')
legend("Linear 10 Hz","Linear 100 Hz")
title("Velocity u")
