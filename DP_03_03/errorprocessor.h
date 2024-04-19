#ifndef ERRORPROCESSOR_H
#define ERRORPROCESSOR_H

class ErrorProcessor : public MessageProcessor
{
public:
    ErrorProcessor();
    ~ErrorProcessor();
    
private:
    void processMessage(const LogMessage& message) override;
    
    std::ofstream file_;
    
};

#endif // ERRORPROCESSOR_H
