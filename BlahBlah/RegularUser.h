// Nikolay Stoyanov 2MI0600435

#pragma once

#include "User.h"

class RegularUser : public User
{
public:
    RegularUser(const String& name, const String& pass);

    bool isAdmin() const override;

    User* clone() const override;

    void saveToTextFile(std::ostream& os) const override;

    void saveToBinaryFile(std::ostream& os) const override;

    static User* loadFromTextFile(std::istream& is);
};