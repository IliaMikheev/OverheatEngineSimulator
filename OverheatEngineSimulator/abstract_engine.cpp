#include "abstract_engine.h"

AbstractEngine::AbstractEngine(float ambientTempreche, float simulationStep)
	: Ta(ambientTempreche)
	, dt(simulationStep)
	, Te(ambientTempreche)
	, V(0.0f)
	, M(0.0f)
{
}

void AbstractEngine::setAmbientTempreche(float ambientTempreche)
{
	Ta = ambientTempreche;
}

void AbstractEngine::setSimulationStep(float simulationStep)
{
	dt = simulationStep;
}

float AbstractEngine::tempreche() const
{
	return Te;
}

float AbstractEngine::angularVelocity() const
{
	return V;
}

float AbstractEngine::torque() const
{
	return M;
}
