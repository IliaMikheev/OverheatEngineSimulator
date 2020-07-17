// OverheatEngineSimulator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "tests_engine.h"
#include "engine.h"
#include "torque_calc.h"
#include <vector>

using namespace std;

// Исходные данные 
const float I = 10;								            // ‎Момент инерции двигателя, кг·м²
const std::vector<float> M{ 20, 75, 100, 105,  75,   0 };   // Крутящий момент (Н*м) для кусочно-линейной зависимости, 
const std::vector<float> V{ 0, 75, 150, 200, 250, 300 };    // Скорость вращения (рад/сек) для кусочно-линейной зависимости
const float T_OVER = 110;							        // Температура перегрева
const float H_M = 0.01;                                     // Коэффициент зависимости скорости нагрева от крутящего момента (С/H*m*cек)
const float H_V = 0.0001;                                   // Коэффициент зависимости скорости нагрева от скорости вращения коленвала (С*сек/рад^2)
const float C = 0.1;                                        // Коэффициент зависимости скорости охлаждения двигателя от разницы температур (С/cек)
const float SIMULATION_STEP = 1.0f;                         // Шаг симуляции (сек) 

int main()
{
    try {
        // Пользовательский ввод
        float ambientTempreche;
        if (!(cin >> ambientTempreche)) { // Допустим, пользователь ввёл какой то текст вместо числа
            throw invalid_argument("Incorrect user input");
        }
        // Создание двигателя
        shared_ptr<Engine> engine = make_shared<Engine>(
            I,
            make_shared<TorqueCalc>(V, M),  // can throw invalid_argument
            H_M,
            H_V,
            C);
        // Симуляция
        auto result = overheadEngineTest(engine, SIMULATION_STEP, T_OVER, ambientTempreche);

        // Вывод результатов
        cout << result.second << " Simulation time: " << result.first << endl;
    }
    catch (invalid_argument& e) {
        // Или - вывод сообщения об ошибке в исходных данных
        cout << e.what() << endl;
    }
}