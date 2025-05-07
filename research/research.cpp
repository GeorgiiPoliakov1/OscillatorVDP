#include "../OscillatorVDP.h"
#include "../Visualization.h"


void testEuler(){
    OscillatorVDP oscillatorE1(2);

    oscillatorE1.euler(0, 100, 0.5, 0.0, 0.1, "points/graphics/Euler1.txt");
    drawPhaseTrajectory(oscillatorE1.getXCoords(), oscillatorE1.getYCoords(), "График фазовой траектории (метод Эйлера)", "images/graphics/EulerPhase1.jpeg");
    drawTimeTrajectory(oscillatorE1.getTimeCoords(), oscillatorE1.getXCoords(), "График зависимости x от t (метод Эйлера)", "images/graphics/EulerTime1.jpeg");

    OscillatorVDP oscillatorE2(2);

    oscillatorE2.euler(0, 100, 0.5, 0.0, 0.01, "points/graphics/Euler2.txt");
    drawPhaseTrajectory(oscillatorE2.getXCoords(), oscillatorE2.getYCoords(), "График фазовой траектории (метод Эйлера)", "images/graphics/EulerPhase2.jpeg");
    drawTimeTrajectory(oscillatorE2.getTimeCoords(), oscillatorE2.getXCoords(), "График зависимости x от t (метод Эйлера)", "images/graphics/EulerTime2.jpeg");

    OscillatorVDP oscillatorE3(2);

    oscillatorE3.euler(0, 100, 0.5, 0.0, 0.001, "points/graphics/Euler3.txt");
    drawPhaseTrajectory(oscillatorE3.getXCoords(), oscillatorE3.getYCoords(), "График фазовой траектории (метод Эйлера)", "images/graphics/EulerPhase3.jpeg");
    drawTimeTrajectory(oscillatorE3.getTimeCoords(), oscillatorE3.getXCoords(), "График зависимости x от t (метод Эйлера)", "images/graphics/EulerTime3.jpeg");

    oscillatorE1 = OscillatorVDP(0);

    oscillatorE1.euler(0, 100, 0.5, 0.0, 0.1, "points/ellipse/Euler1.txt");
    drawPhaseTrajectory(oscillatorE1.getXCoords(), oscillatorE1.getYCoords(), "График фазовой траектории (метод Эйлера)", "images/ellipse/EulerPhase1.jpeg");
    drawTimeTrajectory(oscillatorE1.getTimeCoords(), oscillatorE1.getXCoords(), "График зависимости x от t (метод Эйлера)", "images/ellipse/EulerTime1.jpeg");

    oscillatorE2 = OscillatorVDP(0);

    oscillatorE2.euler(0, 100, 0.5, 0.0, 0.01, "points/ellipse/Euler2.txt");
    drawPhaseTrajectory(oscillatorE2.getXCoords(), oscillatorE2.getYCoords(), "График фазовой траектории (метод Эйлера)", "images/ellipse/EulerPhase2.jpeg");
    drawTimeTrajectory(oscillatorE2.getTimeCoords(), oscillatorE2.getXCoords(), "График зависимости x от t (метод Эйлера)", "images/ellipse/EulerTime2.jpeg");

    oscillatorE3 = OscillatorVDP(0);

    oscillatorE3.euler(0, 100, 0.5, 0.0, 0.001, "points/ellipse/Euler3.txt");
    drawPhaseTrajectory(oscillatorE3.getXCoords(), oscillatorE3.getYCoords(), "График фазовой траектории (метод Эйлера)", "images/ellipse/EulerPhase3.jpeg");
    drawTimeTrajectory(oscillatorE3.getTimeCoords(), oscillatorE3.getXCoords(), "График зависимости x от t (метод Эйлера)", "images/ellipse/EulerTime3.jpeg");
}

