#pragma once

#include "flatbuffers/flexbuffers.h"
#include <functional>

namespace StardustXR {

typedef std::function<void(flexbuffers::Builder&)> ArgsConstructor;
typedef std::function<void(flexbuffers::Reference)> Callback;

static std::vector<uint8_t> FlexbufferFromArguments(ArgsConstructor argsConstructor) {
	flexbuffers::Builder fbb;
	argsConstructor(fbb);
	fbb.Finish();
	return fbb.GetBuffer();
}

} // namespace StardustXR
