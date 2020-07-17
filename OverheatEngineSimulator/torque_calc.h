#pragma once
#include "abstract_torque_calc.h";
#include <vector>;

class TorqueCalc :
    public AbstractTorqueCalc
{

/*
Вспомогательный класс, описывающий один участок кусочно линейной функции
и вычисляющая значение функции на этом участке по формуле y = k*x + b
*/
	class LineEquation {
	public:
		LineEquation(float x1, float y1, float x2, float y2);
		LineEquation(const LineEquation& other);
    	float y(float x);

		float x1() const  { return x1_; }
	private:
		float x1_; // Используется для поиска данного участка в векторе
		float k;
		float b;
	};
	
public:
    TorqueCalc(const std::vector<float>& angularVelocity, const std::vector<float>& torque);
	virtual ~TorqueCalc() override = default;
    // Унаследовано через AbstractTorqueCalc
    virtual float fromAngularVelocity(float angularVelocity) override;

private:
	std::vector<LineEquation> lineEquations;
	float maxAngularVelocity;
};