void testMidpoint(){
    OscillatorVDP oscillatorM1(2); 
    oscillatorM1.midpoint(0, 100, 0.5, 0.0, 0.1, "points/graphics/Midpoint1.txt");
    drawPhaseTrajectory(oscillatorM1.getXCoords(), oscillatorM1.getYCoords(), "График фазовой траектории (метод средней точки)", "images/graphics/MidpointPhase1.jpeg");
    drawTimeTrajectory(oscillatorM1.getTimeCoords(), oscillatorM1.getXCoords(), "График зависимости x от t (метод средней точки)", "images/graphics/MidpointTime1.jpeg");

    OscillatorVDP oscillatorM2(2); 
    oscillatorM2.midpoint(0, 100, 0.5, 0.0, 0.01, "points/graphics/Midpoint2.txt");
    drawPhaseTrajectory(oscillatorM2.getXCoords(), oscillatorM2.getYCoords(), "График фазовой траектории (метод средней точки)", "images/graphics/MidpointPhase2.jpeg");
    drawTimeTrajectory(oscillatorM2.getTimeCoords(), oscillatorM2.getXCoords(), "График зависимости x от t (метод средней точки)", "images/graphics/MidpointTime2.jpeg");

    OscillatorVDP oscillatorM3(2); 
    oscillatorM3.midpoint(0, 100, 0.5, 0.0, 0.001, "points/graphics/Midpoint3.txt");
    drawPhaseTrajectory(oscillatorM3.getXCoords(), oscillatorM3.getYCoords(), "График фазовой траектории (метод средней точки)", "images/graphics/MidpointPhase3.jpeg");
    drawTimeTrajectory(oscillatorM3.getTimeCoords(), oscillatorM3.getXCoords(), "График зависимости x от t (метод средней точки)", "images/graphics/MidpointTime3.jpeg");

    oscillatorM1 = OscillatorVDP(0); 
    oscillatorM1.midpoint(0, 100, 0.5, 0.0, 0.1, "points/ellipse/Midpoint1.txt");
    drawPhaseTrajectory(oscillatorM1.getXCoords(), oscillatorM1.getYCoords(), "График фазовой траектории (метод средней точки)", "images/ellipse/MidpointPhase1.jpeg");
    drawTimeTrajectory(oscillatorM1.getTimeCoords(), oscillatorM1.getXCoords(), "График зависимости x от t (метод средней точки)", "images/ellipse/MidpointTime1.jpeg");

    oscillatorM2 = OscillatorVDP(0); 
    oscillatorM2.midpoint(0, 100, 0.5, 0.0, 0.01, "points/ellipse/Midpoint2.txt");
    drawPhaseTrajectory(oscillatorM2.getXCoords(), oscillatorM2.getYCoords(), "График фазовой траектории (метод средней точки)", "images/ellipse/MidpointPhase2.jpeg");
    drawTimeTrajectory(oscillatorM2.getTimeCoords(), oscillatorM2.getXCoords(), "График зависимости x от t (метод средней точки)", "images/ellipse/MidpointTime2.jpeg");

    oscillatorM3 = OscillatorVDP(0); 
    oscillatorM3.midpoint(0, 100, 0.5, 0.0, 0.001, "points/ellipse/Midpoint3.txt");
    drawPhaseTrajectory(oscillatorM3.getXCoords(), oscillatorM3.getYCoords(), "График фазовой траектории (метод средней точки)", "images/ellipse/MidpointPhase3.jpeg");
    drawTimeTrajectory(oscillatorM3.getTimeCoords(), oscillatorM3.getXCoords(), "График зависимости x от t (метод средней точки)", "images/ellipse/MidpointTime3.jpeg");
    
}

