#pragma once

namespace frankie {

	class Context {
	public:
		Context(const std::string request) : _request(request) {

		}

		std::string protocol() {
			return "";
		}

		std::string path() {
			return "";
		}
		
	private:
		std::string _request;
	};
}