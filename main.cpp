#include "OscillatorVDP.h"
#include "Visualization.h"


void makeGraphics(){
    OscillatorVDP oscillatorE(2);
    oscillatorE.euler(0, 100, 0.5, 0.0, 0.001, "points/graphics/Euler.txt");
    drawPhaseTrajectory(oscillatorE.getXCoords(), oscillatorE.getYCoords(), "График фазовой траектории (метод Эйлера)", "images/graphics/EulerPhase.jpeg");
    drawTimeTrajectory(oscillatorE.getTimeCoords(), oscillatorE.getXCoords(), "График зависимости x от t (метод Эйлера)", "images/graphics/EulerTime.jpeg");
    visualizePhaseTrajectory(oscillatorE.getXCoords(), oscillatorE.getYCoords(), "Аницмация фазовой траектории (метод Эйлера)", "gifs/EulerPhase.gif");

    OscillatorVDP oscillatorM(2); 
    oscillatorM.midpoint(0, 100, 0.5, 0.0, 0.001, "points/graphics/Midpoint.txt");
    drawPhaseTrajectory(oscillatorM.getXCoords(), oscillatorM.getYCoords(), "График фазовой траектории (метод средней точки)", "images/graphics/MidpointPhase.jpeg");
    drawTimeTrajectory(oscillatorM.getTimeCoords(), oscillatorM.getXCoords(), "График зависимости x от t (метод средней точки)", "images/graphics/MidpointTime.jpeg");
    visualizePhaseTrajectory(oscillatorM.getXCoords(), oscillatorM.getYCoords(), "Анимация фазовой траектории (метод средней точки)", "gifs/MidpointPhase.gif");

    OscillatorVDP oscillatorRK4(2);
    oscillatorRK4.RK4(0, 100, 0.5, 0.0, 0.001, "points/graphics/RK4.txt");
    drawPhaseTrajectory(oscillatorRK4.getXCoords(), oscillatorRK4.getYCoords(), "График фазовой траектории (метод рунге-кутты 4-го порядка)", "images/graphics/RK4Phase.jpeg");
    drawTimeTrajectory(oscillatorRK4.getTimeCoords(), oscillatorRK4.getXCoords(), "График зависимости x от t (метод рунге-кутты 4-го порядка)", "images/graphics/RK4Time.jpeg");
    visualizePhaseTrajectory(oscillatorRK4.getXCoords(), oscillatorRK4.getYCoords(), "Анимация фазовой траектории (метод рунге-кутты 4-го порядка)", "gifs/RK4Phase.gif");

    OscillatorVDP oscillatorImpM(2);
    oscillatorImpM.implicitMidpoint(0, 100, 0.5, 0.0, 0.001, "points/graphics/ImpMid.txt");
    drawPhaseTrajectory(oscillatorImpM.getXCoords(), oscillatorImpM.getYCoords(), "График фазовой траектории (неявный метод средней точки)", "images/graphics/ImpMidPhase.jpeg");
    drawTimeTrajectory(oscillatorImpM.getTimeCoords(), oscillatorImpM.getXCoords(), "График зависимости x от t (неявный метод средней точки)", "images/graphics/ImpMidTime.jpeg");
    visualizePhaseTrajectory(oscillatorImpM.getXCoords(), oscillatorImpM.getYCoords(), "Анимация фазовой траектории (неявный метод средней точки)", "gifs/ImpMidPhase.gif");

    OscillatorVDP oscillatorImpTr(2);
    oscillatorImpTr.implicitTrapezoid(0, 100, 0.5, 0.0, 0.001, "points/graphics/ImpTr.txt");
    drawPhaseTrajectory(oscillatorImpTr.getXCoords(), oscillatorImpTr.getYCoords(), "График фазовой траектории (неявный метод трапеций)", "images/graphics/ImpTrPhase.jpeg");
    drawTimeTrajectory(oscillatorImpTr.getTimeCoords(), oscillatorImpTr.getXCoords(), "График зависимости x от t (неявный метод трапеций)", "images/graphics/ImpTrTime.jpeg");
    visualizePhaseTrajectory(oscillatorImpTr.getXCoords(), oscillatorImpTr.getYCoords(), "Анимация фазовой траектории (неявный метод трапеций)", "gifs/ImpTrPhase.gif");

    OscillatorVDP oscillatorABM2(2);
    oscillatorABM2.ABM2(0, 100, 0.5, 0.0, 0.001, "points/graphics/ABM2.txt");
    drawPhaseTrajectory(oscillatorABM2.getXCoords(), oscillatorABM2.getYCoords(), "График фазовой траектории (неявный метод Адамса-Башфорта-Мултона 2-го порядка)", "images/graphics/ABM2Phase.jpeg");
    drawTimeTrajectory(oscillatorABM2.getTimeCoords(), oscillatorABM2.getXCoords(), "График зависимости x от t (неявный метод Адамса-Башфорта-Мултона 2-го порядка)", "images/graphics/ABM2Time.jpeg");
    visualizePhaseTrajectory(oscillatorABM2.getXCoords(), oscillatorABM2.getYCoords(), "Анимация фазовой траектории (неявный метод Адамса-Башфорта-Мултона 2-го порядка)", "gifs/ABM2Phase.gif");

    OscillatorVDP oscillatorABM4(2);
    oscillatorABM4.ABM4(0, 100, 0.5, 0.0, 0.001, "points/graphics/ABM4.txt");
    drawPhaseTrajectory(oscillatorABM4.getXCoords(), oscillatorABM4.getYCoords(), "График фазовой траектории (неявный метод Адамса-Башфорта-Мултона 4-го порядка)", "images/graphics/ABM4Phase.jpeg");
    drawTimeTrajectory(oscillatorABM4.getTimeCoords(), oscillatorABM4.getXCoords(), "График зависимости x от t(неявный метод Адамса-Башфорта-Мултона 4-го порядка)", "images/graphics/ABM4Time.jpeg");
    visualizePhaseTrajectory(oscillatorABM4.getXCoords(), oscillatorABM4.getYCoords(), "Анимация фазовой траектории (неявный метод Адамса-Башфорта-Мултона 4-го порядка)", "gifs/ABM4Phase.gif");

    OscillatorVDP oscillatorEmHe(2);
    oscillatorEmHe.emHeunEulerAdaptive(0, 100, 0.5, 0.0, 0.001, "points/graphics/EmHeunEuler.txt");
    drawPhaseTrajectory(oscillatorEmHe.getXCoords(), oscillatorEmHe.getYCoords(), "График фазовой траектории (вложенный метод Хойна Эйлера 2(1))", "images/graphics/EmHeunEulerPhase.jpeg");
    drawTimeTrajectory(oscillatorEmHe.getTimeCoords(), oscillatorEmHe.getXCoords(), "График зависимости x от t (вложенный метод Хойна Эйлера 2(1))", "images/graphics/EmHeunEulerTime.jpeg");
    visualizePhaseTrajectory(oscillatorEmHe.getXCoords(), oscillatorEmHe.getYCoords(), "Анимация фазовой траектории (вложенный метод Хойна Эйлера 2(1))", "gifs/EmHeunEulerPhase.gif");
}

