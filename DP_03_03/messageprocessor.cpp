#include <string>
#include <vector>
#include <memory>

#include "type.h"
#include "logmessage.h"

#include "messageprocessor.h"

MessageProcessor::MessageProcessor()
{
    type_ = empty_type;
}

bool MessageProcessor::suitableType(const Type &type_of_message) const
{
    return type_of_message == type_;
}

void MessageProcessor::addDownstream(std::unique_ptr<MessageProcessor> &&downstream_processor)
{
    downstream_processor->upstream_ = this;
    downstreams_.push_back(std::move(downstream_processor));
}

void MessageProcessor::catchMessage(const LogMessage& message)
{
    if (suitableType(message.type()))
    {
        processMessage(message);
        return;
    }
    if (!downstreams_.empty())
    {
        for (auto it = downstreams_.begin(); it != downstreams_.end(); it++)
        {
            (*it)->catchMessage(message);
        }
    }
}
