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
            std::cout << "����� ���������� � �������� ���������!" << std::endl;
            std::cout << "1. ����� ��� ��������� ����������" << std::endl;
            std::cout << "2. ����� ��� ���������� ����������" << std::endl;
            std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;
            std::cout << "�������� ��� �����: ";
            try {
                std::cin >> type;
                if (type < 0 || type > 3) {
                    throw Error::Error("����������� ��� �����, ���������� �����");
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
            std::cout << "������� ����� ���������� (������ ���� �������������): ";
            try {
                std::cin >> dist;
                if (dist < 0) {
                    throw Error::Error("��������� ������ ���� �������������, ���������� �����");
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

        std::cout << "��������������� ���� �� ��� ������������ ��������" << std::endl;
        system("PAUSE");
        system("CLS");

        int temp = type;
        type = 0;

        for (std::vector <int> temp2;;) {
            std::cout << all_vehicle[0]->get_name() << ". " << "����������: " << dist << std::endl;
            if (all_vehicle.size() > 1) {
                std::cout << "������������������ ������������ ��������: ";
                for (int i = 1; i < all_vehicle.size(); ++i) {
                    if (i == all_vehicle.size() - 1) {
                        std::cout << all_vehicle[i]->get_name() << std::endl;
                    }
                    else {
                        std::cout << all_vehicle[i]->get_name() << ", ";
                    }
                }
            }
            std::cout << "1. �������-���������" << std::endl;
            std::cout << "2. �����" << std::endl;
            std::cout << "3. �������" << std::endl;
            std::cout << "4. �������" << std::endl;
            std::cout << "5. ����" << std::endl;
            std::cout << "6. �������-���������" << std::endl;
            std::cout << "7. �����-�������" << std::endl;
            std::cout << "0. ��������� �����������" << std::endl;
            std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";

            try {
                std::cin >> type;

                system("CLS");
                if (type == 0) {
                    if (temp2.size() > 1) {
                        for (;;) {
                            std::cout << "1. ���������������� ���������" << std::endl;
                            std::cout << "2. ������ �����" << std::endl;
                            std::cout << "�������� ��������: ";
                            try {
                                std::cin >> type;
                                if (type == 1 || type == 2) {
                                    system("CLS");
                                    break;
                                }
                                else {
                                    throw Error::Error("������� ����������� ��������");
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
                        throw Error::Error("������� ����� ���� ������������ �������");
                    }
                }

                if (type < 0 || type > 7) {
                    throw Error::Error("����������� ��� ����������");
                }
                if (temp == 2) {
                    if (type == 1 || type == 3 || type == 4 || type == 6) {
                        type = 0;
                        throw Error::Error("��������� ���� ��������� �� �������� ��� ��������� �����");
                    }
                }
                if (temp == 1) {
                    if (type == 2 || type == 5 || type == 7) {
                        type = 0;
                        throw Error::Error("��������� ���� ��������� �� �������� ��� �������� �����");
                    }
                }
                if (temp2.size() > 0) {
                    for (int i = 0; i < temp2.size(); ++i) {
                        if (temp2[i] == type) {
                            throw Error::Error("������ �������������� ��� ���������� ���� ����������");
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
                std::cout << "�������-��������� ������� ����������������" << std::endl;
                break;
            case 3:
                all_vehicle.push_back(new Vehicles::Camel(dist));
                std::cout << "������� ������� ���������������" << std::endl;
                break;
            case 4:
                all_vehicle.push_back(new Vehicles::Centaur(dist));
                std::cout << "������� ������� ���������������" << std::endl;
                break;
            case 6:
                all_vehicle.push_back(new Vehicles::Camel_is_fast(dist));
                std::cout << "�������-��������� ������� ���������������" << std::endl;
                break;
            case 2:
                all_vehicle.push_back(new Vehicles::Broom(dist));
                std::cout << "����� ������� ����������������" << std::endl;
                break;
            case 5:
                all_vehicle.push_back(new Vehicles::Eagle(dist));
                std::cout << "���� ������� ���������������" << std::endl;
                break;
            case 7:
                all_vehicle.push_back(new Vehicles::Carpet_plane(dist));
                std::cout << "�����-������� ������� ���������������" << std::endl;
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
            std::cout << "���������� �����:" << std::endl;
            for (int i = 0; i < leaderboard.size() - 1; ++i) {
                std::cout << i + 1 << ". " << leaderboard[i]->get_name() << ". " << "�����: " << leaderboard[i]->get_time() << std::endl;
            }
            std::cout << std::endl;
            std::cout << "1. �������� ��� ���� �����" << std::endl;
            std::cout << "2. �����" << std::endl;
            std::cout << "�������� ��������: ";

            try {
                std::cin >> type;
                if (type < 1 || type > 2) {
                    throw Error::Error("������� ����������� ��������");
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