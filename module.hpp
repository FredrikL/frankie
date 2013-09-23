#pragma once

#include <map>
#include <functional>
#include <string>

namespace frankie {

	class Context {};
	class Response {};

	

	class Module{
		public:
			bool canHandle(std::string protocol, std::string path) { return false;};

		protected:
			void Get(std::string path, std::function<frankie::Response(frankie::Context)> f) {
				get[path] = f;
			}


		private:
			std::map<std::string, std::function<frankie::Response(frankie::Context)>> get;
	};


	



};