#ifndef CORIN_STDLIB_BASE64_H
#define CORIN_STDLIB_BASE64_H

#include <string>

namespace corin {
namespace base64 {

std::string encode(const std::string& data);
std::string decode(const std::string& encoded);

} // namespace base64
} // namespace corin

#endif // CORIN_STDLIB_BASE64_H
