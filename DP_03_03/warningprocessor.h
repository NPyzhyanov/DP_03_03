#ifndef WARNINGPROCESSOR_H
#define WARNINGPROCESSOR_H

class WarningProcessor : public MessageProcessor
{
public:
    WarningProcessor();
    
private:
    void processMessage(const LogMessage& message) override;
    
};

#endif // WARNINGPROCESSOR_H
