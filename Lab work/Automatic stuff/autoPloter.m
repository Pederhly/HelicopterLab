function [figHandle] = autoPloter(matFile,rows,endTime)
%AUTOPLOTER Summary of this function goes here
%   Detailed explanation goes here
file_struct = load(matFile);
var = file_struct.var;
time_row = var(1,:);
if exist('endTime', 'var')
    %edit stop time
    endTimeNr=find( time_row >= endTime, 1 );
    time_row=time_row(1, 1:endTimeNr);
    var_To_Plot = var(rows,1:endTimeNr);
else
    var_To_Plot = var(rows,:);
end

plot(time_row,var_To_Plot);
figHandle = gca;
grid
endTime=time_row(length(time_row));
figHandle.XLim=[0,endTime];

end