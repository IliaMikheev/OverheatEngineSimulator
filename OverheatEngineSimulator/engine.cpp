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
    // ��� ��������� �� ������ ����� ����������� ������ ���������, ����� ����� ���������� ������
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
    float Vh = M * Hm + powf(V, 2) * Hv;  // �������� ������� ��������� 
    float Vc = C * (Ta - Te);              // �������� ���������� ���������
    Te += ( (Vh + Vc) * dt );                  // ����������� ��������� �� ��������� ���� ���������
    V += ( (M / I) * dt );                     // �������� �������� ��������� �� ��������� ���� ��������� 
}