void testRK4(){
    OscillatorVDP oscillatorRK4(2); 
    oscillatorRK4.RK4(0, 100, 0.5, 0.0, 0.1, "points/graphics/RK4_1.txt");
    drawPhaseTrajectory(oscillatorRK4.getXCoords(), oscillatorRK4.getYCoords(), "График фазовой траектории (метод рунге-кутты 4-го порядка)", "images/graphics/RK4Phase1.jpeg");
    drawTimeTrajectory(oscillatorRK4.getTimeCoords(), oscillatorRK4.getXCoords(), "График зависимости x от t (метод рунге-кутты 4-го порядка)", "images/graphics/RK4Time1.jpeg");

    OscillatorVDP oscillatorRK4_2(2); 
    oscillatorRK4_2.RK4(0, 100, 0.5, 0.0, 0.01, "points/graphics/RK4_2.txt");
    drawPhaseTrajectory(oscillatorRK4_2.getXCoords(), oscillatorRK4_2.getYCoords(), "График фазовой траектории (метод рунге-кутты 4-го порядка)", "images/graphics/RK4Phase2.jpeg");
    drawTimeTrajectory(oscillatorRK4_2.getTimeCoords(), oscillatorRK4_2.getXCoords(), "График зависимости x от t (метод рунге-кутты 4-го порядка)", "images/graphics/RK4Time2.jpeg");

    OscillatorVDP oscillatorRK4_3(2); 
    oscillatorRK4_3.RK4(0, 100, 0.5, 0.0, 0.001, "points/graphics/RK4_3.txt");
    drawPhaseTrajectory(oscillatorRK4_3.getXCoords(), oscillatorRK4_3.getYCoords(), "График фазовой траектории (метод рунге-кутты 4-го порядка)", "images/graphics/RK4Phase3.jpeg");
    drawTimeTrajectory(oscillatorRK4_3.getTimeCoords(), oscillatorRK4_3.getXCoords(), "График зависимости x от t (метод рунге-кутты 4-го порядка)", "images/graphics/RK4Time3.jpeg");

    oscillatorRK4 = OscillatorVDP(0); 
    oscillatorRK4.RK4(0, 100, 0.5, 0.0, 0.1, "points/ellipse/RK4_1.txt");
    drawPhaseTrajectory(oscillatorRK4.getXCoords(), oscillatorRK4.getYCoords(), "График фазовой траектории (метод рунге-кутты 4-го порядка)", "images/ellipse/RK4Phase1.jpeg");
    drawTimeTrajectory(oscillatorRK4.getTimeCoords(), oscillatorRK4.getXCoords(), "График зависимости x от t (метод рунге-кутты 4-го порядка)", "images/ellipse/RK4Time1.jpeg");

    oscillatorRK4_2 = OscillatorVDP(0); 
    oscillatorRK4_2.RK4(0, 100, 0.5, 0.0, 0.01, "points/ellipse/RK4_2.txt");
    drawPhaseTrajectory(oscillatorRK4_2.getXCoords(), oscillatorRK4_2.getYCoords(), "График фазовой траектории (метод рунге-кутты 4-го порядка)", "images/ellipse/RK4Phase2.jpeg");
    drawTimeTrajectory(oscillatorRK4_2.getTimeCoords(), oscillatorRK4_2.getXCoords(), "График зависимости x от t (метод рунге-кутты 4-го порядка)", "images/ellipse/RK4Time2.jpeg");

    oscillatorRK4_3 = OscillatorVDP(0); 
    oscillatorRK4_3.RK4(0, 100, 0.5, 0.0, 0.001, "points/ellipse/RK4_3.txt");
    drawPhaseTrajectory(oscillatorRK4_3.getXCoords(), oscillatorRK4_3.getYCoords(), "График фазовой траектории (метод рунге-кутты 4-го порядка)", "images/ellipse/RK4Phase3.jpeg");
    drawTimeTrajectory(oscillatorRK4_3.getTimeCoords(), oscillatorRK4_3.getXCoords(), "График зависимости x от t (метод рунге-кутты 4-го порядка)", "images/ellipse/RK4Time3.jpeg");
}

