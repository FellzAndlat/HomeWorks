#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>

class BD {
private:
	std::string login;
	int id = 0;
public:
	void CreateTables() {
		try {
			pqxx::connection c(login);
			pqxx::work tx{ c };
			tx.exec(
				"CREATE TABLE IF NOT EXISTS Users ( "
				"id SERIAL PRIMARY KEY, "
				"name varchar(60) NOT NULL, "
				"last_name varchar(60) NOT NULL, "
				"email varchar(60) UNIQUE NOT NULL "
				"); "
				"CREATE TABLE IF NOT EXISTS Phone ( "
				"id SERIAL PRIMARY KEY, "
				"number varchar(60) UNIQUE NOT NULL, "
				"users_id integer not null references Users(id) "
				");");
			tx.commit();
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	void Insert_users(std::string name, std::string last_name, std::string email) {
		try {
			pqxx::connection c(login);
			pqxx::work tx{ c };
			tx.exec(
				"INSERT INTO Users (name,last_name,email) "
				"values ('" + tx.esc(name) + "','" + tx.esc(last_name) + "','" + tx.esc(email) + "')"
			);
			tx.commit();
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	void Insert_Phone(int temp) {
		std::string number;
		number = std::to_string(temp);
		try
		{
			pqxx::connection c(login);
			c.prepare("insert_number", "INSERT INTO Phone(number, users_id) VALUES($1,$2)");
			pqxx::work tx{ c };
			tx.exec_prepared("insert_number", number, tx.query_value<int>("SELECT MAX(id) FROM Users"));
			tx.commit();
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	void Add_Number(int id) {
		std::string number;
		std::cout << "Введите номер телефона: ";
		std::cin >> number;
		try 
		{
			pqxx::connection c(login);
			pqxx::work tx{ c };
			c.prepare("insert_number", "INSERT INTO Phone(number, users_id) VALUES($1,$2)");
			tx.exec_prepared("insert_number", number, id);
			tx.commit();
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	void Update_Users(int id_temp) {
		std::string id;
		id = std::to_string(id_temp);
		id_temp = 0;
		try
		{
			pqxx::connection c(login);
			pqxx::work tx{ c };
			for (;;) {
				std::cout << "Выберите что вы хотите изменить \n"
					"1) Имя \n"
					"2) Фамилия \n"
					"3) Email \n"
					"4) Номер телефона \n"
					"5) Завершить изменения \n"
					"Введите номер: ";
				std::cin >> id_temp;
				if (id_temp == 5) {
					break;
				}
				std::string str;
				switch (id_temp) {
				case 1:
					std::cout << "Введите имя: ";
					std::cin >> str;
					tx.exec(
						"UPDATE Users "
						"SET name = '" + tx.esc(str) + "' "
						"WHERE id = '" + tx.esc(id) + "';"
					);
					tx.commit();
					break;
				case 2:
					std::cout << "Введите фамилию: ";
					std::cin >> str;
					tx.exec(
						"UPDATE Users "
						"SET last_name = '" + tx.esc(str) + "' "
						"WHERE id = '" + tx.esc(id) + "';"
					);
					tx.commit();
					break;
				case 3:
					std::cout << "Введите email: ";
					std::cin >> str;
					tx.exec(
						"UPDATE Users "
						"SET email = '" + tx.esc(str) + "' "
						"WHERE id = '" + tx.esc(id) + "';"
					);
					tx.commit();
					break;
				case 4:
					for (auto [id, number] : tx.query<int, std::string>(
						"SELECT id, number "
						"FROM Phone "
						"WHERE users_id = '" + tx.esc(id) + "';"
					)) {
						std::cout << id << " " << number << std::endl;
					}
					id = "";
					std::cout << "Введите id номера который хотите изменить: ";
					std::cin >> id;

					std::cout << "Введите Номер телефона: ";
					std::cin >> str;
					tx.exec(
						"UPDATE Phone "
						"SET number = '" + tx.esc(str) + "' "
						"WHERE id = '" + tx.esc(id) + "';"
					);
					tx.commit();
					break;
				}
			}
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

	}
	void Delete_Phone(int id_temp) {
		std::string id;
		id = std::to_string(id_temp);
		try
		{
			pqxx::connection c(login);
			pqxx::work tx{ c };
			std::cout << "id number" << std::endl;
			for (auto [id, number] : tx.query<int, std::string>(
				"SELECT id, number "
				"FROM Phone "
				"WHERE users_id = '" + tx.esc(id) + "';"
			)) {
				std::cout << id << " " << number << std::endl;
			}
			id = "";
			std::cout << "Введите id номера который хотите удалить: ";
			std::cin >> id;
			tx.exec(
				"DELETE FROM Phone WHERE id = '" + tx.esc(id) + "'"
			);
			tx.commit();
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	void Delete_Users(int id_temp) {
		std::string id;
		id = std::to_string(id_temp);
		try 
		{
			pqxx::connection c(login);
			pqxx::work tx{ c };
			tx.exec(
				"DELETE FROM Phone WHERE users_id = '" + tx.esc(id) + "'; "
				"DELETE FROM Users WHERE id = '" + tx.esc(id) + "';"
			);
			tx.commit();
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

	}
	void Search(std::string search) {
		int temp;
		try 
		{
			pqxx::connection c(login);
			pqxx::work tx{ c };
			std::cout << "id  name  last_name  email  number" << std::endl;
			for (auto [id, name, last_name, email, number] : tx.query<int, std::string, std::string, std::string, std::string>(
				"SELECT u.id, u.name, u.last_name, u.email, COALESCE(p.number, 'unknown') "
				"FROM Users u "
				"LEFT JOIN Phone p ON u.id = p.users_id "
				"WHERE u.name = '" + tx.esc(search) + "' OR u.last_name = '" + tx.esc(search) + "' OR u.email = '" + tx.esc(search) + "' OR p.number = '" + tx.esc(search) + "' "
				"GROUP BY u.id, p.number;"
			)) {
				std::cout << id << " " << name << " " << last_name << " " << email << " " << number << std::endl;
			}
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
			std::cout << "Введите id нужного клиента или введите 0 что бы вернуться в главное меню: ";
			std::cin >> temp;
			if (temp != 0) {
				int temp_id = temp;
				for (;;) {
					temp = 0;
					std::cout << "Выберите вариант действия \n"
						"1) Добавить телефон \n"
						"2) Изменить данные клиента \n"
						"3) Удалить телефон \n"
						"4) Удалить клиента \n"
						"5) Выйти в главное меню \n"
						"Введите номер: ";
					std::cin >> temp;
					if (temp == 5) {
						break;
					}
					switch (temp) {
					case 1:
						Add_Number(temp_id);
						break;
					case 2:
						Update_Users(temp_id);
						break;
					case 3:
						Delete_Phone(temp_id);
						break;
					}
					if (temp == 4) {
						Delete_Users(temp_id);
						break;
					}
				}

			}

	}
	BD(std::string l) {
		login = l;
		CreateTables();
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string yes = "да";

	std::string const str = 
		"host=localhost "
		"port=5432 "
		"dbname=hw4 "
		"user=postgres "
		"password=LKPjLe%5";

	BD bd(str);
	
	for (;;) {
		std::string name = "";
		std::string last_name = "";
		std::string email = "";
		std::string temp = "";
		long number = 0;
		int num = 0;

		std::cout << "Приветствую. Выберети действие: \n"
				"1) Добавить нового клиента: \n"
				"2) Найти клиента по его данным (имени, фамилии, email-у или телефону) \n"
				"3) Зайкончить работу \n"
				"Введите номер: ";
		std::cin >> num;

		if (num == 1) {
			std::cout << "Введите имя: ";
			std::cin >> name;
			std::cout << "Введите фамилию: ";
			std::cin >> last_name;
			std::cout << "Введите Email: ";
			std::cin >> email;
			bd.Insert_users(name, last_name, email);
			std::cout << "Введите номер телефона, для введите 0: ";
			std::cin >> number;
			if (number != 0) {
				bd.Insert_Phone(number);
			}
		}
		else if (num == 2) {
			std::cout << "Введите один из вариантов (имя, фамилия, email, телефон): ";
			std::cin >> temp;
			bd.Search(temp);
		}
		else {
			break;
		}
	}
}