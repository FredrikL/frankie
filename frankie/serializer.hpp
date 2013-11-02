#pragma once

#include <entity/entity.h>
#include <entity/json.h>
#include <entity/xml.h>

using namespace ent;

namespace frankie {
	template <class T>
	T Deserialize(frankie::Context c) {
		T result;

		if(c.isJson()) 
			result.template from<json>(c.request_data());
		else if(c.isXml())
			result.template from<xml>(c.request_data());
		return result;
	}

	template <class T>
	std::string Serialize(T e, frankie::Context c) {
		if(c.wantXml())
			return (e.template to<xml>());

		return (e.template to<json>());
	}

	template <class T>
	std::string Serialize(T e) {
		return (e.template to<json>());
	}
};