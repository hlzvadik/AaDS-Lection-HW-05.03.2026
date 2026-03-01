#include <iostream>

template< class T >
struct BiList
{
  T val;
  BiList< T >* next;
  BiList< T >* prev;
};

template< class T >
BiList< T >* fake(BiList< T >* next)
{
  BiList< T >* el = static_cast< BiList< T >* >(::operator new (sizeof(BiList< T >*)));
  el->next = next;
  next->prev = el;
  return next;
}

template< class T >
BiList< T >* rmfake(BiList< T >* fake) noexcept
{
  BiList< T >* ret = fake->next;
  ret->prev = nullptr;
  ::operator delete(fake);
  return ret;
}

int main()
{}