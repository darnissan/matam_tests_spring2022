#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#include <stdlib.h>
#include <string>
class Exception : public std::exception
{
protected:
    std::string m_errorMessage;

public:
    Exception(const std::string &msg) : m_errorMessage(msg) {}
    virtual ~Exception() {}
    virtual const char *what() const noexcept 
    {
        return m_errorMessage.c_str();
    }
};
class DeckFileNotFound : public Exception
{
public:
    DeckFileNotFound(const std::string &msg) : Exception(msg) {}
    virtual ~DeckFileNotFound() {}
    virtual const char *what() const noexcept 
    {
        return "Deck File Error: File not found";
    }
};
class DeckFileFormatError : public Exception
{
private:
    std::string m_lineNumberInDeckFile;

public:
    DeckFileFormatError(const std::string &msg, std::string lineNumberInDeckFile) : Exception(msg)
    {
        m_lineNumberInDeckFile = lineNumberInDeckFile;
        m_errorMessage = "Deck File Error: File format error in line " + m_lineNumberInDeckFile;
    }
    virtual ~DeckFileFormatError() {}
    virtual const char *what() const noexcept 
    {

        return (m_errorMessage.c_str());
    }
};

class DeckFileInvalidSize : public Exception
{
public:
    DeckFileInvalidSize(const std::string &msg) : Exception(msg){};
    virtual ~DeckFileInvalidSize(){};
    virtual const char *what() const noexcept 
    {
        return "Deck File Error: Deck size is invalid";
    }
};

#endif /* EXCEPTION_H_ */