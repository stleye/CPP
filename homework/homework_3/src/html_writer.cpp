#include "html_writer.hpp"
#include <fmt/core.h>

namespace html_writer {

void OpenDocument() {
  fmt::println("<!DOCTYPE html>");
  fmt::println("<html>");
}

void CloseDocument() { fmt::println("</html>"); }

void AddCSSStyle(const std::string &stylesheet) {
  //<link rel = "stylesheet" href = "styles.css">
  fmt::println("<link rel = \"stylesheet\" href = {}>", stylesheet);
  // std::cout << "<link rel=\" stylesheet \" href=\"" << stylesheet << "\">"<<
  // std::endl;
}

void AddTitle(const std::string &title) {
  fmt::println("<title> {} </title>", title);
}

void OpenBody() { fmt::println("<body>"); }

void CloseBody() { fmt::println("</body>"); }

void OpenRow() { fmt::println("<div class=\" row \">"); }

void CloseRow() { fmt::println("</div>"); }

void AddImage(const std::string &img_path, float score, bool highlight) {
  if (highlight)
    fmt::println(
        "<div class = \"column\" style = \" border : 5px solid green;\">");

  fmt::println("<h2> {} </h2>", img_path);
  fmt::println("<img src=\"{}\" />", img_path);
  fmt::println("<p>score = {:.2f} </p>", score);

  if (highlight)
    fmt::println("</div>");
}

} // namespace html_writer