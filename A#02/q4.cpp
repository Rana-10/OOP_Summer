// Assignment 02
// Muhammad Azmat
// 23i-2651
// OOP-B

#include <iostream>
#include <string>

using namespace std;

class bank
{
private:
    string account_owner;
    int bill_number;
    int total_cash;
    int withdraw_cash;
    int deposit_cash;
    int account_id;

public:
    bank() : account_owner(""), bill_number(0), total_cash(0), withdraw_cash(0), deposit_cash(0), account_id(0) {}
    bank(string owner_name, int acc_id, int moneyy)
    {
        account_owner = owner_name;
        account_id = acc_id;
        total_cash = moneyy;
    }

    void pay_bill(int bill_no, int bill_amount)
    {
        bill_number = bill_no;
        if (total_cash >= bill_amount)
        {
            total_cash = total_cash - bill_amount;
            cout << "Congratulations, Your bill payment was successful! " << endl;
        }
        else
        {
            cout << "You don't have sufficient funds in account to pay this bill poor guy :( " << endl;
        }
    }

    void deposit_money(int rich_boy_money)
    {
        total_cash = total_cash + rich_boy_money;
    }

    void withdraw_money(int poor_boy_money)
    {
        if (total_cash >= poor_boy_money)
        {
            total_cash = total_cash - poor_boy_money;
        }
        else
        {
            cout << "You are poor :(" << endl;
        }
    }

    void make_new_account(string acc_owner_name, int acc_owner_id, int paisa)
    {
        account_owner = acc_owner_name;
        account_id = acc_owner_id;
        total_cash = paisa;
    }

    void view_account_deets()
    {
        cout << "Account holder name: " << account_owner << endl;
        cout << "Your account number is: " << account_id << endl;
        cout << "Your total balance is: " << total_cash << endl;
    }

    void back_to_menu()
    {
        return;
    }

    int get_bill_no()
    {
        return bill_number;
    }

    void set_deposited_cash(int paisa)
    {
        deposit_cash = paisa;
    }

    int get_total_cash()
    {
        return total_cash;
    }

    int get_account_id()
    {
        return account_id;
    }

    void set_total_cash(int x)
    {
        total_cash = x;
    }
};

class atm
{
private:
    bank *accounts[15];
    int pin_code[15];
    int accounts_count;

public:
    atm() : accounts_count(0) {}

    void add_account(bank *account, int pin_codee)
    {
        if (accounts_count < 15)
        {
            accounts[accounts_count] = account;
            pin_code[accounts_count] = pin_codee;
            accounts_count++;
        }
        else
        {
            cout << "Bank account creation limit reached :o " << endl;
        }
    }

