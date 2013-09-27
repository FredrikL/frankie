#pragma once

namespace frankie {

	class Response {
	public:
		Response(const std::string response) : _response(response) { }

		Response(const char response[]) : _response(response) { }

		const std::string get() {
			return _response;
		}
	private:
		std::string _response;
	};
}