// Nikolay Stoyanov 2MI0600435

#pragma once

#include "User.h"

class AdminUser : public User
{
private:
    static uint32_t nextAdminCode;
    uint32_t adminCode;

public:
    AdminUser(const String& name, const String& pass, uint32_t adminCode);

    bool isAdmin() const override;

    User* clone() const override;

    void saveToTextFile(std::ostream& os) const override;

    void saveToBinaryFile(std::ostream& os) const override;

    static User* loadFromTextFile(std::istream& is);

    static uint32_t getNextAdminCode();
    static void setNextAdminCode(uint32_t newCode);
};