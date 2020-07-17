#pragma once

#include <memory>
#include <math.h>
#include "abstract_engine.h"
#include "abstract_torque_calc.h"
class Engine :
    public AbstractEngine
{
public:
    Engine(
        float inertia,
        std::shared_ptr<AbstractTorqueCalc> torqueFunction,
        float heatOfTorque,
        float heatOfVelocity,
        float cooling,
        float ambientTempreche = 21,
        float simulationStep = 1.0f
    );

    // Унаследовано через AbstractEngine
    virtual void reset() override;          // Приводит двигатель в начальное состояние для нового теста
    virtual void progress() override;       // Расчет изменения параметров для следующего шака симуляции

private:
    float I;      // Момент инерции 
    float Hm;     // Коэффициент зависимости скорости нагрева от крутящего момента 
    float Hv;     // Коэффициент зависимости скорости нагрева от скорости вращения коленвала
    float C;      // Коэффициент зависимости скорости охлаждения от температуры окружающей среды  
    std::shared_ptr<AbstractTorqueCalc> torqueCalc;
};