void testImplicitMidpoint(){
    OscillatorVDP oscillatorImpM(2); 
    oscillatorImpM.implicitMidpoint(0, 100, 0.5, 0.0, 0.1, "points/graphics/ImpM1.txt");
    drawPhaseTrajectory(oscillatorImpM.getXCoords(), oscillatorImpM.getYCoords(), "График фазовой траектории (неявный метод средней точки)", "images/graphics/ImpMPhase1.jpeg");
    drawTimeTrajectory(oscillatorImpM.getTimeCoords(), oscillatorImpM.getXCoords(), "График зависимости x от t (неявный метод средней точки)", "images/graphics/ImpMTime1.jpeg");

    OscillatorVDP oscillatorImpM2(2); 
    oscillatorImpM2.implicitMidpoint(0, 100, 0.5, 0.0, 0.01, "points/graphics/ImpM2.txt");
    drawPhaseTrajectory(oscillatorImpM2.getXCoords(), oscillatorImpM2.getYCoords(), "График фазовой траектории (неявный метод средней точки)", "images/graphics/ImpMPhase2.jpeg");
    drawTimeTrajectory(oscillatorImpM2.getTimeCoords(), oscillatorImpM2.getXCoords(), "График зависимости x от t (неявный метод средней точки)", "images/graphics/ImpMTime2.jpeg");

    OscillatorVDP oscillatorImpM3(2); 
    oscillatorImpM3.implicitMidpoint(0, 100, 0.5, 0.0, 0.001, "points/graphics/ImpM3.txt");
    drawPhaseTrajectory(oscillatorImpM3.getXCoords(), oscillatorImpM3.getYCoords(), "График фазовой траектории (неявный метод средней точки)", "images/graphics/ImpMPhase3.jpeg");
    drawTimeTrajectory(oscillatorImpM3.getTimeCoords(), oscillatorImpM3.getXCoords(), "График зависимости x от t (неявный метод средней точки)", "images/graphics/ImpMTime3.jpeg");

    oscillatorImpM = OscillatorVDP(0); 
    oscillatorImpM.implicitMidpoint(0, 100, 0.5, 0.0, 0.1, "points/ellipse/ImpM1.txt");
    drawPhaseTrajectory(oscillatorImpM.getXCoords(), oscillatorImpM.getYCoords(), "График фазовой траектории (неявный метод средней точки)", "images/ellipse/ImpMPhase1.jpeg");
    drawTimeTrajectory(oscillatorImpM.getTimeCoords(), oscillatorImpM.getXCoords(), "График зависимости x от t (неявный метод средней точки)", "images/ellipse/ImpMTime1.jpeg");

    oscillatorImpM2 = OscillatorVDP(0); 
    oscillatorImpM2.implicitMidpoint(0, 100, 0.5, 0.0, 0.01, "points/ellipse/ImpM2.txt");
    drawPhaseTrajectory(oscillatorImpM2.getXCoords(), oscillatorImpM2.getYCoords(), "График фазовой траектории (неявный метод средней точки)", "images/ellipse/ImpMPhase2.jpeg");
    drawTimeTrajectory(oscillatorImpM2.getTimeCoords(), oscillatorImpM2.getXCoords(), "График зависимости x от t (неявный метод средней точки)", "images/ellipse/ImpMTime2.jpeg");

    oscillatorImpM3 = OscillatorVDP(0); 
    oscillatorImpM3.implicitMidpoint(0, 100, 0.5, 0.0, 0.001, "points/ellipse/ImpM3.txt");
    drawPhaseTrajectory(oscillatorImpM3.getXCoords(), oscillatorImpM3.getYCoords(), "График фазовой траектории (неявный метод средней точки)", "images/ellipse/ImpMPhase3.jpeg");
    drawTimeTrajectory(oscillatorImpM3.getTimeCoords(), oscillatorImpM3.getXCoords(), "График зависимости x от t (неявный метод средней точки)", "images/ellipse/ImpMTime3.jpeg");
}

