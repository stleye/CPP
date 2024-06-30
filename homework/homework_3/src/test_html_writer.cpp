#include "html_writer.hpp"
#include <cstdlib>

int main() {
  html_writer::OpenDocument();
  html_writer::AddCSSStyle("style.css");
  html_writer::AddTitle("Test HTML Writer");
  html_writer::OpenBody();
  html_writer::OpenRow();
  html_writer::AddImage("data/000000.png", 9.5, true);
  html_writer::AddImage("data/000100.png", 8.3);
  html_writer::CloseRow();
  html_writer::CloseBody();
  html_writer::CloseDocument();

  return EXIT_SUCCESS;
}
