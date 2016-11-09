#ifndef MEMORY_H
#define MEMORY_H

void* operator new(std::size_t size)
{
  return std::malloc(size);
}

void operator delete(void *ptr) noexcept
{
  std::free(ptr);
}

#endif // MEMORY_H

