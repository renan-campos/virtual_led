#ifndef _EXAMPLE_SERVER
#define _EXAMPLE_SERVER

#include "com/example/virtled/Manager/server.hpp"

namespace phosphor
{
namespace tutorial
{


using ManagerIface = \
    sdbusplus::server::object::object<sdbusplus::com::example::virtled::server::Manager>;

/** @class Manager
 *  @brief OpenBMC logging manager implementation.
 *  @details A concrete implementation for the
 *  xyz.openbmc_project.Logging.Internal.Manager DBus API.
 */
class Manager : public ManagerIface
{
    public:
        
        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Manager(sdbusplus::bus::bus& bus, const char* objPath) :
                ManagerIface(bus, objPath) {};

  /** @brief Implementation for SetState
   *  Changes the state of the led.
   *
   *  @param[in] newState - On | Off | Blink
   */
    void setState(Action newState) override;
};

} // namespace logging
} // namespace phosphor
#endif
