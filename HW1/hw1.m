close all; clc; clear;
load("encposition_step_normalized_second.mat");
position = data.extractTimetable.Sum2;
position = position(18000:end);
timep = 0.001;
time = (0:timep:(size(position)/1000))';
%plot(position);

% hold on
vel = smooth(diff(position)/timep)*(2*pi()/400);
plot(time(1:end-2),vel)
ylabel("Angular Velocity(rad/sec)");
xlabel("Time(sec)");
%scatter(time(2:end),vel, 'filled');

% f = fittype('k*(exp(-x/tau))');
% [fit1,gof,fitinfo] = fit(time(3:end),vel,f,'StartPoint',[5 70]);
% %params = fittype(k/(t*s + 1))
% stepinfo(vel)

% load("encposition_step_normalized_third.mat");
% position = data.extractTimetable.Sum2;
% position = position(6216:12000);
% timep = 0.001;
% time = (0:timep:12.000-6.216)';
% % plot(position);
% % hold on
% vel = smooth(diff(position)/timep)*(2*pi()/400);
% scatter(time(2:end),vel, 'filled');
% 
% f = fittype('k*(1 - exp(-x/tau))');
% [fit1,gof,fitinfo] = fit(time(2:end),vel,f,'StartPoint',[427 0.2]);
% %params = fittype(k/(t*s + 1))
% % [transferfunc, f] = tfestimate(ones(10807,1), vel);
% % %plot(f,mag2db(abs(transferfunc)));