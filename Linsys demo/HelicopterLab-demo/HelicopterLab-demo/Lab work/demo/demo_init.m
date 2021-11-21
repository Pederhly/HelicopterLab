%% FOR HELICOPTER NR 1-2
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert h�sten 2006 av Jostein Bakkeheim
% Oppdatert h�sten 2008 av Arnfinn Aas Eielsen
% Oppdatert h�sten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring

%% Demo initialization
clear;
clc;

%IMU port
PORT = 4;

%Select which lab to run [1-4]
%REMEMBER TO HOLD THE HELICOPTER AT EQUILIBRIUM POINT FOR LAB 2, 3 AND 4
LabToRun = 4;

%If lab 1, select test [1-8]
Lab1TestToRun = 8;

%Lab 2 task to run: [1-2] (integral action or not)
%1 = No integral action
%2 = Integral action
Lab2TaskToRun = 1;

%Lab 2 test to run: [1-8]
Lab2TestToRun = 7;

%Lab 3 test to run: (1,2,3,5)
Lab3TestToRun = 5;

%Lab 4 test to run (1,2,5,6)
Lab4TestToRun = 6;






%% Global variables used in all exercises
%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;

%%%%%%%%%%% Physical constants
g = 9.81;       % gravitational constant [m/s^2]
l_c = 0.40;     % distance elevation axis to counterweight [m]
l_h = 0.66;     % distance elevation axis to helicopter head [m]
l_p = 0.175;    % distance pitch axis to motor [m]
m_c = 1.92;     % Counterweight mass [kg]
m_p = 0.65;     % Motor mass [kg]

