#include <iostream>
#include <deque>        
#include <iterator>  

using namespace::std;


template <typename T>
class Account {
protected:
    T amount;
    
    int percent;
public:
    int period;
    Account(T am, int perd, int perc)
    {
        amount = am;
        period = perd;
        percent = perc;
    }
    
   


    virtual int income() {
        return ((amount / 100 * percent) * period) + amount;
    };
    int permonth()
    {
        cout << amount / 100 * percent << endl;
        return amount / 100 * percent;
    };
    void displayinfo() {
        cout << "Your deposite is " << amount << " with " << percent << "% and for " << period << " months." << endl;
    };
    int dispalyin() {
        cout << "You will recive: " << income() << " - " << amount << " = " << income() - amount << endl;
        return income() - amount;
    };

    void addammount(int x) {
        amount += x;
    }
    int check(const Account& a) {
        if (amount > a.amount){ return amount; }
            
        else { return a.amount; }
          
    };

};


template <typename T>
class LoyalDeposite : public Account<int> {
private:
    int bonus;

public:
    LoyalDeposite(int bon, T am, int perd, int perc) :Account(am, perd, perc)
    {
        bonus = bon;
    }
    int bonusbuf() {
        if (period >= 12) {
            period = period - 12;
            percent += 2;
            if (period >= 12) {
                period = period - 12;
                percent += 2;
                if (period >= 12) {
                    period = period - 12;
                    percent += 2;
                    if (period >= 12) {
                        period = period - 12;
                        percent += 2;
                    }
                }
            }

        }
        return percent;
    }


    int dispalyin() {
        Account::displayinfo();
        cout << " And your bonus is " << bonus << endl;
    };

    int income() {
        return ((amount / 100 * percent) * period) + amount;
    };

};







int main()
{   
    int a=0, b=0, c=0;
    cin >> a >> b >> c;
    Account<int> acc1(a, b, c);

    int q = 0, w = 0, e = 0;
    cin >> q >> w >> e;
    Account<int> acc2(q, w, e);


    deque<Account<int>> myDeque;
    myDeque.push_back(Account<int>(acc1));
    myDeque.push_back(Account<int>(acc2));
 
  
    for (Account<int> n : myDeque) {
        n.displayinfo();
    }
    cout << myDeque[0].period << " months " << myDeque[1].period << " months " << endl;
    cout << myDeque[0].check(myDeque[1]) << endl;
        int h = 0;
        if (b > w) {h =  b; }
        
    else { h = w; }
    
        
    cout << "Bank need to return: " << myDeque[0].income() + myDeque[1].income() << " in just " << h << " months" << endl;
    
    return 0;
}
