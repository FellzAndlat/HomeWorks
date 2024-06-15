#include "sql_query_builder.h"
#include <iostream>
#include <cassert>

int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    std::string expected_query = "SELECT name, phone FROM students WHERE id=42 AND name=John;";
    assert(query_builder.BuildQuery() == expected_query);

    std::cout << query_builder.BuildQuery() << std::endl;

    return 0;
}