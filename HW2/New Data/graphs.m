clear all
close all
load('lqg_exp_square_100.mat')
position  = plant_output_square.extractTimetable.Gain;
%position = nonzeros(position);

input = square_input.extractTimetable;
input = input.Variables;
%input = nonzeros(input);

%%
plot(0:0.001:10,position(3600:13600), LineWidth=2)
hold on
grid on
plot(0:0.001:10,input(3600:13600), LineWidth=1)
xlabel('Time (sec)')
ylabel('Position (rad)')
legend('Motor Position', 'Reference')
title('LQG 100Hz')










