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

    // ������������ ����� AbstractEngine
    virtual void reset() override;          // �������� ��������� � ��������� ��������� ��� ������ �����
    virtual void progress() override;       // ������ ��������� ���������� ��� ���������� ���� ���������

private:
    float I;      // ������ ������� 
    float Hm;     // ����������� ����������� �������� ������� �� ��������� ������� 
    float Hv;     // ����������� ����������� �������� ������� �� �������� �������� ���������
    float C;      // ����������� ����������� �������� ���������� �� ����������� ���������� �����  
    std::shared_ptr<AbstractTorqueCalc> torqueCalc;
};

