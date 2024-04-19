#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <memory>
#include <stdexcept>

#include "type.h"
#include "logmessage.h"
#include "messageprocessor.h"
#include "fatalerrorprocessor.h"
#include "errorprocessor.h"
#include "warningprocessor.h"
#include "unknownmessageprocessor.h"

int main()
{
    std::unique_ptr<MessageProcessor> root(new MessageProcessor);
    std::unique_ptr<MessageProcessor> fatal_processor (new FatalErrorProcessor);
    std::unique_ptr<MessageProcessor> error_processor (new ErrorProcessor);
    std::unique_ptr<MessageProcessor> warning_processor (new WarningProcessor);
    std::unique_ptr<MessageProcessor> unknown_msg_processor (new UnknownMessageProcessor);
    
    warning_processor->addDownstream(std::move(unknown_msg_processor));
    error_processor->addDownstream(std::move(warning_processor));
    fatal_processor->addDownstream(std::move(error_processor));
    root->addDownstream(std::move(fatal_processor));
    
    std::vector<LogMessage> messages{
        { Type::unknown_message, "bipbiphellohumans" },
        { Type::warning, "Something suspicious occured" },
        { Type::error, "Something wrong occured" },
        { Type::fatal_error, "Something fatal occured" }
    };
    
    for (auto msg : messages)
    {
        try
        {
            root->catchMessage(msg);
        }
        catch (const std::exception &ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl;
        }
    }
    
    return 0;
}