void makeEllipses(){
    OscillatorVDP oscillatorE(0);
    oscillatorE.euler(0, 100, 0.5, 0.0, 0.001, "points/ellipse/Euler.txt");
    drawPhaseTrajectory(oscillatorE.getXCoords(), oscillatorE.getYCoords(), "График фазовой траектории (метод Эйлера)", "images/ellipse/EulerPhase.jpeg");
    drawTimeTrajectory(oscillatorE.getTimeCoords(), oscillatorE.getXCoords(), "График зависимости x от t (метод Эйлера)", "images/ellipse/EulerTime.jpeg");

    OscillatorVDP oscillatorM(0); 
    oscillatorM.midpoint(0, 100, 0.5, 0.0, 0.001, "points/ellipse/Midpoint.txt");
    drawPhaseTrajectory(oscillatorM.getXCoords(), oscillatorM.getYCoords(), "График фазовой траектории (метод средней точки)", "images/ellipse/MidpointPhase.jpeg");
    drawTimeTrajectory(oscillatorM.getTimeCoords(), oscillatorM.getXCoords(), "График зависимости x от t (метод средней точки)", "images/ellipse/MidpointTime.jpeg");

    OscillatorVDP oscillatorRK4(0);
    oscillatorRK4.RK4(0, 100, 0.5, 0.0, 0.001, "points/ellipse/RK4.txt");
    drawPhaseTrajectory(oscillatorRK4.getXCoords(), oscillatorRK4.getYCoords(), "График фазовой траектории (метод рунге-кутты 4-го порядка)", "images/ellipse/RK4Phase.jpeg");
    drawTimeTrajectory(oscillatorRK4.getTimeCoords(), oscillatorRK4.getXCoords(), "График зависимости x от t (метод рунге-кутты 4-го порядка)", "images/ellipse/RK4Time.jpeg");


    OscillatorVDP oscillatorImpM(0);
    oscillatorImpM.implicitMidpoint(0, 100, 0.5, 0.0, 0.001, "points/ellipse/ImpMid.txt");
    drawPhaseTrajectory(oscillatorImpM.getXCoords(), oscillatorImpM.getYCoords(), "График фазовой траектории (неявный метод средней точки)", "images/ellipse/ImpMidPhase.jpeg");
    drawTimeTrajectory(oscillatorImpM.getTimeCoords(), oscillatorImpM.getXCoords(), "График зависимости x от t (неявный метод средней точки)", "images/ellipse/ImpMidTime.jpeg");

    OscillatorVDP oscillatorImpTr(0);
    oscillatorImpTr.implicitTrapezoid(0, 100, 0.5, 0.0, 0.001, "points/ellipse/ImpTr.txt");
    drawPhaseTrajectory(oscillatorImpTr.getXCoords(), oscillatorImpTr.getYCoords(), "График фазовой траектории (неявный метод трапеций)", "images/ellipse/ImpTrPhase.jpeg");
    drawTimeTrajectory(oscillatorImpTr.getTimeCoords(), oscillatorImpTr.getXCoords(), "График зависимости x от t (неявный метод трапеций)", "images/ellipse/ImpTrTime.jpeg");
    
    OscillatorVDP oscillatorABM2(0);
    oscillatorABM2.ABM2(0, 100, 0.5, 0.0, 0.001, "points/ellipse/ABM2.txt");
    drawPhaseTrajectory(oscillatorABM2.getXCoords(), oscillatorABM2.getYCoords(), "График фазовой траектории (неявный метод Адамса-Башфорта-Мултона 2-го порядка)", "images/ellipse/ABM2Phase.jpeg");
    drawTimeTrajectory(oscillatorABM2.getTimeCoords(), oscillatorABM2.getXCoords(), "График зависимости x от t(неявный метод Адамса-Башфорта-Мултона 2-го порядка)", "images/ellipse/ABM2Time.jpeg");

    OscillatorVDP oscillatorABM4(0);
    oscillatorABM4.ABM4(0, 100, 0.5, 0.0, 0.001, "points/ellipse/ABM4.txt");
    drawPhaseTrajectory(oscillatorABM4.getXCoords(), oscillatorABM4.getYCoords(), "График фазовой траектории (неявный метод Адамса-Башфорта-Мултона 4-го порядка)", "images/ellipse/ABM4Phase.jpeg");
    drawTimeTrajectory(oscillatorABM4.getTimeCoords(), oscillatorABM4.getXCoords(), "График зависимости x от t (неявный метод Адамса-Башфорта-Мултона 4-го порядка)", "images/ellipse/ABM4Time.jpeg");

    OscillatorVDP oscillatorEmHe(0);
    oscillatorEmHe.emHeunEulerAdaptive(0, 100, 0.5, 0.0, 0.001, "points/ellipse/EmHeunEuler.txt");
    drawPhaseTrajectory(oscillatorEmHe.getXCoords(), oscillatorEmHe.getYCoords(), "График фазовой траектории (вложенный метод Хойна Эйлера 2(1))", "images/ellipse/EmHeunEulerPhase.jpeg");
    drawTimeTrajectory(oscillatorEmHe.getTimeCoords(), oscillatorEmHe.getXCoords(), "График зависимости x от t (вложенный метод Хойна Эйлера 2(1))", "images/ellipse/EmHeunEulerTime.jpeg");
}

int main(){
    makeGraphics();
    makeEllipses();
    plotMuVariation(0, 4, 1,
        0, 100, 0.5, 0.0, 0.001, "images/graphics/MuVariation.jpeg"); 
}