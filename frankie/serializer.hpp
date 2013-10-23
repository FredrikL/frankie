#pragma once

#include <entity/entity.h>
#include <entity/json.h>
#include <entity/xml.h>

using namespace ent;

namespace frankie {
	template <class T>
	T Deserialize(frankie::Context c) {
		T result;
		result.template from<json>(c.request_data());
		return result;
	}

	template <class T>
	std::string Serialize(T e) {
		return (e.template to<json>());
	}
};