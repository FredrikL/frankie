#pragma once

#include <map>
#include <functional>
#include <string>
#include "context.hpp"

namespace frankie {

	class Response {
	public:
		Response(const std::string response) : _response(response) {

		}

		const std::string get() {
			return _response;
		}
	private:
		std::string _response;
	};

	typedef std::function<frankie::Response(frankie::Context)> ffunc;
	

	class Module{
		public:
			bool canHandle(std::string protocol, std::string path) { 
				for(auto &k : get) {
					if(k.first == path)
						return true;
				}
				return false;
			};

			frankie::Response handle(std::string protocol, std::string path) {
				return get[path](frankie::Context(""));
			}

		protected:
			void Get(std::string path, ffunc f) {
				get[path] = f;
			}

		private:
			std::map<std::string, ffunc> get;
	};
};