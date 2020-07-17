#pragma once

#include <memory>
#include <utility>
#include <string>
#include "abstract_engine.h"

/* Логика тестирования двигателя на перегрев.
   Просто функция.
   Принисмает на вход двигатель,    (любой, который реализует 
   абстрактный класс AbstractEngine) и параметры симуляции

   которая возвращает время и текстовое сообщение
   о причинах завершения теста. 
*/
std::pair<float, std::string> overheadEngineTest(
	std::shared_ptr<AbstractEngine> engine,
	float simulationStep,
	float overheatTempreche,
	float ambientTempreche
);