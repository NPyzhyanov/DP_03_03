#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

#include "type.h"
#include "logmessage.h"
#include "messageprocessor.h"

#include "unknownmessageprocessor.h"

UnknownMessageProcessor::UnknownMessageProcessor()
{
    type_ = Type::unknown_message;
}

void UnknownMessageProcessor::processMessage(const LogMessage& message)
{
    throw std::runtime_error("Unknown message received. It was left unprocessed");
}
