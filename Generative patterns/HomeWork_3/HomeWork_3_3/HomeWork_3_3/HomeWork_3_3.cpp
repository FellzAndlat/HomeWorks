#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <memory>

enum class MessageType {
    Warning,
    Error,
    FatalError,
    Unknown
};

class LogMessage {
private:
    MessageType type_;
    std::string message_;
public:
    LogMessage(MessageType type, const std::string& message)
        : type_(type), message_(message) {}

    MessageType type() const { return type_; }
    const std::string& message() const { return message_; }
};

class LogHandler {
protected:
    virtual bool canHandle(const LogMessage& logMessage) const = 0;
    virtual void process(const LogMessage& logMessage) = 0;
private:
    std::shared_ptr<LogHandler> next_;
public:
    virtual ~LogHandler() = default;

    void setNext(std::shared_ptr<LogHandler> next) {
        next_ = next;
    }

    void handle(const LogMessage& logMessage) {
        if (canHandle(logMessage)) {
            process(logMessage);
        }
        else if (next_) {
            next_->handle(logMessage);
        }
        else {
            throw std::runtime_error("Unhandled log message: " + logMessage.message());
        }
    }
};

class FatalErrorHandler : public LogHandler {
protected:
    bool canHandle(const LogMessage& logMessage) const override {
        return logMessage.type() == MessageType::FatalError;
    }

    void process(const LogMessage& logMessage) override {
        throw std::runtime_error("Fatal error: " + logMessage.message());
    }
};

class ErrorHandler : public LogHandler {
protected:
    bool canHandle(const LogMessage& logMessage) const override {
        return logMessage.type() == MessageType::Error;
    }

    void process(const LogMessage& logMessage) override {
        std::ofstream file(filePath_, std::ios_base::app);
        if (file.is_open()) {
            file << "Error: " << logMessage.message() << std::endl;
        }
        else {
            throw std::runtime_error("Unable to open log file: " + filePath_);
        }
    }
private:
    std::string filePath_;
public:
    explicit ErrorHandler(const std::string& filePath) : filePath_(filePath) {}
};

class WarningHandler : public LogHandler {
protected:
    bool canHandle(const LogMessage& logMessage) const override {
        return logMessage.type() == MessageType::Warning;
    }

    void process(const LogMessage& logMessage) override {
        std::cout << "Warning: " << logMessage.message() << std::endl;
    }
};

class UnknownHandler : public LogHandler {
protected:
    bool canHandle(const LogMessage& logMessage) const override {
        return logMessage.type() == MessageType::Unknown;
    }

    void process(const LogMessage& logMessage) override {
        throw std::runtime_error("Unknown log message: " + logMessage.message());
    }
};

int main() {
    auto fatalErrorHandler = std::make_shared<FatalErrorHandler>();
    auto errorHandler = std::make_shared<ErrorHandler>("error_log.txt");
    auto warningHandler = std::make_shared<WarningHandler>();
    auto unknownHandler = std::make_shared<UnknownHandler>();

    fatalErrorHandler->setNext(errorHandler);
    errorHandler->setNext(warningHandler);
    warningHandler->setNext(unknownHandler);

    try {
        LogMessage warningMessage(MessageType::Warning, "This is a warning message.");
        LogMessage errorMessage(MessageType::Error, "This is an error message.");
        LogMessage fatalErrorMessage(MessageType::FatalError, "This is a fatal error message.");
        LogMessage unknownMessage(MessageType::Unknown, "This is an unknown message.");

        fatalErrorHandler->handle(warningMessage);
        fatalErrorHandler->handle(errorMessage);
        fatalErrorHandler->handle(fatalErrorMessage);
        fatalErrorHandler->handle(unknownMessage);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}