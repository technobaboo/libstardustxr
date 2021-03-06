#pragma once

#include "flatbuffers/flexbuffers.h"
#include <unistd.h>

namespace StardustXR {

class ClientScenegraph {
public:
	ClientScenegraph(){};
	virtual ~ClientScenegraph(){};

	virtual void sendSignal(std::string path, std::string method, flexbuffers::Reference data) {
		executeMethod(path, method, data);
	}
	virtual std::vector<uint8_t> executeMethod(std::string path, std::string method, flexbuffers::Reference args) = 0;
};

} // namespace StardustXR
