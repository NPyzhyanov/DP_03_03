#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

#include "type.h"
#include "logmessage.h"
#include "messageprocessor.h"

#include "fatalerrorprocessor.h"

FatalErrorProcessor::FatalErrorProcessor()
{
    type_ = Type::fatal_error;
}

void FatalErrorProcessor::processMessage(const LogMessage& message)
{
    throw std::runtime_error(message.message());
}
