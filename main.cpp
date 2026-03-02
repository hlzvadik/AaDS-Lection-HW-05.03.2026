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
void rmfake(BiList< T >* fake) noexcept
{
  ::operator delete(fake);
}
//

// Task 2
template< class T >
BiList< T >* insert(BiList< T >* prev, const T& data); // Добавление после
template< class T >
BiList< T >* add(BiList< T >* next, const T& data); // Добавление перед
template< class T >
BiList< T >* makeBiList(const T& data); // Создание BiList
template< class T >
BiList< T >* cut(BiList< T >* el); // Удаление элемента после
template< class T >
void clear(BiList< T >* fakeStart, BiList< T >* fakeEnd); // Удаление всего списка
//

// Task 3
template< class T >
BiList< T >* insert(BiList< T >* prev, const T& data)
{
  BiList< T >* el = new BiList< T >;
  el->val = data;
  el->prev = prev;
  el->next = prev->next;
  el->prev->next = el;
  el->next->prev = el;
  return el;
}

template< class T >
BiList< T >* add(BiList< T >* next, const T& data)
{
  BiList< T >* el = new BiList< T >;
  el->val = data;
  el->next = next;
  el->prev = next->prev;
  el->prev->next = el;
  el->next->prev = el;
  return el;
}

template< class T >
BiList< T >* makeBiList(const T& data)
{
  BiList< T >*el = new BiList< T >;
  el->val = data;
  fakeStart(el);
  fakeEnd(el);
  return el;
}

template< class T >
BiList< T >* cut(BiList< T >* el)
{
  BiList< T >* r = el->next;
  el->next = el->next->next;
  el->next->prev = el;
  delete r;
  return el;
}

template< class T >
void clear(BiList< T >* fakeStart, BiList< T >* fakeEnd)
{
  while(fakeStart->next != fakeEnd)
  {
    cut(fakeStart);
  }
  rmfake(fakeStart);
  rmfake(fakeEnd);
}
//

int main()
{
  // Task 4
  int a[2] = {1, 2};
  size_t len_a = 2;
  BiList< int >* aBL = makeBiList(a[0]);
  BiList< int >* fS = aBL->prev;
  BiList< int >* fE = aBL->next;
  for (size_t i = 1; i < len_a; ++i)
  {
    add(fE, a[i]);
  }
  clear(fS, fE);
  //
}
