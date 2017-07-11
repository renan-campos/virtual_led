#include <sdbusplus/server.hpp>
#include "config.h"
#include "server.hpp"

/*
  Sets up manager server (defined in method_tutorial.hpp) 
  on default bus (gotten from server.hpp) 
  with known name BMC_BUSNAME and path BMC_OBJPATH (from config.h)
*/
int main(int argc, char**)
{
    auto bus = sdbusplus::bus::new_default();

    // Add sdbusplus ObjectManager.
    sdbusplus::server::manager::manager objManager(bus, BMC_OBJPATH);

    phosphor::tutorial::Manager manager(bus,
                                        BMC_OBJPATH);

    bus.request_name(BMC_BUSNAME);

    while(true)
    {
        bus.process_discard();
        bus.wait();
    }

    exit(EXIT_SUCCESS);

}
