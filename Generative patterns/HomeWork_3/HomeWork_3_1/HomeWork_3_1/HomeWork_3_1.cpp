#include <iostream>
#include <fstream>
#include <string>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
private:
    std::string file_path_;
public:
    explicit FileLogCommand(const std::string& file_path) : file_path_(file_path) {}

    void print(const std::string& message) override {
        std::ofstream file(file_path_, std::ios_base::app);
        if (file.is_open()) {
            file << message << std::endl;
        }
        else {
            std::cerr << "Error: Unable to open file " << file_path_ << std::endl;
        }
    }
};

void print(LogCommand& log_command, const std::string& message) {
    log_command.print(message);
}

int main() {
    ConsoleLogCommand console_logger;
    FileLogCommand file_logger("log.txt");

    print(console_logger, "This is a message to the console.");
    print(file_logger, "This is a message to the file.");

    return 0;
}