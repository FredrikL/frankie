#pragma once

namespace frankie {

	class Context {
	public:
		Context(const std::string request) : _request(request) {
			auto fs = request.find_first_of(" ");
			_protocol = request.substr(0, fs);

			auto ss = request.find_first_of(" ", fs+1);
			_path = request.substr(fs + 1, ss -(fs+1));
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