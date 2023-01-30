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
load("finalworkspace.mat")
time10 = linspace(0,10,101)';
time100 = linspace(0,10,1001)';
time1000 = linspace(0,10,10001)';
figure(1)
hold on
% red 10, green 100, blue 1000, L normal, NL dashed
plot(time10,smooth(L_u_10Hz),'r',time100,smooth(L_u_100Hz),'g',time1000,smooth(L_u_1000Hz),'b')
plot(time10,smooth(NL_u_10Hz),'r--',time100,smooth(NL_u_100Hz),'g--',time1000,smooth(NL_u_1000Hz),'b--')
legend("Linear 10 Hz","Linear 100 Hz","Linear 1000 Hz","Non Linear 10 Hz","Non Linear 100 Hz","Non Linear 1000 Hz")
title("Input u")
xlim([0 2])

figure(2)
hold on
% red 10, green 100, blue 1000, L normal, NL dashed
plot(time10,smooth(L_y_10Hz),'r',time100,smooth(L_y_100Hz),'g',time1000,smooth(L_y_1000Hz),'b')
plot(time10,smooth(NL_y_10Hz),'r--',time100,smooth(NL_y_100Hz),'g--',time1000,smooth(NL_y_1000Hz),'b--')
legend("Linear 10 Hz","Linear 100 Hz","Linear 1000 Hz","Non Linear 10 Hz","Non Linear 100 Hz","Non Linear 1000 Hz")
title("Output y")
xlim([0 2])

L_w_10Hz = interp1(L_w_10Hz.Time,L_w_10Hz.Data,time10,'nearest');
L_w_100Hz = interp1(L_w_100Hz.Time,L_w_100Hz.Data,time100,'nearest');
L_w_1000Hz = interp1(L_w_1000Hz.Time,L_w_1000Hz.Data,time1000,'nearest');
NL_w_10Hz = interp1(NL_w_10Hz.Time,NL_w_10Hz.Data,time10,'nearest');
NL_w_100Hz = interp1(NL_w_100Hz.Time,NL_w_100Hz.Data,time100,'nearest');
NL_w_1000Hz = interp1(NL_w_1000Hz.Time,NL_w_1000Hz.Data,time1000,'nearest');

figure(3)
hold on
% red 10, green 100, blue 1000, L normal, NL dashed
plot(time10,smooth(L_w_10Hz),'r',time100,smooth(L_w_100Hz),'g',time1000,smooth(L_w_1000Hz),'b')
plot(time10,smooth(NL_w_10Hz),'r--',time100,smooth(NL_w_100Hz),'g--',time1000,smooth(NL_w_1000Hz),'b--')
legend("Linear 10 Hz","Linear 100 Hz","Linear 1000 Hz","Non Linear 10 Hz","Non Linear 100 Hz","Non Linear 1000 Hz")
title("Velocity w")
xlim([0 2])