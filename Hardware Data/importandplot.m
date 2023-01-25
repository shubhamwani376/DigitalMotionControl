clc; clear all; 
matfiles = dir('*.mat') ; 
N = length(matfiles) ; 
iwant = cell(N,1) ;  % to save output 
for i = 1:N
    load(matfiles(i).name)
    % do what you want, let out put be out
    iwant{i} = out
end