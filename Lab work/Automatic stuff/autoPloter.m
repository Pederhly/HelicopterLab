function [figHandle] = autoPloter(file_struct,rows)
%AUTOPLOTER Summary of this function goes here
%   Detailed explanation goes here
var = file_struct.var;
time_row = var(1,:);

var_To_Plot = var(rows,:);
plot(time_row,var_To_Plot);
figHandle = gca;
grid
end