#pragma once

#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>

namespace frankie {

	class Context {
	public:
		Context(const std::string request) : _request(request) { 
			parseRequest();
		}

		const std::string protocol() const {
			return _protocol;
		}

		const std::string path() const {
			return _path;
		}

		const std::string host() const {
			return _host;
		}

	private:
		void parseRequest() {
			std::vector<std::string> parts;
			boost::split(parts, _request, boost::is_any_of("\n"));

			auto fs = parts[0].find_first_of(" ");
			_protocol = parts[0].substr(0, fs);

			auto ss = parts[0].find_first_of(" ", fs+1);
			_path = parts[0].substr(fs + 1, ss -(fs+1));

			for(auto &x : parts) {
				if(boost::starts_with(x, "Host:")) {
					auto pos = x.find_first_of(" ");
					_host = x.substr(pos + 1, x.length() - pos);
				}
			}

		}

		std::string _protocol;
		std::string _path;
		std::string _request;
		std::string _host;
	};
}