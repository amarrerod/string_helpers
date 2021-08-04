
#ifndef __STRING_HELPERS_H__
#define __STRING_HELPERS_H__

#include <algorithm>
#include <string>
#include <vector>

namespace string_helper {
using namespace std::string_literals;

template <typename CharT>
using tstring =
    std::basic_string<CharT, std::char_traits<CharT>, std::allocator<CharT>>;

template <typename CharT>
using tstringstream = std::basic_stringstream<CharT, std::char_traits<CharT>,
                                              std::allocator<CharT>>;

/**
 * @brief Function to convert a string to uppercarse
 *
 * @tparam CharT
 * @param text
 * @return tstring<CharT>
 */
template <typename CharT>
inline tstring<CharT> to_upper(tstring<CharT> text) {
    std::transform(std::begin(text), std::end(text), std::begin(text), toupper);
    return text;
}
/**
 * @brief Function to convert a string to lowercase
 *
 * @tparam CharT
 * @param text
 * @return tstring<CharT>
 */
template <typename CharT>
inline tstring<CharT> to_lower(tstring<CharT> text) {
    std::transform(std::begin(text), std::end(text), std::begin(text), tolower);
    return text;
}

/**
 * @brief Function to reverse a string
 *
 * @tparam CharT
 * @param text
 * @return tstring<CharT>
 */
template <typename CharT>
inline tstring<CharT> reverse(tstring<CharT> text) {
    std::reverse(std::begin(text), std::end(text));
    return text;
}

/**
 * @brief Function to trim a string. Removes beginning and ending whitespaces
 *
 * @tparam CharT
 * @param text
 * @return tstring<CharT>
 */
template <typename CharT>
inline tstring<CharT> trim(tstring<CharT> const& text) {
    auto first{text.find_first_not_of(' ')};
    auto last{text.find_last_not_of(' ')};
    return text.substr(first, (last - first + 1));
}

/**
 * @brief Function to remove whitespace on the left of a string type
 *
 * @tparam CharT
 * @param text
 * @return tstring<CharT>
 */
template <typename CharT>
inline tstring<CharT> trimleft(tstring<CharT> const& text) {
    auto first{text.find_first_not_of(' ')};
    return text.substr(first, text.size() - first);
}

/**
 * @brief Function to remove whitespaces on the right side of a string type
 *
 * @tparam CharT
 * @param text
 * @return tstring<CharT>
 */
template <typename CharT>
inline tstring<CharT> trimright(tstring<CharT> const& text) {
    auto last{text.find_last_not_of(' ')};
    return text.substr(0, last + 1);
}

/**
 * @brief Function to remove specific characters from the sides of a string type
 *
 * @tparam CharT
 * @param text
 * @param chars
 * @return tstring<CharT>
 */
template <typename CharT>
inline tstring<CharT> trim(tstring<CharT> const& text,
                           tstring<CharT> const& chars) {
    auto first{text.find_first_not_of(chars)};
    auto last{text.find_last_not_of(chars)};
    return text.substr(first, (last - first + 1));
}

/**
 * @brief Function to remove specific characters from the beginning of a string
 * type
 *
 * @tparam CharT
 * @param text
 * @param chars
 * @return tstring<CharT>
 */
template <typename CharT>
inline tstring<CharT> trimleft(tstring<CharT> const& text,
                               tstring<CharT> const& chars) {
    auto first{text.find_first_not_of(chars)};
    return text.substr(first, text.size() - first);
}

/**
 * @brief Function to remove specific characters from the end of a string type
 *
 * @tparam CharT
 * @param text
 * @param chars
 * @return tstring<CharT>
 */
template <typename CharT>
inline tstring<CharT> trimright(tstring<CharT> const& text,
                                tstring<CharT> const& chars) {
    auto last{text.find_last_not_of(chars)};
    return text.substr(0, last + 1);
}

/**
 * @brief Function to remove a certain character from a string type
 *
 * @tparam CharT
 * @param text
 * @param character
 * @return tstring<CharT>
 */
template <typename CharT>
inline tstring<CharT> remove(tstring<CharT> text, CharT const character) {
    auto start = std::remove_if(std::begin(text), std::end(text),
                                [=](CharT const c) { return c == character; });
    text.erase(start, std::end(text));
    return text;
}

/**
 * @brief Function to split a string in tokens by the delimiter
 *
 * @tparam CharT
 * @param text
 * @param delimiter
 * @return std::vector<tstring<CharT>>
 */
template <typename CharT>
inline std::vector<tstring<CharT>> split(tstring<CharT> text,
                                         CharT const delimiter) {
    auto sstr = tstringstream<CharT>{text};
    auto tokens = std::vector<tstring<CharT>>{};
    auto token = tstring<CharT>{};
    while (std::getline(sstr, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}
}  // namespace string_helper

#endif