#include <iostream>

template< class T >
struct BiList
{
  T val;
  BiList< T >* next;
  BiList< T >* prev;
};

// Task 0
template< class T >
BiList< T >* fakeStart(BiList< T >* next)
{
  BiList< T >* el = static_cast< BiList< T >* >(::operator new(sizeof(BiList< T >*)));
  el->next = next;
  next->prev = el;
  return el;
}

template< class T >
BiList< T >* fakeEnd(BiList< T >* prev)
{
  BiList< T >* el = static_cast< BiList< T >* >(::operator new(sizeof(BiList< T >*)));
  el->prev = prev;
  prev->next = el;
  return el;
}

template< class T >
BiList< T >* rmfake(BiList< T >* fake) noexcept
{
  BiList< T >* ret = fake->next;
  ret->prev = nullptr;
  ::operator delete(fake);
  return ret;
}

// Task 1
template< class T >
BiList< T >* insert(BiList< T >* prev, const T& data); // Добавление после
template< class T >
BiList< T >* add(BiList< T >* next, const T& data); // Добавление перед
template< class T >
BiList< T >* makeBiList(const T& data); // Создание BiList
template< class T >
BiList< T >* cut(BiList< T >* el); // Удаление элемента
template< class T >
void clear(BiList< T >* fakeStart, BiList< T >* fakeEnd); // Удаление всего списка

int main()
{}