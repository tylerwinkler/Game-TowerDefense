template <class T>
ServiceLocator<T>::ServiceLocator()
{
    m_service = nullptr;

    m_initialized = false;
}

template <class T>
T& ServiceLocator<T>::getService()
{
    return *m_service;
}

template <class T>
void ServiceLocator<T>::setService(T* service)
{
    if (m_service != nullptr)
    {
        delete m_service;
    }

    m_service = service;

    m_initialized = true;
}
