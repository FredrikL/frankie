#pragma once

namespace frankie {

	class Response {
	public:
		Response(const std::string response) : _status(200), _response(response) { }

		Response(const std::string response, uint status) : _status(status), _response(response) { }

		Response(const char response[]) : _status(200), _response(response) { }

		uint status() {
			return _status;
		}

		const std::string get() {
			return "HTTP/1.1 " +
						std::to_string(_status) +
						" OK\r\nContent-Type: " +
						_contentType +
				 		"\r\nContent-Lenght: " + 
				 		std::to_string(_response.length()) +
				 		"\r\n\r\n" +
						_response +
						"\r\n\r\n";
		}

	protected:
		uint _status;
		std::string _response;
		std::string _contentType;
	};

	class StaticResponse : public Response{
	public:
		StaticResponse(const std::string path) : Response("", 200), _path(path) {

		}

		const std::string get() {
			// load file into _response
			// set correct _contentType + status
			return Response::get();
		}

	private:
		std::string _path;
	};

	class NotFoundResponse : public Response {
	public:
		NotFoundResponse() : Response("not found", 404) { }
	};
}