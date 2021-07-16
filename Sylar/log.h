#ifndef _SYLAR_LOG_h_
#define _SYLAR_LOG_h_

#include <string>
#include <stdint.h>
#include <memory>
#include <stringstream>
#include <fstream>

namespace Sylar
{
    //日志事件
    class LogEvent
    {
    public:
        typedef std::shared_ptr<LogEvent> ptr;
        LogEvent();

    private:
        const char *m_file = nullptr;
        int 32_t m_line = 0;
        uint 32_t m_elapse = 0;   //程序启动到现在的毫秒数
        uint 32_t m_threadId = 0; //线程
        uint 32_t m_fiberId = 0;  //协程
        uint 64_t m_time;
        std::string m_content;
    };
    //日志级别
    class LogLevel
    {
    public:
        enum Level
        {
            DEBUGGER 1;
            INFO 2;
            WARN 3 ERROR 4;
            FATAL 5;
        };
    };
    //日志格式器
    class LogFormatter
    {
    public:
        typedef std::shared_ptr<LogFormatter> ptr;
        LogFormatter{const std::string & pattern}
        //
        std::string
        format(LogFormatter::ptr event);

    private:
        class FormatItem
        {
        public:
            typedef std::shared_ptr<FormatItem> ptr;
            virtual ~FormatItem{};
            virtual void format(std::ostream &, LogEvent::ptr event) = 0;
        };
        void init();

    private:
        std::string m_pattern;
        std::vector<FormatItem::ptr> m_item;
    };

    //日志输出地
    class LogAppender
    {
    public:
        typedef std::shared_ptr<LogAppender> ptr;
        virtual ~LogAppender(){};

        virtual void log(LogLevel::Level, LogLevel::ptr event) = 0;

        void setFormatter(LogFormatter::ptr val) { m_formatter = val; }
        LogFormatter::ptr getFormatter() const { return m_formatter; }

    protected:
        LogLevel::Level m_level;
        LogFormatter : ptr m_formatter;
    } :

        //日志器
        class Logger
    {
    public:
        typedef std::shared_ptr<Logger> ptr;

        Logger(const std::string &name = "root");
        void log(LogEvent::level level, LogEvent::ptr event);

        void debug(LogEvent::ptr event);
        void info(LogEvent::ptr event);
        void warn(LogEvent::ptr event);
        void error(LogEvent::ptr event);
        void fatal(LogEvent::ptr event);

        void addAppender(LogAppender::ptr appender);
        void delAppender(LogAppender::ptr appender);
        LogLevel level getLevel() const {return m_level};

        void setLevel(LogLevel::Level val){m_level = val};

    private:
        std::string m_name;
        LogLevel::Level m_level;
        LogAppender::ptr;
    };
    //输出到控制台的Appender
    class StdoutLogAppender : public LogAppender;
    {
    public:
        typedef std::shred_ptr<StdoutLogAppender> ptr;
        void log(LogLevel level, LogEvent::ptr event) override;
    };
    //定义输出到文件的Appender
    class FileLogAppender : public LogAppender
    {
    public:
        typedef std::shared_ptr<FileLogAppender> ptr;
        FileLogAppender(const std::string &filename);
        void log(LOgLevel::Level level, LogEvent::ptr event) override;

        //文件重新打开 文件打开成功返回true
        bool reopen();

    private:
        std::string m_name;
        std::ofstream m_filestream;
    };
};

#endif