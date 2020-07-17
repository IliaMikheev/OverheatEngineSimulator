#pragma once
class AbstractEngine
{
public:
    AbstractEngine(float ambientTempreche, float simulationStep);
    void setAmbientTempreche(float ambientTempreche);   
    void setSimulationStep(float simulationStep);       

    virtual void reset() = 0;                           // �������� ��������� � ��������� ��������� ��� ������ �����
    virtual void progress() = 0;                        // ������ ��������� ���������� ��� ���������� ���� ���������

    float tempreche() const;                            
    float angularVelocity() const;                      
    float torque() const;                               

protected:
    float Ta;     // ����������� ���������� �����
    float dt;     // ��� �������������, ���
    float Te;     // ����������� ���������        T- tempreche e - engine
    float V;      // ������� �������� �������� ��������� (���/�)
    float M;      // �������� ������ �� ���� ����� ����� ����������� � ��� ����������
};

