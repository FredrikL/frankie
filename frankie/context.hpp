#pragma once

#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>
#include <map>

namespace frankie {

	class Context {
	public:
		Context(const std::string request) : _request(request) { 
			_datasize=0;
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

		const std::map<std::string, std::string> & parameters() const {
			return _parameters;
		}

		const std::vector<std::string> & accept_headers() const {
			return _accept_headers;
		}

		const std::string content_type() const {
			return _contenttype;
		}

		const std::string request_data() const {
			return _data;
		}

		bool complete() const {
			return _datasize == _data.size();
		}

	private:
		void parseRequest() {
			std::vector<std::string> parts;
			boost::split(parts, _request, boost::is_any_of("\n"));

			auto fs = parts[0].find_first_of(" ");
			_protocol = parts[0].substr(0, fs);

			auto ss = parts[0].find_first_of(" ", fs+1);
			parsePathAndParameters(parts[0].substr(fs + 1, ss -(fs+1)));

			for(auto &x : parts) {
				if(boost::starts_with(x, "Host:")) {
					auto pos = x.find_first_of(" ");
					_host = x.substr(pos + 1, x.length() - pos);
				} else if(boost::starts_with(x, "Accept: ")) {
					parseAcceptHeaders(x);
				} else if(boost::starts_with(x, "Content-Type: ")) {
					auto pos = x.find_first_of(" ");
					_contenttype = x.substr(pos +1 , x.length() -pos);
				} else if(boost::starts_with(x, "Content-Length: ")) {
					auto pos = x.find_first_of(" ");
					auto size = x.substr(pos +1 , x.length() -pos);
					_datasize = atoi(size.c_str());
				}
			}

			auto datapos = _request.find("\r\n\r\n");
			if(datapos != std::string::npos) {
				_data = _request.substr(datapos+4, _request.length() - (datapos+4));
			}
		}

		void parsePathAndParameters(std::string path) {
			auto parampos = path.find_first_of("?");
			if(parampos == std::string::npos) {
				_path = path;
			} else {
				_path = path.substr(0, parampos);
				auto params = path.substr(parampos+1, path.length() - parampos);
				std::vector<std::string> parts;
				boost::split(parts, params, boost::is_any_of("&"));
				for(auto &x : parts) {
					auto eqpos = x.find_first_of("=");
					auto key = x.substr(0, eqpos);
					auto val = x.substr(eqpos+1, x.length());
					_parameters[key] = val;
				}
			}
		}

		void parseAcceptHeaders(const std::string & accept) {
			std::string list = accept.substr(8, accept.length() -8);
			boost::split(_accept_headers, list, boost::is_any_of(","));
		}

		unsigned long _datasize;
		std::string _protocol;
		std::string _path;
		std::string _request;
		std::string _host;
		std::string _contenttype;
		std::string _data;
		std::map<std::string, std::string> _parameters;
		std::vector<std::string> _accept_headers;

	};
}