#pragma once

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <memory>
#include <string>

namespace frankie {

	using boost::asio::ip::tcp;

	class Connection {
	public:
		static std::shared_ptr<Connection> create(boost::asio::io_service& service) {
			return std::shared_ptr<Connection>(new Connection(service));
		}

		tcp::socket& socket() {
			return _socket;
		}

		void handle_request() {
			msg = "Hai!";

			boost::asio::async_write(_socket, boost::asio::buffer(msg),
				boost::bind(&Connection::handle_write, this,
				boost::asio::placeholders::error, 
				boost::asio::placeholders::bytes_transferred));
		}

	private:
		Connection(boost::asio::io_service& service) : _socket(service) {

		}

		void handle_write(const boost::system::error_code&, size_t) {
		}

		tcp::socket _socket;
		std::string msg;
	};


	class Server {
	public:
		Server(boost::asio::io_service& service, int port) 
			: acceptor(service, tcp::endpoint(tcp::v4(), port)){

			start_accept();
		}

	private:
		void start_accept() {
			auto connection = Connection::create(acceptor.get_io_service());

			acceptor.async_accept(connection->socket(),
				boost::bind(&Server::handle_accept, this, connection,
					boost::asio::placeholders::error));
		}

		void handle_accept(std::shared_ptr<Connection> connection,
		 					const boost::system::error_code& error) {
			if(!error) {
				connection->handle_request();
			}

			start_accept();
		}

		tcp::acceptor acceptor;
	};
}