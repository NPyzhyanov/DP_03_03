#ifndef FATALERRORPROCESSOR_H
#define FATALERRORPROCESSOR_H

class FatalErrorProcessor : public MessageProcessor
{
public:
    FatalErrorProcessor();
    
private:
    void processMessage(const LogMessage& message) override;
    
};

#endif // FATALERRORPROCESSOR_H
