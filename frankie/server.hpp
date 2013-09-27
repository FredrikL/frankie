#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>
#include "connection.hpp"

namespace frankie {

	using boost::asio::ip::tcp;

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