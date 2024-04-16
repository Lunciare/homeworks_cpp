#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Logger 
{
public:
    enum class Level 
    {
        ERROR = 0,
        WARNING,
        INFO,
        DEBUG,
    };

private:
    ofstream logFile;
    Level currentLevel;

    Logger(const string &filename, Level level = Level::INFO) : currentLevel(level) 
    {
        logFile.open(filename);
        if(!logFile.is_open())
        {
            throw runtime_error("Failed to open log file.");
        }
    }

    Logger(const Logger &) = delete; // запрет на конструктор копирования
    Logger &operator=(const Logger &) = delete; // запрет оператора присваивания

 public:
    ~Logger() 
    {
        logFile.close();
    }
    static Logger &getInstance(const string &filename = "logfile.txt") 
    {
        static Logger instance(filename);
        return instance;
    }

    void setLevel(Level level) 
    {
        this->currentLevel = level;
    }

    void log(const string &message, Level level = Level::INFO) 
    {
        if(level <= currentLevel)
        {
            logFile << time(NULL) << "sec " << levelToString(level) << " " << message << endl; 
        }
        return;
    }

private:
    string levelToString(Level level) 
    {
        switch (level) 
        {
        case Level::DEBUG:
            return "DEBUG";
        case Level::INFO:
            return "INFO";
        case Level::ERROR:
            return "ERROR";
        case Level::WARNING:
            return "WARNING";
        }
    }
};

auto &logger = Logger::getInstance();

int sum(int a, int b) 
{
    logger.log("Зашли в метод sum.", Logger::Level::DEBUG);
    int res = a + b;
    logger.log("Суммируем числа " + to_string(a) + " "
                    + to_string(b) + "res = " + to_string(res),
                Logger::Level::INFO);
    return a + b;
}

int main() 
{
    logger.setLevel(Logger::Level::DEBUG);
    sum(10, 20);
    sum(50, 50);
    return 0;
}
