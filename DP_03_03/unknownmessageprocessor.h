#ifndef UNKNOWNMESSAGEPROCESSOR_H
#define UNKNOWNMESSAGEPROCESSOR_H

class UnknownMessageProcessor : public MessageProcessor
{
public:
    UnknownMessageProcessor();
    
private:
    void processMessage(const LogMessage& message) override;
    
};

#endif // UNKNOWNMESSAGEPROCESSOR_H
