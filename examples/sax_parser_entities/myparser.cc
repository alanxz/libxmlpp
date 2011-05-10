// -*- C++ -*-

/* myparser.cc
 *
 * Copyright (C) 2002 The libxml++ development team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "myparser.h"

#include <iostream>

MySaxParser::MySaxParser()
  : xmlpp::SaxParser(true /* override on_get_entity */)
{
}

MySaxParser::~MySaxParser()
{
}

void MySaxParser::on_start_document()
{
  std::cout << "on_start_document()" << std::endl;
}

void MySaxParser::on_end_document()
{
  std::cout << "on_end_document()" << std::endl;
}

void MySaxParser::on_start_element(const xmlpp::string& name,
                                   const AttributeList& attributes)
{
  std::cout << "node name=" << name << std::endl;

  // Print attributes:
  for(xmlpp::SaxParser::AttributeList::const_iterator iter = attributes.begin(); iter != attributes.end(); ++iter)
  {
    std::cout << "  Attribute " << iter->name << " = " << iter->value << std::endl;
  }
}

void MySaxParser::on_end_element(const xmlpp::string& /* name */)
{
  std::cout << "on_end_element()" << std::endl;
}

void MySaxParser::on_characters(const xmlpp::string& text)
{
  std::cout << "on_characters(): " << text << std::endl;
}

void MySaxParser::on_comment(const xmlpp::string& text)
{
  std::cout << "on_comment(): " << text << std::endl;
}

void MySaxParser::on_warning(const xmlpp::string& text)
{
  std::cout << "on_warning(): " << text << std::endl;
}

void MySaxParser::on_error(const xmlpp::string& text)
{
  std::cout << "on_error(): " << text << std::endl;
}

void MySaxParser::on_fatal_error(const xmlpp::string& text)
{
  std::cout << "on_fatal_error(): " << text << std::endl;
}

_xmlEntity* MySaxParser::on_get_entity(const xmlpp::string& name)
{
  std::cout << "on_get_entity(): " << name << std::endl;
  
  //Call the base class:
  return SaxParser::on_get_entity(name);
}

void MySaxParser::on_entity_declaration(const xmlpp::string& name, xmlpp::XmlEntityType type, const xmlpp::string& publicId, const xmlpp::string& systemId, const xmlpp::string& content)
{
  std::cout << "on_entity_declaration(): name=" << name << ", publicId=" << publicId << ", systemId=" << systemId << ", content=" << content << std::endl;

  //Call the base class:
  SaxParser::on_entity_declaration(name, type, publicId, systemId, content);
}


