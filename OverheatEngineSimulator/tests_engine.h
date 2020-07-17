#pragma once

#include <memory>
#include <utility>
#include <string>
#include "abstract_engine.h"

/* ������ ������������ ��������� �� ��������.
   ������ �������.
   ���������� �� ���� ���������,    (�����, ������� ��������� 
   ����������� ����� AbstractEngine) � ��������� ���������

   ������� ���������� ����� � ��������� ���������
   � �������� ���������� �����. 
*/
std::pair<float, std::string> overheadEngineTest(
	std::shared_ptr<AbstractEngine> engine,
	float simulationStep,
	float overheatTempreche,
	float ambientTempreche
);