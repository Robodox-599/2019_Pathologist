
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

class Log
{
  private:
    std::ofstream logFile;
    bool m_isOpen = false;
    int m_level = -1;

  public:
    Log();
    Log(std::string path);
    void LogIt(std::string message, int level);
    void Close();
    bool GetIsOpen();
};