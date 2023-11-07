#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "Error.h"
#include "Leaderboard.h"
#include "VehiclesAndTracks.h"


int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int type;
    double dist;

    std::vector <Vehicles::Race_for_land_and_air_transport*> all_vehicle;

    for (;;) {

        for (;;) {
            std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
            std::cout << "1. Гонка для наземного транспорта" << std::endl;
            std::cout << "2. Гонка для воздушного транспорта" << std::endl;
            std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
            std::cout << "Выберите тип гонки: ";
            try {
                std::cin >> type;
                if (type < 0 || type > 3) {
                    throw Error::Error("Неизвестный тип гонки, попробуйте снова");
                }
                else {
                    system("CLS");
                    break;
                }
            }
            catch (Error::Error& ex) {
                system("CLS");
                std::cout << ex.get_error() << std::endl;
                system("PAUSE");
                system("CLS");
            }
        }

        for (;;) {
            std::cout << "Укажите длину дистранции (должна быть положительной): ";
            try {
                std::cin >> dist;
                if (dist < 0) {
                    throw Error::Error("Дистанция должна быть положительной, попробуйте снова");
                }
                else {
                    system("CLS");
                    break;
                }
            }
            catch (Error::Error& ex) {
                system("CLS");
                std::cout << ex.get_error() << std::endl;
                system("PAUSE");
                system("CLS");
            }
        }

        switch (type) {
        case 1:
            all_vehicle.push_back(new Vehicles::Race_for_land_transport);
            break;
        case 2:
            all_vehicle.push_back(new Vehicles::Race_for_air_transport);
            break;
        case 3:
            all_vehicle.push_back(new Vehicles::Race_for_land_and_air_transport);
            break;
        }

        std::cout << "Зарегестрируйте хотя бы два транспортных средства" << std::endl;
        system("PAUSE");
        system("CLS");

        int temp = type;
        type = 0;

        for (std::vector <int> temp2;;) {
            std::cout << all_vehicle[0]->get_name() << ". " << "Расстояние: " << dist << std::endl;
            if (all_vehicle.size() > 1) {
                std::cout << "Зарегистрированные транспортные средства: ";
                for (int i = 1; i < all_vehicle.size(); ++i) {
                    if (i == all_vehicle.size() - 1) {
                        std::cout << all_vehicle[i]->get_name() << std::endl;
                    }
                    else {
                        std::cout << all_vehicle[i]->get_name() << ", ";
                    }
                }
            }
            std::cout << "1. Ботинки-вездеходы" << std::endl;
            std::cout << "2. Метла" << std::endl;
            std::cout << "3. Верблюд" << std::endl;
            std::cout << "4. Кентавр" << std::endl;
            std::cout << "5. Орел" << std::endl;
            std::cout << "6. Верблюд-быстроход" << std::endl;
            std::cout << "7. Ковер-самолет" << std::endl;
            std::cout << "0. Закончить регистрацию" << std::endl;
            std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";

            try {
                std::cin >> type;

                system("CLS");
                if (type == 0) {
                    if (temp2.size() > 1) {
                        for (;;) {
                            std::cout << "1. Зарегистрировать транспорт" << std::endl;
                            std::cout << "2. Начать гонку" << std::endl;
                            std::cout << "Выберите действие: ";
                            try {
                                std::cin >> type;
                                if (type == 1 || type == 2) {
                                    system("CLS");
                                    break;
                                }
                                else {
                                    throw Error::Error("Выбрано неизвестное действие");
                                }
                            }
                            catch (Error::Error& ex) {
                                system("CLS");
                                std::cout << ex.get_error() << std::endl;
                                system("PAUSE");
                                system("CLS");
                            }
                        }
                        if (type == 1) {

                            continue;
                        }
                        if (type == 2) {
                            break;
                        }

                    }
                    else {
                        throw Error::Error("Выбрано менее двух транспортных средств");
                    }
                }

                if (type < 0 || type > 7) {
                    throw Error::Error("Неизвестный тип транспорта");
                }
                if (temp == 2) {
                    if (type == 1 || type == 3 || type == 4 || type == 6) {
                        type = 0;
                        throw Error::Error("Выбранный вами транспорт не подходит для воздушных гонок");
                    }
                }
                if (temp == 1) {
                    if (type == 2 || type == 5 || type == 7) {
                        type = 0;
                        throw Error::Error("Выбранный вами транспорт не подходит для наземных гонок");
                    }
                }
                if (temp2.size() > 0) {
                    for (int i = 0; i < temp2.size(); ++i) {
                        if (temp2[i] == type) {
                            throw Error::Error("Нельза регестрировать два одинаковых типа транспорта");
                        }
                    }
                }
                temp2.push_back(type);
            }

            catch (Error::Error& ex) {
                system("CLS");
                std::cout << ex.get_error() << std::endl;
                system("PAUSE");
                system("CLS");
            }

            switch (type) {
            case 1:
                all_vehicle.push_back(new Vehicles::All_terrain_boots(dist));
                std::cout << "Ботинки-вездеходы успешно зарегистрированы" << std::endl;
                break;
            case 3:
                all_vehicle.push_back(new Vehicles::Camel(dist));
                std::cout << "Верблюд успешно зарегистрирован" << std::endl;
                break;
            case 4:
                all_vehicle.push_back(new Vehicles::Centaur(dist));
                std::cout << "Кентавр успешно зарегистрирован" << std::endl;
                break;
            case 6:
                all_vehicle.push_back(new Vehicles::Camel_is_fast(dist));
                std::cout << "Верблюд-быстроход успешно зарегистрирован" << std::endl;
                break;
            case 2:
                all_vehicle.push_back(new Vehicles::Broom(dist));
                std::cout << "Метла успешно зарегистрирована" << std::endl;
                break;
            case 5:
                all_vehicle.push_back(new Vehicles::Eagle(dist));
                std::cout << "Орел успешно зарегистрирован" << std::endl;
                break;
            case 7:
                all_vehicle.push_back(new Vehicles::Carpet_plane(dist));
                std::cout << "Ковер-самолет успешно зарегистрирован" << std::endl;
                break;
            }

        }

        std::vector <Leaderboard::Leaderboard*> leaderboard;

        for (int i = 1; i < all_vehicle.size(); ++i) {
            leaderboard.push_back(new Leaderboard::Leaderboard(all_vehicle[i]->get_name(), all_vehicle[i]->get_time()));
        }

        leaderboard.push_back(new Leaderboard::Leaderboard(" ", 0));

        for (int i = 0; i < leaderboard.size() - 2; ++i) {
            for (int j = 0; j < leaderboard.size() - i - 2; ++j) {
                if (leaderboard[j]->get_time() > leaderboard[j + 1]->get_time()) {
                    leaderboard.back() = leaderboard[j];
                    leaderboard[j] = leaderboard[j + 1];
                    leaderboard[j + 1] = leaderboard.back();
                }
            }
        }

        for (;;) {
            std::cout << "Результаты гонки:" << std::endl;
            for (int i = 0; i < leaderboard.size() - 1; ++i) {
                std::cout << i + 1 << ". " << leaderboard[i]->get_name() << ". " << "Время: " << leaderboard[i]->get_time() << std::endl;
            }
            std::cout << std::endl;
            std::cout << "1. Провести еще одну гонку" << std::endl;
            std::cout << "2. Выйти" << std::endl;
            std::cout << "Выберите действие: ";

            try {
                std::cin >> type;
                if (type < 1 || type > 2) {
                    throw Error::Error("Выбрано неизвестное действие");
                }
            }
            catch (Error::Error& ex) {
                system("CLS");
                std::cout << ex.get_error() << std::endl;
                system("PAUSE");
                system("CLS");
            }

            if (type == 1 || type == 2) {
                break;
            }
        }
        all_vehicle.clear();
        leaderboard.clear();

        if (type == 1) {
            system("CLS");
            continue;
        }
        else {
            break;
        }
    }
    return 0;
}