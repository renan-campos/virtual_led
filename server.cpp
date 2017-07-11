#include <iostream>
#include "server.hpp"


namespace phosphor
{
namespace tutorial
{

void Manager::setState(Action newState) {
	// Make whatever systemcalls here.
	state(newState); // Uses auto-generated setter to change the state
        stateChange();	 // Sends signal to notify any clients that are listening
}

} // tutorial
}
