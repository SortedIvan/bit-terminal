#include <string>
using std::string;
class Account {
	string account_id;
	string account_name;
	string account_password;
	public:
		Account();

		void SetAccountId(string account_id);
		string GetAccountId();

		void SetAccountName(string account_name);
		string GetAccountName();

		void SetAccountPassword(string account_password);
		string GetAccountPassword();

};