#pragma once
class AbstractEngine
{
public:
    AbstractEngine(float ambientTempreche, float simulationStep);
    void setAmbientTempreche(float ambientTempreche);   
    void setSimulationStep(float simulationStep);       

    virtual void reset() = 0;                           // Приводит двигатель в начальное состояние для нового теста
    virtual void progress() = 0;                        // Расчет изменения параметров для следующего шака симуляции

    float tempreche() const;                            
    float angularVelocity() const;                      
    float torque() const;                               

protected:
    float Ta;     // Температура окрушающей среды
    float dt;     // Шаг моделирования, сек
    float Te;     // Температура двигателя        T- tempreche e - engine
    float V;      // Угловая скорость вращения коленвала (рад/с)
    float M;      // Крутящий момент на валу Пусть будет возможность и его возвращать
};

