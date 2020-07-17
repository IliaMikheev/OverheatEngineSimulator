#include "torque_calc.h"
#include <stdexcept>
#include <algorithm>

using namespace std;


TorqueCalc::TorqueCalc(const std::vector<float>& angularVelocity, const std::vector<float>& torque)
{
	if (angularVelocity.size() != torque.size()) {
		throw invalid_argument("Torque/velocity lookup table: the sizes of the vectors of torque and angular velocity are unequal");
	}

	if (angularVelocity.size() < 2) {
		throw invalid_argument("Torque/velocity lookup table: number of points less than 2");
	}

	if (!is_sorted(begin(angularVelocity), end(angularVelocity))) {
		throw invalid_argument("Torque/velocity lookup table: angular velocity vector must be sorted in ascending order");
	}

	// Создать вектор кусочно-ломаных функций
	for (size_t i = 0; i < angularVelocity.size() - 1; ++i) {
		lineEquations.push_back(LineEquation(angularVelocity[i], torque[i],
				angularVelocity[i + 1], torque[i + 1]));
	}
	maxAngularVelocity = angularVelocity.back();

}

float TorqueCalc::fromAngularVelocity(float angularVelocity)
{
	// Поиск первого элемента кусочно ломанной, на котором угловая скорость точно больше, 
	// чем заданная (потом перейдём к предыдущему элементу)
	auto lineIt = upper_bound(lineEquations.begin(), lineEquations.end(), angularVelocity, 
		[](float av, const TorqueCalc::LineEquation& item) { return av < item.x1();  });   
	// Проверка принадлежности заданной угловой скорости к кусочно ломанной характеристике.
	// Заданная точка может лежать правее, или левее, чем вся кусочно ломанная. Тогда вернём 0.
	if (lineIt == lineEquations.begin() || angularVelocity > maxAngularVelocity) {
		return 0.0f;
	}
	return (--lineIt)->y(angularVelocity);
}

TorqueCalc::LineEquation::LineEquation(float x1, float y1, float x2, float y2)
	: x1_(x1)
	, k((y2 - y1) / (x2 - x1))
	, b(y2 - k * x2)
{
}
/**/
TorqueCalc::LineEquation::LineEquation(const LineEquation& other)
{
	x1_ = other.x1_;
	k = other.k;
	b = other.b;
}

float TorqueCalc::LineEquation::y(float x)
{
	return k* x + b;
}
