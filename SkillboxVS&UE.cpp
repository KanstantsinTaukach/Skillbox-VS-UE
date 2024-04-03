#include <iostream>
#include <string>

constexpr int ARRSIZE = 10;

class Animal
{
public:
    virtual void Voice() = 0;
};

class Dog : public Animal
{
    void Voice() override
    {
        std::cout << "A dog sais: Woof - woof!";
    }
};

class MarchCat : public Animal
{
    void Voice() override
    {
        std::cout << "A march cat screams: MeeeeoooooowwWW!";
    }
};

class Badger : public Animal
{
    void Voice() override
    {
        std::cout << "A badger (illegible): Brr - mrrr - prrrr";
    }
};

int main()
{
    Animal* Animals[ARRSIZE];

    for (int i = 0; i < ARRSIZE; ++i)
    {
        if (i % 3 == 0)
        {
            Animals[i] = new Dog;
        }
        else if (i % 3 == 1)
        {
            Animals[i] = new MarchCat;
        }
        else
        {
            Animals[i] = new Badger;
        }
    }
    
    for (int i = 0; i < ARRSIZE; ++i)
    {
        Animals[i]->Voice();
        std::cout << std::endl;
    }
   
    return 0;
}