void testImplicitTrapezoid(){
    OscillatorVDP oscillatorImpTr(2); 
    oscillatorImpTr.implicitTrapezoid(0, 100, 0.5, 0.0, 0.1, "points/graphics/ImpTr1.txt");
    drawPhaseTrajectory(oscillatorImpTr.getXCoords(), oscillatorImpTr.getYCoords(), "График фазовой траектории (неявный метод трапеций)", "images/graphics/ImpTrPhase1.jpeg");
    drawTimeTrajectory(oscillatorImpTr.getTimeCoords(), oscillatorImpTr.getXCoords(), "График зависимости x от t (неявный метод трапеций)", "images/graphics/ImpTrTime1.jpeg");

    OscillatorVDP oscillatorImpTr2(2); 
    oscillatorImpTr2.implicitTrapezoid(0, 100, 0.5, 0.0, 0.01, "points/graphics/ImpTr2.txt");
    drawPhaseTrajectory(oscillatorImpTr2.getXCoords(), oscillatorImpTr2.getYCoords(), "График фазовой траектории (неявный метод трапеций)", "images/graphics/ImpTrPhase2.jpeg");
    drawTimeTrajectory(oscillatorImpTr2.getTimeCoords(), oscillatorImpTr2.getXCoords(), "График зависимости x от t (неявный метод трапеций)", "images/graphics/ImpTrTime2.jpeg");

    OscillatorVDP oscillatorImpTr3(2); 
    oscillatorImpTr3.implicitTrapezoid(0, 100, 0.5, 0.0, 0.001, "points/graphics/ImpTr3.txt");
    drawPhaseTrajectory(oscillatorImpTr3.getXCoords(), oscillatorImpTr3.getYCoords(), "График фазовой траектории (неявный метод трапеций)", "images/graphics/ImpTrPhase3.jpeg");
    drawTimeTrajectory(oscillatorImpTr3.getTimeCoords(), oscillatorImpTr3.getXCoords(), "График зависимости x от t (неявный метод трапеций)", "images/graphics/ImpTrTime3.jpeg");

    oscillatorImpTr = OscillatorVDP(0); 
    oscillatorImpTr.implicitTrapezoid(0, 100, 0.5, 0.0, 0.1, "points/ellipse/ImpTr1.txt");
    drawPhaseTrajectory(oscillatorImpTr.getXCoords(), oscillatorImpTr.getYCoords(), "График фазовой траектории (неявный метод трапеций)", "images/ellipse/ImpTrPhase1.jpeg");
    drawTimeTrajectory(oscillatorImpTr.getTimeCoords(), oscillatorImpTr.getXCoords(), "График зависимости x от t (неявный метод трапеций)", "images/ellipse/ImpTrTime1.jpeg");

    oscillatorImpTr2 = OscillatorVDP(0); 
    oscillatorImpTr2.implicitTrapezoid(0, 100, 0.5, 0.0, 0.01, "points/ellipse/ImpTr2.txt");
    drawPhaseTrajectory(oscillatorImpTr2.getXCoords(), oscillatorImpTr2.getYCoords(), "График фазовой траектории (неявный метод трапеций)", "images/ellipse/ImpTrPhase2.jpeg");
    drawTimeTrajectory(oscillatorImpTr2.getTimeCoords(), oscillatorImpTr2.getXCoords(), "График зависимости x от t (неявный метод трапеций)", "images/ellipse/ImpTrTime2.jpeg");

    oscillatorImpTr3 = OscillatorVDP(0); 
    oscillatorImpTr3.implicitTrapezoid(0, 100, 0.5, 0.0, 0.001, "points/ellipse/ImpTr3.txt");
    drawPhaseTrajectory(oscillatorImpTr3.getXCoords(), oscillatorImpTr3.getYCoords(), "График фазовой траектории (неявный метод трапеций)", "images/ellipse/ImpTrPhase3.jpeg");
    drawTimeTrajectory(oscillatorImpTr3.getTimeCoords(), oscillatorImpTr3.getXCoords(), "График зависимости x от t (неявный метод трапеций)", "images/ellipse/ImpTrTime3.jpeg");
}

