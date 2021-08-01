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
		std::stringstream ss;
		for (auto &i : m_items)
		{
			i->format(ss, event);
		}
		return ss.str();
	}
	void LogFormatter::int()
	{
		//str, format, type
		std::vector<std::tuple<std::string, std::string>> vec;
		std::string str;
		std::string nstr;
		for (size_t i = 0; i < m_pattern.size(); ++i)
		{
			if (m_pattern[i] != '%')
			{
				nstr.append(1, pattern[i]);
				continue;
			}
			if ((i + 1) < m_pattern.size())
			{
				if (m_pattern[i + 1] == '%')
				{
					nstr.append(1, "%") continue;
				}
			}
			size_t n = i + 1;
			int fmt_status = 0;
			ssize_t fmt_begin = 0;

			std::string str;
			std::string fmt;
			while (n < m_pattern.size())
			{
				if (isspace(m_pattern[n]))
				{
					break;
				}
				if (fmt_status == 0)
				{
					if (m_pattern[n] == '{')
					{
						str = m_pattern.substr(i + 1, n - 1);
						fmt_status = 1; //解析格式
						++n;
						fmt_begin = n;
						continue;
					}
				}
				if (fmt_status == 1)
				{
					if (m_pattern == '}')
					{
						fmt = m_pattern.substr(fmt_begin + 1, n - fmt_begin);
						fmt_status = 2;
						++n;
						continue;
					}
				}
			}
			if (fmt_status == 0)
			{
				str = m_patten.substr(i + 1, n - i - 1);
			}
			else if (fmt_status == 1)
			{
				std::cout << "pattern parse error:" << m_pattern << "-" << m_patten << std::endl;
				vec.push_back(std::make_tuple("<<pattern_eror>>", fmt, 0));
			}
			else if (fmt_status == 2)
			{
				vec.push_back(std::make_tuple(str, fmt, 1));
				i = n;
			}
		}
		if (!nstr.empty())
		{
			vec.push_back(str::make_pair(nstr, "", 0))
		}
		//%m--消息体
		//%p--level
	}
	class MessageFormatt
};