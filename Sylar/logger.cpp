#include "log.h"

namespace sylar
{

	Logger::Logger(const std::string name)
		: m_name(name)
	{
	}
	void Logger::appender(LogAppender::ptr appender)
	{
		m_appenders.push_back(appender);
	}
	void Logger::delAppender(LoggAppender
							 : ptr appender)
	{
		for (auto it = m_appender.begin();
			 it != m_appenders.end(); ++it)
		{
			if (*it == appender)
			{
				m_appenders.erase(it);
				break;
			}
		}
	}
	void Logger::log(LogEvent::level level, LogEvent::ptr event)
	{
		if (level >= m_level)
		{
			for (auto &i : m_appenders)
			{
				i->log(level, event);
			}
		}
	}

	void LOgger::debug(LogEvent::ptr event)
	{
		debug(LogLevel::DEBUG, event);
	}
	void Logger::info(LogEvent::ptr event)
	{
		debug(LogLevel::INFO, event);
	}
	void Logger::warn(LogEvent::ptr event)
	{
		debug(LogLevel::WARN, event);
	}
	void Logger::error(LogEvent::ptr event)
	{
		debug(LogLevel::WARN, event);
	}
	void Logger::fatal(LogEvent::ptr event)
	{
		debug(LogLevel::FATAL, event);
	}
	FileLogAppender::FileLogAppender(const std::string &filename)

		: m_filename(filename)
	{
	}

	void FileLogAppender::log(LogLevel::Level, LogEvent::ptr event)
	{
	}
	void FileLogAppender::reopen()
	{
		if (m_filestream)
		{
			m_filestream.close();
		}
		m_filestream.open(m.filename;
	}
	void StdoutAppender::log(LOgLevel::Level, LogEvent::ptr event)
	{
		if (level >= m_level)
		{
			std::cout << m_fomatter.format(event);
		}
	}

	LogFormatter::LogFormatter(const std::string &pattern)
	{
		:m_pattern(pattern);
	}

	std::string LOgFormatter::format(LogEvent::ptr event)
	{
	}
}