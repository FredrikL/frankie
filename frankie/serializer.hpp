#pragma once

#include <sstream>
#include <cereal/archives/json.hpp>
#include <cereal/archives/xml.hpp>

namespace frankie {
	template <class T>
	T Deserialize(frankie::Context c) {
		T result;
		std::istringstream iss (c.request_data());

		if(c.isJson()) { 
			cereal::JSONInputArchive json(iss);
			json(result);
			//result.template from<json>(c.request_data());
		} else if(c.isXml()) {
			//result.template from<xml>(c.request_data());
			cereal::XMLInputArchive xml(iss);
			xml(result);
		}
		return result;
	}

	template <class T>
	std::string Serialize(T e, frankie::Context c) {
		std::ostringstream oss;

		if(c.wantXml()) {
			cereal::XMLOutputArchive xml(oss);

			xml(e);
		} else {
			cereal::JSONOutputArchive json(oss);

			json(CEREAL_NVP(e));
		}

		return oss.str();
	}

	template <class T>
	std::string Serialize(T e) {
		std::ostringstream oss;
		cereal::JSONOutputArchive json(oss);

		json(CEREAL_NVP(e));

		return oss.str();

//		return (e.template to<json>());
	}
};