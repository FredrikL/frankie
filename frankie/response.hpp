#pragma once

namespace frankie {

	class Response {
	public:
		Response(const std::string response) : _response(response) { }

		Response(const char response[]) : _response(response) { }

		const std::string get() {
			return _response;
		}

		const uint length() {
			return _response.length();
		}

		const std::string contentType() {
			return "text/plain";
		}
	private:
		std::string _response;
		std::string _contentType;
	};
}