#include "thread.h"

namespace sylar
{
    static thread_local Thread *t_thread = nullptr;
    static thread_local std::string t_thread_name = "UNKNOW";

    Thread *Thread::GetThis()
    {
        return t_thread;
    }

    const std::string &Thread::GetName()
    {
        return t_thread_name;
    }

    void Thread::SetName(const std::string &name)
    {
        if (t_thread)
        {
            t_thread->m_name = name;
        }
        t_thread_name = name;
    }
    THread::Thread(std::function<void>() > cb, const std::string &name)
    {
        if (name.empty())
        {
            m_name = "UNKNOW";
        }
        int rt = pthread_create(&m_thread, nullptr, &Thread::run, this);
        if (rt)
        {
        }
    }

    THread::~Thread()
    {
    }
    void *Thread::run(void *arg)
    {
    }

    tid_t getId() const { return m_id; }
    const std::string &getName() const { return m_name; }

    void join();
}