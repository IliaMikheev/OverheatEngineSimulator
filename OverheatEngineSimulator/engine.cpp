#include "engine.h"

Engine::Engine(
    float inertia,
    std::shared_ptr<AbstractTorqueCalc> torqueCalc,
    float heatOfTorque,
    float heatOfVelocity,
    float cooling,
    float ambientTempreche,
    float simulationStep)
    : AbstractEngine(ambientTempreche, simulationStep)
    , I(inertia)
    , Hm(heatOfTorque)
    , Hv(heatOfVelocity)
    , C(cooling)
    , torqueCalc(torqueCalc)
{
    // Раз двигатель не должен иметь специальной логики включения, пусть сразу генерирует момент
    M = torqueCalc->fromAngularVelocity(V); 
}

void Engine::reset()
{
    Te = Ta;
    V = 0;
    M = torqueCalc->fromAngularVelocity(V);
}

void Engine::progress()
{
    float M = torqueCalc->fromAngularVelocity(V);
    float Vh = M * Hm + powf(V, 2) * Hv;  // Скорость нагрева двигателя 
    float Vc = C * (Ta - Te);              // Скорость охлаждения двигателя
    Te += ( (Vh + Vc) * dt );                  // Температура двигателя на следующем шаге симуляции
    V += ( (M / I) * dt );                     // Скорость вращения коленвала на следующем шаге симуляции 
}
