#ifndef _VAULT_TESTS_COMMON_HPP_
#define _VAULT_TESTS_COMMON_HPP_

#include <QStringList>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__  ":" TOSTRING(__LINE__)

namespace {

template <class CharT>
std::basic_ostream<CharT>& operator <<
(std::basic_ostream<CharT> &dst, QStringList const &src)
{
    for (auto v : src)
        dst  << v.toStdString() << ",";
    return dst;
}

template <class CharT, class T>
std::basic_ostream<CharT>& operator <<
(std::basic_ostream<CharT> &dst, QSet<T> const &src)
{
    for (auto v : src)
        dst  << str(v) << ",";
    return dst;
}

template <class CharT>
std::basic_ostream<CharT>& operator <<
(std::basic_ostream<CharT> &dst, QString const &src)
{
    dst << src.toStdString();
    return dst;
}

QStringList strings()
{
    return QStringList();
}

template <typename ...A>
QStringList strings(QString const &s, A &&...args)
{
    return QStringList(s) + strings(std::forward<A>(args)...);
}

template <typename T>
QString dump(T && t)
{
    QString s;
    QDebug d(&s);
    d << t;
    return s;
}

}


#endif // _VAULT_TESTS_COMMON_HPP_