%%%%%%%%%%% Calculated values
Vs_0 = 6;                                   % Voltage offset [V]
k_f = g*(2*m_p*l_h-m_c*l_c)/(Vs_0*l_h);     % Motor constant [N/V]
k_1 = k_f/(2*m_p*l_p);                      % Calculated constant
k_f = g*(2*m_p*l_h-m_c*l_c)/(Vs_0*l_h);     % Motor constant [N/V]
k_2 = (k_f*l_h)/(m_c*l_c^2+2*m_p*l_h^2);    % Elevation acceleration gain (e double dot)
k_3 = g*(m_c*l_c-2*m_p*l_h)/ ...            % Yaw acceleration gain (lambda
    (m_c*l_c^2+2*m_p*(l_h^2+l_p^2));

%System matrices
A = [0 1 0; 0 0 0; 0 0 0];
B = [0 0; 0 k_1; k_2 0];
C = [1 0 0; 0 0 1];
D = zeros(2);

%Augmented system matrices (LQR with integral action)
A_aug = [A zeros(3,2); -C zeros(2)];
B_aug = [B; zeros(2)];
C_aug = [C zeros(2)];
D_aug = D;
G_aug = [0 0; 0 0; 0 0; -1 0; 0 -1];



%% Lab 1-specific code
if LabToRun == 1
    %Controller values
    switch Lab1TestToRun
        
        case 1 %Run test 1
            lambda_1 = -4;          %Pole 1
            lambda_2 = -4;          %Pole 2
            
            
        case 2 %Run test 2
            lambda_1 = -6;          %Pole 1
            lambda_2 = -2;          %Pole 2
        
        case 3 %Run test 3
            lambda_1 = -2;          %Pole 1
            lambda_2 = -6;          %Pole 2
        
        case 4 %Run test 4
            lambda_1 = -12;         %Pole 1
            lambda_2 = -12;         %Pole 2
        
        case 5 %Run test 5
            lambda_1 = -4 + 0.5i;   %Pole 1
            lambda_2 = -4 - 0.5i;   %Pole 2
            
        case 6 %Run test 6
            lambda_1 = -4 + 2i;     %Pole 1
            lambda_2 = -4 - 2i;     %Pole 2
            
        case 7 %Run test 7
            lambda_1 = -2;          %Pole 1
            lambda_2 = -2;          %Pole 2
            
        case 8 %Run test 8
            lambda_1 = -30;         %Pole 1
            lambda_2 = -2;          %Pole 2
    end
    
    %Calculate controller gains
    K_pp = (lambda_1*lambda_2)/k_1;     %Pitch P-gain
    K_pd = -(lambda_1+lambda_2)/k_1;    %Pitch D-gain
    
    %Open Simulink model for lab 1
    open_system('models/lab1_model.slx')
    open_system('lab1_model/Pitch_scope')
end

%% Lab 2 specific code
if LabToRun == 2
    %% Task 1 - Multivariable control matrices and Q_lqr & R_lqr
 
    %Tunable Q and R diagonal values
    if Lab2TaskToRun == 1
        switch Lab2TestToRun
            case 1 %Run test 1
                Q_dig = [1 1 1]; %Pitch, Pitch rate, angle rate
                R_dig = [1 1];   %vs, vd
            case 2 %Run test 2
                Q_dig = [40 1 1];
                R_dig = [1 1];
            case 3 %Run test 3
                Q_dig = [400 1 1];
                R_dig = [1 1];
            case 4 %Run test 4
                Q_dig = [400 50 1];
                R_dig = [1 1];
            case 5 %Run test 5
                Q_dig = [400 50 400];
                R_dig = [1 1];
            case 6 %Run test 6
                Q_dig = [400 50 400];
                R_dig = [1/20 1];
            case 7 %Run test 7
                Q_dig = [400 50 400];
                R_dig = [1 1/5];
            case 8 %Run test 8
                Q_dig = [400 50 400];
                R_dig = [1/5 1];
        end
        
    %Calculate Q and R
    Q = eye(3).*Q_dig;
    R = eye(2).*R_dig;    
    
    %LQR controller
    [K,S,e] = lqr(A,B,Q,R);

    %Feed forward gain matrix
    F = (C*(B*K-A)^-1*B)^-1;
    
    %Open Simulink model for lab 2, task 1
    open_system('models/lab2_task1_model.slx')
    open_system('lab2_task1_model/Controller_scope')
    end 
    
    %% Task 2 Augmented control matrices
    if Lab2TaskToRun == 2
        %Tunable Q and R diagonal values 
        %%FIX THIS NOT DONE
        %%XOXOXOXOXOXOXOXOXOXOXOXOXOXXOXOXOXOXOXOXXOXOXOXO
            switch Lab2TestToRun
                case 1 %Run test 1
                    Q_aug_dig = [400 50 400 1 1]; %Pitch, Pitch rate, angle rate
                    R_aug_dig = [0.2 1];   %vs, vd
                case 2 %Run test 2
                    Q_aug_dig = [400 50 400 200 200];
                    R_aug_dig = [0.2 1];
                case 3 %Run test 3
                    Q_aug_dig = [400 50 400 1 200];
                    R_aug_dig = [0.2 1];
                case 4 %Run test 4
                    Q_aug_dig = [400 50 400 1 400];
                    R_aug_dig = [0.2 1];
                case 5 %Run test 5
                    Q_aug_dig = [400 50 400 1 200];
                    R_aug_dig = [0.2 1];
                case 6 %Run test 6
                    Q_aug_dig = [400 50 400 1 100];
                    R_aug_dig = [0.2 1];
                case 7 %Run test 7
                    Q_aug_dig = [400 50 400 1 100];
                    R_aug_dig = [0.2 1];
                case 8 %Run test 8
                    Q_aug_dig = [40 10 40 1 10];
                    R_aug_dig = [0.05 1];
            end
        
        %Calculate Q and R
        Q_aug = eye(5).*Q_aug_dig;
        R_aug = eye(2).*R_aug_dig;

        %LQR controller
        [K_aug,S_aug,e_aug] = lqr(A_aug,B_aug,Q_aug,R_aug);

        %Feed forward gain matrix
        F_aug = (C*(B*K_aug(:,1:3)-A)^-1*B)^-1;

        %Open Simulink model for lab 2, task 2
        open_system('models/lab2_task2_model.slx')
        open_system('lab2_task2_model/Controller_scope')
    end
end

%% Lab 3 specific code
if LabToRun == 3
    %LQR controller parameters
    Q_aug_dig = [40 10 40 1 10];%Pitch, Pitch rate, angle rate, pitch integral, elevation rate integral
    R_aug_dig = [0.05 1];       %Vs Vd
    Q_aug = eye(5).*Q_aug_dig;
    R_aug = eye(2).*R_aug_dig;

    %LQR controller
    [K_aug,S_aug,e_aug] = lqr(A_aug,B_aug,Q_aug,R_aug);
    F_aug = (C*(B*K_aug(:,1:3)-A)^-1*B)^-1;

    %Estimator
    A_est = [0 1 0 0 0; 0 0 0 0 0; 0 0 0 1 0; 0 0 0 0 0; k_3 0 0 0 0];
    B_est = [0 0 0 k_2 0; 0 k_1 0 0 0]';
    C_est = eye(5);
    %C_est = [1 0 0 0 0;0 0 1 0 0; 0 0 0 1 0; 0 0 0 0 1];

    
    %Estimator pole placement
    switch Lab3TestToRun
        case 1 %Run test 1
            P_est = [-5 -5 -5 -5 -5];
        case 2 %Run test 2
            P_est = [-15 -15 -15 -15 -15];
        case 3 %Run test 3
            P_est = [-30 -30 -30 -30 -30];
        case 5 %Run test 5
            P_est = [(-20-20i) (-20+20i) (-20+20i) (-20-20i) -20];
    end

    
    %Observer gain
    L = place(A_est',C_est',P_est)';
    
    %Open Simulink model for lab 3
    open_system('models/lab3_model.slx')
    open_system('lab3_model/Estimate_vs_encoder')
end

%% Lab 4 specific code
if LabToRun == 4
    %LQR controller parameters
    Q_aug_dig = [40 10 40 1 10];%Pitch, Pitch rate, angle rate, pitch integral, elevation rate integral
    R_aug_dig = [0.05 1];       %Vs Vd
    Q_aug = eye(5).*Q_aug_dig;
    R_aug = eye(2).*R_aug_dig;

    %LQR controller
    [K_aug,S_aug,e_aug] = lqr(A_aug,B_aug,Q_aug,R_aug);
    F_aug = (C*(B*K_aug(:,1:3)-A)^-1*B)^-1;
    
    %Continous system matrices
    A_c = zeros(6); A_c(1,2) = 1; A_c(3,4) = 1; A_c(6,1) = k_3;
    B_c = zeros(6,2); B_c(2,2) = k_1; B_c(4,1) = k_2;
    C_c = [eye(5) zeros(5,1)]; C_c(5,5) = 0; C_c(5,6) = 1;
    D_c = zeros(5,2);
    
    %Transform to discrete state-space model
    ss_c = ss(A_c,B_c,C_c,D_c);
    [ss_d,~] = c2d(ss_c, 0.002);

    %Discrete system matricres
    A_d = ss_d.A;
    B_d = ss_d.B;
    C_d = ss_d.C;
    D_d = ss_d.D;

    %Initial values
    P_init_pred = zeros(6);
    X_init_pred = zeros(6,1); X_init_pred(3,1) = -0.4189;

    switch Lab4TestToRun
        case 1 %Run test 1
            Q_d = zeros(6);
        case 2 %Run test 2
            Q_d = 1000*eye(6);
        case 5 %Run test 5
            Q_d = 0.008.*eye(6).*[1 0.5 1 1 1 1]';
        case 6
            Q_d = 0.0001.*eye(6).*[1 0.5 1 1 1 1]';
    end
    %Measurement covariance matrix (experiamentally found by hovering at equilibrium point)
    R_d = [ 0.0028    0.0035    0.0028   -0.0042    0.0013;
            0.0035    0.0308    0.0172   -0.0103   -0.0238;
            0.0028    0.0172    0.0123   -0.0071   -0.0098;
           -0.0042   -0.0103   -0.0071    0.0149    0.0040;
            0.0013   -0.0238   -0.0098    0.0040    0.0773];
    open_system('models/lab4_model.slx')
    open_system('lab4_model/Estimat_vs_encoder1')
    
end


