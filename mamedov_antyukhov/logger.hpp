#pragma once

#include <fstream>
#include <string>

namespace uni_course_cpp {
class Logger {
 public:
  static Logger& get_logger();
  void log(const std::string& string);

  Logger(const Logger& other) = delete;
  void operator=(const Logger& other) = delete;

  Logger(Logger&& other) = delete;
  void operator=(Logger&& other) = delete;

 private:
  ~Logger() = default;
  Logger();

  std::ofstream log_file_;
};
}  // namespace uni_course_cpp