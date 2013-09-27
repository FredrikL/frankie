#pragma once

namespace frankie {

	class Response {
	public:
		Response(const std::string response) : _response(response), _status(200) { }

		Response(const std::string response, uint status) : _response(response), _status(status) { }

		Response(const char response[]) : _response(response) { }

		const uint status() {
			return _status;
		}

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
		uint _status;
		std::string _response;
		std::string _contentType;
	};

	class NotFoundResponse : public Response {
	public:
		NotFoundResponse() : Response("not found", 404) { }
	};
}