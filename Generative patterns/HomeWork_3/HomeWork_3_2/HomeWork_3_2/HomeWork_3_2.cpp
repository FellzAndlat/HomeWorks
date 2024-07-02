#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};

class WarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "Warning: " << message << std::endl;
    }
};

class ErrorObserver : public Observer {
public:
    explicit ErrorObserver(const std::string& file_path) : file_path_(file_path) {}

    void onError(const std::string& message) override {
        std::ofstream file(file_path_, std::ios_base::app);
        if (file.is_open()) {
            file << "Error: " << message << std::endl;
        }
        else {
            std::cerr << "Error: Unable to open file " << file_path_ << std::endl;
        }
    }

private:
    std::string file_path_;
};

class FatalErrorObserver : public Observer {
private:
    std::string file_path_;
public:
    explicit FatalErrorObserver(const std::string& file_path) : file_path_(file_path) {}

    void onFatalError(const std::string& message) override {
        std::cout << "Fatal Error: " << message << std::endl;
        std::ofstream file(file_path_, std::ios_base::app);
        if (file.is_open()) {
            file << "Fatal Error: " << message << std::endl;
        }
        else {
            std::cerr << "Fatal Error: Unable to open file " << file_path_ << std::endl;
        }
    }
};

class Observable {
private:
    template <typename Func>
    void notifyObservers(Func func, const std::string& message) const {
        for (auto observer : observers_) {
            if (observer) {
                (observer->*func)(message);
            }
        }
    }

    std::vector<Observer*> observers_;
public:
    void addObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }

    void warning(const std::string& message) const {
        notifyObservers(&Observer::onWarning, message);
    }

    void error(const std::string& message) const {
        notifyObservers(&Observer::onError, message);
    }

    void fatalError(const std::string& message) const {
        notifyObservers(&Observer::onFatalError, message);
    }
};

int main() {
    Observable observable;

    WarningObserver warningObserver;
    ErrorObserver errorObserver("error_log.txt");
    FatalErrorObserver fatalErrorObserver("fatal_error_log.txt");

    observable.addObserver(&warningObserver);
    observable.addObserver(&errorObserver);
    observable.addObserver(&fatalErrorObserver);

    observable.warning("This is a warning message.");
    observable.error("This is an error message.");
    observable.fatalError("This is a fatal error message.");

    observable.removeObserver(&warningObserver);
    observable.removeObserver(&errorObserver);
    observable.removeObserver(&fatalErrorObserver);

    return 0;
}