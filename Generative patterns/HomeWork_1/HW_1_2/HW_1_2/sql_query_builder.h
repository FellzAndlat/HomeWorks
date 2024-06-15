#ifndef SQL_QUERY_BUILDER_H
#define SQL_QUERY_BUILDER_H

#include <string>
#include <vector>
#include <map>

class SqlSelectQueryBuilder {
private:
    std::vector<std::string> columns;
    std::string from_table;
    std::map<std::string, std::string> where_conditions;
public:
    SqlSelectQueryBuilder& AddColumn(const std::string& column);

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;

    SqlSelectQueryBuilder& AddFrom(const std::string& table);

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value);

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;

    std::string BuildQuery() const;
};

#endif