#pragma once

#include <functional>
#include <string>
#include <vector>
#include <memory>

namespace frankie{
	
	class Registry {
		typedef std::function<std::shared_ptr<frankie::Module>(void)> Creator;
		typedef std::map<std::string, Creator> Creators;
		Creators _creators;


	public:
		void reg(const std::string &className, const Creator &creator) {
			_creators[className] = creator;
		}
		std::shared_ptr<frankie::Module> create(const std::string &className){
			return _creators[className]();
		}
	};


	typedef std::function<void(frankie::Registry)> func;
	typedef std::vector<func> reg;


	inline frankie::reg& regs() {
		static reg regs;
		return regs;
	};


	struct known {
		known(func f){
			regs().push_back(f);
		}
	};
}