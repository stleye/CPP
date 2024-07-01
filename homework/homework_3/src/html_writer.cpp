#include "html_writer.hpp"
#include <filesystem>
#include <fmt/core.h>

namespace fs = std::filesystem;

namespace html_writer {

void OpenDocument() {
  fmt::println("<!DOCTYPE html>");
  fmt::println("<html>");
}

void CloseDocument() { fmt::println("</html>"); }

void AddCSSStyle(const std::string &stylesheet) {
  fmt::println("<head>");
  fmt::println("<link rel=\"stylesheet\" type=\"text/css\" href=\"{}\" />",
               stylesheet);
  fmt::println("</head>");
}

void AddTitle(const std::string &title) {
  fmt::println("<title> {} </title>", title);
}

void OpenBody() { fmt::println("<body>"); }

void CloseBody() { fmt::println("</body>"); }

void OpenRow() { fmt::println("<div class=\"row\">"); }

void CloseRow() { fmt::println("</div>"); }

void AddImage(const std::string &img_path, float score, bool highlight) {

  fs::path filepath = img_path;
  fs::path filename = filepath.filename();

  if (highlight)
    fmt::println("<div class=\"column\" style=\" border:5px solid green;\">");
  else
    fmt::println("<div class=\"column\">");

  fmt::println("<h2> {} </h2>", filename.string());
  fmt::println("<img src=\"{}\" />", img_path);
  fmt::println("<p>score = {:.2f} </p>", score);
  fmt::println("</div>");
}

} // namespace html_writer