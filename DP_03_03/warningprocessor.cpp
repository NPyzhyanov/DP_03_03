#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "type.h"
#include "logmessage.h"
#include "messageprocessor.h"

#include "warningprocessor.h"

WarningProcessor::WarningProcessor()
{
    type_ = Type::warning;
}

void WarningProcessor::processMessage(const LogMessage& message)
{
    std::cout << message.message() << std::endl;
}
