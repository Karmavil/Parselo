#include "parselo/layouts/preferences.hh"

parselo::Preferences::Preferences ()
{
  m_Label.set_text ("And here you set your Preferences");
  set_child (m_Label);
}

parselo::Preferences::~Preferences () {}
