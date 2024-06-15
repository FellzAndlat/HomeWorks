#include "sql_query_builder.h"
#include <sstream>

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) {
    columns.push_back(column);
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) {
    from_table = table;
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& column, const std::string& value) {
    where_conditions[column] = value;
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() const {
    std::ostringstream query;

    query << "SELECT ";

    if (columns.empty()) {
        query << "*";
    }
    else {
        for (size_t i = 0; i < columns.size(); ++i) {
            query << columns[i];
            if (i < columns.size() - 1) {
                query << ", ";
            }
        }
    }

    query << " FROM " << from_table;

    if (!where_conditions.empty()) {
        query << " WHERE ";
        bool first = true;
        for (const auto& condition : where_conditions) {
            if (!first) {
                query << " AND ";
            }
            query << condition.first << "=" << condition.second;
            first = false;
        }
    }

    query << ";";

    return query.str();
}