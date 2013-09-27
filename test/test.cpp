#include <bandit/bandit.h>

using namespace bandit;

go_bandit([](){

    describe("fuzzbox:", [](){
      it("starts in clean mode", [&](){
        AssertThat(1, Equals(1));
      });
    });

});




int main(int argc, char* argv[])
{
  return bandit::run(argc, argv);
}