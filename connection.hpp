#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>
#include <string>
#include "registry.hpp"

namespace frankie {

	using boost::asio::ip::tcp;

	class Connection :
		public std::enable_shared_from_this<Connection> {
	public:
		static std::shared_ptr<Connection> create(boost::asio::io_service& service) {
			return std::shared_ptr<Connection>(new Connection(service));
		}

		tcp::socket& socket() {
			return _socket;
		}

		void handle_request() {
			std::cout << "handle_request" << std::endl;
			boost::asio::async_read_until(_socket, buffer,
				"\r\n\r\n",
				boost::bind(&Connection::handle_read, shared_from_this(), 
					boost::asio::placeholders::error, 
					boost::asio::placeholders::bytes_transferred));
		}

	private:
		Connection(boost::asio::io_service& service) : _socket(service) { }

		void handle_read(const boost::system::error_code& error, std::size_t bytes) {
			if(!error) {

				auto bufs = buffer.data();
				std::string input(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs) + bytes);
				buffer.consume(bytes);

				// magic?!
				std::cout << input << std::endl;
				auto module = registry.createModuleForUrl("GET", "/");
				auto result = module->handle("GET", "/");

				msg = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Lenght: 100\r\n\r\n" +
						result.get() +
						"\r\n\r\n";

				boost::asio::async_write(_socket, boost::asio::buffer(msg),
					boost::bind(&Connection::handle_write, shared_from_this(),
					boost::asio::placeholders::error, 
					boost::asio::placeholders::bytes_transferred));
			}
		}

		void handle_write(const boost::system::error_code&, size_t) {
			//std::cout << "handle_write" << std::endl;
		}

		boost::asio::streambuf buffer;
		tcp::socket _socket;
		std::string msg;
		frankie::Registry registry;
	};

}