/* document.cc
 * this file is part of libxml++
 *
 * copyright (C) 2003 by the libxml++ development team
 *
 * this file is covered by the GNU Lesser General Public License,
 * which should be included with libxml++ as the file COPYING.
 */

#include <libxml++/document.h>
#include <libxml++/dtd.h>
#include <libxml++/attribute.h>
#include <libxml++/nodes/element.h>
#include <libxml++/exceptions/internal_error.h>
#include <libxml++/keepblanks.h>
#include <libxml++/io/ostreamoutputbuffer.h>

#include <libxml/tree.h>

#include <iostream>

namespace xmlpp
{

Document::Init::Init()
{
  xmlInitParser(); //Not always necessary, but necessary for thread safety.
}

Document::Init::~Init()
{
  //We don't call this because it breaks libxml generally and should only be
  //called at the very end of a process, such as at the end of a main().
  //libxml might still be used by the application, so we don't want to break
  //that.
  //This is important even here, which usually happens only when the library
  //is unloaded, because that might happen during normal application use,
  //if the application does dynamic library loading, for instance to load
  //plugins.
  //See http://xmlsoft.org/html/libxml-parser.html#xmlCleanupParser
  //xmlCleanupParser(); //As per xmlInitParser(), or memory leak will happen.
}

Document::Init Document::init_;

Document::Document(const xmlpp::string& version)
  : impl_(xmlNewDoc((const xmlChar*)version.c_str()))
{
  impl_->_private = this;
}

Document::Document(xmlDoc* doc)
  : impl_(doc)
{
  impl_->_private = this;
}

Document::~Document()
{
  Node::free_wrappers(reinterpret_cast<xmlNode*>(impl_));
  xmlFreeDoc(impl_);
}

xmlpp::string Document::get_encoding() const
{
  xmlpp::string encoding;
  if(impl_->encoding)
    encoding = (const char*)impl_->encoding;

  return encoding;
}

Dtd* Document::get_internal_subset() const
{
  xmlDtd* dtd = xmlGetIntSubset(impl_);
  if(!dtd)
    return 0;

  if(!dtd->_private)
    dtd->_private = new Dtd(dtd);

  return reinterpret_cast<Dtd*>(dtd->_private);
}

void Document::set_internal_subset(const xmlpp::string& name,
                                   const xmlpp::string& external_id,
                                   const xmlpp::string& system_id)
{
  xmlDtd* dtd = xmlCreateIntSubset(impl_,
				   (const xmlChar*)name.c_str(),
				   external_id.empty() ? (const xmlChar*)0 : (const xmlChar*)external_id.c_str(),
				   system_id.empty() ? (const xmlChar*)0 : (const xmlChar*)system_id.c_str());

  if (dtd && !dtd->_private)
    dtd->_private = new Dtd(dtd);
}

Element* Document::get_root_node() const
{
  xmlNode* root = xmlDocGetRootElement(impl_);
  if(root == 0)
    return 0;
  else
  {
    Node::create_wrapper(root);
    return reinterpret_cast<Element*>(root->_private);
  }
}

Element* Document::create_root_node(const xmlpp::string& name,
                                    const xmlpp::string& ns_uri,
                                    const xmlpp::string& ns_prefix)
{
  xmlNode* node = xmlNewDocNode(impl_, 0, (const xmlChar*)name.c_str(), 0);
  xmlDocSetRootElement(impl_, node);

  Element* element = get_root_node();

  if( !ns_uri.empty() )
  {
    element->set_namespace_declaration(ns_uri, ns_prefix);
    element->set_namespace(ns_prefix);
  }

  return element;
}

Element* Document::create_root_node_by_import(const Node* node,
					      bool recursive)
{
  //Create the node, by copying:
  xmlNode* imported_node = xmlDocCopyNode(const_cast<xmlNode*>(node->cobj()), impl_, recursive);
  if (!imported_node)
  {
    #ifdef LIBXMLCPP_EXCEPTIONS_ENABLED
    throw exception("Unable to import node");
    #else
    return 0;
    #endif //LIBXMLCPP_EXCEPTIONS_ENABLED
  }

  xmlDocSetRootElement(impl_, imported_node);

  return get_root_node();
}

CommentNode* Document::add_comment(const xmlpp::string& content)
{
  xmlNode* node = xmlNewComment((const xmlChar*)content.c_str());
  if(!node)
  {
    #ifdef LIBXMLCPP_EXCEPTIONS_ENABLED
    throw internal_error("Cannot create comment node");
    #else
    return 0;
    #endif //LIBXMLCPP_EXCEPTIONS_ENABLED
  }

  // Use the result, because node can be freed when merging text nodes:
  node = xmlAddChild( (xmlNode*)impl_, node);
  Node::create_wrapper(node);
  return static_cast<CommentNode*>(node->_private);
}

void Document::write_to_file(const xmlpp::string& filename, const xmlpp::string& encoding)
{
  do_write_to_file(filename, encoding, false);
}

void Document::write_to_file_formatted(const xmlpp::string& filename, const xmlpp::string& encoding)
{
  do_write_to_file(filename, encoding, true);
}

xmlpp::string Document::write_to_string(const xmlpp::string& encoding)
{
  return do_write_to_string(encoding, false);
}

xmlpp::string Document::write_to_string_formatted(const xmlpp::string& encoding)
{
  return do_write_to_string(encoding, true);
}

void Document::write_to_stream(std::ostream& output, const xmlpp::string& encoding)
{
  do_write_to_stream(output, encoding.empty()?get_encoding():encoding, false);
}

void Document::write_to_stream_formatted(std::ostream& output, const xmlpp::string& encoding)
{
  do_write_to_stream(output, encoding.empty()?get_encoding():encoding, true);
}

void Document::do_write_to_file(
    const xmlpp::string& filename,
    const xmlpp::string& encoding,
    bool format)
{
  KeepBlanks k(KeepBlanks::Default);
  xmlIndentTreeOutput = format?1:0;
  const int result = xmlSaveFormatFileEnc(filename.c_str(), impl_, encoding.empty() ? 0 : encoding.c_str(), format?1:0);

  if(result == -1)
  {
    #ifdef LIBXMLCPP_EXCEPTIONS_ENABLED
    throw exception("do_write_to_file() failed.");
    #else
    return;
    #endif //LIBXMLCPP_EXCEPTIONS_ENABLED
  }
}

xmlpp::string Document::do_write_to_string(
    const xmlpp::string& encoding,
    bool format)
{
  KeepBlanks k(KeepBlanks::Default);
  xmlIndentTreeOutput = format?1:0;
  xmlChar* buffer = 0;
  int length = 0;

  xmlDocDumpFormatMemoryEnc(impl_, &buffer, &length, encoding.empty() ? 0 : encoding.c_str(), format?1:0);

  if(!buffer)
  {
    #ifdef LIBXMLCPP_EXCEPTIONS_ENABLED
    throw exception("do_write_to_string() failed.");
    #else
    return xmlpp::string();
    #endif //LIBXMLCPP_EXCEPTIONS_ENABLED
  }

  // Create a xmlpp::string copy of the buffer

  // Here we force the use of Glib::ustring::ustring( InputIterator begin, InputIterator end )
  // instead of Glib::ustring::ustring( const char*, size_type ) because it
  // expects the length of the string in characters, not in bytes.
  xmlpp::string result( reinterpret_cast<const char *>(buffer), reinterpret_cast<const char *>(buffer + length) );

  // Deletes the original buffer
  xmlFree(buffer);
  // Return a copy of the string
  return result;
}

void Document::do_write_to_stream(std::ostream& output, const xmlpp::string& encoding, bool format)
{
  // TODO assert document encoding is UTF-8 if encoding is different than UTF-8
  OStreamOutputBuffer buffer(output, encoding);
  const int result = xmlSaveFormatFileTo(buffer.cobj(), impl_, encoding.c_str(), format ? 1 : 0);
  
  if(result == -1)
  {
    #ifdef LIBXMLCPP_EXCEPTIONS_ENABLED
    throw exception("do_write_to_stream() failed.");
    #else
    return;
    #endif //LIBXMLCPP_EXCEPTIONS_ENABLED
  }
}

void Document::set_entity_declaration(const xmlpp::string& name, XmlEntityType type,
                              const xmlpp::string& publicId, const xmlpp::string& systemId,
                              const xmlpp::string& content)
{
  xmlAddDocEntity( impl_, (const xmlChar*) name.c_str(), type,
    publicId.empty() ? (const xmlChar*)0 : (const xmlChar*)publicId.c_str(),
    systemId.empty() ? (const xmlChar*)0 : (const xmlChar*)systemId.c_str(),
    (const xmlChar*) content.c_str() );
}

_xmlEntity* Document::get_entity(const xmlpp::string& name)
{
  return xmlGetDocEntity(impl_, (const xmlChar*) name.c_str());
}

_xmlDoc* Document::cobj()
{
  return impl_;
}

const _xmlDoc* Document::cobj() const
{
  return impl_;
}

} //namespace xmlpp
