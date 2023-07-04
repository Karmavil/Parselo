#include "parselo/layouts/inquiry.hh"

parselo::Inquiry::Inquiry ()
{
  m_Label.set_text ("Inquiries are made here");
  set_child (m_Label);
}

parselo::Inquiry::~Inquiry () {}
