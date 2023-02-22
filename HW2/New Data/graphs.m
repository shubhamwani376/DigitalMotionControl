%clear all
close all
%load('lqg_exp_sine_100.mat')

%%
position  = sine_output.extractTimetable.Gain;
%position = nonzeros(position);

input = sine_input.extractTimetable;
input = input.Variables;
%input = nonzeros(input);

%%
plot(0:0.01:5,position(2200:2700), LineWidth=2)
hold on
grid on
plot(0:0.01:5,input(2200:2700), LineWidth=1)
xlabel('Time (sec)')
ylabel('Position (rad)')
legend('Motor Position', 'Reference')
title('Integral + Oscillator 1000Hz')










