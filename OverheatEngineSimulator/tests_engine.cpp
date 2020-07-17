#include "tests_engine.h"

std::pair<float, std::string> overheadEngineTest(
	std::shared_ptr<AbstractEngine> engine,
	float simulationStep,
	float overheatTempreche, 
	float ambientTempreche)
{
	engine->setSimulationStep(simulationStep);
	engine->setAmbientTempreche(ambientTempreche);
	engine->reset();

	float t = 0.0f;                                        // Время. В секундах. При необходимости - с долями секунд
	float previousTempreche = engine->tempreche();         // 
	float previousVelocity = engine->angularVelocity();

	while (engine->tempreche() < overheatTempreche) {
		engine->progress();		
		t += simulationStep;
		/* Если температура не растет, и скорость вращения не растёт, а перегрев
		   ещё не наступил, значит он и не наступит. Если это так - нужно завершить симуляцию.
		*/
		float nextTempreche = engine->tempreche();
		float nextVelocity = engine->angularVelocity();

		if (nextTempreche <= previousTempreche &&
			nextVelocity <= previousVelocity)
		{
			return{ t, "The maximum speed is reached, but the temperature doesn`t rise. "
				"Overheating isn`t possible." };
		}
		previousTempreche = nextTempreche;
		previousVelocity = nextVelocity;
	}
	return { t, "Overheating reached." };
}
