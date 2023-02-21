clear all
close all
load('pendulum_integral_sine_1000.mat')
position  = plant_output.extractTimetable.Gain;
position = nonzeros(position);

input = sine_input.extractTimetable;
input = input.Variables;
input = nonzeros(input);

%%
plot(0:0.001:10,position(1:10001), LineWidth=2)
hold on
grid on
plot(0:0.001:10,input(1:10001), LineWidth=1)
xlabel('Time (sec)')
ylabel('Position (rad)')
legend('Motor Position', 'Reference')
title('Integral 1000Hz')










