% To automaticly run a number of tests

number_Of_Tests = 2; %Enter number of tests
%insert matrix of all test paramteres 
testMatrix = ...
[1	1	1	1	1;
40	1	1	1	1;
40	10	1	1	1;
1	20	1	1	1;
1	1	40	1	1;
1	1	1	20	1;
1	1	1	1	20;
1	1	1	1000	1000;
40	40	40	1	1;
1	1	1	20	20];
    
[row,col]=size(testMatrix);
for n=1:row
    %Run script with 
    sim('Model_Name',Simulation_Time)

end