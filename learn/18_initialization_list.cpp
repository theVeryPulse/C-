#include <string>

class Entity
{
  public:
    // initialization is done in the order variables are declared in the class.
    // In this case, `name_` will always be initalized prior to `score_`
    // `name_` is initialized directly as "unknown" without another step of
    // copying. For this reason, using initialization list is almost always
    // better
    Entity() : name_("unknown"), score_(0)
    {
    }
    Entity(const std::string& name) : name_(name), score_(0)
    {
    }

  private:
    std::string name_;
    int         score_;
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
