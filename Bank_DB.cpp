#include<iostream>
#include<fstream>
using namespace std;
class BankAccount {
private:
 string name;
 string acc_no;
 float balance = 10000; // Ek hi base balance jo modify hoga
 float amt;
public:
 void withdraw() {
 cout << "Enter your name: " << endl;
 cin >> name;
 cout << "Enter acc. no.: " << endl;
 cin >> acc_no;
 cout << "Enter amount to withdraw: " << endl;
 cin >> amt;
 if (amt <= balance) {
 balance -= amt; // Balance update kiya
 cout << "Remaining balance = " << balance << endl;
 logTransaction("Withdrawal");
 } else {
 cout << "InsuUicient balance :-(" <<endl;
 }
 }
 void deposit() {
 cout << "Enter your name: " << endl;
 cin >> name;
 cout << "Enter acc. no.: " << endl;
 cin >> acc_no;
 cout << "Enter amount to deposit: " << endl;
 cin >> amt;
 balance += amt; // Balance update kiya
 cout << "Current balance = " << balance << endl;
 logTransaction("Deposit");
 }
private:
 // Ek common private function jo file me append (`ios::app`) karega

 void logTransaction(string type) {
//Log data ko file me save karta hai. aur logTransection fn name hai..
 ofstream fout("Bank_DB.txt", ios::app); // ios::app se data overwrite nahi hoga, neeche judta jayega
 if (fout.is_open()) {
 fout << "--- " << type << " Transaction ---" << endl;
 fout << "Name = " << name << endl;
 fout << "Account No. = " << acc_no << endl;
 fout << "Amount = " << amt << endl;
 fout << "Updated Balance = " << balance << endl;
 fout << "------------------------" << endl << endl;
 fout.close();
 cout << "Transaction saved to Database successfully! \n";
 }
 }
};
int main() {
 BankAccount account; // Ek hi object se dono kaam
 int choose;

 //Loop
 while(true) {
 cout<<"\n========== WELCOME TO OMNI BANKING SYSTEM =========="<<endl;
 cout<<"1. Withdraw Money"<<endl;
 cout<<"2. Deposit Money"<<endl;
 cout<<"3. Exit"<<endl;
 cout << "Select an option (1-3): ";
 cin >> choose;

 if (choose == 1) {
 account.withdraw();
 } else if (choose == 2) {
 account.deposit();
 } else if (choose == 3){
 cout << "Thank you for using our banking system." << endl;
 break; //loop close
 }
 else{
 cout<<"Invalid input! "<<endl;
}}
 return 0;
}
 
