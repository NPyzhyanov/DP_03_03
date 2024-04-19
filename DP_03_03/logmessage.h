#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

class LogMessage
{
public:
    LogMessage(Type type, std::string message) : type_(type), message_(message) {}
      
    Type type() const { return type_; }
    const std::string& message() const { return message_; }
    
private:
    Type type_;
    std::string message_;
};

#endif // LOGMESSAGE_H