void testABM2(){
    OscillatorVDP oscillatorABM2(2); 
    oscillatorABM2.ABM2(0, 100, 0.5, 0.0, 0.1, "points/graphics/ABM2_1.txt");
    drawPhaseTrajectory(oscillatorABM2.getXCoords(), oscillatorABM2.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 2 порядка)", "images/graphics/ABM2Phase1.jpeg");
    drawTimeTrajectory(oscillatorABM2.getTimeCoords(), oscillatorABM2.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 2 порядка)", "images/graphics/ABM2Time1.jpeg");

    OscillatorVDP oscillatorABM22(2); 
    oscillatorABM22.ABM2(0, 100, 0.5, 0.0, 0.01, "points/graphics/ABM2_2.txt");
    drawPhaseTrajectory(oscillatorABM22.getXCoords(), oscillatorABM22.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 2 порядка)", "images/graphics/ABM2Phase2.jpeg");
    drawTimeTrajectory(oscillatorABM22.getTimeCoords(), oscillatorABM22.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 2 порядка)", "images/graphics/ABM2Time2.jpeg");

    OscillatorVDP oscillatorABM23(2); 
    oscillatorABM23.ABM2(0, 100, 0.5, 0.0, 0.001, "points/graphics/ABM2_3.txt");
    drawPhaseTrajectory(oscillatorABM23.getXCoords(), oscillatorABM23.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 2 порядка)", "images/graphics/ABM2Phase3.jpeg");
    drawTimeTrajectory(oscillatorABM23.getTimeCoords(), oscillatorABM23.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 2 порядка)", "images/graphics/ABM2Time3.jpeg");

    oscillatorABM2 = OscillatorVDP(0); 
    oscillatorABM2.ABM2(0, 100, 0.5, 0.0, 0.1, "points/ellipse/ABM2_1.txt");
    drawPhaseTrajectory(oscillatorABM2.getXCoords(), oscillatorABM2.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 2 порядка)", "images/ellipse/ABM2Phase1.jpeg");
    drawTimeTrajectory(oscillatorABM2.getTimeCoords(), oscillatorABM2.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 2 порядка)", "images/ellipse/ABM2Time1.jpeg");

    oscillatorABM22 = OscillatorVDP(0); 
    oscillatorABM22.ABM2(0, 100, 0.5, 0.0, 0.01, "points/ellipse/ABM2_2.txt");
    drawPhaseTrajectory(oscillatorABM22.getXCoords(), oscillatorABM22.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 2 порядка)", "images/ellipse/ABM2Phase2.jpeg");
    drawTimeTrajectory(oscillatorABM22.getTimeCoords(), oscillatorABM22.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 2 порядка)", "images/ellipse/ABM2Time2.jpeg");

    oscillatorABM23 = OscillatorVDP(0); 
    oscillatorABM23.ABM2(0, 100, 0.5, 0.0, 0.001, "points/ellipse/ABM2_3.txt");
    drawPhaseTrajectory(oscillatorABM23.getXCoords(), oscillatorABM23.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 2 порядка)", "images/ellipse/ABM2Phase3.jpeg");
    drawTimeTrajectory(oscillatorABM23.getTimeCoords(), oscillatorABM23.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 2 порядка)", "images/ellipse/ABM2Time3.jpeg");
}

void testABM4(){
    OscillatorVDP oscillatorABM4(2); 
    oscillatorABM4.ABM4(0, 100, 0.5, 0.0, 0.1, "points/graphics/ABM4_1.txt");
    drawPhaseTrajectory(oscillatorABM4.getXCoords(), oscillatorABM4.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 4 порядка)", "images/graphics/ABM4Phase1.jpeg");
    drawTimeTrajectory(oscillatorABM4.getTimeCoords(), oscillatorABM4.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 4 порядка)", "images/graphics/ABM4Time1.jpeg");

    OscillatorVDP oscillatorABM42(2); 
    oscillatorABM42.ABM4(0, 100, 0.5, 0.0, 0.01, "points/graphics/ABM4_2.txt");
    drawPhaseTrajectory(oscillatorABM42.getXCoords(), oscillatorABM42.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 4 порядка)", "images/graphics/ABM4Phase2.jpeg");
    drawTimeTrajectory(oscillatorABM42.getTimeCoords(), oscillatorABM42.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 4 порядка)", "images/graphics/ABM4Time2.jpeg");

    OscillatorVDP oscillatorABM43(2); 
    oscillatorABM43.ABM4(0, 100, 0.5, 0.0, 0.001, "points/graphics/ABM4_3.txt");
    drawPhaseTrajectory(oscillatorABM43.getXCoords(), oscillatorABM43.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 4 порядка)", "images/graphics/ABM4Phase3.jpeg");
    drawTimeTrajectory(oscillatorABM43.getTimeCoords(), oscillatorABM43.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 4 порядка)", "images/graphics/ABM4Time3.jpeg");

    oscillatorABM4 = OscillatorVDP(0); 
    oscillatorABM4.ABM4(0, 100, 0.5, 0.0, 0.1, "points/ellipse/ABM4_1.txt");
    drawPhaseTrajectory(oscillatorABM4.getXCoords(), oscillatorABM4.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 4 порядка)", "images/ellipse/ABM4Phase1.jpeg");
    drawTimeTrajectory(oscillatorABM4.getTimeCoords(), oscillatorABM4.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 4 порядка)", "images/ellipse/ABM4Time1.jpeg");

    oscillatorABM42 = OscillatorVDP(0); 
    oscillatorABM42.ABM4(0, 100, 0.5, 0.0, 0.01, "points/ellipse/ABM4_2.txt");
    drawPhaseTrajectory(oscillatorABM42.getXCoords(), oscillatorABM42.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 4 порядка)", "images/ellipse/ABM4Phase2.jpeg");
    drawTimeTrajectory(oscillatorABM42.getTimeCoords(), oscillatorABM42.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 4 порядка)", "images/ellipse/ABM4Time2.jpeg");

    oscillatorABM43 = OscillatorVDP(0); 
    oscillatorABM43.ABM4(0, 100, 0.5, 0.0, 0.001, "points/ellipse/ABM4_3.txt");
    drawPhaseTrajectory(oscillatorABM43.getXCoords(), oscillatorABM43.getYCoords(), "График фазовой траектории (метод Адамса-Башфорта-Мултона 4 порядка)", "images/ellipse/ABM4Phase3.jpeg");
    drawTimeTrajectory(oscillatorABM43.getTimeCoords(), oscillatorABM43.getXCoords(), "График зависимости x от t (метод Адамса-Башфорта-Мултона 4 порядка)", "images/ellipse/ABM4Time3.jpeg");
}

