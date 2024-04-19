#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "type.h"
#include "logmessage.h"
#include "messageprocessor.h"
#include "settings.h"

#include "errorprocessor.h"

ErrorProcessor::ErrorProcessor()
{
    type_ = Type::error;
    if (!file_.is_open())
    {
        file_.open(settings::filename, std::ios::app);
    }
}

ErrorProcessor::~ErrorProcessor()
{
    file_.close();
}

void ErrorProcessor::processMessage(const LogMessage& message)
{
    file_ << message.message() << std::endl;
}
