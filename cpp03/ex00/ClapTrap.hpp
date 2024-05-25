#include <string>

class ClapTrap
{
  public:
    //=============== Types: Classes, Enums, and Aliases (using) ===============
    //================= Constructors, Assignments, Destructor ==================

    ClapTrap(const std::string& name);
    ~ClapTrap();
    ClapTrap(const ClapTrap& other); // Copy constructor
    ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator

    //=============================== Functions ================================

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    //================================== Data ==================================

  protected:
    //=============== Types: Classes, Enums, and Aliases (using) ===============
    //================= Constructors, Assignments, Destructor ==================
    //=============================== Functions ================================
    //================================== Data ==================================

  private:
    //=============== Types: Classes, Enums, and Aliases (using) ===============
    //================= Constructors, Assignments, Destructor ==================

    ClapTrap();

    //=============================== Functions ================================
    //================================== Data ==================================

    std::string  name_;
    unsigned int hit_point_;
    unsigned int energy_point_;
    unsigned int attack_damage_;
};
