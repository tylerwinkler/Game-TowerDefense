#ifndef SERVICELOCATOR_HPP
#define SERVICELOCATOR_HPP

template <class T>
class ServiceLocator
{
public:
    ServiceLocator<T>();

    T& getService();

    void setService(T* service);

    bool isInitialized(){return m_initialized;}

private:
    T* m_service;
    bool m_initialized;
};

#include "ServiceLocator.tpp"

#endif // SERVICELOCATOR_HPP
