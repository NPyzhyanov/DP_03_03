#ifndef MESSAGEPROCESSOR_H
#define MESSAGEPROCESSOR_H

class MessageProcessor
{
public:
    MessageProcessor();
    virtual ~MessageProcessor() = default;
    
    bool suitableType(const Type& type_of_message) const;
    void addDownstream(std::unique_ptr<MessageProcessor> &&downstream_processor);
    void catchMessage(const LogMessage& message);
    
protected:
    virtual void processMessage(const LogMessage& message) {}
    
    Type type_;
    
private:
    std::vector<std::unique_ptr<MessageProcessor>> downstreams_;
    MessageProcessor* upstream_ = nullptr;
    
};

#endif // MESSAGEPROCESSOR_H
