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
		} else if(c.isXml()) {
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

			xml(CEREAL_NVP(e));
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
	}
};