#pragma once
#include "User.h"

class AdminUser : public User
{
private:
    String adminCode;

public:
    AdminUser(const String& name, const String& pass, const String& adminCode);

    bool isAdmin() const override;

    User* clone() const override;

    void saveToTextFile(std::ostream& os) const override;

    void saveToBinaryFile(std::ostream& os) const override;

    static User* loadFromTextFile(std::istream& is);
};