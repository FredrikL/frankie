#pragma once

#include <functional>
#include <string>
#include <vector>
#include <memory>

namespace frankie{
	typedef std::function<std::shared_ptr<frankie::Module>(void)> Creator;

	struct knowns {
		std::string name;
		Creator func;
	};
	typedef std::vector<knowns> reg;

	inline frankie::reg& regs() {
		static reg regs;
		return regs;
	};

	struct known {
		known(knowns k){
			regs().push_back(k);
		}
	};

	class Registry {

	private:
		typedef std::map<std::string, Creator> Creators;
		Creators _creators;

		void reg(const std::string &className, const Creator &creator) {
			_creators[className] = creator;
		}

	public:
		Registry(frankie::reg r) {
			for(auto &x : r) {
				reg(x.name, x.func);
			}
		}

		std::shared_ptr<frankie::Module> create(const std::string &className){
			return _creators[className]();
		}
	};
}