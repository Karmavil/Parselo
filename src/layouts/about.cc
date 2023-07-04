#include "parselo/layouts/about.hh"

parselo::About::About ()
{
  m_Label.set_text ("About this program and how to use it");
  set_child (m_Label);
}

parselo::About::~About () {}