    bool pin_validation(int acc_id, int pin)
    {
        for (int i = 0; i < accounts_count; i++)
        {
            if (accounts[i]->get_account_id() == acc_id)
            {
                if (pin_code[i] == pin)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }

    void withdraw_cash_from_atm(int acc_id, int moneyy)
    {
        for (int i = 0; i < accounts_count; i++)
        {
            if (accounts[i]->get_account_id() == acc_id)
            {
                accounts[i]->withdraw_money(moneyy);
                return;
            }
        }
        cout << "Invalid Account ID, Make sure you're typing the correct ID." << endl;
    }

    void change_pin(int acc_id, int pin_codee)
    {
        for (int i = 0; i < accounts_count; i++)
        {
            if (accounts[i]->get_account_id() == acc_id)
            {
                pin_code[i] = pin_codee;
                cout << "Your 4 digit PIN has been changed." << endl;
                return;
            }
        }
        cout << "Account ID not found, Try again! " << endl;
    }

    void balance_enquiry(int acc_id)
    {
        for (int i = 0; i < accounts_count; ++i)
        {
            if (accounts[i]->get_account_id() == acc_id)
            {
                accounts[i]->view_account_deets();
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void exit_to_main()
    {
        cout << "** Exiting to main menu, bye bye ** " << endl;
    }
};

class admin
{
private:
    bank *accounts[15];
    int accounts_count;
    string admin_name;
    string admin_pass;

public:
    admin() : admin_name("admin"), admin_pass("12345678"), accounts_count(0){};

    string get_admin_name()
    {
        return admin_name;
    }

    string get_admin_pass()
    {
        return admin_pass;
    }

    void user_authentication(string name, string pass)
    {
        if (get_admin_name() != name || get_admin_pass() != pass)
        {
            cout << "Credentials don't match for admin, try again! " << endl;
        }
        else
        {
            cout << "You are in " << endl;
        }
    }

    void view_all_accounts()
    {
        for (int i = 0; i < accounts_count; i++)
        {
            accounts[i]->view_account_deets();
            cout << endl;
        }
    }

    void process_bill_payments()
    {
        int acc_idd;
        double bill_amount;
        cout << "Enter account ID brother/sister: ";
        cin >> acc_idd;
        cout << "Enter amount to pay: ";
        cin >> bill_amount;

        for (int i = 0; i < accounts_count; ++i)
        {
            if (accounts[i]->get_account_id() == acc_idd)
            {
                accounts[i]->pay_bill(0, bill_amount);
                return;
            }
        }
        cout << "Dear, you account doesn't exist." << endl;
    }

    void open_new_acc()
    {
        if (accounts_count >= 15)
        {
            cout << "Cannot open more accounts. Limit reached." << endl;
            return;
        }

        string holderName;
        int acc_id, pin;
        double initialBalance;
        cout << "Enter new account number: ";
        cin >> acc_id;
        cout << "Enter account holder/owner's name: ";
        cin >> holderName;
        cout << "Enter initial balance: ";
        cin >> initialBalance;
        cout << "Enter the PIN with which you want to access your account: ";
        cin >> pin;

        accounts[accounts_count] = new bank(holderName, acc_id, initialBalance);
        accounts_count++;
        cout << "Account successfully created." << endl;
    }

    void good_ending()
    {
        cout << "It is time for you to leave now, happy banking fella!" << endl;
        return;
    }
};

atm test1;
admin admin1;

void bank_section()
{
    string name;
    int acc_id, initial_balance;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your account ID: ";
    cin >> acc_id;
    cout << "Enter your initial balance: ";
    cin >> initial_balance;

    bank *new_account = new bank(name, acc_id, initial_balance);
    test1.add_account(new_account, 0000);

    int choice;
    do
    {
        cout << "\nBank Menu:\n1. Pay Bills\n2. Withdraw Cash\n3. Deposit Cash\n4. View Account Details\n5. Exit to Main Menu\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int bill_no, bill_amount;
            cout << "Enter bill number: ";
            cin >> bill_no;
            cout << "Enter bill amount: ";
            cin >> bill_amount;
            new_account->pay_bill(bill_no, bill_amount);
            break;
        }
        case 2:
        {
            int amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            new_account->withdraw_money(amount);
            break;
        }
        case 3:
        {
            int amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            new_account->deposit_money(amount);
            break;
        }
        case 4:
            new_account->view_account_deets();
            break;
        case 5:
            cout << "Exiting to main menu." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);
}

void atm_section()
{
    int acc_id, pin;
    cout << "Enter your account ID: ";
    cin >> acc_id;
    cout << "Enter your PIN: ";
    cin >> pin;

    if (!test1.pin_validation(acc_id, pin))
    {
        cout << "Invalid account ID or PIN. Exiting." << endl;
        return;
    }

    int choice;
    do
    {
        cout << "\nATM Menu:\n1. Withdraw Cash\n2. Change PIN\n3. Balance Inquiry\n4. Exit to Main Menu\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            test1.withdraw_cash_from_atm(acc_id, amount);
            break;
        }
        case 2:
        {
            int new_pin;
            cout << "Enter new PIN: ";
            cin >> new_pin;
            test1.change_pin(acc_id, new_pin);
            break;
        }
        case 3:
            test1.balance_enquiry(acc_id);
            break;
        case 4:
            cout << "Exiting to main menu." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);
}

void admin_section()
{
    string name, pass;
    cout << "Enter admin username: ";
    cin >> name;
    cout << "Enter admin password: ";
    cin >> pass;

    admin1.user_authentication(name, pass);
}

int main()
{
    int x;
    do
    {

        cout << "** WELCOME TO PURANA-PAY BANKING ** " << endl;
        cout << "Please select one of the options below to continue." << endl;
        cout << "Select 1 to enter Bank" << endl;
        cout << "Select 2 to enter ATM" << endl;
        cout << "Select 3 to gain Admin access" << endl;
        cout << "Select 4 to exit the system" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            bank_section();
            break;
        case 2:
            atm_section();
            break;
        case 3:
            admin_section();
            break;
        case 4:
            cout << "Exiting the system now. Happy Banking :)" << endl;
            break;
        default:
            cout << "You are not entering the proper digit. Try again." << endl;
        }
    } while (x != 4);

    return 0;
}