struct MethodData {
    string name;
    vector<double> t;
    vector<double> errors;
    string color;
};

vector<tuple<double, double, double>> readData(const string& filename) {
    vector<tuple<double, double, double>> data;
    ifstream file(filename);
    double t, x, y;
    
    while (file >> t >> x >> y) {
        data.emplace_back(t, x, y);
    }
    return data;
}


vector<double> calculateRMSE(
    const vector<tuple<double, double, double>>& reference,
    const vector<tuple<double, double, double>>& method
) {
    vector<double> errors;
    for (size_t i = 0; i < min(reference.size(), method.size()); i++) {
        double dx = get<1>(method[i]) - get<1>(reference[i]);
        double dy = get<2>(method[i]) - get<2>(reference[i]);
        errors.push_back(sqrt(dx*dx + dy*dy));
    }
    return errors;
}

void drawCombinedErrorGraph(
    const vector<MethodData>& all_methods,
    const string& filename
) {
    Gnuplot gp;
    gp << "set terminal jpeg enhanced size 1200,800\n";
    gp << "set output '" << filename << "'\n";
    gp << "set title 'Сравнение ошибок методов'\n";
    gp << "set xlabel 'Время t'\n";
    gp << "set ylabel 'RMSE'\n";
    gp << "set grid\n";
    gp << "set key outside right center\n";
    gp << "set logscale y\n"; 
    string plot_cmd = "plot ";
    for (size_t i = 0; i < all_methods.size(); ++i) {
        plot_cmd += "'-' with lines title '" + all_methods[i].name + 
                   "' lw 2 lc rgb '" + all_methods[i].color + "'";
        if (i != all_methods.size()-1) plot_cmd += ", ";
    }
    gp << plot_cmd << endl;
    for (const auto& method : all_methods) {
        gp.send1d(make_pair(method.t, method.errors));
    }
}

int main() {
    vector<string> colors = {
        "#FF0000", "#00FF00", "#0000FF", 
        "#FF00FF", "#00FFFF", "#FFA500"
    };

    auto ref_data = readData("points/graphics/RK4_3.txt");
    vector<double> t_ref;
    for (const auto& point : ref_data) {
        t_ref.push_back(get<0>(point));
    }
    vector<MethodData> all_methods;
    vector<pair<string, string>> methods = {
        {"Euler", "Euler3.txt"},
        {"Midpoint", "Midpoint3.txt"},
        {"ImpMidpoint", "ImpM3.txt"},
        {"ImpTrapezoid", "ImpTr3.txt"},
        {"ABM2", "ABM2_3.txt"},
        {"ABM4", "ABM4_3.txt"}
    };
    for (size_t i = 0; i < methods.size(); ++i) {
        auto method_data = readData("points/graphics/" + methods[i].second);
        auto errors = calculateRMSE(ref_data, method_data);
        
        MethodData md;
        md.name = methods[i].first;
        md.t = vector<double>(t_ref.begin(), t_ref.begin() + errors.size());
        md.errors = errors;
        md.color = colors[i % colors.size()];
        
        all_methods.push_back(md);
    }
    drawCombinedErrorGraph(all_methods, "images/graphics/combined_errors_3.jpg");
    return 0;
}