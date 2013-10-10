#pragma once

#include <entity/entity.h>
#include <entity/json.h>

using namespace ent;

namespace frankie {
	template <class T>
	T Deserialize(frankie::Context c) {
		T result;
		std::cout << "Deserialize" << std::endl;
		result.template from<json>(c.request_data());
		return result;
	}
};