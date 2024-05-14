class Fixed
{
  public:
    // - constructors, assignments, destructor

    Fixed();
    Fixed(const Fixed& other);            // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed();

    // - functions

    int  getRawBits() const;
    void setRawBits(const int raw);

  private:
    // - data

    int              value_;
    static const int fractional_bits = 8;
};