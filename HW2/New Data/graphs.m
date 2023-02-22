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
plot(0:0.001:5,position(11790:16790), LineWidth=2)
hold on
grid on
plot(0:0.001:5,input(11790:16790), LineWidth=1)
xlabel('Time (sec)')
ylabel('Position (rad)')
legend('Motor Position', 'Reference')
title('Integral + Oscillator 1000Hz')










