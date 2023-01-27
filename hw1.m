close all;
%load("encposition_step_normalized_second.mat");
position = data.extractTimetable.Sum2;
position = position(5193:16000);
timep = 0.001;
time = (0:timep:16.000-5.193)';
%plot(position);
% hold on
vel = smooth(diff(position)/timep)*(2*pi()/400);
% plot(vel,'*');

f = fittype('k*(1 - exp(-x/tau))');
[fit1,gof,fitinfo] = fit(time(2:end),vel,f,'StartPoint',[427 0.2]);
%params = fittype(k/(t*s + 1))
stepinfo(vel)

[transferfunc, f] = tfestimate(ones(10807,1), vel);
plot(f,mag2db(abs(transferfunc)));