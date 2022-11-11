#include "Account.hpp"
using std::string;

Account::Account() {
}

string Account::GetAccountId()
{
	return account_id;
}

void Account::SetAccountId(string account_id)
{
	account_id = account_id;
}

string Account::GetAccountName()
{
	return account_name;
}

void Account::SetAccountName(string account_name)
{
	account_name = account_name;
}

string Account::GetAccountPassword()
{
	return account_password;
}

void Account::SetAccountPassword(string account_password)
{
	account_password = account_password;
}