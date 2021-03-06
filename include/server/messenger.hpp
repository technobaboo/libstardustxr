#pragma once

#include "../messenger.hpp"
#include "scenegraph.hpp"
#include <map>
#include <mutex>
#include <signal.h>
#include <thread>

namespace StardustXR {

class MessengerManager;

class ServerMessenger : public Messenger {
public:
	explicit ServerMessenger(uint sessionID, int readFD, int writeFD, ServerScenegraph *scenegraph, MessengerManager *manager);

	void startHandler();

protected:
	void messageHandler();
	void handleMessage(const Message *message);

	virtual void onPipeBreak() {
		scenegraph->handleMessengerDeletion(sessionID);
	}
	uint sessionID;
	ServerScenegraph *scenegraph;
	MessengerManager *manager;
};

} // namespace StardustXR
