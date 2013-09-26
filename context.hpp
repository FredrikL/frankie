#pragma once

namespace frankie {

	class Context {
	public:
		Context(const std::string request) : _request(request), _protocol("GET"), _path("/") {

		}

		const std::string protocol() const {
			return _protocol;
		}

		const std::string path() const {
			return _path;
		}

	private:
		std::string _protocol;
		std::string _path;
		std::string _request;
	};
}