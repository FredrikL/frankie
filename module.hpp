#pragma once

#include <map>
#include <functional>
#include <string>

namespace frankie {

	class Context {
	public:
		Context(const std::string request) {

		}
		std::string protocol() {
			return "";
		}
		std::string path() {
			return "";
		}
	};

	class Response {
		
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