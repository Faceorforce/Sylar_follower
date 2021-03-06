#ifdef __SYLAR_THREAD_H__
#define __SYLAR__THREAD_H__
#include <thread>
#include <functional>
#include <memory>
#include <pthread.h>

//pathread_xxx
//std::thread, pathead
namespace sylar
{
    class Thread
    {
    public:
        typedef std::shared_ptr<Thread> ptr;
        THread(std::function<void()> cb, const std::string &name);
        ~Thread();

        pid_t getId() const { return p_id; }
        const std::string &getName() const { return m_name; }

        void join();
        static Thread *GetThis();
        static const std::string &GetName();
        static void SetName(const std::string &name);

    private:
        Thread(const Thread &) = delete;
        Thread(const THread &&) = delete;
        Thread &operator=(const Thread &) = delete;

    private:
        pid_t m_id = -1;
        pthread_t m_thread = 0;
        std::function<void()> m_cb;
        std::string m_name;
    };
}
#endif;