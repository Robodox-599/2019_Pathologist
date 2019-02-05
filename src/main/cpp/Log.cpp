
#include "Log.h"

Log::Log()
{
    std::string fileName;

    std::time_t t = std::time(nullptr);
    char buffer[100];
    if (std::strftime(buffer, sizeof(buffer), "%Y%m%d-%H%M%S", std::localtime(&t)))
    {
        fileName = buffer;
    }

    logFile.open("/home/lvuser/" + fileName + ".txt");

    m_isOpen = true;
}

Log::Log(std::string path)
{

    std::string fileName;

    std::time_t t = std::time(nullptr);
    char buffer[100];
    if (std::strftime(buffer, sizeof(buffer), "%Y%m%d-%H%M%S", std::localtime(&t)))
    {
        fileName = buffer;
    }

    logFile.open(path + fileName + ".txt");

    m_isOpen = true;
}

void Log::LogIt(std::string message, int level)
{
    if (!m_isOpen)
    {
        return;
    } // In case file's closed, no action

    if (level <= m_level || level == -1)
    {
        std::string timeStamp = "*** ";

        std::time_t t = std::time(nullptr);
        char buffer[100];
        if (std::strftime(buffer, sizeof(buffer), "%Y%m%d-%H%M%S", std::localtime(&t)))
        {
            timeStamp = buffer;
        }

        logFile << timeStamp << "\t" << level << "\t" << message << "\n";
    }
}

void Log::Close()
{
    if (m_isOpen)
    {
        logFile.close();
        m_isOpen = false;
    }
    else
    {
        // File's already closed, no action
    }
}

bool Log::GetIsOpen()
{
    return m_isOpen;
}